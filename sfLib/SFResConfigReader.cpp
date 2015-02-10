#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

vector<SFXmlReader::XmlNodeData*> SFXmlReader::s_parseCount;

SFXmlReader::SFXmlReader(string xsdPath) :m_pFrameRootNode(NULL), m_maxDepth(0)
{
	initFrameByXsd(xsdPath);
}

bool SFXmlReader::initFrameByXsd(string xsdPath)
{
	HRESULT hr = S_OK;
	CComPtr<IStream> pFileStream;
	CComPtr<IXmlReader> pReader;
	XmlNodeType nodeType = XmlNodeType_None;
	LPCWSTR nodeName;
	LPCWSTR name;
	LPCWSTR value;
	bool ret;

	//Open read-only input stream
	hr = SHCreateStreamOnFileA(xsdPath.c_str(), STGM_READ, &pFileStream);
	if (SUCCEEDED(hr))
	{
		hr = CreateXmlReader(__uuidof(IXmlReader), (void**)&pReader, NULL);
	}
	else
	{
		sf_cout(DEBUG_COM, "Error: Can't find the XSD file. (\"" << xsdPath << "\")" << endl);

		return false;
	}
	pReader->SetInput(pFileStream);
	hr = pReader->Read(NULL);

	UINT tabs = 0;
	vector<string> arrNodeBuffer;
	for (; S_OK == hr; hr = pReader->Read(NULL))
	{
		pReader->GetLocalName(&nodeName, NULL);
		if (nodeName[0] > L' ')
		{
			if (wcscmp(nodeName, L"element") == 0 || wcscmp(nodeName, L"attribute") == 0)
			{
				pReader->GetNodeType(&nodeType);
				if (nodeType == XmlNodeType_Element)
				{
					sf_wcout(DEBUG_RES_LOAD, endl);
					for (UINT i = 0; i < tabs; i++)
					{
						sf_wcout(DEBUG_RES_LOAD, L"\t");
					}
					sf_wcout(DEBUG_RES_LOAD, nodeName << L" ");

					POLL_XML_ATTR_BEGIN
						if (wcscmp(nodeName, L"element") == 0)
						{
							if (tabs >= arrNodeBuffer.size())
							{
								arrNodeBuffer.insert(arrNodeBuffer.end(), utfValue);
							}
							if (utfName == "name" || utfName == "ref")
							{
								arrNodeBuffer[tabs] = utfValue;
								if (m_frame.find(utfValue) == m_frame.end())
								{
									m_frame[utfValue].m_name = utfValue;
									m_frame[utfValue].m_index = 0;
									m_frame[utfValue].m_depth = 0;
									m_frame[utfValue].m_isOnly = true;
									m_frame[utfValue].m_parent = NULL;
									m_frame[utfValue].m_attrData = map<string, XsdAttrData>{};
									m_frame[utfValue].m_nodeData = {};
								}
								if (tabs > 0)
								{
									string parent = arrNodeBuffer[tabs - 1];

									m_frame[utfValue].m_parent = &m_frame[parent];
									m_frame[parent].m_nodeData.insert(m_frame[parent].m_nodeData.end(), &m_frame[utfValue]);
								}
								if (m_pFrameRootNode == NULL)
								{
									m_pFrameRootNode = &m_frame[utfValue];
								}
							}
							else if (utfName == "maxOccurs")
							{
								if (utfValue == "unbounded")
								{
									m_frame[arrNodeBuffer[tabs]].m_isOnly = false;
								}
							}
						}
						else if (wcscmp(nodeName, L"attribute") == 0)
						{
							if (utfName == "name")
							{
								map<string, XsdAttrData>& mapAttr = m_frame[arrNodeBuffer[tabs - 1]].m_attrData;

								mapAttr[utfName].m_name = utfValue;
								mapAttr[utfName].m_index = mapAttr.size();
							}
						}
					POLL_XML_ATTR_END
					if (!(pReader->IsEmptyElement()) && wcscmp(nodeName, L"element") == 0)
					{
						tabs++;
					}
				}
				else if (nodeType == XmlNodeType_EndElement)
				{
					tabs--;
				}
			}
		}
	}

	setSonNodeDepth(m_pFrameRootNode);
	return true;
}

