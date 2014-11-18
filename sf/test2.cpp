#pragma execution_character_set("utf-8")
#include <stdio.h>
#include <XmlLite.h>
#include <shlwapi.h>
#include <comutil.h>
#include <atlcomcli.h>
#include <string>
#include <iostream>
#pragma comment(lib, "comsuppwd.lib")
#pragma comment(lib, "XmlLite.lib")

using namespace std;

int main()
{
	HRESULT hr = S_OK;
	CComPtr<IStream> pFileStream;
	CComPtr<IXmlReader> pReader;
	XmlNodeType nodeType = XmlNodeType_None;
	LPCWSTR value;
	LPCWSTR name;
	UINT u;
	

	//Open read-only input stream
	hr = SHCreateStreamOnFile("D:/s360/game/sf/sf/data/p001/sk001/status.xml", STGM_READ, &pFileStream);
	if (SUCCEEDED(hr))
	{
		hr = CreateXmlReader(__uuidof(IXmlReader), (void**)&pReader, NULL);
	}
	pReader->SetInput(pFileStream);
	while (S_OK == (hr = pReader->Read(&nodeType)))
	{
		pReader->GetLocalName(&name, &u);
		if (name[0] > L' ')
		{
			wprintf(L"<<<<<<<<<<%s: %d>>>>>>>>>>>>>>\n", name, u);
		}
		pReader->GetValue(&value, NULL);
		if (value[0] > L' ')
		{
			wprintf(L"%s\n", value);
		}
	}

	printf("a");
	getchar();
}