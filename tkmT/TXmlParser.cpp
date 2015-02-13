#pragma execution_character_set("utf-8")
#include <bpt.h>

TXmlReader::TXmlReader(string path) :m_path(path)
{
	refreshReader(path);
}

bool TXmlReader::refreshReader(string xmlPath)
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
	UINT tabs = 0;

	vector<XmlNodeData*> pNodeBuffer;
	XmlNodeData* pCurNode = NULL;

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
	m_pParentNodeBuffer.clear();

	for (; S_OK == hr; hr = pReader->Read(NULL))
	{
		pReader->GetLocalName(&nodeName, NULL);
		pReader->GetNodeType(&nodeType);
		if (nodeType == XmlNodeType_Element)
		{
			bool isEmpty = pReader->IsEmptyElement();
			StringA utfNodeName = TStrTrans::UnicodeToUtf8(nodeName);

			if (m_pParentNodeBuffer.size() == 0)
			{
				pCurNode = &m_rootNode;
				m_pParentNodeBuffer.push_back(pCurNode);
				pCurNode->m_name = utfNodeName;
				pCurNode->m_pParent = NULL;
			}
			else
			{
				m_pParentNodeBuffer[tabs - 1]->m_son.push_back(XmlNodeData());
				pCurNode = &(m_pParentNodeBuffer[tabs - 1]->m_son[m_pParentNodeBuffer[tabs - 1]->m_son.size() - 1]);
				if (tabs >= m_pParentNodeBuffer.size())
				{
					m_pParentNodeBuffer.push_back(pCurNode);
				}
				else
				{
					m_pParentNodeBuffer[tabs] = pCurNode;
				}
				pCurNode->m_name = utfNodeName;
				pCurNode->m_pParent = m_pParentNodeBuffer[tabs - 1];
			}
			sf_cout(DEBUG_RES_LOAD, "<" << utfNodeName << ">");
			POLL_XML_ATTR_BEGIN
				pCurNode->m_attr.insert(pair<string, string>(utfName, utfValue));
			POLL_XML_ATTR_END
			if (!isEmpty)
			{
				tabs++;
			}
		}
		else if (nodeType == XmlNodeType_Text)
		{
			pReader->GetValue(&value, NULL);
			StringA utfValue = TStrTrans::UnicodeToUtf8(value);
			sf_cout(DEBUG_RES_LOAD, endl << "    " << utfValue);
			pCurNode->m_string = utfValue;
		}
		else if (nodeType == XmlNodeType_EndElement)
		{
			tabs--;
		}
	}

	return true;
}

bool TXmlReader::addNode(XmlNodeData& dst, XmlNodeData& src)
{
	src.m_pParent = &dst;
	dst.m_son.push_back(src);

	return true;
}

TXmlWriter::TXmlWriter(string path, TXmlReader xmlNodes) :m_xmlNodes(xmlNodes), m_path(path)
{
	refreshWriter(path, xmlNodes);
}

bool TXmlWriter::refreshWriter(string proPath, TXmlReader xmlNodes)
{
	HRESULT hr = S_OK;
	CComPtr<IStream> pFileStream;
	CComPtr<IXmlWriter> pWriter;

	//Open stream
	hr = SHCreateStreamOnFileA(proPath.c_str(), STGM_WRITE, &pFileStream);
	if (SUCCEEDED(hr))
	{
		hr = CreateXmlWriter(__uuidof(IXmlWriter), (void**)(&pWriter), NULL);
	}
	else
	{
		sf_cout(DEBUG_COM, "Error: Can't find the Xml file. (\"" << proPath << "\")" << endl);

		return false;
	}
	pWriter->SetOutput(pFileStream);

	if (FAILED(hr = pWriter->SetProperty(XmlWriterProperty_Indent, TRUE)))
	{
		wprintf(L"Error, Method: SetProperty XmlWriterProperty_Indent, error is %08.8lx", hr);
		return false;
	}
	if (FAILED(hr = pWriter->WriteStartDocument(XmlStandalone_Omit)))
	{
		sf_wprintf(DEBUG_COM, L"Error, Method: WriteStartDocument, error is %08.8lx", hr);
		return false;
	}
	writerNode(xmlNodes.m_rootNode, pWriter);

	return true;
}

void TXmlWriter::writerNode(XmlNodeData node, CComPtr<IXmlWriter> pWriter)
{
	pWriter->WriteStartElement(NULL, TStrTrans::Utf8ToUnicode(node.m_name.c_str()).c_str(), L"http://schemas.microsoft.com/developer/msbuild/2003");
	{
		map<string, string>::iterator it;
		for (it = node.m_attr.begin(); it != node.m_attr.end(); ++it)
		{
			pWriter->WriteAttributeString(
				NULL,
				TStrTrans::Utf8ToUnicode(it->first.c_str()).c_str(),
				NULL,
				TStrTrans::Utf8ToUnicode(it->second.c_str()).c_str()
			);
		}
	}
	if (node.m_string != "")
	{
		pWriter->WriteString(TStrTrans::Utf8ToUnicode(node.m_string.c_str()).c_str());
	}
	for (UINT i = 0; i < node.m_son.size(); i++)
	{
		writerNode(node.m_son[i], pWriter);
	}
	pWriter->WriteFullEndElement();
}