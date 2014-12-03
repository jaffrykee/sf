#pragma execution_character_set("utf-8")
#include <SFResConfigReader.h>

namespace SFResConfigReader
{
	UINT getFirstSplit(char* dst, int max, const char* src, char split)
	{
		UINT lenSrc = strlen(src);
		UINT minEnd = (max<lenSrc) ? max:lenSrc;

		if (NULL==src || NULL==dst)
		{
			return 0;
		}
		for (UINT i = 0; i < minEnd; i++)
		{
			if (src[i] == split)
			{
				strncpy_s(dst, max, src, i);

				return i;
			}
		}
		strncpy_s(dst, max, src, minEnd);

		return 0;
	}

	bool showAllAttribute(CComPtr<IXmlReader> pReader, UINT tabCount[], SFResPlayer& resPlayer)
	{
		HRESULT hr = S_OK;
		LPCWSTR name;
		LPCWSTR value;
		bool ret = false;
		void* parseCount[PRS_MAX] = {NULL};

		for (hr = pReader->MoveToFirstAttribute(); S_OK == hr; hr = pReader->MoveToNextAttribute())
		{
			pReader->GetLocalName(&name, NULL);
			pReader->GetValue(&value, NULL);
			wprintf(L"%s:%s  ", name, value);
			ret = true;

			if (tabCount[1] == 2)//12
			{
				if (tabCount[2] > 0)//12x
				{
					if (tabCount[3] == 0)//12x0
					{
#pragma region skill
						char tmpSkill[EKA_STR_MAX] = {0};
						StringA tmpValue = TStrTrans::UnicodeToUtf8(value);

						if (wcscmp(name, L"name") == 0)
						{
							UINT tmp = 0;

							tmp = getFirstSplit(tmpSkill, EKA_STR_MAX, tmpValue.c_str(), '_');
							if (tmp > 0)
							{
								SF_EKA tmpEka = SFConfig::GetInstance()->s_mEka[tmpSkill];
								const char* tmpSw = tmpValue.c_str() + tmp + 1;
								bool found = false;
								UINT i = 0;

								parseCount[PRS_SKL] = new SFResSkill(tmpEka);
								resPlayer.m_mSkill[tmpEka] = (SFResSkill*)parseCount[PRS_SKL];
								for (i = 0; i < AS_MAX; i++)
								{
									if (0 == strcmp(tmpSw, g_AsStr[i]))
									{
										found = true;
										break;
									}
								}
								if (!found)
								{
									i = 0;
								}
								parseCount[PRS_SKLSW] = new SFResSkillSwitch((SF_AS)i);
								((SFResSkill*)parseCount[PRS_SKL])->m_mSkillSwitchBmp[i] = (SFResSkillSwitch*)parseCount[PRS_SKLSW];
							}
						}
#pragma endregion
					}
					else if (tabCount[3] == 1)//12x1
					{
						if (tabCount[4] > 0)//12x1x
						{
#pragma region object
//							resPlayer.m_mSkill[];
#pragma endregion
						}
					}
				}
			}
		}
#ifdef RES_DEBUG
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
#endif

		return ret;
	}

	bool readFromXML(char* xmlPath, SFResPlayer& resPlayer)
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
		UINT nodeCount[ND_MAX] = { 0 };

		UINT tabCount[SF_XML_TABS_MAX] = { 0 };
		UINT tabs = 0;

		memset(tabCount, 0, SF_XML_TABS_MAX*sizeof(UINT));
		tabs = 0;

		//Open read-only input stream
		hr = SHCreateStreamOnFileA(xmlPath, STGM_READ, &pFileStream);
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

		return true;
	}
}