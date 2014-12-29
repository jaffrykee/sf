#include <SFResource.h>

SFConfig* g_config = SFConfig::GetInstance();

SFResPlayer::SFResPlayer(SF_SKN skin)
{
	memset(m_mSkill, 0, sizeof(SFResSkill*)*EKA_MAX);
}

SFResPlayer::SFResPlayer(string pid, SF_SKN skin)
{
	string confPath;

	confPath = g_config->m_resPath + g_config->m_resPlayerInfoPrefix + pid + "/" + g_config->m_resPlayerInfoFileName;
	memset(m_mSkill, 0, sizeof(SFResSkill*)*EKA_MAX);
	SFResConfigReader::readFromXML(confPath, this);
}

SFResPlayer::~SFResPlayer()
{
	for (UINT i = 0; i<EKA_MAX; i++)
	{
		if (m_mSkill[i] != NULL)
		{
			delete m_mSkill[i];
			m_mSkill[i] = NULL;
		}
	}
}

SFResSkill* SFResPlayer::operator[](SF_EKA skillIndex)
{
	return m_mSkill[skillIndex];
}

SFResSkill::SFResSkill(SF_EKA eka) :m_id(eka)
{
}

SFResSkill::~SFResSkill()
{
	for (UINT i = 0; i<AS_MAX; i++)
	{
		if (m_mSkillSwitchBmp[i] != NULL)
		{
			delete m_mSkillSwitchBmp[i];
			m_mSkillSwitchBmp[i] = NULL;
		}
	}
}

SFResSkillSwitch* SFResSkill::operator[](SF_AS swIndex)
{
	return m_mSkillSwitchBmp[swIndex];
}

SFResSkillSwitch::SFResSkillSwitch(SF_AS as) :m_id(as)
{
}

SFResSkillSwitch::~SFResSkillSwitch()
{
}

SFResObject* SFResSkillSwitch::operator[](unsigned int objIndex)
{
	return m_mObject[objIndex];
}

SFResObject::SFResObject(unsigned int index) :m_index(index)
{
}

SFResObject::~SFResObject()
{
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