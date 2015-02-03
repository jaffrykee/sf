#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

namespace SFResConfigReader
{
	/*从src中得到第一个以split这个字符为分割的字符串，放到dst中*/
	UINT getFirstSplit(char* dst, int max, const char* src, char split)
	{
		UINT lenSrc = strlen(src);
		UINT minEnd = (max < lenSrc) ? max:lenSrc;

		if (NULL==src || NULL==dst)
		{
			return 0;
		}
		for (UINT i = 0; i < minEnd; i++)
		{
			if (src[i] == split)
			{
				strncpy_s(dst, max, src, i);

				return i;
			}
		}
		strncpy_s(dst, max, src, minEnd);

		return 0;
	}

	/*XML单个节点解析主逻辑*/
	bool readXMLNode(CComPtr<IXmlReader> pReader, UINT tabCount[], SFResPlayer* resPlayer)
	{
		HRESULT hr = S_OK;
		LPCWSTR name;
		LPCWSTR value;
		bool ret = false;
		static void* parseCount[PRS_MAX] = {NULL};
		static SF_EKA s_skillEka;
		static SF_AS s_skillAs;
		static SF_SSSE s_skillSsse;
		static bool s_skillSavable;
		static UINT boxType = 0;

		if (resPlayer == NULL)
		{
			return false;
		}
		if (tabCount[1] == 1)//11
		{
			if (tabCount[2] == 0)//110
			{
				#pragma region skin_table
				#pragma endregion
			}
			else if (tabCount[2] > 0)//11x
			{
				if (tabCount[3] == 0)//11x0
				{
					#pragma region skin
					#pragma endregion
				}
			}
		}
		else if (tabCount[1] == 2)//12
		{
			if (tabCount[2] == 0)//120
			{
				#pragma region skill_table
				#pragma endregion
			}
			else if (tabCount[2] > 0)//12x
			{
				if (tabCount[3] == 0)//12x0
				{
					#pragma region skill
					POLL_XML_ATTR_BEGIN
						if (utfName == "eka")
						{
							map<string, UINT>::iterator itEka = g_pConf->m_pDiEka->m_map.find(utfValue);
							if (itEka != g_pConf->m_pDiEka->m_map.end())
							{
								s_skillEka = (SF_EKA)itEka->second;
							}
							else
							{
								sf_cout(DEBUG_COM, endl << "readXMLNode error: This is not \"" << utfValue << "\" " << utfName << " Attr.");
								return false;
							}
						}
						else if (utfName == "as")
						{
							map<string, UINT>::iterator itAs = g_pConf->m_pDiAs->m_map.find(utfValue);
							if (itAs != g_pConf->m_pDiAs->m_map.end())
							{
								s_skillAs = (SF_AS)itAs->second;
							}
							else
							{
								sf_cout(DEBUG_COM, endl << "readXMLNode error: This is not \"" << utfValue << "\" " << utfName << " Attr.");
								return false;
							}
						}
						else if (utfName == "ssse")
						{
							map<string, UINT>::const_iterator itSsse = g_pConf->m_pDiSsse->m_map.find(utfValue);
							if (itSsse != g_pConf->m_pDiSsse->m_map.end())
							{
								s_skillSsse = (SF_SSSE)itSsse->second;
							}
							else
							{
								sf_cout(DEBUG_COM, endl << "readXMLNode error: This is not \"" << utfValue << "\" " << utfName << " Attr.");
								return false;
							}
						}
						else if (utfName == "savable")
						{
							if (utfValue == "true")
							{
								s_skillSavable = true;
							}
							else
							{
								s_skillSavable = false;
							}
						}
					POLL_XML_ATTR_END
					#pragma endregion
				}
				else if (tabCount[3] == 1)//12x1
				{
					if (tabCount[4] == 0)//12x10
					{
						#pragma region object_table & skill节点头结束
						parseCount[PRS_SKL] = new SFResSkill(s_skillEka, s_skillAs, s_skillSsse, resPlayer, s_skillSavable);
						#pragma endregion
					}
					else if (tabCount[4] > 0)//12x1x
					{
						if (tabCount[5] == 0)//12x1x 0
						{
							#pragma region object
							parseCount[PRS_OBJ] = new SFResObject((SFResSkill*)parseCount[PRS_SKL]);
							POLL_XML_ATTR_BEGIN
								if (utfName == "id")
								{
									stringstream ss;
									UINT iValue;

									ss << utfValue;
									ss >> iValue;
								}
							POLL_XML_ATTR_END
							#pragma endregion
						}
						else if (tabCount[5] == 1)//12x1x 1
						{
							if (tabCount[6] == 0)//12x1x 10
							{
								#pragma region frame_table
								#pragma endregion
							}
							else if (tabCount[6] > 0)//12x1x 1x
							{
								if (tabCount[7] == 0)//12x1x 1x0
								{
									#pragma region frame
									parseCount[PRS_FRM] = new SFResFrame((SFResObject*)parseCount[PRS_OBJ]);
									((SFResFrame*)parseCount[PRS_FRM])->m_parent = (SFResObject*)parseCount[PRS_OBJ];
									POLL_XML_ATTR_BEGIN
										if (utfName == "id")
										{
											stringstream ss;
											UINT iValue;

											ss << utfValue;
											ss >> iValue;
										}
									POLL_XML_ATTR_END
									#pragma endregion
								}
								else if (tabCount[7] == 1)//12x1x 1x1x
								{
									if (tabCount[8] == 0)//12x1x 1x10
									{
										#pragma region point(frame) 代表物体的位移属性
										POLL_XML_ATTR_BEGIN
											if (utfName == "x")
											{
												stringstream ss;
												float fValue;

												ss << utfValue;
												ss >> fValue;
												((SFResFrame*)parseCount[PRS_FRM])->m_poiMove.x = fValue;
											}
											else if (utfName == "y")
											{
												stringstream ss;
												float fValue;

												ss << utfValue;
												ss >> fValue;
												((SFResFrame*)parseCount[PRS_FRM])->m_poiMove.y = fValue;
											}
										POLL_XML_ATTR_END
										#pragma endregion
									}
								}
								else if (tabCount[7] == 2)//12x1x 1x2x
								{
									if (tabCount[8] == 0)//12x1x 1x20
									{
										#pragma region box_table
										#pragma endregion
									}
									else if (tabCount[8] > 0)//12x1x 1x2x
									{
										if (tabCount[9] == 0)//12x1x 1x2x0
										{
											#pragma region box
											POLL_XML_ATTR_BEGIN
												if (utfName == "type")
												{
													stringstream ss;
													UINT iValue;

													ss << utfValue;
													ss >> iValue;
													boxType = iValue;
												}
											POLL_XML_ATTR_END
											#pragma endregion
										}
										else if (tabCount[9] == 1)//12x1x 1x2x1
										{
											if (tabCount[10] == 0)//12x1x 1x2x1 0
											{
												#pragma region rect(box)
												static D2D1_RECT_F box;
												POLL_XML_ATTR_BEGIN
													if (utfName == "t")
													{
														stringstream ss;
														float fValue;

														ss << utfValue;
														ss >> fValue;
														box.top = fValue;
													}
													else if (utfName == "l")
													{
														stringstream ss;
														float fValue;

														ss << utfValue;
														ss >> fValue;
														box.left = fValue;
													}
													else if (utfName == "b")
													{
														stringstream ss;
														float fValue;

														ss << utfValue;
														ss >> fValue;
														box.bottom = fValue;
													}
													else if (utfName == "r")
													{
														stringstream ss;
														float fValue;

														ss << utfValue;
														ss >> fValue;
														box.right = fValue;
													}
												POLL_XML_ATTR_END

												if (boxType & 0x1)
												{
													((SFResFrame*)parseCount[PRS_FRM])->m_lBodyBox.insert(
														((SFResFrame*)parseCount[PRS_FRM])->m_lBodyBox.end(),
														box);
												}
												if (boxType & 0x2)
												{
													((SFResFrame*)parseCount[PRS_FRM])->m_lAttackBox.insert(
														((SFResFrame*)parseCount[PRS_FRM])->m_lAttackBox.end(),
														box);
												}
												#pragma endregion
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		if (g_pConf->m_enDebug[DEBUG_RES_LOAD])
		{
			wcout << L"\n";
			for (int i = 1; i < SF_XML_TABS_MAX; i++)
			{
				if (tabCount[i] != 0)
				{
					wcout << L"    ";
				}
				else
				{
					break;
				}
			}
			for (int i = 0; i < SF_XML_TABS_MAX; i++)
			{
				wcout << tabCount[i];
				if (i % 5 == 4)
				{
					wcout << " ";
				}
			}
		}

		return ret;
	}

	/*XML解析主逻辑入口*/
	bool readFromXML(string xmlPath, SFResPlayer* resPlayer)
	{
		HRESULT hr = S_OK;
		CComPtr<IStream> pFileStream;
		CComPtr<IXmlReader> pReader;
		XmlNodeType nodeType = XmlNodeType_None;
		WCHAR trueName[NODE_NAME_MAX] = {0};
		LPCWSTR name;
		bool nodeSw[ND_MAX] = {false};
		bool nodeIsOnly[ND_MAX] = {false};
		bool nodeHad[ND_MAX] = {false};
		UINT nodeCount[ND_MAX] = { 0 };

		UINT tabCount[SF_XML_TABS_MAX] = { 0 };
		UINT tabs = 0;

		if (resPlayer == NULL)
		{
			return false;
		}

		memset(tabCount, 0, SF_XML_TABS_MAX*sizeof(UINT));
		tabs = 0;

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

		POLL_XML_NODE_BEGIN(ND_PLY_INF)
			POLL_XML_NODE_BEGIN(ND_SKN_TBL)
				POLL_XML_NODE_BEGIN(ND_SKN)
				POLL_XML_NODE_END(ND_SKN)
			POLL_XML_NODE_END(ND_SKN_TBL)
			POLL_XML_NODE_BEGIN(ND_SKL_TBL)
				POLL_XML_NODE_BEGIN(ND_SKL)
					POLL_XML_NODE_BEGIN(ND_OBJ_TBL)
						POLL_XML_NODE_BEGIN(ND_OBJ)
							POLL_XML_NODE_BEGIN(ND_FRM_TBL)
								POLL_XML_NODE_BEGIN(ND_FRM)
									POLL_XML_NODE_BEGIN(ND_FRM_POI)
									POLL_XML_NODE_END(ND_FRM_POI)
									POLL_XML_NODE_BEGIN(ND_BOX_TBL)
										POLL_XML_NODE_BEGIN(ND_BOX)
											POLL_XML_NODE_BEGIN(ND_BOX_RCT)
											POLL_XML_NODE_END(ND_BOX_RCT)
										POLL_XML_NODE_END(ND_BOX)
									POLL_XML_NODE_END(ND_BOX_TBL)
								POLL_XML_NODE_END(ND_FRM)
							POLL_XML_NODE_END(ND_FRM_TBL)
						POLL_XML_NODE_END(ND_OBJ)
					POLL_XML_NODE_END(ND_OBJ_TBL)
				POLL_XML_NODE_END(ND_SKL)
			POLL_XML_NODE_END(ND_SKL_TBL)
		POLL_XML_NODE_END(ND_PLY_INF)

		return true;
	}

}

SFXmlReader::SFXmlReader(string xsdPath) :m_pRootNode(NULL)
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

	//Open read-only input stream
	hr = SHCreateStreamOnFileA(xsdPath.c_str(), STGM_READ, &pFileStream);
	if (SUCCEEDED(hr))
	{
		hr = CreateXmlReader(__uuidof(IXmlReader), (void**)&pReader, NULL);
	}
	else
	{
		sf_cout(DEBUG_COM, "Error: Can't find the XML file. (\"" << xsdPath << "\")" << endl);
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
					sf_wcout(DEBUG_COM, endl);
					for (UINT i = 0; i < tabs; i++)
					{
						sf_wcout(DEBUG_COM, L"\t");
					}
					sf_wcout(DEBUG_COM, nodeName << L" ");

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
								if (m_data.find(utfValue) == m_data.end())
								{
									m_data[utfValue] = { utfValue, true, NULL, {}, {} };
								}
								if (utfName == "name" || utfName == "ref")
								{
									if (havGetRoot == false)
									{
										m_pRootNode = &m_data[utfValue];
										havGetRoot = true;
									}
									if (tabs > 0)
									{
										string parent = arrNodeBuffer[tabs - 1];

										m_data[utfValue].m_parent = &m_data[parent];
										m_data[parent].m_nodeData.insert(m_data[parent].m_nodeData.end(), &m_data[utfValue]);
									}
								}
							}
							else if (utfName == "minOccurs")
							{

							}
							else if (utfName == "maxOccurs")
							{
								if (utfValue == "unbounded")
								{
									m_data[arrNodeBuffer[tabs]].m_isOnly = false;
								}
							}
						}
						else if (wcscmp(nodeName, L"attribute") == 0)
						{
							if (utfName == "name")
							{
								m_data[arrNodeBuffer[tabs - 1]].m_attrData.insert(m_data[arrNodeBuffer[tabs - 1]].m_attrData.end(), utfValue);
							}
							else if (utfName == "type")
							{
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
}