#pragma once
#pragma execution_character_set("utf-8")
#include <tchar.h>
#include <comutil.h>
#include <msxml6.h>
class CXmlDoc
{
	TCHAR  m_szXmlFile[MAX_PATH];
protected:
	IXMLDOMDocument * m_pXmlDoc;

public:
	CXmlDoc(void);
public:
	~CXmlDoc(void);

public:
	HRESULT CreateXmlDoc();
	//读数据
	HRESULT Open(const TCHAR * pszXmlFile);
	HRESULT GetRoot(IXMLDOMElement **ppRoot);
	//写数据
	HRESULT AddDeclaration(TCHAR *version = _T("1.0"), TCHAR *encoding = _T("Unicode"));
	HRESULT CreateElement(TCHAR* tagName, IXMLDOMElement **pElement);
	HRESULT SetAttribute(IXMLDOMElement *pElement, TCHAR* name, TCHAR* value);
	HRESULT SetAttribute(IXMLDOMElement *pElement, TCHAR* name, int value);
	HRESULT SetAttribute(IXMLDOMElement *pElement, TCHAR* name, __int64 value);
	HRESULT SetAttribute(IXMLDOMElement *pElement, TCHAR* name, float value);
	HRESULT SetAttribute(IXMLDOMElement *pElement, TCHAR* name, double value);
	HRESULT SetAttribute(IXMLDOMElement *pElement, TCHAR* name, short value);
	HRESULT SetAttribute(IXMLDOMElement *pElement, TCHAR* name, bool value);
	HRESULT SetAttribute(IXMLDOMElement *pElement, TCHAR* name, BYTE value);
	HRESULT AppendChild(IXMLDOMNode* pParentNode, IXMLDOMNode* pNewChild, IXMLDOMNode **outNewChild);
	HRESULT Save(const TCHAR * pszXmlFile = NULL);
};