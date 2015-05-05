#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

#pragma region SFSpriteGroup
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
	pSprite->m_pGroup = this;

	return true;
}
#pragma endregion

#pragma region SFActScene
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
})
#pragma endregion
{
	SFPlayer* pPlayer1 = new SFPlayer(resId1, skin1, 1, this);
	SFPlayer* pPlayer2 = new SFPlayer(resId2, skin2, 2, this);
	m_pResScene = new SFResScene();

	m_width = m_pResScene->m_width;
	m_height = m_pResScene->m_height;
	m_poiInitP1 = m_pResScene->m_poiP1;
	m_poiInitP2 = m_pResScene->m_poiP2;
	m_ground = m_pResScene->m_fGround;
	addFightP1(pPlayer1);
	addFightP2(pPlayer2);
	m_stage = SCN_STG_FREE;
	initPositionFightP1();
	initPositionFightP2();
	doCollision();

	m_tc = 0;
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

#pragma region 事件
//事件抉择
bool SFActScene::doEvent(SF_TEV event)
{
	if (event >= TEV_KEY_MIN && event <= TEV_KEY_MAX)
	{
		//键盘事件
		if (event >= TEV_KD_MIN && event <= TEV_KD_MAX)
		{
			//键盘按下事件
			if (event >= TEV_KD_P1MIN && event <= TEV_KD_P1MAX)
			{
				//P1
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
				//P2
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
			//键盘弹起事件
			if (event >= TEV_KU_P1MIN && event <= TEV_KU_P1MAX)
			{
				//P1
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
				//P2
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
		//时钟触发事件
		bool ret1, ret2;

		if (event == TEV_TMR_PAINT)
		{
			return true;
		}
		else if (event == TEV_TMR_ACTION)
		{
			//判断碰撞之类，SF主物理逻辑，以及确定位置
			doCollision();

			return true;
		}
		else if (event == TEV_TMR_SKILL)
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
#pragma endregion

#pragma region 碰撞
bool SFActScene::addFrameToCollosion(SFPlayer* pPlayer, __out vector<SFResFrame*>& arrpFrame)
{
	if (pPlayer != NULL)
	{
		pPlayer->moveToNextFrame();
		SFResSkill* pSkill = pPlayer->m_resPlayer->m_arrSkill[pPlayer->m_nowSkill][pPlayer->m_nowAs][pPlayer->m_nowSsse];
		if (pSkill != NULL)
		{
			UINT objectCount = pSkill->m_arrObject.size();
			if (objectCount > 0)
			{
				for (UINT i = 0; i < objectCount; i++)
				{
					arrpFrame.insert(arrpFrame.end(), &(pSkill->m_arrObject[i].m_arrFrame[pPlayer->m_countSkillFrame]));
				}
			}
		}
	}

	return true;
}

//碰撞，与绘制是不同线程
bool SFActScene::doCollision()
{
	SFPlayer* pPlayer = NULL;
	vector<SFResFrame*> arrpFrame1;
	vector<SFResFrame*> arrpFrame2;

	if (m_tc % 60 == 0)
	{
		sf_cout(DEBUG_COM, "<time>:" << m_tc / 60 << endl);
	}
	refreshDirection();
	addFrameToCollosion(getFightP1(), arrpFrame1);
	addFrameToCollosion(getFightP2(), arrpFrame2);
	refreshDirection();
	m_tc++;

	return true;
}
#pragma endregion

#pragma region 基本
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
		pSpriteGroup->m_pScene = this;
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
#pragma endregion

#pragma region 位置
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
	FLOAT dy = getFightP1()->m_resPlayer->m_arrSkill[EKA_DEF][AS_DEF][SSSE_DEF]->m_arrObject[0].m_arrFrame[0].m_lBodyBox.begin()->bottom;
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
	FLOAT dy = getFightP2()->m_resPlayer->m_arrSkill[EKA_DEF][AS_DEF][SSSE_DEF]->m_arrObject[0].m_arrFrame[0].m_lBodyBox.begin()->bottom;
	m_poiInitP2.y -= dy;

	return setPositionFightP2(m_poiInitP2);
}

void SFActScene::setDirection(bool isP1Left)
{
	if (getFightP1()->m_hitStatus == ASH_DEF)
	{
		if (isP1Left)
		{
			m_mapTevEk[TEV_KU_P1LF] = EK_4;
			m_mapTevEk[TEV_KU_P1RG] = EK_6;
			m_mapTevEk[TEV_KD_P1LF] = EK_4;
			m_mapTevEk[TEV_KD_P1RG] = EK_6;
		}
		else
		{
			m_mapTevEk[TEV_KU_P1LF] = EK_6;
			m_mapTevEk[TEV_KU_P1RG] = EK_4;
			m_mapTevEk[TEV_KD_P1LF] = EK_6;
			m_mapTevEk[TEV_KD_P1RG] = EK_4;
		}
		if (getFightP1()->m_isTwdRight != isP1Left)
		{
			UCHAR tmp = getFightP1()->m_eStatus.m_aStatus[EK_4];
			getFightP1()->m_eStatus.m_aStatus[EK_4] = getFightP1()->m_eStatus.m_aStatus[EK_6];
			getFightP1()->m_eStatus.m_aStatus[EK_6] = tmp;
			getFightP1()->m_isTwdRight = isP1Left;
		}
	}
	if (getFightP2()->m_hitStatus == ASH_DEF)
	{
		if (isP1Left)
		{
			m_mapTevEk[TEV_KU_P2LF] = EK_6;
			m_mapTevEk[TEV_KU_P2RG] = EK_4;
			m_mapTevEk[TEV_KD_P2LF] = EK_6;
			m_mapTevEk[TEV_KD_P2RG] = EK_4;
		}
		else
		{
			m_mapTevEk[TEV_KU_P2LF] = EK_4;
			m_mapTevEk[TEV_KU_P2RG] = EK_6;
			m_mapTevEk[TEV_KD_P2LF] = EK_4;
			m_mapTevEk[TEV_KD_P2RG] = EK_6;
		}
		if (getFightP2()->m_isTwdRight != !isP1Left)
		{
			UCHAR tmp = getFightP2()->m_eStatus.m_aStatus[EK_4];
			getFightP2()->m_eStatus.m_aStatus[EK_4] = getFightP2()->m_eStatus.m_aStatus[EK_6];
			getFightP2()->m_eStatus.m_aStatus[EK_6] = tmp;
			getFightP2()->m_isTwdRight = !isP1Left;
		}
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
#pragma endregion

#pragma region 绘制
void SFActScene::onDrawForFightBox(
	ID2D1HwndRenderTarget* pRenderTarget,
	ID2D1SolidColorBrush* pBrush,
	SFPlayer* pPlayer,
	list<D2D1_RECT_F>* pList
	)
{
	for (list<D2D1_RECT_F>::iterator it = pList->begin(); it != pList->end(); it++)
	{
		D2D1_RECT_F sRect = *it;
		if (pPlayer->m_isTwdRight)
		{
			sRect.left += pPlayer->m_position.x;
			sRect.right += pPlayer->m_position.x;
		}
		else
		{
			sRect.left = pPlayer->m_position.x - sRect.left;
			sRect.right = pPlayer->m_position.x - sRect.right;
		}
		sRect.top += pPlayer->m_position.y;
		sRect.bottom += pPlayer->m_position.y;
		D2D1_RECT_F vRect = SFd2d::getViewRectFromScene(pRenderTarget, sRect);
		pRenderTarget->FillRectangle(vRect, pBrush);
	}
}

void SFActScene::onDrawForFightSprite(
	ID2D1HwndRenderTarget* pRenderTarget,
	ID2D1SolidColorBrush* pBodyBrush,
	ID2D1SolidColorBrush* pActBrush,
	SFPlayer* pPlayer
	)
{
	if (pPlayer != NULL)
	{
		SFResSkill* pSkill = pPlayer->m_resPlayer->m_arrSkill[pPlayer->m_nowSkill][pPlayer->m_nowAs][pPlayer->m_nowSsse];

		if (pSkill != NULL)
		{
			UINT objectCount = pSkill->m_arrObject.size();
			if (objectCount > 0)
			{
				for (UINT i = 0; i < objectCount; i++)
				{
					list<D2D1_RECT_F>* pList = NULL;

					pList = &pSkill->m_arrObject[i].m_arrFrame[pPlayer->m_countSkillFrame].m_lBodyBox;
					onDrawForFightBox(pRenderTarget, pBodyBrush, pPlayer, pList);
					pList = &pSkill->m_arrObject[i].m_arrFrame[pPlayer->m_countSkillFrame].m_lAttackBox;
					onDrawForFightBox(pRenderTarget, pActBrush, pPlayer, pList);
				}
			}
		}
	}
}

//与碰撞是不同线程
void SFActScene::onDraw(
	ID2D1HwndRenderTarget* pRenderTarget,
	ID2D1SolidColorBrush* pBodyBrush,
	ID2D1SolidColorBrush* pActBrush,
	ID2D1BitmapBrush* pBackBrush
	)
{
	double mpx = (getFightP1()->m_position.x + getFightP2()->m_position.x)/2;
	double dpx = g_pConf->m_viewBenchmark.width / 2 - mpx;
	D2D1_POINT_2F sCmrPoi = { dpx , 0 };
	D2D1_POINT_2F vCmrPoi = SFd2d::getViewPoiFromScene(pRenderTarget, sCmrPoi);
	D2D1_POINT_2F sSize = { m_width, m_height };
	D2D1_POINT_2F vSize = SFd2d::getViewPoiFromScene(pRenderTarget, sSize);

	//设置变换
	pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
	pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(vCmrPoi.x, vCmrPoi.y));
	//画背景
	pRenderTarget->FillRectangle(D2D1::RectF(0.0f, 0.0f, vSize.x, vSize.y), pBackBrush);
	onDrawForFightSprite(pRenderTarget, pBodyBrush, pActBrush, getFightP1());
	onDrawForFightSprite(pRenderTarget, pBodyBrush, pActBrush, getFightP2());
}
#pragma endregion
#pragma endregion