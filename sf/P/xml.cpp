#pragma execution_character_set("utf-8")
#include "xml.h"
#include <stdio.h>
#include <Shlwapi.h>
#include <strsafe.h>
#pragma comment(lib,"msxml2.lib")
#pragma comment(lib,"comsuppw.lib")
#pragma comment(lib,"Shlwapi.lib")
#pragma comment(lib,"strsafe.lib")

const CLSID CLSID_DOMDocument60;

CXmlDoc::CXmlDoc(void)
{
	memset(m_szXmlFile, 0, sizeof(m_szXmlFile));
	m_pXmlDoc = NULL;
	//InitXmlDoc();
}

CXmlDoc::~CXmlDoc(void)
{
	if (m_pXmlDoc)
	{
		m_pXmlDoc->Release();
	}
}

HRESULT CXmlDoc::CreateXmlDoc()
{
	return CoCreateInstance(CLSID_DOMDocument60, NULL, CLSCTX_INPROC_SERVER,
		IID_IXMLDOMDocument, (void**)&m_pXmlDoc);
}
HRESULT CXmlDoc::Open(const TCHAR * pszXmlFile)
{
	VARIANT var;
	var.vt = VT_BSTR;
	var.bstrVal = _bstr_t(pszXmlFile);
	VARIANT_BOOL bSuccess = FALSE;
	return m_pXmlDoc->load(var, &bSuccess);
}
HRESULT CXmlDoc::GetRoot(IXMLDOMElement **ppRoot)
{
	return m_pXmlDoc->get_documentElement(ppRoot);
}
HRESULT CXmlDoc::Save(const TCHAR * pszXmlFile)
{

	VARIANT var;

	var.vt = VT_BSTR;
	if (!pszXmlFile&&PathFileExists(m_szXmlFile))
	{
		var.bstrVal = _bstr_t(m_szXmlFile);
	}
	else
		var.bstrVal = _bstr_t(pszXmlFile);
	return m_pXmlDoc->save(var);
}

HRESULT CXmlDoc::AddDeclaration(TCHAR *version, TCHAR *encoding)
{
	IXMLDOMProcessingInstruction *pi = NULL;
	TCHAR *format = _T("version=\"%s\" encoding=\"%s\"");
	TCHAR data[1024];
	memset(data, 0, sizeof(data));
	StringCchPrintf(data, sizeof(data), format, version, encoding);
	HRESULT hr = m_pXmlDoc->createProcessingInstruction(_bstr_t(_T("xml")), _bstr_t(data), &pi);
	hr = m_pXmlDoc->appendChild(pi, NULL);
	pi->Release();
	return hr;
}

HRESULT CXmlDoc::CreateElement(TCHAR* tagName, IXMLDOMElement **pElement)
{
	return m_pXmlDoc->createElement(_bstr_t(tagName), pElement);
}

HRESULT CXmlDoc::SetAttribute(IXMLDOMElement *pElement, TCHAR* name, TCHAR* value)
{
	assert(pElement);
	BSTR bstrName = _bstr_t(name).copy();
	VARIANT varAttr;
	varAttr.vt = VT_BSTR;
	varAttr.bstrVal = _bstr_t(value);

	HRESULT hr = pElement->setAttribute(bstrName, varAttr);
	SysFreeString(bstrName);
	return hr;

}

HRESULT CXmlDoc::SetAttribute(IXMLDOMElement *pElement, TCHAR* name, int value)
{
	assert(pElement);
	VARIANT varAttr;
	varAttr.vt = VT_INT;
	varAttr.intVal = value;
	return pElement->setAttribute(_bstr_t(name), varAttr);
}

HRESULT CXmlDoc::SetAttribute(IXMLDOMElement *pElement, TCHAR* name, __int64 value)
{
	assert(pElement);
	VARIANT varAttr;
	varAttr.vt = VT_I8;
	varAttr.llVal = value;
	return pElement->setAttribute(_bstr_t(name), varAttr);
}

HRESULT CXmlDoc::SetAttribute(IXMLDOMElement *pElement, TCHAR* name, float value)
{
	assert(pElement);
	VARIANT varAttr;
	varAttr.vt = VT_R4;
	varAttr.fltVal = value;
	return pElement->setAttribute(_bstr_t(name), varAttr);
}
HRESULT CXmlDoc::SetAttribute(IXMLDOMElement *pElement, TCHAR* name, double value)
{
	assert(pElement);
	VARIANT varAttr;
	varAttr.vt = VT_R8;
	varAttr.dblVal = value;
	return pElement->setAttribute(_bstr_t(name), varAttr);
}
HRESULT CXmlDoc::SetAttribute(IXMLDOMElement *pElement, TCHAR* name, short value)
{
	assert(pElement);
	VARIANT varAttr;
	varAttr.vt = VT_I2;
	varAttr.iVal = value;
	return pElement->setAttribute(_bstr_t(name), varAttr);
}
HRESULT CXmlDoc::SetAttribute(IXMLDOMElement *pElement, TCHAR* name, bool value)
{
	assert(pElement);
	VARIANT varAttr;
	varAttr.vt = VT_BOOL;
	varAttr.boolVal = value;
	return pElement->setAttribute(_bstr_t(name), varAttr);
}
HRESULT CXmlDoc::SetAttribute(IXMLDOMElement *pElement, TCHAR* name, BYTE value)
{
	assert(pElement);
	VARIANT varAttr;
	varAttr.vt = VT_UI1;
	varAttr.bVal = value;
	return pElement->setAttribute(_bstr_t(name), varAttr);
}
HRESULT CXmlDoc::AppendChild(IXMLDOMNode* pParentNode, IXMLDOMNode* pNewChild, IXMLDOMNode **outNewChild)
{
	if (pParentNode)
	{
		return pParentNode->appendChild(pNewChild, outNewChild);
	}
	else
		return m_pXmlDoc->appendChild(pNewChild, outNewChild);
}