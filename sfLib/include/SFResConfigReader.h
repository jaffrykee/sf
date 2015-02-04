#pragma once
#pragma execution_character_set("utf-8")

using namespace std;

#pragma region POLL_XML函数宏及其相关define
#define POLL_RET (hr)
#define POLL_PREADER (pReader)
#define POLL_NAME (name)
#define POLL_SW nodeSw
#define POLL_NODEISONLY nodeIsOnly
#define POLL_NODEHAD nodeHad
#define POLL_NODENAME nodeName
#define POLL_TABSCOUNT (tabs)
#define POLL_NODECOUNT nodeCount
#define POLL_TABSCOUNT_ARR tabCount
#define POLL_RESPLAYER resPlayer

/*
遍历该级xml的每一个枚举为"sf_nd"的节点。
tips:linuxC风格太浓厚了，不过很灵活。
*/
#define POLL_XML_NODE_BEGIN(sf_nd)	\
	if(!(POLL_NODEISONLY[sf_nd] && POLL_NODEHAD[sf_nd]))	\
	{	\
		POLL_TABSCOUNT++;	\
		for ( \
			POLL_PREADER->GetLocalName(&POLL_NAME, NULL); \
			S_OK == POLL_RET; \
			POLL_RET = POLL_PREADER->Read(NULL),	\
			POLL_PREADER->GetLocalName(&POLL_NAME, NULL)	\
		)	\
		{	\
			if (POLL_NAME[0] > L' ')	\
			{	\
				if ((POLL_SW[sf_nd]))	\
				{	\
					if (0 == wcscmp(POLL_NAME, POLL_NODENAME[sf_nd]))	\
					{	\
						POLL_SW[sf_nd] = false;	\
						for(int i = sf_nd + 1; i < ND_MAX; i++)	\
						{	\
							POLL_NODEHAD[i] = false;	\
						}	\
						POLL_TABSCOUNT_ARR[POLL_TABSCOUNT] = 0;	\
						POLL_TABSCOUNT--;	\
						break;	\
					}

#define POLL_XML_NODE_END(sf_nd)	\
				}	\
				else	\
				{	\
					if (0 == wcscmp(POLL_NAME, POLL_NODENAME[sf_nd]))	\
					{	\
						(POLL_SW[sf_nd]) = true;	\
						(POLL_NODEHAD[sf_nd]) = true;	\
						if(g_pConf->m_enDebug[DEBUG_RES_LOAD])	\
						{	\
							cout << "\n";	\
							for(UINT i = 0; i < POLL_TABSCOUNT - 1; i++)	\
								cout << "    ";	\
							cout << "#" << (POLL_TABSCOUNT - 1) << ":" << (POLL_TABSCOUNT_ARR[POLL_TABSCOUNT - 1] + 1);	\
							wcout << L"<" << nodeName[sf_nd] << L">";	\
						}	\
						POLL_TABSCOUNT_ARR[POLL_TABSCOUNT - 1]++; \
						readXMLNode(POLL_PREADER, POLL_TABSCOUNT_ARR, POLL_RESPLAYER);	\
					}	\
				}	\
			}	\
		}	\
	}

#define POLL_XML_ATTR_BEGIN		\
for (hr = pReader->MoveToFirstAttribute(); S_OK == hr; hr = pReader->MoveToNextAttribute())		\
{		\
	pReader->GetLocalName(&name, NULL);		\
	pReader->GetValue(&value, NULL);		\
	StringA utfName = TStrTrans::UnicodeToUtf8(name);		\
	StringA utfValue = TStrTrans::UnicodeToUtf8(value);		\
	sf_cout(DEBUG_RES_LOAD, utfName << ":" << utfValue << " ");		\
	ret = true;

#define POLL_XML_ATTR_END		\
}

#define NODE_NAME_MAX 64
#pragma endregion

#pragma region playerInfo.xml中的所有节点相关define以及路径define
enum SF_XML_ND
{
	ND_PLY_INF, ND_SKN_TBL, ND_SKN, ND_SKL_TBL, ND_SKL, ND_OBJ_TBL, ND_OBJ,
	ND_FRM_TBL, ND_FRM, ND_FRM_POI, ND_BOX_TBL, ND_BOX, ND_BOX_RCT,
	ND_MAX
};
#define SF_XML_TABS_MAX ND_MAX
#pragma endregion

namespace SFResConfigReader
{
	const bool nodeIsOnly[SF_XML_ND::ND_MAX] = {
		true, true, false, true, false, true, false,
		true, false, true, true, false, true
	};

	const WCHAR nodeName[SF_XML_ND::ND_MAX][NODE_NAME_MAX] = {
		L"player_info", L"skin_table", L"skin", L"skill_table", L"skill", L"object_table", L"object",
		L"frame_table", L"frame", L"point", L"box_table", L"box", L"rect"
	};

	bool __declspec(dllexport) readXMLNode(CComPtr<IXmlReader> pReader, UINT tabCount[], SFResPlayer& resPlayer);
	bool __declspec(dllexport) readFromXML(string xmlPath, SFResPlayer* resPlayer);
}

class __declspec(dllexport) SFXmlReader
{
public:
	struct XsdNodeData
	{
		string m_name;
		UINT m_depth;
		bool m_isOnly;

		XsdNodeData* m_parent;
		vector<string> m_attrData;
		vector<XsdNodeData*> m_nodeData;
	};

	string m_path;
	string m_name;
	XsdNodeData* m_pRootNode;
	map<string, XsdNodeData> m_data;
	UINT m_maxDepth;

	SFXmlReader(string xsdPath);

	bool initFrameByXsd(string xsdPath);
	void setSonNodeDepth(XsdNodeData* pRootNode);
	bool getDataByXml(string xmlPath);

protected:
	virtual void parseXmlNode(string nodeName) = 0;
	virtual void parseXmlAttr(string attrName, string attrValue) = 0;
};

class __declspec(dllexport) SFXmlPlayer :public SFXmlReader
{
	SFResPlayer* m_pResPlayer;
};

class __declspec(dllexport) SFXmlScene :public SFXmlReader
{
	SFResScene* m_pResScene;
};