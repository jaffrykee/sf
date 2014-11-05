#pragma once
#pragma execution_character_set("utf-8")
//强制无签名utf-8
//用于读取资源

#include <init.h>
#include <map>


/*
	全局资源单例类
	<inc>可能会有两种方式。一种是将全部资源都读完，一种是在选人结束后再从硬盘读入，虽然后者更好。
*/
class SFResPlayer
{
public:
	static map<SF_PLR, map<SF_SKN, map<SF_EKA, map<SF_AS, map<int, ID2D1Bitmap*>>>>> s_mSkillBmp;

private:
	SFResPlayer()
	{
		int i = 0;
	}
	static SFResPlayer *m_pInstance;
	class SFCGarbo
	{
	public:
		~SFCGarbo()
		{
			if (SFResPlayer::m_pInstance)
				delete SFResPlayer::m_pInstance;
		}
	};
	static SFCGarbo s_garbo;	//定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数  
public:
	static SFResPlayer * GetInstance()
	{
		if (m_pInstance == NULL)	//判断是否第一次调用  
			m_pInstance = new SFResPlayer();
		return m_pInstance;
	}

	static void getResSkill(SF_EKA sid, SF_AS status, int count)
	{
		
	}
};