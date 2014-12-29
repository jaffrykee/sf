﻿#pragma execution_character_set("utf-8")
#include <init.h>

char path[] = "./data/p001/playerInfo.xml";

void main()
{
	SFResPlayer resPlayer(SKN_SK1);
	SFConfig* pConfig = SFConfig::GetInstance();

	system("chcp 65001");
	SFResConfigReader::readFromXML(path, resPlayer);
	for (int i = 0; i < EKA_MAX; i++)
	{
		if (resPlayer.m_mSkill[i] != NULL)
		{
			cout << endl << i << " : ";
			cout << g_EkaStr[i];
		}
	}

	getchar();
}