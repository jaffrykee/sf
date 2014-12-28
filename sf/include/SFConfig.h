#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>

/* 全局配置单例类 */
class SFConfig
{
public:
	map<string, SF_EKF> s_mEkf;
	map<string, SF_EKA> s_mEka;
	static string m_resPath;
	static string m_resPlayerInfoPrefix;
	static string m_resPlayerInfoFileName;

private:
	static SFConfig *m_pInstance;
	class SFCGarbo 
	{
	public:
		~SFCGarbo();
	};
	static SFCGarbo s_garbo;

	SFConfig();

public:
	static SFConfig* GetInstance();
};