void SFXmlReader::setSonNodeDepth(XsdNodeData* pRootNode)
{
	static UINT iCount = 0;

	if (pRootNode == m_pFrameRootNode)
	{
		iCount = 0;
	}
	else
	{
		iCount++;
	}
	for (UINT i = 0; i < pRootNode->m_nodeData.size(); i++)
	{
		pRootNode->m_nodeData[i]->m_depth = pRootNode->m_depth + 1;
		if (pRootNode->m_nodeData[i]->m_depth > m_maxDepth)
		{
			m_maxDepth = pRootNode->m_nodeData[i]->m_depth;
		}
		pRootNode->m_nodeData[i]->m_index = iCount + 1;
		sf_cout(DEBUG_RES_LOAD, endl << pRootNode->m_nodeData[i]->m_name <<
			((pRootNode->m_nodeData[i]->m_name.length() >= 8) ? "\t" : "\t\t") << "depth:" << pRootNode->m_nodeData[i]->m_depth <<
			"\t" << "index:" << pRootNode->m_nodeData[i]->m_index);
		setSonNodeDepth(pRootNode->m_nodeData[i]);
	}

	return;
}

bool SFXmlReader::getDataByXml(string xmlPath)
{
	HRESULT hr = S_OK;
	CComPtr<IStream> pFileStream;
	CComPtr<IXmlReader> pReader;
	XmlNodeType nodeType = XmlNodeType_None;
	LPCWSTR nodeName;
	LPCWSTR name;
	LPCWSTR value;
	bool ret;
	bool havGetRoot = false;

	vector<XmlNodeData*> pNodeBuffer;
	XmlNodeData* pNode = NULL;

	pNodeBuffer.resize(m_maxDepth + 1, NULL);

	//Open read-only input stream
	hr = SHCreateStreamOnFileA(xmlPath.c_str(), STGM_READ, &pFileStream);
	if (SUCCEEDED(hr))
	{
		hr = CreateXmlReader(__uuidof(IXmlReader), (void**)&pReader, NULL);
	}
	else
	{
		sf_cout(DEBUG_COM, "Error: Can't find the XML file. (\"" << xmlPath << "\")" << endl);

		return false;
	}
	pReader->SetInput(pFileStream);
	hr = pReader->Read(NULL);

	for (; S_OK == hr; hr = pReader->Read(NULL))
	{
		pReader->GetLocalName(&nodeName, NULL);
		if (nodeName[0] > L' ')
		{
			pReader->GetNodeType(&nodeType);
			if (nodeType == XmlNodeType_Element)
			{
				StringA utfNodeName = TStrTrans::UnicodeToUtf8(nodeName);

				if (m_frame.find(utfNodeName) != m_frame.end())
				{
					XmlNodeData* pParent = NULL;
					if (m_frame[utfNodeName].m_depth == 0)
					{
						pNodeBuffer[0] = &m_rootNode;
						m_rootNode.m_pParent = NULL;
						m_rootNode.m_pNodeType = &m_frame[utfNodeName];
					}
					else
					{
						pParent = pNodeBuffer[m_frame[utfNodeName].m_depth - 1];
						pParent->m_son.insert(pParent->m_son.end(), XmlNodeData());
						pParent->m_son[pParent->m_son.size() - 1].m_pParent = pParent;
						pParent->m_son[pParent->m_son.size() - 1].m_pNodeType = &m_frame[utfNodeName];
						pNodeBuffer[m_frame[utfNodeName].m_depth] = &pParent->m_son[pParent->m_son.size() - 1];
					}
					pParent = pNodeBuffer[m_frame[utfNodeName].m_depth];
					sf_cout(DEBUG_RES_LOAD, endl);
					for (UINT i = 0; i < m_frame[utfNodeName].m_depth; i++)
					{
						sf_cout(DEBUG_RES_LOAD, "  ");
					}
					sf_cout(DEBUG_RES_LOAD, "<" << utfNodeName << ">");
					POLL_XML_ATTR_BEGIN
						pParent->m_attr.insert(pair<string, string>(utfName, utfValue));
					POLL_XML_ATTR_END
				}
			}
		}
	}
	parseXml(m_rootNode);

	return true;
}

