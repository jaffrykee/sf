#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>
#include <list>

using namespace std;

class SFPlayerBuffer
{
public:
	int m_id;
	PCWSTR m_name;
	PCWSTR m_headImgPath;
	D2D_RECT_U m_headImgRect;
};

class SFSkillFrame
{
public:
	int m_id;
	D2D_VECTOR_2F m_move;
	ID2D1Bitmap* m_imgFrame;
	bool m_enAtted;
	D2D_RECT_F m_rAtted;
	bool m_enAtt;
	D2D_RECT_F m_rAtt;
	bool m_enBreak;
	bool m_enChain;

};

#define SF_SKILL_EK_MAX 16

struct SFSkillKeys
{
	int m_body[SF_SKILL_EK_MAX];
};

class SFSkill
{
public:
	int m_id;
	int m_name;
	PCWSTR m_key;
};

class SFPlayer
{
public:
	int m_id;
	PCWSTR m_name;
	D2D_POINT_2U m_headImgWH;
	SFPEventStatus m_eStatus;
	SF_AS m_actionStatus;
	bool m_enableSkill[SF_AS::AS_MAX][SF_EKA::EKA_MAX];
	SFSkill m_aSkill[SF_EKA::EKA_MAX];
	SFConfig* m_pSfconfig;

	SFPlayer()
	{
		getSkillEnableFromFile("");
		m_pSfconfig = SFConfig::GetInstance();
		m_actionStatus = AS_STAND;
	}

	void getSkillEnableFromFile(string path)
	{
		if (path == "")
		{
			for (int i = 0; i < AS_MAX; i++)
			{
				for (int j = 0; j < EKF_MAX; j++)
				{
					m_enableSkill[i][j] = false;
				}
			}
		}
	}
	
	void setUpEventListTimeout()
	{
		m_eStatus.setTimeout();
	}

	void enableDownStatus(SF_EKD val)
	{
		m_eStatus.m_aStatus[val] = 1;
	}

	void disableDownStatus(SF_EKD val)
	{
		m_eStatus.m_aStatus[val] = 0;
	}

	void addEvent(SF_EKU val)
	{
		m_eStatus.addEvent(val);
		disableDownStatus((SF_EKD)(val-1));
	}

	string getEkaString(string tail)
	{
		return m_eStatus.m_sUp + tail;
	}

	string getActionSkill(string ekaStr)
	{
		for (int i = 0; i < ekaStr.size(); i++)
		{
			string tmp = ekaStr.substr(i, ekaStr.size()-i);
			map<string, int>::iterator it = m_pSfconfig->s_mEka.find(tmp);

			if (it != m_pSfconfig->s_mEka.end())
			{
				m_enableSkill[m_actionStatus][(m_pSfconfig->s_mEka["tmp"])];
			}
		}
	}

	void moveToNextFrame()
	{
		
	}
};