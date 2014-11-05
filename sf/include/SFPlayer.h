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
	bool m_enBody;
	D2D_RECT_F m_boxBody;
	bool m_enAttack;
	D2D_RECT_F m_boxAttack;
	bool m_enChain;
};

class SFSkill
{
public:
	int m_id;
	string m_name;
	SF_EKA m_eka;
	int m_maxFrame;
	list<SFSkillFrame> m_skillFrames;
};

class SFPlayer
{
public:
	//人物id，初始化调用资源用
	int m_id;
	//皮肤id，初始化调用资源用
	int m_cid;
	string m_name;
	//代表P1还是P2，即在左边还是右边
	int m_pid;
	D2D_POINT_2U m_headImgWH;
	//全局配置的引用
	SFConfig* m_pSfconfig;
	//全局资源的引用

	//技能资源
	SFSkill* m_aSkill[SF_EKA::EKA_MAX];

	//按键状态
	SFPEventStatus m_eStatus;
	//当前状态(SF_AS:正常、跳跃、防御、连锁、技能、被击、倒地)
	SF_AS m_actionStatus;
	//各个状态下被允许的技能
	bool m_enableSkill[SF_AS::AS_MAX][SF_EKA::EKA_MAX];

	//当前等待打印的技能
	SF_EKA m_nowSkill;
	//当前等待打印的技能的帧计数器
	int m_countSkillFrame;

	SFPlayer()
	{
		getSkillEnableFromFile("");
		m_pSfconfig = SFConfig::GetInstance();
		m_actionStatus = AS_STAND;
		m_nowSkill = EKA_MAX;
		m_countSkillFrame = 0;
	}

	SFPlayer(int id, int cid, int pid) :m_id(id), m_cid(cid), m_pid(pid)
	{
		getSkillEnableFromFile("");
		m_pSfconfig = SFConfig::GetInstance();
		m_actionStatus = AS_STAND;
		m_nowSkill = EKA_MAX;
		m_countSkillFrame = 0;
	}

	void getSkillEnableFromFile(string path)
	{
		if (path == "")
		{
			for (int i = 0; i < EKA_MAX; i++)
			{
				m_aSkill[i] = NULL;
				for (int j = 0; j < AS_MAX; j++)
				{
					m_enableSkill[j][i] = false;
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

	SF_EKA getActionSkill(string ekaStr)
	{
		for (int i = 0; i < ekaStr.size(); i++)
		{
			string tmp = ekaStr.substr(i, ekaStr.size()-i);
			map<string, SF_EKA>::iterator it = m_pSfconfig->s_mEka.find(tmp);

			if (it != m_pSfconfig->s_mEka.end())
			{
				//found
				SF_EKA ret = (SF_EKA)(m_pSfconfig->s_mEka[tmp]);
				if (m_enableSkill[m_actionStatus][ret])
				{
					//enable，返回结果	<inc>
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

	bool selectSkill(SF_EKD key)
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

	bool doSkill()
	{

	}

	int getMaxSkillFrame()
	{
		return m_aSkill[m_nowSkill]->m_maxFrame;
	}

	void moveToNextFrame()
	{
		
	}
};