bool SFXmlReader::parseXml(XmlNodeData& nodeData)
{
	if (nodeData.m_pParent == NULL)
	{
		s_parseCount.clear();
		s_parseCount.resize(m_maxDepth + 1, NULL);
	}

	s_parseCount[nodeData.m_pNodeType->m_depth] = &nodeData;
	parseXmlNode(nodeData);
	for (UINT i = 0; i < nodeData.m_son.size(); i++)
	{
		parseXml(nodeData.m_son[i]);
	}

	return true;
}

typedef enum SF_ResParseNodeForPlayer
{
	RNP_player_info, RNP_skin_table, RNP_skin, RNP_skill_table, RNP_skill,
	RNP_object_table, RNP_object, RNP_frame_table, RNP_frame, RNP_point,
	RNP_box_table, RNP_box, RNP_rect,
	RNP_MAX
}SF_RNP;

typedef enum SF_ResParsePtrBufferForPlayer
{
	RPP_SKL, RPP_OBJ, RPP_FRM,
	RPP_MAX
}SF_RPP;

bool SFXmlPlayer::parseXmlNode(XmlNodeData& nodeData)
{
	static void* pBuffer[RPP_MAX] = {NULL};

	if (m_pResPlayer == NULL)
	{
		return false;
	}
	switch (nodeData.m_pNodeType->m_index)
	{
	case RNP_player_info:
		memset(pBuffer, NULL, sizeof(void*)*RPP_MAX);
		break;
	case RNP_skin_table:
		break;
	case RNP_skin:
		break;
	case RNP_skill_table:
		break;
	case RNP_skill:
		#pragma region skill
		if (g_pConf->m_pDiEka->m_map.find(nodeData.m_attr["eka"]) != g_pConf->m_pDiEka->m_map.end())
		{
			if (g_pConf->m_pDiAs->m_map.find(nodeData.m_attr["as"]) != g_pConf->m_pDiAs->m_map.end())
			{
				if (g_pConf->m_pDiSsse->m_map.find(nodeData.m_attr["ssse"]) != g_pConf->m_pDiSsse->m_map.end())
				{
					bool saveble = (nodeData.m_attr["savable"] == "true");

					pBuffer[RPP_SKL] = m_pResPlayer->addSkill(
						(SF_EKA)g_pConf->m_pDiEka->m_map[nodeData.m_attr["eka"]],
						(SF_AS)g_pConf->m_pDiAs->m_map[nodeData.m_attr["as"]],
						(SF_SSSE)g_pConf->m_pDiSsse->m_map[nodeData.m_attr["ssse"]],
						saveble
					);
				}
				else
				{
					sf_cout(DEBUG_COM, endl << "readXMLNode error: This is not \"" << nodeData.m_attr["ssse"] << "\" " << "ssse" << " Attr.");
					return false;
				}
			}
			else
			{
				sf_cout(DEBUG_COM, endl << "readXMLNode error: This is not \"" << nodeData.m_attr["as"] << "\" " << "as" << " Attr.");
				return false;
			}
		}
		else
		{
			sf_cout(DEBUG_COM, endl << "readXMLNode error: This is not \"" << nodeData.m_attr["eka"] << "\" " << "eka" << " Attr.");
			return false;
		}
		#pragma endregion
		break;
	case RNP_object_table:
		break;
	case RNP_object:
		pBuffer[RPP_OBJ] = &((SFResSkill*)(pBuffer[RPP_SKL]))->addObject();
		break;
	case RNP_frame_table:
		break;
	case RNP_frame:
		pBuffer[RPP_FRM] = &((SFResObject*)(pBuffer[RPP_OBJ]))->addFrame();
		break;
	case RNP_point:
		#pragma region point
		{
			stringstream ss;
			FLOAT fValue;

			ss << nodeData.m_attr["x"];
			ss >> fValue;
			((SFResFrame*)pBuffer[RPP_FRM])->m_poiMove.x = fValue;
			ss.clear();
			ss << nodeData.m_attr["y"];
			ss >> fValue;
			((SFResFrame*)pBuffer[RPP_FRM])->m_poiMove.y = fValue;
			ss.clear();
		}
		#pragma endregion
		break;
	case RNP_box_table:
		break;
	case RNP_box:
		#pragma region box
		{
			stringstream ss;
			UINT iValue;
			FLOAT fValue;
			D2D1_RECT_F box;

			ss << nodeData.m_son[0].m_attr["t"];
			ss >> fValue;
			box.top = fValue;
			ss.clear();
			ss << nodeData.m_son[0].m_attr["l"];
			ss >> fValue;
			box.left = fValue;
			ss.clear();
			ss << nodeData.m_son[0].m_attr["b"];
			ss >> fValue;
			box.bottom = fValue;
			ss.clear();
			ss << nodeData.m_son[0].m_attr["r"];
			ss >> fValue;
			box.right = fValue;
			ss.clear();
			ss << nodeData.m_attr["type"];
			ss >> iValue;
			((SFResFrame*)pBuffer[RPP_FRM])->addBox(iValue, box);
			ss.clear();
		}
		#pragma endregion
		break;
	case RNP_rect:
		break;
	}

	return true;
}

