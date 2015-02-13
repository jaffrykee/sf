#pragma once
#pragma execution_character_set("utf-8")

struct XmlNodeData
{
	XmlNodeData* m_pParent;
	string m_name;

	vector<XmlNodeData> m_son;
	map<string, string> m_attr;
	string m_string;
};

class TXmlReader
{
public:
	string m_path;
	XmlNodeData m_rootNode;
	vector<XmlNodeData*> m_pParentNodeBuffer;

	TXmlReader(string path);
	bool refreshReader(string xmlPath);
	bool addNode(XmlNodeData& dst, XmlNodeData& src);
};

class TXmlWriter
{
public:
	string m_path;
	TXmlReader m_xmlNodes;

	TXmlWriter(string path, TXmlReader xmlNodes);
	bool refreshWriter(string proPath, TXmlReader xmlNodes);
	void writerNode(XmlNodeData node, CComPtr<IXmlWriter> pWriter);
};