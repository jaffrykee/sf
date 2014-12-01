﻿#pragma execution_character_set("utf-8")
#include <SFResConfigReader.h>

namespace SFResConfigReader
{
	UINT tabCount[SF_XML_TABS_MAX] = { 0 };
	UINT tabs = 0;

	bool getFirstSplit(char* dst, int max, char* src, char split)
	{
		if (NULL==src || NULL==dst || split<' ')
		{
			return false;
		}
		for (int i = 0; i < strlen(src); i++)
		{
			if (src[i] == split)
			{
				strncpy_s(dst, max, src, i);
				return true;
			}
		}

		return false;
	}

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
		wprintf(L"\n");
		for (int i = 1; i < SF_XML_TABS_MAX; i++)
		{
			if (tabCount[i] != 0)
			{
				wprintf(L"    ");
			}
			else
			{
				break;
			}
		}
		for (int i = 0; i < SF_XML_TABS_MAX; i++)
		{
			wprintf(L"%d ", tabCount[i]);
		}

		return ret;
	}

	bool readFromXML(char* xmlPath, SFResPlayer* pPlayer)
	{
		HRESULT hr = S_OK;
		CComPtr<IStream> pFileStream;
		CComPtr<IXmlReader> pReader;
		XmlNodeType nodeType = XmlNodeType_None;
		WCHAR trueName[NODE_NAME_MAX] = {0};
		LPCWSTR name;
		bool nodeSw[ND_MAX] = {false};
		bool nodeIsOnly[ND_MAX] = {false};
		bool nodeHad[ND_MAX] = {false};
		UINT nodeCount[ND_MAX] = {0};

		memset(tabCount, 0, SF_XML_TABS_MAX*sizeof(UINT));
		tabs = 0;

		//Open read-only input stream
		hr = SHCreateStreamOnFile(xmlPath, STGM_READ, &pFileStream);
		if (SUCCEEDED(hr))
		{
			hr = CreateXmlReader(__uuidof(IXmlReader), (void**)&pReader, NULL);
		}
		else
		{
			cout << "Error: Can't find the XML file. (\"" << xmlPath << "\")" << endl;
			getchar();

			return false;
		}
		pReader->SetInput(pFileStream);
		hr = pReader->Read(NULL);

		POLL_XML_NODE_BEGIN(ND_PLY_INF)
			POLL_XML_NODE_BEGIN(ND_SKN_TBL)
				POLL_XML_NODE_BEGIN(ND_SKN)
				POLL_XML_NODE_END(ND_SKN)
			POLL_XML_NODE_END(ND_SKN_TBL)
			POLL_XML_NODE_BEGIN(ND_SKL_TBL)
				POLL_XML_NODE_BEGIN(ND_SKL)
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
		POLL_XML_NODE_END(ND_PLY_INF)

		getchar();

		return true;
	}
}