#pragma execution_character_set("utf-8")
#include <SFSceneManager.h>

namespace SFFightManager
{
	SFActScene* createScene(UINT resId1, SF_SKN skin1, UINT resId2, SF_SKN skin2)
	{
		SFPlayer* pPlayer1 = new SFPlayer(resId1, skin1, 1);
		SFPlayer* pPlayer2 = new SFPlayer(resId2, skin2, 2);
		SFActScene* pScene = new SFActScene();
		pScene->addSprite(g_strFightPGN[FIGHT_PGN_P1], pPlayer1);
		pScene->addSprite(g_strFightPGN[FIGHT_PGN_P2], pPlayer2);

		return pScene;
	}

	bool releaseScene(SFActScene* pScene)
	{
		if (pScene != NULL)
		{
			delete pScene;
			return true;
		}
		else
		{
			return false;
		}
	}

	SFPlayer* getPlayerInSceneByPGN(SFActScene* pScene, string groupName)
	{
		if (pScene != NULL)
		{
			map<string, SFSpriteGroup*>::iterator itSpriteGroup = pScene->m_mapSpriteGroup.find(groupName);
			SFSpriteGroup* pSpriteGroup = NULL;

			if (itSpriteGroup != pScene->m_mapSpriteGroup.end())
			{
				pSpriteGroup = pScene->m_mapSpriteGroup[groupName];
				if (pSpriteGroup != NULL)
				{
					if (pSpriteGroup->m_aSprite.size() > 0)
					{
						if (pSpriteGroup->m_aSprite[0] != NULL)
						{
							return pSpriteGroup->m_aSprite[0];
						}
					}
				}
			}
		}

		return false;
	}
}