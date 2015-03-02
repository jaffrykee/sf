#pragma execution_character_set("utf-8")
#include <TInit.h>
#include <tkmT.h>

__declspec(dllexport) TConfig* TConfig::m_pInstance = NULL;
__declspec(dllexport) TConfig::TCGarbo TConfig::s_garbo;

TConfig::TConfig():
#pragma region 全局配置默认值
	m_enDebug(new bool[TDEBUG_MAX]{
		true, true
	})
#pragma endregion
{
}

TConfig* TConfig::GetInstance()
{
	if (m_pInstance == NULL)  //判断是否第一次调用
	{
		m_pInstance = new TConfig();
	}
	return m_pInstance;
}

TConfig::TCGarbo::~TCGarbo()
{
	if (TConfig::m_pInstance)
		delete TConfig::m_pInstance;
}