#pragma once
#pragma execution_character_set("utf-8")

using namespace std;

#pragma region xml读取节点的define
/*
tips:linuxC风格太浓厚了，不过很灵活。
*/
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
#pragma endregion

class __declspec(dllexport) SFXmlReader
{
public:
	struct XsdAttrData
	{
		string m_name;
		UINT m_index;
	};
	struct XsdNodeData
	{
		string m_name;
		UINT m_index;
		UINT m_depth;
		bool m_isOnly;

		XsdNodeData* m_parent;
		map<string, XsdAttrData> m_attrData;
		vector<XsdNodeData*> m_nodeData;
	};
	struct XmlNodeData
	{
		XmlNodeData* m_pParent;
		XsdNodeData* m_pNodeType;
		vector<XmlNodeData> m_son;
		map<string, string> m_attr;
	};

	string m_path;
	string m_name;
	XsdNodeData* m_pFrameRootNode;
	map<string, XsdNodeData> m_frame;
	XmlNodeData m_rootNode;
	UINT m_maxDepth;
	vector<XmlNodeData*> m_pParentNodeBuffer;

	static vector<XmlNodeData*> s_parseCount;

	SFXmlReader(string xsdPath);

	bool initFrameByXsd(string xsdPath);
	void setSonNodeDepth(XsdNodeData* pRootNode);
	bool getDataByXml(string xmlPath);
	bool parseXml(XmlNodeData& nodeData);

	virtual bool parseXmlNode(XmlNodeData& nodeData) = 0;
};

class __declspec(dllexport) SFXmlPlayer :public SFXmlReader
{
public:
	SFResPlayer* m_pResPlayer;

	SFXmlPlayer(string xsdPath, SFResPlayer* pResPlayer) :SFXmlReader(xsdPath), m_pResPlayer(pResPlayer){}
	bool parseXmlNode(XmlNodeData& nodeData);
};

class __declspec(dllexport) SFXmlScene :public SFXmlReader
{
public:
	SFResScene* m_pResScene;

	SFXmlScene(string xsdPath, SFResScene* pResScene) :SFXmlReader(xsdPath), m_pResScene(pResScene){}
	bool parseXmlNode(XmlNodeData& nodeData);
};