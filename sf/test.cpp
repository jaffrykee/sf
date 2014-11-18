#pragma execution_character_set("utf-8")
#include <stdio.h>
#include <msxml6.h>  
#include <comutil.h>
#include <atlcomcli.h>
#pragma comment(lib, "comsuppwd.lib")  

void main()
{
	CoInitialize(NULL);
	CComPtr<IXMLDOMDocument> spXmldoc;
	HRESULT hr = spXmldoc.CoCreateInstance(L"MSXML2.DOMDocument.6.0");

	if (SUCCEEDED(hr))
	{
		VARIANT_BOOL isSuccessFul;
		CComVariant varXmlFile(L"./data/p001/sk001/status.xml");

		spXmldoc->put_async(VARIANT_FALSE);
		HRESULT hr = spXmldoc->load(varXmlFile, &isSuccessFul);

		if (isSuccessFul == VARIANT_TRUE)
		{
			CComBSTR bstrXml;
			CComPtr<IXMLDOMElement> spRoot = NULL;
			CComPtr<IXMLDOMElement> spTheBook = NULL;
			CComPtr<IXMLDOMNode> spTheNode = NULL;
			CComPtr<IXMLDOMNode> spTheNode2 = NULL;
			CComPtr<IXMLDOMNodeList> spList = NULL;
			CComPtr<IXMLDOMNode> spNode = NULL;
			

			printf("Load:ok\n");

			hr = spXmldoc->get_documentElement(&spRoot);
			//spRoot->get_xml(&bstrXml);

			//hr = spRoot->selectSingleNode(L"/skill_list/skill[name='default']", &spTheNode);
			hr = spRoot->get_firstChild(&spTheNode);
//			spRoot = NULL;
			hr = spTheNode->get_firstChild(&spTheNode2);
//			spTheNode = NULL;
			hr = spTheNode2->get_firstChild(&spTheNode);
//			spTheNode2 = NULL;
			if (SUCCEEDED(hr))
			{
				printf("Find:ok\n");
#if 1
				hr = spTheNode.QueryInterface(&spTheBook);
//				spTheNode = NULL;
				spTheBook->get_xml(&bstrXml);
				printf("name:\"default\"\n");
				printf(_com_util::ConvertBSTRToString(bstrXml));
#else
				hr = spTheNode2->get_childNodes(&spList);
				for (int i = 0; hr = SUCCEEDED(spList->get_item(i, &spNode)); i++)
				{
					spNode.QueryInterface(&spTheBook);
					spNode.Release();
					spTheBook->get_xml(&bstrXml);
					printf("\n---------------------------\n");
					printf(_com_util::ConvertBSTRToString(bstrXml));
					spTheBook.Release();
				}
#endif
			}
			printf("Find:failed\n");
			SysFreeString(bstrXml);

		}
		else
		{
			printf("Load:failed\n");
		}
	}

	getchar();
}