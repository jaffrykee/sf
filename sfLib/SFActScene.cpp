#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

SFSpriteGroup::SFSpriteGroup(string name) :m_name(name)
{

}

SFSpriteGroup::~SFSpriteGroup()
{
	for (UINT i = 0; i < m_aSprite.size(); i++)
	{
		if (m_aSprite[i] != NULL)
		{
			delete m_aSprite[i];
			m_aSprite[i] = NULL;
		}
	}
}

bool SFSpriteGroup::addSprite(SFSprite* pSprite)
{
	if (pSprite == NULL)
	{
		return false;
	}
	m_aSprite.insert(m_aSprite.end(), pSprite);

	return true;
}

SFActScene::SFActScene(SF_SCN_MAP mapType) :m_mapType(mapType)
{
	m_stage = SCN_STG_FREE;
}

SFActScene::SFActScene(UINT resId1, SF_SKN skin1, UINT resId2, SF_SKN skin2, SF_SCN_MAP mapType) :m_mapType(mapType)
{
	SFPlayer* pPlayer1 = new SFPlayer(resId1, skin1, 1);
	SFPlayer* pPlayer2 = new SFPlayer(resId2, skin2, 2);

	addSprite(SFConfig::GetInstance()->m_pDiFightPGN->m_str[FIGHT_PGN_P1], pPlayer1);
	addSprite(SFConfig::GetInstance()->m_pDiFightPGN->m_str[FIGHT_PGN_P2], pPlayer2);
	m_stage = SCN_STG_FREE;
}

SFActScene::~SFActScene()
{
	map<string, SFSpriteGroup*>::iterator itSpriteGroup;
	for (itSpriteGroup = m_mapSpriteGroup.begin(); itSpriteGroup != m_mapSpriteGroup.end(); ++itSpriteGroup)
	{
		if (itSpriteGroup->second != NULL)
		{
			delete itSpriteGroup->second;
			itSpriteGroup->second = NULL;
		}
	}
}

bool SFActScene::addSprite(string groupName, SFSprite* pSprite)
{
	if (pSprite == NULL || m_stage != SCN_STG_FREE)
	{
		return false;
	}

	map<string, SFSpriteGroup*>::iterator itSpriteGroup = m_mapSpriteGroup.find(groupName);
	SFSpriteGroup* pSpriteGroup = NULL;

	if (itSpriteGroup != m_mapSpriteGroup.end())
	{
		pSpriteGroup = m_mapSpriteGroup[groupName];
	}
	else
	{
		pSpriteGroup = new SFSpriteGroup(groupName);
		m_mapSpriteGroup[groupName] = pSpriteGroup;
	}
	if (pSpriteGroup->addSprite(pSprite))
	{
		return true;
	}
	else
	{
		return false;
	}
}

SFPlayer* SFActScene::getPlayerInSceneByPGN(string groupName)
{
	map<string, SFSpriteGroup*>::iterator itSpriteGroup = m_mapSpriteGroup.find(groupName);
	SFSpriteGroup* pSpriteGroup = NULL;

	if (itSpriteGroup != m_mapSpriteGroup.end())
	{
		pSpriteGroup = m_mapSpriteGroup[groupName];
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

	return NULL;
}

bool SFActScene::keyDown(WPARAM wParam)
{
	return true;
}

bool SFActScene::keyUp(WPARAM wParam)
{
	return true;
}