#pragma execution_character_set("utf-8")
#include <SFPlayer.h>

SFPlayer::SFPlayer(unsigned int id, SF_SKN skinId, int pid) :m_id(id), m_skinId(skinId), m_pid(pid)
{
	m_resPlayer = new SFResPlayer(TStrTrans::intIdToStrId(id), skinId);

	m_pSfconfig = SFConfig::GetInstance();
	m_standStatus = AS_STAND;
	m_nowSkill = EKA_MAX;
	m_countSkillFrame = 0;
}

SFPlayer::~SFPlayer()
{
	delete m_resPlayer;
}

void SFPlayer::setUpEventListTimeout()
{
	m_eStatus.setTimeout();
}

void SFPlayer::enableDownStatus(SF_EKD val)
{
	m_eStatus.m_aStatus[val] = 1;
}

void SFPlayer::disableDownStatus(SF_EKD val)
{
	m_eStatus.m_aStatus[val] = 0;
}

void SFPlayer::addEvent(SF_EKU val)
{
	m_eStatus.addEvent(val);
	disableDownStatus((SF_EKD)(val - 1));
}

string SFPlayer::getEkaString(string tail)
{
	return m_eStatus.m_sUp + tail;
}

SF_EKA SFPlayer::getActionSkill(string ekaStr)
{
	for (unsigned int i = 0; i < ekaStr.size(); i++)
	{
		string tmp = ekaStr.substr(i, ekaStr.size() - i);
		map<string, SF_EKA>::iterator it = m_pSfconfig->s_mEka.find(tmp);

		printf("\ne:%s", ekaStr.c_str());
		if (it != m_pSfconfig->s_mEka.end())
		{
			//found
			printf("\nt:%s", tmp.c_str());
			SF_EKA ret = (SF_EKA)(m_pSfconfig->s_mEka[tmp]);
			if ((*m_resPlayer)[ret])
			{
				if ((*(*m_resPlayer)[ret])[m_standStatus])
				{
					//enable，返回结果	<inc>
					printf("<<<");
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

bool SFPlayer::selectSkill(SF_EKD key)
{
	SF_EKA ret;

	enableDownStatus(key);
	ret = getActionSkill(m_eStatus.m_sUp + m_eStatus.getEkdChar(key));
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

int SFPlayer::getMaxSkillFrame()
{
	return m_aSkill[m_nowSkill]->m_maxFrame;
}

void SFPlayer::moveToNextFrame()
{

}