﻿#pragma execution_character_set("utf-8")
#include <sf.h>
using namespace std;

//string path = "./data/p001/playerInfo.xml";
string path = "./data/playerFrame.xsd";
string path2 = "./data/p001/playerInfo.xml";

SFPlayer* g_pP1 = NULL;
SFPlayer* g_pP2 = NULL;

string g_strEkf1 = "";
string g_strEkf2 = "";

SFActScene* g_scn = NULL;

void main()
{
/*
	g_pEventManager = new SFEventManager();
	SFActScene g_scn(PLR_JET, SKN_SK1, PLR_JET, SKN_SK1);
	SFPlayer* g_pP1 = g_scn.getFightP1();
	SFPlayer* g_pP2 = g_scn.getFightP2();

	for (UINT i = 0; i < EKA_MAX; i++)
	{
		if (g_pP1->m_resPlayer->m_arrSkill[i][0][0] != NULL)
		{
			cout << endl << i << " : ";
			cout << g_pConf->m_pDiEka->m_str[i];
		}
		}*/

	g_pEventManager = new SFEventManager();
	g_scn = new SFActScene(PLR_JET, SKN_SK1, PLR_JET, SKN_SK1);
	g_pP1 = g_scn->getFightP1();
	g_pP2 = g_scn->getFightP2();
	g_pEventManager->setActiveScene(g_scn);

	getchar();
}