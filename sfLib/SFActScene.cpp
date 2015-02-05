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

SFActScene::SFActScene(UINT resId1, SF_SKN skin1, UINT resId2, SF_SKN skin2, SF_SCN_MAP mapType):
#pragma region 默认值
m_mapType(mapType),
m_mapTevEk({
	pair<SF_TEV, SF_EK>(TEV_KD_P1UP, EK_8),
	pair<SF_TEV, SF_EK>(TEV_KD_P1LF, EK_4),
	pair<SF_TEV, SF_EK>(TEV_KD_P1DW, EK_2),
	pair<SF_TEV, SF_EK>(TEV_KD_P1RG, EK_6),
	pair<SF_TEV, SF_EK>(TEV_KD_P1AA, EK_A),
	pair<SF_TEV, SF_EK>(TEV_KD_P1BB, EK_B),
	pair<SF_TEV, SF_EK>(TEV_KD_P1CC, EK_C),
	pair<SF_TEV, SF_EK>(TEV_KD_P1DD, EK_D),
	pair<SF_TEV, SF_EK>(TEV_KD_P1EE, EK_E),
	pair<SF_TEV, SF_EK>(TEV_KD_P1FF, EK_F),
	pair<SF_TEV, SF_EK>(TEV_KD_P1ST, EK_S1),
	pair<SF_TEV, SF_EK>(TEV_KD_P1MN, EK_S2),
	pair<SF_TEV, SF_EK>(TEV_KD_P2UP, EK_8),
	pair<SF_TEV, SF_EK>(TEV_KD_P2LF, EK_6),
	pair<SF_TEV, SF_EK>(TEV_KD_P2DW, EK_2),
	pair<SF_TEV, SF_EK>(TEV_KD_P2RG, EK_4),
	pair<SF_TEV, SF_EK>(TEV_KD_P2AA, EK_A),
	pair<SF_TEV, SF_EK>(TEV_KD_P2BB, EK_B),
	pair<SF_TEV, SF_EK>(TEV_KD_P2CC, EK_C),
	pair<SF_TEV, SF_EK>(TEV_KD_P2DD, EK_D),
	pair<SF_TEV, SF_EK>(TEV_KD_P2EE, EK_E),
	pair<SF_TEV, SF_EK>(TEV_KD_P2FF, EK_F),
	pair<SF_TEV, SF_EK>(TEV_KD_P2ST, EK_S1),
	pair<SF_TEV, SF_EK>(TEV_KD_P2MN, EK_S2),
	pair<SF_TEV, SF_EK>(TEV_KU_P1UP, EK_8),
	pair<SF_TEV, SF_EK>(TEV_KU_P1LF, EK_4),
	pair<SF_TEV, SF_EK>(TEV_KU_P1DW, EK_2),
	pair<SF_TEV, SF_EK>(TEV_KU_P1RG, EK_6),
	pair<SF_TEV, SF_EK>(TEV_KU_P1AA, EK_A),
	pair<SF_TEV, SF_EK>(TEV_KU_P1BB, EK_B),
	pair<SF_TEV, SF_EK>(TEV_KU_P1CC, EK_C),
	pair<SF_TEV, SF_EK>(TEV_KU_P1DD, EK_D),
	pair<SF_TEV, SF_EK>(TEV_KU_P1EE, EK_E),
	pair<SF_TEV, SF_EK>(TEV_KU_P1FF, EK_F),
	pair<SF_TEV, SF_EK>(TEV_KU_P1ST, EK_S1),
	pair<SF_TEV, SF_EK>(TEV_KU_P1MN, EK_S2),
	pair<SF_TEV, SF_EK>(TEV_KU_P2UP, EK_8),
	pair<SF_TEV, SF_EK>(TEV_KU_P2LF, EK_6),
	pair<SF_TEV, SF_EK>(TEV_KU_P2DW, EK_2),
	pair<SF_TEV, SF_EK>(TEV_KU_P2RG, EK_4),
	pair<SF_TEV, SF_EK>(TEV_KU_P2AA, EK_A),
	pair<SF_TEV, SF_EK>(TEV_KU_P2BB, EK_B),
	pair<SF_TEV, SF_EK>(TEV_KU_P2CC, EK_C),
	pair<SF_TEV, SF_EK>(TEV_KU_P2DD, EK_D),
	pair<SF_TEV, SF_EK>(TEV_KU_P2EE, EK_E),
	pair<SF_TEV, SF_EK>(TEV_KU_P2FF, EK_F),
	pair<SF_TEV, SF_EK>(TEV_KU_P2ST, EK_S1),
	pair<SF_TEV, SF_EK>(TEV_KU_P2MN, EK_S2)
}),
m_width(2000),
m_height(1000),
m_ground(80),
m_poiInitP1({800,920}),
m_poiInitP2({1200,920})
#pragma endregion
{
	SFPlayer* pPlayer1 = new SFPlayer(resId1, skin1, 1);
	SFPlayer* pPlayer2 = new SFPlayer(resId2, skin2, 2);

	addFightP1(pPlayer1);
	addFightP2(pPlayer2);
	m_stage = SCN_STG_FREE;
	initPositionFightP1();
	initPositionFightP2();
	doCollision();
	setDirection(true);
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

bool SFActScene::doEvent(SF_TEV event)
{
	if (event >= TEV_KEY_MIN && event <= TEV_KEY_MAX)
	{
		if (event >= TEV_KD_MIN && event <= TEV_KD_MAX)
		{
			if (event >= TEV_KD_P1MIN && event <= TEV_KD_P1MAX)
			{
				if (getFightP1())
				{
					return getFightP1()->downEvent(m_mapTevEk[event]);
				}
				else
				{
					return false;
				}
			}
			else if (event >= TEV_KD_P2MIN && event <= TEV_KD_P2MAX)
			{
				if (getFightP2())
				{
					return getFightP2()->downEvent(m_mapTevEk[event]);
				}
				else
				{
					return false;
				}
			}
		}
		else if (event >= TEV_KU_MIN && event <= TEV_KU_MAX)
		{
			if (event >= TEV_KU_P1MIN && event <= TEV_KU_P1MAX)
			{
				if (getFightP1())
				{
					return getFightP1()->upEvent(m_mapTevEk[event]);
				}
				else
				{
					return false;
				}
			}
			else if (event >= TEV_KU_P2MIN && event <= TEV_KU_P2MAX)
			{
				if (getFightP2())
				{
					return getFightP2()->upEvent(m_mapTevEk[event]);
				}
				else
				{
					return false;
				}
			}
		}
	}
	else if (event >= TEV_TMR_MIN && event <= TEV_TMR_MAX)
	{
		bool ret1, ret2;

		if (event == TEV_TMR_PAINT)
		{
			return true;
		}
		else
		{
			if (getFightP1() != NULL && getFightP2() != NULL)
			{
				getFightP1()->doTimer(event);
				getFightP2()->doTimer(event);

				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}

bool SFActScene::doCollision()
{
	return true;
}

bool SFActScene::addFightP1(SFSprite* pSprite)
{
	return addSprite(g_pConf->m_pDiFightPGN->m_str[FIGHT_PGN_P1], pSprite);
}

bool SFActScene::addFightP2(SFSprite* pSprite)
{
	return addSprite(g_pConf->m_pDiFightPGN->m_str[FIGHT_PGN_P2], pSprite);
}

SFPlayer* SFActScene::getFightP1()
{
	return m_mapSpriteGroup[g_pConf->m_pDiFightPGN->m_str[FIGHT_PGN_P1]]->m_aSprite[0];
}

SFPlayer* SFActScene::getFightP2()
{
	return m_mapSpriteGroup[g_pConf->m_pDiFightPGN->m_str[FIGHT_PGN_P2]]->m_aSprite[0];
}

bool SFActScene::setPositionFightP1(D2D1_POINT_2F point)
{
	if (getFightP1() != NULL)
	{
		getFightP1()->m_position = point;

		return true;
	}

	return false;
}

bool SFActScene::initPositionFightP1()
{
	FLOAT dy = getFightP1()->m_resPlayer->m_arrSkill[EKA_DEF][AS_DEF][SSSE_DEF]->m_arrObject[0]->m_arrFrame[0]->m_lBodyBox.begin()->bottom;
	m_poiInitP1.y -= dy;

	return setPositionFightP1(m_poiInitP1);
}

bool SFActScene::setPositionFightP2(D2D1_POINT_2F point)
{
	if (getFightP2() != NULL)
	{
		getFightP2()->m_position = point;

		return true;
	}

	return false;
}

bool SFActScene::initPositionFightP2()
{
	FLOAT dy = getFightP2()->m_resPlayer->m_arrSkill[EKA_DEF][AS_DEF][SSSE_DEF]->m_arrObject[0]->m_arrFrame[0]->m_lBodyBox.begin()->bottom;
	m_poiInitP2.y -= dy;

	return setPositionFightP1(m_poiInitP2);
}

void SFActScene::setDirection(bool isP1Left)
{
	if (isP1Left)
	{
		m_mapTevEk[TEV_KU_P1LF] = EK_4;
		m_mapTevEk[TEV_KU_P1RG] = EK_6;
		m_mapTevEk[TEV_KU_P2LF] = EK_6;
		m_mapTevEk[TEV_KU_P2RG] = EK_4;
	}
	else
	{
		m_mapTevEk[TEV_KU_P1LF] = EK_6;
		m_mapTevEk[TEV_KU_P1RG] = EK_4;
		m_mapTevEk[TEV_KU_P2LF] = EK_4;
		m_mapTevEk[TEV_KU_P2RG] = EK_6;
	}
}

void SFActScene::refreshDirection()
{
	if (getFightP1()->m_position.x < getFightP2()->m_position.x)
	{
		setDirection(true);
	}
	else
	{
		setDirection(false);
	}
}