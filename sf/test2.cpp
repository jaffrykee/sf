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

#define POLL_RET (hr)
#define POLL_PREADER (pReader)
#define POLL_NAME (name)
#define POLL_SW nodeSw
#define POLL_NODEISONLY nodeIsOnly
#define POLL_NODEHAD nodeHad
#define POLL_NODENAME nodeName
#define POLL_TABSCOUNT (tabs)

//遍历该级xml的每一个枚举为"sf_nd"的节点。
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
						wprintf(L"\n");	\
						for(int i = 0; i < POLL_TABSCOUNT; i++)	\
							wprintf(L"    ");	\
						wprintf(L"<%s>", nodeName[sf_nd]);	\
						showAllAttribute(POLL_PREADER);	\
					}	\
				}	\
			}	\
		}	\
	}

#define NODE_NAME_MAX 64

enum SF_ND
{
	ND_SKL_TBL, ND_SKL, ND_SKN_TBL, ND_SKN, ND_OBJ_TBL,ND_OBJ,
	ND_FRM_TBL, ND_FRM, ND_FRM_RCT, ND_BOX_TBL, ND_BOX, ND_BOX_RCT,
	ND_MAX
};

bool showAllAttribute(CComPtr<IXmlReader> pReader)
{
	HRESULT hr = S_OK;
	LPCWSTR name;
	LPCWSTR value;
	bool ret = false;

	for (hr = pReader->MoveToFirstAttribute(); S_OK == hr; hr = pReader->MoveToNextAttribute())
	{
		pReader->GetLocalName(&name, NULL);
		pReader->GetValue(&value, NULL);
		wprintf(L"%s:%s  ", name, value);
		ret = true;
	}

	return ret;
}

void main()
{
	HRESULT hr = S_OK;
	CComPtr<IStream> pFileStream;
	CComPtr<IXmlReader> pReader;
	XmlNodeType nodeType = XmlNodeType_None;
	WCHAR trueName[NODE_NAME_MAX] = { 0 };
	LPCWSTR name;
	int tabs = 0;
	bool nodeSw[ND_MAX] = {false};
	bool nodeIsOnly[ND_MAX] = {
		true, false, true, false, true, false,
		true, false, true, true, false, true
	};
	bool nodeHad[ND_MAX] = {false};
	WCHAR nodeName[ND_MAX][NODE_NAME_MAX] = {
		L"skill_table", L"skill", L"skin_table", L"skin", L"object_table", L"object",
		L"frame_table", L"frame", L"rect", L"box_table", L"box", L"rect"
	};
	
	//Open read-only input stream
	hr = SHCreateStreamOnFile("D:/s360/game/sf/sf/data/p001/sk.xml", STGM_READ, &pFileStream);
	if (SUCCEEDED(hr))
	{
		hr = CreateXmlReader(__uuidof(IXmlReader), (void**)&pReader, NULL);
	}
	pReader->SetInput(pFileStream);
	hr = pReader->Read(NULL);

	POLL_XML_NODE_BEGIN(ND_SKL_TBL)
		POLL_XML_NODE_BEGIN(ND_SKL)
			POLL_XML_NODE_BEGIN(ND_SKN_TBL)
				POLL_XML_NODE_BEGIN(ND_SKN)
				POLL_XML_NODE_END(ND_SKN)
			POLL_XML_NODE_END(ND_SKN_TBL)
			POLL_XML_NODE_BEGIN(ND_OBJ_TBL)
				POLL_XML_NODE_BEGIN(ND_OBJ)
					POLL_XML_NODE_BEGIN(ND_FRM_TBL)
						POLL_XML_NODE_BEGIN(ND_FRM)
							POLL_XML_NODE_BEGIN(ND_FRM_RCT)
							POLL_XML_NODE_END(ND_FRM_RCT)
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

	getchar();

	return;
}