#pragma execution_character_set("utf-8")
#include <stdio.h>
#include <XmlLite.h>
#include <shlwapi.h>
#include <comutil.h>
#include <atlcomcli.h>
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
	LPCWSTR name;
	WCHAR trueName[64] = {0};
	LPWSTR A;
	LPCWSTR value;
	UINT u;
	
	//Open read-only input stream
	hr = SHCreateStreamOnFile("D:/s360/game/sf/sf/data/p001/sk_26A_def.xml", STGM_READ, &pFileStream);
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
			if (0 == wcscmp(name, L"skill"))
			{
				wprintf(L"<%s>\n", name);
				while (S_OK == (hr = pReader->Read(&nodeType)))
				{
					pReader->GetLocalName(&name, &u);
					if (name[0] > L' ')
					{
						if (0 == wcscmp(name, L"name"))
						{
							wcscpy_s(trueName, name);
							if ((S_OK == (hr = pReader->Read(&nodeType))))
							{
								pReader->GetValue(&value, NULL);
								if (value[0] > L' ')
								{
									wprintf(L"%s: %s\n", trueName, value);
								}
							}
						}
					}
				}
			}
		}
	}

	printf("a");
	getchar();
}