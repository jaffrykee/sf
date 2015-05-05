#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

SFPlayer::SFPlayer(UINT id, SF_SKN skinId, int pid, SFActScene* pScene) :m_skinId(skinId), m_pid(pid), m_pScene(pScene)
{
	m_id = TStrTrans::intIdToStrId(id);
	m_resPlayer = new SFResPlayer(m_id, skinId);

	m_pSfconfig = g_pConf;
	m_standStatus = AS_STAND;
	m_nowSkill = EKA_DEF;
	m_countSkillFrame = 0;
	m_iTimeOut = 0;
	m_pGroup = NULL;
	m_isTwdRight = true;
}

SFPlayer::SFPlayer(string id, SF_SKN skinId, int pid, SFActScene* pScene) :m_id(id), m_skinId(skinId), m_pid(pid), m_pScene(pScene)
{
	m_resPlayer = new SFResPlayer(m_id, skinId);

	m_pSfconfig = g_pConf;
	m_standStatus = AS_STAND;
	m_nowSkill = EKA_DEF;
	m_countSkillFrame = 0;
	m_iTimeOut = 0;
	m_pGroup = NULL;
	m_isTwdRight = true;
}

SFPlayer::~SFPlayer()
{
	delete m_resPlayer;
}

#pragma region 通用取值与设值
void SFPlayer::setEventListTimeout()
{
	m_eStatus.setTimeout();
	m_iTimeOut = 0;
}

void SFPlayer::setDownStatusEnable(SF_EK val)
{
	m_eStatus.m_aStatus[val] = 1;
}

void SFPlayer::setDownStatusDisable(SF_EK val)
{
	m_eStatus.m_aStatus[val] = 0;
}

void SFPlayer::setHitStatus(SF_ASH ash)
{
	sf_cout(DEBUG_PLAYER_ACT, endl << "player" << this->m_pid << ":hitStatus <from>: " 
		<< g_pConf->m_pDiAsh->m_str[m_hitStatus] << " <to>: " << g_pConf->m_pDiAsh->m_str[ash]);
	m_hitStatus = ash;
}

bool SFPlayer::getEnableSavedInSkill(SF_EKA skill, SF_AS sta)
{
	SFResSkill* pResSkill = m_resPlayer->m_arrSkill[skill][sta][SF_SSSE::SSSE_BASIC];

	if (pResSkill != NULL)
	{
		if (pResSkill->m_savable)
		{
			return true;
		}
	}

	return false;
}

bool SFPlayer::getEnableUpEventInSkill(SF_EKA skill, SF_AS sta)
{
	SFResSkill* pResSkill = m_resPlayer->m_arrSkill[skill][sta][SSSE_UP];

	if (pResSkill != NULL)
	{
		return true;
	}

	return false;
}
#pragma endregion

#pragma region 事件接口
//由场景调用，计时器事件
void SFPlayer::doTimer(SF_TEV timer)
{
	if (timer == TEV_TMR_SKILL)
	{
		if (m_iTimeOut < 5)
		{
			m_iTimeOut++;
		}
		else
		{
			setEventListTimeout();
		}
	}
}

//由场景调用的，键盘弹起事件
bool SFPlayer::upEvent(SF_EK key)
{
	setDownStatusDisable((SF_EK)key);
	if (m_hitStatus == ASH_SAVED)
	{
		if (getLastKeyFromSkill(m_nowSkill) == key)
		{
			if (this->getEnableUpEventInSkill(m_nowSkill, m_nowAs))
			{
				m_nowSsse = SSSE_UP;
				//setHitStatus(ASH_ATC);
			}
			else
			{
				//<inc>场景中应该有个释放控制的函数，能够让场景按照地图类型，将精灵归位。
				m_nowSkill = EKA_DEF;
				m_nowAs = AS_DEF;
				m_nowSsse = SSSE_BASIC;
				m_standStatus = AS_DEF;
				setHitStatus(ASH_DEF);
				m_countSkillFrame = 0;
			}
		}
	}
	return false;
}

//由场景调用的，键盘按下事件
bool SFPlayer::downEvent(SF_EK key)
{
	SF_EKA ret = EKA_MAX;

	if (m_eStatus.m_aStatus[key] == 1)
	{
		return true;
	}
	m_iTimeOut = 0;
	m_eStatus.addEvent(key);
	setDownStatusEnable(key);
	//只有可控制状态才可以进入selectSkill阶段
	if (m_hitStatus == ASH_DEF || (m_hitStatus == ASH_SAVED && m_nowSkill <= EKA_66))
	{
		ret = getActionSkill(m_eStatus.m_sDownEvent);
	}
	if (ret == EKA_MAX)
	{
		return false;
	}
	else
	{
		m_nowSkill = ret;
	}
	return true;
}
#pragma endregion

