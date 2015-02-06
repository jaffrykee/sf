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

	confPath = g_pConf->m_resPath + g_pConf->m_resPlayerInfoPrefix + pid + "/" + g_pConf->m_resPlayerInfoFileName;
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

SFResSkill* SFResPlayer::addSkill(SF_EKA eka, SF_AS as, SF_SSSE ssse, bool savable)
{
	SFResSkill(eka, as, ssse, this, savable);

	return m_arrSkill[eka][as][ssse];
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
	if (m_parent != NULL)
	{
		m_parent->m_arrSkill[m_eka][m_as][m_ssse] = NULL;
	}
}

SFResObject& SFResSkill::addObject()
{
	m_arrObject.insert(m_arrObject.end(), SFResObject(this));

	return m_arrObject[m_arrObject.size() - 1];
}

bool SFResSkill::getEnableSpecialEvent(SF_SSSE ssse)
{
	if (m_parent->m_arrSkill[m_eka][m_as][ssse] != NULL)
	{
		return true;
	}

	return false;
}

SFResObject& SFResSkill::operator[](UINT intObjIndex)
{
	return m_arrObject[intObjIndex];
}

SFResObject::SFResObject(SFResSkill* pParent) :m_parent(pParent)
{
	if (pParent != NULL)
	{
		m_index = pParent->m_arrObject.size();
	}
}

SFResObject::~SFResObject()
{
}

SFResFrame& SFResObject::operator[](UINT frameIndex)
{
	return m_arrFrame[frameIndex];
}

SFResFrame& SFResObject::addObject()
{
	m_arrFrame.insert(m_arrFrame.end(), SFResFrame(this));

	return m_arrFrame[m_arrFrame.size() - 1];
}

SFResFrame::SFResFrame(SFResObject* pParent) :m_parent(pParent)
{
	if (pParent != NULL)
	{
		m_index = pParent->m_arrFrame.size();
	}
}

SFResFrame::~SFResFrame()
{
}