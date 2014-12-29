﻿#pragma once
#pragma execution_character_set("utf-8")
//用于读取资源

#include <init.h>

/*
	技能帧，如果不动，那么，渲染矩形的左下为(0,0)（即left和bottom都为0），渲染位移参照也是靠左下角为凭据的，位移
参照上一帧的。
*/
class SFResFrame
{
public:
	unsigned int m_index;
	float m_mid;
	SFResObject* m_parent;
	//渲染矩形
	D2D1_RECT_F m_drawBox;
	//位图资源
	ID2D1Bitmap* m_mBmp;

	list<D2D1_RECT_F> m_lBodyBox;
	list<D2D1_RECT_F> m_lAttackBox;

	SFResFrame(unsigned int index);
	~SFResFrame();
};

//技能对象
class SFResObject
{
public:
	unsigned int m_index;
	unsigned int m_id;
	SFResSkillSwitch* m_parent;
	vector<SFResFrame*> m_mFrame;

	SFResObject(unsigned int index);
	~SFResObject();
	SFResFrame* operator[](unsigned int frameIndex);
};

//技能状态分支
class SFResSkillSwitch
{
public:
	SFResSkill* m_parent;
	SF_AS m_id;
	vector<SFResObject*> m_mObject;

	SFResSkillSwitch(SF_AS as);
	~SFResSkillSwitch();
	SFResObject* operator[](unsigned int objIndex);
};

//技能资源
class SFResSkill
{
public:
	SFResPlayer* m_parent;
	SF_EKA m_id;
	SFResSkillSwitch* m_mSkillSwitchBmp[AS_MAX];

	SFResSkill(SF_EKA eka);
	~SFResSkill();
	SFResSkillSwitch* operator[](SF_AS swIndex);
};

//玩家资源
class SFResPlayer
{
public:
	SFResSkill* m_mSkill[EKA_MAX];

	SFResPlayer(SF_SKN skin);
	SFResPlayer(string pid, SF_SKN skin);
	~SFResPlayer();
	SFResSkill* operator[](SF_EKA skillIndex);
};

#if 0
/*
	全局资源单例类
	<inc>可能会有两种方式。一种是将全部资源都读完，一种是在选人结束后确定要读入的资源，再从硬盘读入，虽然后者占用内存少，但是前者逻辑简单，
	虽然刚刚进入游戏的时候载入时间长，但是之后会比较流畅。
*/
class SFResPlayerMap
{
public:
	static SFResPlayer* s_mPlayer[SF_PLR::PLR_MAX];

	void initPlayer(SF_PLR player, SF_SKN skin)
	{
		if (s_mPlayer[player] == NULL)
		{
			s_mPlayer[player] = new SFResPlayer(skin);
		}
	}

private:
	SFResPlayerMap()
	{
		for (unsigned int i = 0; i < PLR_MAX; i++)
		{
			s_mPlayer[i] = NULL;
		}
	}

	static SFResPlayerMap *m_pInstance;
	class SFCGarbo
	{
	public:
		~SFCGarbo()
		{
			if (SFResPlayerMap::m_pInstance)
				delete SFResPlayerMap::m_pInstance;
		}
	};
	static SFCGarbo s_garbo;	//定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数  
public:
	static SFResPlayerMap * GetInstance()
	{
		if (m_pInstance == NULL)	//判断是否第一次调用  
			m_pInstance = new SFResPlayerMap();
		return m_pInstance;
	}

	static void getResSkill(SF_EKA sid, SF_AS status, int count)
	{

	}

	SFResPlayer* SFGetPlayerData(SF_PLR playerId, SF_SKN skin)
	{
		if (playerId == PLR_ZERO)
		{
			if (skin == SKN_SK1)
			{
				if (GetInstance()->s_mPlayer[playerId] == NULL)
				{
				}
				else
				{
					if (GetInstance()->s_mPlayer[playerId]->m_mSkill[skin] == NULL)
					{
					}
				}
			}
		}
	}
};
#endif