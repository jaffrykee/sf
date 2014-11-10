#pragma once
#pragma execution_character_set("utf-8")
//用于读取资源

#include <init.h>
#include <map>
#include <list>
#include <vector>
#include <TArray.h>

#define BASIC_RES_PATH ./data

/*
	技能帧，如果不动，那么，渲染矩形的左下为(0,0)（即left和bottom都为0），渲染位移参照也是靠左下角为凭据的，位移
参照上一帧的。
*/
class SFResFrame
{
public:
	unsigned int m_count;
	SFResObject* m_parent;
	//渲染矩形
	D2D1_RECT_F m_drawBox;
	//位图资源
	ID2D1Bitmap* m_mBmp;

	list<D2D1_RECT_F> m_boxBody;
	list<D2D1_RECT_F> m_boxAttack;

	SFResFrame()
	{
	}
};

//技能对象
class SFResObject
{
public:
	string m_name;
	SFResSkillSwitch* m_parent;
	vector<SFResFrame> m_mFrame;

	SFResObject()
	{
	}

	SFResFrame& operator[](unsigned int count)
	{
		return m_mFrame[count];
	}
};

//技能状态分支
class SFResSkillSwitch
{
public:
	SFResSkill* m_parent;
	vector<SFResObject> m_mObject;

	SFResSkillSwitch()
	{
	}

	SFResObject& operator[](unsigned int id)
	{
		return m_mObject[id];
	}
};

//技能资源
class SFResSkill
{
public:
	SFResPlayer* m_parent;
	SFResSkillSwitch* m_mSkillSwitchBmp[AS_MAX];

	SFResSkill()
	{
		int i = 0;
	}
};

//玩家资源
class SFResPlayer
{
public:
	SFResSkill* m_mSkill[SKN_MAX][EKA_MAX];

	SFResPlayer(SF_SKN skin)
	{
		memset(m_mSkill, 0, sizeof(SFResSkill*)*SKN_MAX*EKA_MAX);
		//<inc>读文件
	}
};

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
				if (this->GetInstance()->s_mPlayer[playerId] == NULL)
				{
				}
				else
				{
					if (this->GetInstance()->s_mPlayer[playerId]->m_mSkill[skin] == NULL)
					{
					}
				}
			}
		}
	}
};