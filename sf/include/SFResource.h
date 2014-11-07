#pragma once
#pragma execution_character_set("utf-8")
//强制无签名utf-8
//用于读取资源

#include <init.h>
#include <map>
#include <list>

/*
	技能帧，如果不动，那么，渲染矩形的左下左边为(0,0)（即left和bottom都为0），渲染位移参照也是靠左下角为凭据的，位移
参照上一帧的。
*/
class SFResFrame
{
public:
	int m_count;
	//渲染矩形
	D2D1_RECT_F m_drawBox;
	//位图资源
	ID2D1Bitmap* m_mBmp[SKN_MAX];

	list<D2D1_RECT_F> m_boxBody;
	list<D2D1_RECT_F> m_boxAttack;

	SFResFrame()
	{
		int i = 0;
	}
};

//技能对象
class SFResObject
{
	string m_name;
	//int代表是第几帧
	map<int, SFResFrame> m_mFrame;

	SFResObject()
	{
		int i = 0;
	}

	SFResFrame& operator[](int count)
	{
		return m_mFrame[count];
	}
};

//技能状态分支
class SFResSkillSwitch
{
public:
	map<string, SFResObject> m_mObject;

	SFResSkillSwitch()
	{
		int i = 0;
	}

	SFResObject& operator[](string name)
	{
		return m_mObject[name];
	}
};

//技能资源
class SFResSkill
{
public:
	map<SF_AS, SFResSkillSwitch> m_mSkillSwitchBmp;

	SFResSkill()
	{
		int i = 0;
	}

	SFResSkillSwitch& operator[](SF_AS status)
	{
		return m_mSkillSwitchBmp[status];
	}

	void initSkin(SF_SKN skin)
	{
	}
};

//玩家资源
class SFResPlayer
{
public:
	SFResSkill* m_mSkill[EKA_MAX];

	SFResPlayer(SF_SKN skin)
	{
		memset(m_mSkill, 0, sizeof(SFResSkill*)*EKA_MAX);
		//<inc>读文件
	}

	void initSkin(SF_SKN skin)
	{
		for (unsigned int i = EKA_ZERO; i < EKA_MAX; i++)
		{
			//<inc>读文件
			if (m_mSkill[i] != NULL)
			{
				m_mSkill[i]->initSkin(skin);
			}
		}
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
	static SFResPlayer* s_mSkillBmp[SF_PLR::PLR_MAX];

	void initPlayer(SF_PLR player, SF_SKN skin)
	{
		if (s_mSkillBmp[player] == NULL)
		{
			s_mSkillBmp[player] = new SFResPlayer(skin);
		}
		else
		{
			s_mSkillBmp[player]->initSkin(skin);
		}
	}

private:
	SFResPlayerMap()
	{
		for (unsigned int i = 0; i < PLR_MAX; i++)
		{
			s_mSkillBmp[i] = NULL;
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
};