#pragma region 技能选择
//抉择技能
SF_EKA SFPlayer::getActionSkill(string ekaStr)
{
	for (UINT i = 0; i < ekaStr.size(); i++)
	{
		string tmp = ekaStr.substr(i, ekaStr.size() - i);
		map<string, UINT>::iterator it = g_pConf->m_pDiEka->m_map.find(tmp);

		if (it != g_pConf->m_pDiEka->m_map.end())
		{
			sf_cout(DEBUG_SKILL_KEY, endl << "t:" << tmp << "<<");
			SF_EKA ret = (SF_EKA)it->second;
			if (m_resPlayer->m_arrSkill[ret][m_standStatus][SF_SSSE::SSSE_BASIC] != NULL)
			{
				sf_cout(DEBUG_SKILL_KEY, "<<");
				if (m_resPlayer->m_arrSkill[ret][m_standStatus][SF_SSSE::SSSE_BASIC]->m_savable == true)
				{
					m_hitStatus = ASH_SAVED;
				}
				else
				{
//					setHitStatus(ASH_ATC);
				}
				m_nowAs = m_standStatus;
				m_nowSsse = SSSE_BASIC;

				return ret;
			}
			else
			{
				//disable，继续循环，直到((found && enable) || 遍历结束)
			}
		}
	}

	return EKA_MAX;
}

//得到某一技能的最后一个的按键
SF_EK SFPlayer::getLastKeyFromSkill(SF_EKA skill)
{
	if (skill != EKA_DEF && skill != EKA_MAX)
	{
		string strSkill = g_pConf->m_pDiEka->m_str[skill];
		string strLastKey = strSkill.substr(strSkill.length() - 1, 1);
		map<string, UINT>::iterator itEk = g_pConf->m_pDiEk->m_map.find(strLastKey);

		if (itEk != g_pConf->m_pDiEk->m_map.end())
		{
			return (SF_EK)itEk->second;
		}
	}

	return EK_MAX;
}
#pragma endregion

//由场景的doCollision调用，精灵移到下一帧
void SFPlayer::moveToNextFrame()
{
	if (m_nowSkill == EKA_MAX)
	{
		m_nowSkill = EKA_DEF;
		m_hitStatus = ASH_DEF;
	}
	if ((m_nowSkill == EKA_DEF && m_hitStatus == ASH_DEF) || (m_hitStatus == ASH_SAVED && m_nowSkill <= EKA_42))
	{
		UCHAR d4 = m_eStatus.m_aStatus[EK_4];
		UCHAR d6 = m_eStatus.m_aStatus[EK_6];
		UCHAR d8 = m_eStatus.m_aStatus[EK_8];
		UCHAR d2 = m_eStatus.m_aStatus[EK_2];

		if (d4 != d6)
		{
			if (d8 != d2)
			{
				if (d8 == 1)
				{
					m_hitStatus = ASH_DEF;
					if (d6 == 1)
					{
						if (m_nowSkill == EKA_66)
						{
							m_nowSkill = EKA_668;
						}
						else
						{
							m_nowSkill = EKA_68;
						}
					}
					else
					{
						m_nowSkill = EKA_48;
					}
				}
				else
				{
					m_hitStatus = ASH_SAVED;
					if (d6 == 1)
					{
						m_nowSkill = EKA_2;
					}
					else
					{
						m_nowSkill = EKA_42;
					}
				}
			}
			else
			{
				m_hitStatus = ASH_SAVED;
				if (d6 == 1)
				{
					if (m_nowSkill == EKA_66)
					{
						m_nowSkill = EKA_66;
					}
					else
					{
						m_nowSkill = EKA_6;
					}
				}
				else
				{
					m_nowSkill = EKA_4;
				}
			}
		}
		else
		{
			if (d8 != d2)
			{
				if (d8 == 1)
				{
					m_hitStatus = ASH_DEF;
					m_nowSkill = EKA_8;
				}
				else
				{
					m_hitStatus = ASH_SAVED;
					m_nowSkill = EKA_2;
				}
			}
		}
	}

	SFResSkill* pSkill = m_resPlayer->m_arrSkill[m_nowSkill][m_nowAs][m_nowSsse];

	if (pSkill != NULL && (m_hitStatus == ASH_DEF || m_hitStatus == ASH_SAVED || m_countSkillFrame != 0))
	{
		if (pSkill->m_arrObject.size() > 0)
		{
			UINT frameSize = pSkill->m_arrObject[0].m_arrFrame.size();
			D2D1_POINT_2F poiMove = pSkill->m_arrObject[0].m_arrFrame[m_countSkillFrame].m_poiMove;

			if (m_isTwdRight)
			{
				this->m_position.x += poiMove.x;
			}
			else
			{
				this->m_position.x -= poiMove.x;
			}
			this->m_position.y += poiMove.y;
			m_countSkillFrame++;
			if (m_hitStatus == ASH_SAVED)
			{
				if (m_countSkillFrame >= frameSize)
				{
					m_countSkillFrame = 0;
				}
			}
			else
			{
				if (m_countSkillFrame >= frameSize)
				{
					m_hitStatus = ASH_DEF;
					m_nowSkill = EKA_DEF;
					m_countSkillFrame = 0;
				}
				else
				{
					m_hitStatus = ASH_ATC;
				}
			}
		}
		else
		{
			m_countSkillFrame = 0;
		}
	}
	else
	{
		m_countSkillFrame = 0;
	}
}
