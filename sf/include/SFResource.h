#pragma once
#pragma execution_character_set("utf-8")
//强制无签名utf-8
//用于读取资源

#include <init.h>
#include <map>

//技能帧位图
class SFResSkillFrame
{
public:
	ID2D1Bitmap* m_pBmp;

	SFResSkillFrame()
	{
		int i = 0;
	}
};

class SFResSkillSwitch
{
public:
	//int代表是第几帧
	static map<int, SFResSkillFrame> s_mSkillFrameBmp;

	SFResSkillSwitch()
	{
		int i = 0;
	}

	SFResSkillFrame& operator[](int count)
	{
		return s_mSkillFrameBmp[count];
	}
};

class SFResSkill
{
public:
	static map<SF_AS, SFResSkillSwitch> s_mSkillSwitchBmp;

	SFResSkill()
	{
		int i = 0;
	}

	SFResSkillSwitch& operator[](SF_AS status)
	{
		return s_mSkillSwitchBmp[status];
	}
};

class SFResSkin
{
public:
	static map<SF_EKA, SFResSkill> s_mSkillBmp;

	SFResSkin()
	{
		int i = 0;
	}

	SFResSkill& operator[](SF_EKA skillId)
	{
		return s_mSkillBmp[skillId];
	}
};

class SFResPlayer
{
public:
	static map<SF_SKN, SFResSkin> s_mSkinBmp;

	SFResPlayer()
	{
		int i = 0;
	}

	SFResSkin& operator[](SF_SKN skinId)
	{
		return s_mSkinBmp[skinId];
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
	static map<SF_PLR, SFResPlayer> s_mSkillBmp;

private:
	SFResPlayerMap()
	{
		int i = 0;
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