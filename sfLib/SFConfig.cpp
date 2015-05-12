#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

__declspec(dllexport) SFConfig* SFConfig::m_pInstance = NULL;
__declspec(dllexport) SFConfig::SFCGarbo SFConfig::s_garbo;

SFConfig::SFConfig():
#pragma region 全局配置默认值
	m_enDebug(new bool[DEBUG_MAX]{
	true, false, false, false
	}),
	m_resPlayerFramePath("./data/playerFrame.xsd"),
	m_resSceneFramePath("./data/sceneFrame.xsd"),
	m_resSceneDataPath("./data/sceneInfo.xml"),
	m_resPath("./data/"),
	m_resPlayerInfoPrefix("p"),
	m_resPlayerInfoFileName("playerInfo.xml"),
	m_pDiEk(new TDIndexData(conf_aStrEk)),
	m_pDiEka(new TDIndexData(conf_aStrEka)),
	m_aTmr(conf_aIntTmr),
	m_pDiAsh(new TDIndexData(conf_aStrAsh)),
	m_pDiAs(new TDIndexData(conf_aStrAs)),
	m_pDiSsse(new TDIndexData(conf_aStrSsse)),
	m_strAsSplit("_"),
	m_pDiFightPGN(new TDIndexData(conf_aStrFightPGN)),
	m_mapSfActEvent(conf_mapSfActEvent),
	m_mapCmEvent(conf_mapCmEvent),
	m_pEventManager(NULL)
#pragma endregion
{
	m_aTmr[SF_TMR::TMR_PAINT] = 15;
	m_aTmr[SF_TMR::TMR_ACTION] = m_aTmr[SF_TMR::TMR_PAINT];
	m_aTmr[SF_TMR::TMR_SKILL] = 35;
	m_viewBenchmark.width = 800;
	m_viewBenchmark.height = 500;
	m_defaultResolution.width = 400;
	m_defaultResolution.height = 250;
}

SFConfig* SFConfig::GetInstance()
{
	if (m_pInstance == NULL)  //判断是否第一次调用
	{
		m_pInstance = new SFConfig();
		//控制台
		if (SFConfig::GetInstance()->m_enDebug[DEBUG_COM])
		{
			AllocConsole();
			int fd = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
			FILE *file = _fdopen(fd, "w");
			*stdout = *file;
			int status = setvbuf(stdout, 0, _IONBF, 0);
		}
	}
	return m_pInstance;
}

SFConfig::SFCGarbo::~SFCGarbo()
{
	if (SFConfig::m_pInstance)
		delete SFConfig::m_pInstance;
}