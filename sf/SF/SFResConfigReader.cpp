﻿#pragma execution_character_set("utf-8")
#include <SFResConfigReader.h>

namespace SFResConfigReader
{
	/*从src中得到第一个以split这个字符为分割的字符串，放到dst中*/
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

	/*XML单个节点解析主逻辑*/
	bool readXMLNode(CComPtr<IXmlReader> pReader, UINT tabCount[], SFResPlayer& resPlayer)
	{
		HRESULT hr = S_OK;
		LPCWSTR name;
		LPCWSTR value;
		bool ret = false;
		static void* parseCount[PRS_MAX] = {NULL};
		static UINT boxType = 0;

		if (tabCount[1] == 1)//11
		{
			if (tabCount[2] == 0)//110
			{
				#pragma region skin_table
				#pragma endregion
			}
			else if (tabCount[2] > 0)//11x
			{
				if (tabCount[3] == 0)//11x0
				{
					#pragma region skin
					#pragma endregion
				}
			}
		}
		else if (tabCount[1] == 2)//12
		{
			if (tabCount[2] == 0)//120
			{
				#pragma region skill_table
				#pragma endregion
			}
			else if (tabCount[2] > 0)//12x
			{
				if (tabCount[3] == 0)//12x0
				{
					#pragma region skill
					POLL_XML_ATTR_BEGIN
						if (utfName == "name")
						{
							char strSkill[EKA_STR_MAX] = { 0 };
							UINT tmp = 0;

							tmp = getFirstSplit(strSkill, EKA_STR_MAX, utfValue.c_str(), '_');
							if (tmp > 0)
							{
								SF_EKA iSkill = SFConfig::GetInstance()->s_mEka[strSkill];
								const char* tmpSw = utfValue.c_str() + tmp + 1;		//技能状态分支（站立还是跳跃，没有的话就是站立）
								bool found = false;
								UINT i = 0;

								parseCount[PRS_SKL] = new SFResSkill(iSkill);
								resPlayer.m_mSkill[iSkill] = (SFResSkill*)parseCount[PRS_SKL];
								((SFResSkill*)parseCount[PRS_SKL])->m_parent = &resPlayer;
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
								((SFResSkillSwitch*)parseCount[PRS_SKLSW])->m_parent = ((SFResSkill*)parseCount[PRS_SKL]);
							}
						}
					POLL_XML_ATTR_END
					#pragma endregion
				}
				else if (tabCount[3] == 1)//12x1
				{
					if (tabCount[4] == 0)//12x10
					{
						#pragma region object_table
						#pragma endregion
					}
					else if (tabCount[4] > 0)//12x1x
					{
						if (tabCount[5] == 0)//12x1x0
						{
							#pragma region object
							parseCount[PRS_OBJ] = new SFResObject(tabCount[4] - 1);
							((SFResSkillSwitch*)parseCount[PRS_SKLSW])->m_mObject.insert(
								((SFResSkillSwitch*)parseCount[PRS_SKLSW])->m_mObject.end(),
								(SFResObject*)parseCount[PRS_OBJ]
								);
							((SFResObject*)parseCount[PRS_OBJ])->m_parent = (SFResSkillSwitch*)parseCount[PRS_SKLSW];
							POLL_XML_ATTR_BEGIN
								if (utfName == "id")
								{
									stringstream ss;
									unsigned int iValue;

									ss << utfValue;
									ss >> iValue;
								}
							POLL_XML_ATTR_END
							#pragma endregion
						}
						else if (tabCount[5] == 1)//12x1x1
						{
							if (tabCount[6] == 0)//12x1x10
							{
								#pragma region frame_table
								#pragma endregion
							}
							else if (tabCount[6] > 0)//12x1x1x
							{
								if (tabCount[7] == 0)//12x1x1x0
								{
									#pragma region frame
									parseCount[PRS_FRM] = new SFResFrame(tabCount[6] - 1);
									((SFResObject*)parseCount[PRS_OBJ])->m_mFrame.insert(
										((SFResObject*)parseCount[PRS_OBJ])->m_mFrame.end(),
										(SFResFrame*)parseCount[PRS_FRM]
										);
									((SFResFrame*)parseCount[PRS_FRM])->m_parent = (SFResObject*)parseCount[PRS_OBJ];
									POLL_XML_ATTR_BEGIN
										if (utfName == "id")
										{
											stringstream ss;
											unsigned int iValue;

											ss << utfValue;
											ss >> iValue;
										}
										else if (utfName == "m")
										{
											stringstream ss;
											float fValue;

											ss << utfValue;
											ss >> fValue;

											((SFResFrame*)parseCount[PRS_FRM])->m_mid = fValue;
										}
									POLL_XML_ATTR_END
									#pragma endregion
								}
								else if (tabCount[7] == 1)//12x1x1x1x
								{
									if (tabCount[8] == 0)//12x1x1x10
									{
										#pragma region rect(frame)
										D2D1_RECT_F box;

										POLL_XML_ATTR_BEGIN
											if (utfName == "t")
											{
												stringstream ss;
												float fValue;

												ss << utfValue;
												ss >> fValue;
												box.top = fValue;
											}
											else if (utfName == "l")
											{
												stringstream ss;
												float fValue;

												ss << utfValue;
												ss >> fValue;
												box.left = fValue;
											}
											else if (utfName == "b")
											{
												stringstream ss;
												float fValue;

												ss << utfValue;
												ss >> fValue;
												box.bottom = fValue;
											}
											else if (utfName == "r")
											{
												stringstream ss;
												float fValue;

												ss << utfValue;
												ss >> fValue;
												box.right = fValue;
											}
										POLL_XML_ATTR_END

										((SFResFrame*)parseCount[PRS_FRM])->m_drawBox = box;
										#pragma endregion
									}
								}
								else if (tabCount[7] == 2)//12x1x1x2x
								{
									if (tabCount[8] == 0)//12x1x1x20
									{
										#pragma region box_table
										#pragma endregion
									}
									else if (tabCount[8] > 0)//12x1x1x2x
									{
										if (tabCount[9] == 0)//12x1x1x2x0
										{
											#pragma region box
											POLL_XML_ATTR_BEGIN
												if (utfName == "type")
												{
													stringstream ss;
													unsigned int iValue;

													ss << utfValue;
													ss >> iValue;
													boxType = iValue;
												}
											POLL_XML_ATTR_END
											#pragma endregion
										}
										else if (tabCount[9] == 1)//12x1x1x2x1
										{
											if (tabCount[10] == 0)//12x1x1x2x10
											{
												#pragma region rect(box)
												D2D1_RECT_F box;
												POLL_XML_ATTR_BEGIN
													if (utfName == "t")
													{
														stringstream ss;
														float fValue;

														ss << utfValue;
														ss >> fValue;
														box.top = fValue;
													}
													else if (utfName == "l")
													{
														stringstream ss;
														float fValue;

														ss << utfValue;
														ss >> fValue;
														box.left = fValue;
													}
													else if (utfName == "b")
													{
														stringstream ss;
														float fValue;

														ss << utfValue;
														ss >> fValue;
														box.bottom = fValue;
													}
													else if (utfName == "r")
													{
														stringstream ss;
														float fValue;

														ss << utfValue;
														ss >> fValue;
														box.right = fValue;
													}
												POLL_XML_ATTR_END

												if (boxType & 0x1)
												{
													((SFResFrame*)parseCount[PRS_FRM])->m_lBodyBox.insert(
														((SFResFrame*)parseCount[PRS_FRM])->m_lBodyBox.end(),
														box);
												}
												if (boxType & 0x2)
												{
													((SFResFrame*)parseCount[PRS_FRM])->m_lAttackBox.insert(
														((SFResFrame*)parseCount[PRS_FRM])->m_lAttackBox.end(),
														box);
												}
												#pragma endregion
											}
										}
									}
								}
							}
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

	/*XML解析主逻辑入口*/
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