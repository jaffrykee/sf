#pragma execution_character_set("utf-8")
#include <sf.h>
using namespace std;

//string path = "./data/p001/playerInfo.xml";
string path = "./data/playerFrame.xsd";
string path2 = "./data/p001/playerInfo.xml";

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
	SFResPlayer* pRes = NULL;

	SFXmlPlayer a(path);
	a.getDataByXml(path2, pRes);

	getchar();
}