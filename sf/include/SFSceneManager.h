#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>

typedef enum SF_FIGHT_PlayerGroupName
{
	FIGHT_PGN_P1, FIGHT_PGN_P2,
	FIGHT_PGN_MAX
}SF_FIGHT_PGN;

const string g_strFightPGN[FIGHT_PGN_MAX] = {
	"p1", "p2"
};

namespace SFFightManager
{
	SFActScene* createScene(UINT resId1, SF_SKN skin1, UINT resId2, SF_SKN skin2);
	bool releaseScene(SFActScene* pScene);

	SFPlayer* getPlayerInSceneByPGN(SFActScene* pScene, string groupName);
}