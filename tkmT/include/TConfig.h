#pragma once
#pragma execution_character_set("utf-8")

#define g_pTConf TConfig::GetInstance()

/* 全局配置单例类 */
class __declspec(dllexport) TConfig
{
public:
/*
	map<string, t_EKF> s_mEkf;
	map<string, t_EKA> s_mEka;
*/
	bool* m_enDebug;

private:
	static TConfig *m_pInstance;
	class TCGarbo 
	{
	public:
		~TCGarbo();
	};
	static TCGarbo s_garbo;

	TConfig();

public:
	static TConfig* GetInstance();
};