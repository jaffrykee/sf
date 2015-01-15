#pragma execution_character_set("utf-8")
#include <SFSceneManager.h>

namespace SFSceneManager
{
	SFActScene* createFightScene(UINT resId1, SF_SKN skin1, UINT resId2, SF_SKN skin2)
	{
		SFPlayer* pPlayer1 = new SFPlayer(resId1, skin1, 1);
		SFPlayer* pPlayer2 = new SFPlayer(resId2, skin2, 2);
		SFActScene* pScene = new SFActScene();
		pScene->addSprite(pPlayer1);
		pScene->addSprite(pPlayer2);
	}
}