typedef enum SF_ResParseNodeForScene
{
	RNS_scene_info, RNS_scene_table, RNS_scene, RNS_camera_info, RNS_sprite_table,
	RNS_sprite,
	RNS_MAX
}SF_RNS;

bool SFXmlScene::parseXmlNode(XmlNodeData& nodeData)
{
	if (m_pResScene == NULL)
	{
		return false;
	}
	switch (nodeData.m_pNodeType->m_index)
	{
	case RNS_scene_info:
		break;
	case RNS_scene_table:
		break;
	case RNS_scene:
		{
			stringstream ss;
			FLOAT fValue;

			ss << nodeData.m_attr["width"];
			ss >> fValue;
			m_pResScene->m_width = fValue;
			ss.clear();
			ss << nodeData.m_attr["height"];
			ss >> fValue;
			m_pResScene->m_height = fValue;
			ss.clear();
		}
		break;
	case RNS_camera_info:
		{
			stringstream ss;
			FLOAT fValue;

			ss << nodeData.m_attr["x"];
			ss >> fValue;
			m_pResScene->m_camera.x = fValue;
			ss.clear();
			ss << nodeData.m_attr["y"];
			ss >> fValue;
			m_pResScene->m_camera.y = fValue;
			ss.clear();
		}
		break;
	case RNS_sprite_table:
		break;

	case RNS_sprite:
		{
			stringstream ss;
			FLOAT fValue;
			FLOAT tx, ty;
			D2D1_POINT_2F tPoi;

			if (nodeData.m_attr.find("x") != nodeData.m_attr.end())
			{
				ss << nodeData.m_attr["x"];
				ss >> fValue;
				tx = fValue;
				ss.clear();
			}
			else
			{
				tx = 0;
			}
			if (nodeData.m_attr.find("y") != nodeData.m_attr.end())
			{
				ss << nodeData.m_attr["y"];
				ss >> fValue;
				ty = fValue;
				ss.clear();
			}
			else
			{
				ty = 0;
			}
			tPoi = { tx, ty };

			if (nodeData.m_attr["id"] == "player1")
			{
				m_pResScene->m_poiP1 = tPoi;
			}
			else if (nodeData.m_attr["id"] == "player2")
			{
				m_pResScene->m_poiP2 = tPoi;
			}
			else if (nodeData.m_attr["id"] == "ground")
			{
				m_pResScene->m_fGround = ty;
			}
		}
		break;
	}

	return true;
}