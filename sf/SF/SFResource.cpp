#include <SFResource.h>

SFConfig* g_config = SFConfig::GetInstance();

SFResPlayer::SFResPlayer(SF_SKN skin)
{
	memset(m_arrSkill, 0, sizeof(SFResSkill*)*EKA_MAX*AS_MAX*SSSE_MAX);
}

SFResPlayer::SFResPlayer(string pid, SF_SKN skin)
{
	string confPath;

	confPath = g_resPath + g_resPlayerInfoPrefix + pid + "/" + g_resPlayerInfoFileName;
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

SFResSkill::SFResSkill(SF_EKA eka, SF_AS as, SF_SSSE ssse) :m_id(eka*as*ssse), m_eka(eka), m_as(as), m_ssse(ssse)
{
}

SFResSkill::~SFResSkill()
{
	for (unsigned int i = 0; i < m_arrObject.size(); i++)
	{
		if (m_arrObject[i] != NULL)
		{
			delete m_arrObject[i];
			m_arrObject[i] = NULL;
		}
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

SFResObject* SFResSkill::operator[](unsigned int objIndex)
{
	return m_arrObject[objIndex];
}

SFResObject::SFResObject(unsigned int index) :m_index(index)
{
}

SFResObject::~SFResObject()
{
	for (unsigned int i = 0; i < m_mFrame.size(); i++)
	{
		if (m_mFrame[i] != NULL)
		{
			delete m_mFrame[i];
			m_mFrame[i] = NULL;
		}
	}
}

SFResFrame* SFResObject::operator[](unsigned int frameIndex)
{
	return m_mFrame[frameIndex];
}

SFResFrame::SFResFrame(unsigned int index) :m_index(index)
{
}

SFResFrame::~SFResFrame()
{
}