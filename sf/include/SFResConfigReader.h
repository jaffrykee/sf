#pragma once
#pragma execution_character_set("utf-8")
#include <stdio.h>
#include <XmlLite.h>
#include <shlwapi.h>
#include <comutil.h>
#include <atlcomcli.h>
#include <iostream>
#include <SFResource.h>
#pragma comment(lib, "comsuppwd.lib")
#pragma comment(lib, "XmlLite.lib")

using namespace std;

#pragma region POLL_XML函数宏及其相关define
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
						for(int i = 0; i < POLL_TABSCOUNT - 1; i++)	\
							wprintf(L"    ");	\
						wprintf(L"<%s>", nodeName[sf_nd]);	\
						showAllAttribute(POLL_PREADER);	\
										}	\
				}	\
						}	\
		}	\
		}

#define NODE_NAME_MAX 64
#pragma endregion

#pragma region playerInfo.xml中的所有节点相关define以及路径define
enum SF_XML_ND
{
	ND_PLY_INF, ND_SKN_TBL, ND_SKN, ND_SKL_TBL, ND_SKL, ND_OBJ_TBL, ND_OBJ,
	ND_FRM_TBL, ND_FRM, ND_FRM_RCT, ND_BOX_TBL, ND_BOX, ND_BOX_RCT,
	ND_MAX
};
#pragma endregion
namespace SFResConfigReader
{
	bool showAllAttribute(CComPtr<IXmlReader> pReader);
	bool readFromXML(char* xmlPath, SFResPlayer* pPlayer);
}