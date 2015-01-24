#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

SFResPlayer::SFResPlayer(SF_SKN skin)
{
	memset(m_arrSkill, 0, sizeof(SFResSkill*)*EKA_MAX*AS_MAX*SSSE_MAX);
}

SFResPlayer::SFResPlayer(string pid, SF_SKN skin)
{
	string confPath;

	confPath = SFConfig::GetInstance()->m_resPath + SFConfig::GetInstance()->m_resPlayerInfoPrefix + pid + "/" + SFConfig::GetInstance()->m_resPlayerInfoFileName;
	memset(m_arrSkill, 0, sizeof(SFResSkill*)*EKA_MAX*AS_MAX*SSSE_MAX);
	SFResConfigReader::readFromXML(confPath, this);
}

SFResPlayer::~SFResPlayer()
{
	for (UINT i = 0; i<EKA_MAX; i++)
	{
		for (UINT j = 0; j < AS_MAX; j++)
		{
			for (UINT k = 0; k < SSSE_MAX; k++)
			{
				if (m_arrSkill[i][j][k] != NULL)
				{
					delete m_arrSkill[i][j][k];
					m_arrSkill[i][j][k] = NULL;
				}
			}
		}
	}
}

/*
SFResSkill* SFResPlayer::operator[](SF_EKA skillIndex)
{
	return m_mSkill[skillIndex];
}

SFResSkill::SFResSkill(SF_EKA eka) :m_id(eka)
{
	for (UINT i = 0; i < AS_MAX; i++)
	{
		for (UINT j = 0; j < SSSE_MAX; j++)
		{
			m_mSkillSwitchBmp[i][j] = NULL;
		}
	}
}

SFResSkill::~SFResSkill()
{
	for (UINT i = 0; i < AS_MAX; i++)
	{
		for (UINT j = 0; j < SSSE_MAX; j++)
		{
			if (m_mSkillSwitchBmp[i][j] != NULL)
			{
				delete m_mSkillSwitchBmp[i][j];
				m_mSkillSwitchBmp[i][j] = NULL;
			}
		}
	}
}

bool SFResSkill::getEnableSpecialEvent(SF_AS as, SF_SSSE ssse)
{
	if (this->m_mSkillSwitchBmp[SF_SSSE_GETAS(as, ssse)] != NULL)
	{
		return true;
	}

	return false;
}
*/

SFResSkill::SFResSkill(SF_EKA eka, SF_AS as, SF_SSSE ssse, SFResPlayer* pParent,bool savable)
	:m_id(eka*as*ssse), m_eka(eka), m_as(as), m_ssse(ssse), m_parent(pParent), m_savable(savable)
{
	if (pParent != NULL)
	{
		pParent->m_arrSkill[eka][as][ssse] = this;
	}
}

SFResSkill::~SFResSkill()
{
	for (UINT i = 0; i < m_arrObject.size(); i++)
	{
		if (m_arrObject[i] != NULL)
		{
			delete m_arrObject[i];
			m_arrObject[i] = NULL;
		}
	}
	if (m_parent != NULL)
	{
		m_parent->m_arrSkill[m_eka][m_as][m_ssse] = NULL;
	}
}

bool SFResSkill::getEnableSpecialEvent(SF_SSSE ssse)
{
	if (m_parent->m_arrSkill[m_eka][m_as][ssse] != NULL)
	{
		return true;
	}

	return false;
}

SFResObject* SFResSkill::operator[](UINT intObjIndex)
{
	return m_arrObject[intObjIndex];
}

SFResObject::SFResObject(SFResSkill* pParent) :m_parent(pParent)
{
	if (pParent != NULL)
	{
		m_index = pParent->m_arrObject.size();
		pParent->m_arrObject.insert(pParent->m_arrObject.end(), this);
	}
}

SFResObject::~SFResObject()
{
	for (UINT i = 0; i < m_arrFrame.size(); i++)
	{
		if (m_arrFrame[i] != NULL)
		{
			delete m_arrFrame[i];
			m_arrFrame[i] = NULL;
		}
	}
	if (m_parent != NULL)
	{
		if (m_index < m_parent->m_arrObject.size())
		{
			m_parent->m_arrObject[m_index] = NULL;
		}
	}
}

SFResFrame* SFResObject::operator[](UINT frameIndex)
{
	return m_arrFrame[frameIndex];
}

SFResFrame::SFResFrame(SFResObject* pParent) :m_parent(pParent)
{
	if (pParent != NULL)
	{
		m_index = pParent->m_arrFrame.size();
		pParent->m_arrFrame.insert(pParent->m_arrFrame.end(), this);
	}
}

SFResFrame::~SFResFrame()
{
	if (m_parent != NULL)
	{
		if (m_index < m_parent->m_arrFrame.size())
		{
			m_parent->m_arrFrame[m_index] = NULL;
		}
	}
}