#pragma execution_character_set("utf-8")
#include <SFPlayer.h>

SFPlayer::SFPlayer(UINT id, SF_SKN skinId, int pid) :m_id(id), m_skinId(skinId), m_pid(pid)
{
	m_resPlayer = new SFResPlayer(TStrTrans::intIdToStrId(id), skinId);

	m_pSfconfig = SFConfig::GetInstance();
	m_standStatus = AS_STAND;
	m_nowSkill = EKA_MAX;
	m_countSkillFrame = 0;
	m_iTimeOut = 0;
}

SFPlayer::~SFPlayer()
{
	delete m_resPlayer;
}

void SFPlayer::setEventListTimeout()
{
	m_eStatus.setTimeout();
	m_iTimeOut = 0;
}

void SFPlayer::setDownStatusEnable(SF_EKD val)
{
	m_eStatus.m_aStatus[val] = 1;
}

void SFPlayer::setDownStatusDisable(SF_EKD val)
{
	m_eStatus.m_aStatus[val] = 0;
}

bool SFPlayer::getEnableSavedInSkill(SF_EKA skill, SF_AS sta)
{
	SFResSkill* pResSkill = m_resPlayer->m_mSkill[skill];

	if (pResSkill != NULL)
	{
		if (pResSkill->m_mSkillSwitchBmp[sta]->m_savable)
		{
			return true;
		}
	}

	return false;
}

bool SFPlayer::getEnableUpEventInSkill(SF_EKA skill, SF_AS sta)
{
	SFResSkill* pResSkill = m_resPlayer->m_mSkill[skill];

	if (pResSkill != NULL)
	{
		if (pResSkill->getEnableSpecialEvent(sta, SSSE_U))
		{
			return true;
		}
	}

	return false;
}

SF_EKA SFPlayer::getActionSkill(string ekaStr)
{
	for (UINT i = 0; i < ekaStr.size(); i++)
	{
		string tmp = ekaStr.substr(i, ekaStr.size() - i);
		map<string, SF_EKA>::iterator it = m_pSfconfig->s_mEka.find(tmp);

		if (it != m_pSfconfig->s_mEka.end())
		{
			sf_cout(DEBUG_SKILL_KEY, endl << "t:" << tmp << "<<");
			SF_EKA ret = (SF_EKA)(m_pSfconfig->s_mEka[tmp]);
			if ((*m_resPlayer)[ret])
			{
				if ((*(*m_resPlayer)[ret])[m_standStatus])
				{
					sf_cout(DEBUG_SKILL_KEY, "<<");
					return ret;
				}
			}
			else
			{
				//disable，继续循环，直到((found && enable) || 遍历结束)
			}
		}
	}

	return EKA_MAX;
}

SF_EKD SFPlayer::getLastKeyFromSkill(SF_EKA skill)
{
	if (skill != EKA_DEF && skill != EKA_MAX)
	{
		string strSkill = g_strEka[skill];
		strSkill.end();
	}
	else
	{
		return EKD_MAX;
	}
}

bool SFPlayer::upEvent(SF_EKU key)
{
	setDownStatusDisable((SF_EKD)key);
	if (m_hitStatus == ASH_SAVED)
	{
	}
	return false;
}

bool SFPlayer::downEvent(SF_EKD key)
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
	if (m_hitStatus == ASH_DEF)
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

bool SFPlayer::doSkill()
{
	return false;
}

void SFPlayer::moveToNextFrame()
{

}

void SFPlayer::doTimer(SF_TMR timer)
{
	if (timer == TMR_SKILL)
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