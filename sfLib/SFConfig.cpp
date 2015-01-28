#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

__declspec(dllexport) SFConfig* SFConfig::m_pInstance = NULL;
__declspec(dllexport) SFConfig::SFCGarbo SFConfig::s_garbo;

SFConfig::SFConfig():
#pragma region 全局配置默认值
	m_enDebug(new bool[DEBUG_MAX]{
		true, true, true, true
	}),
	m_resPath("./data/"),
	m_resPlayerInfoPrefix("p"),
	m_resPlayerInfoFileName("playerInfo.xml"),
	m_pDiEk(new TDIndexData({
		"8", "4", "2", "6", "a", "b",
		"A", "B", "C", "D", "E", "F"
	}, EK_MAX)),
	m_pDiEka(new TDIndexData({
		"DEF",
		"8", "4", "2", "6", "44", "66",
		"A", "B", "C", "D",
		"26A", "26B", "26C", "26D",
		"24A", "24B", "24C", "24D",
		"626A", "626B", "626C", "626D",
		"424A", "424B", "424C", "424D",
		"426A", "426B", "426C", "426D",
		"624A", "624B", "624C", "624D",
		"2624A", "2624B", "2624C", "2624D",
		"2426A", "2426B", "2426C", "2426D",
		"2626A", "2626B", "2626C", "2626D",
		"2424A", "2424B", "2424C", "2424D",
		"624624A", "624624B", "624624C", "624624D",
		"426426A", "426426B", "426426C", "426426D"
	}, EKA_MAX)),
	m_aTmr(new UINT[]{
		0, 15, 10, 30
	}),
	m_pDiAsh(new TDIndexData({
		"ASH_DEF", "ASH_ATC", "ASH_HITED", "ASH_FLOOR", "ASH_DAD",
		"ASH_SAVED"
	}, ASH_MAX)),
	m_pDiAs(new TDIndexData({
		"def", "jump" 
	}, AS_MAX)),
	m_pDiSsse(new TDIndexData({
		"basic", "up"
	}, SSSE_MAX)),
	m_strAsSplit("_"),
	m_pDiFightPGN(new TDIndexData({
		"p1", "p2"
	}, FIGHT_PGN_MAX)),
	m_mapEvent({
		pair<UINT, MapEvent_T>(WM_KEYDOWN, {
			pair<WPARAM, SF_TEV>(VK_A, TEV_KD_P1LF),
			pair<WPARAM, SF_TEV>(VK_W, TEV_KD_P1UP),
			pair<WPARAM, SF_TEV>(VK_A, TEV_KD_P1LF),
			pair<WPARAM, SF_TEV>(VK_S, TEV_KD_P1DW),
			pair<WPARAM, SF_TEV>(VK_D, TEV_KD_P1RG),
			pair<WPARAM, SF_TEV>(VK_U, TEV_KD_P1AA),
			pair<WPARAM, SF_TEV>(VK_I, TEV_KD_P1BB),
			pair<WPARAM, SF_TEV>(VK_O, TEV_KD_P1CC),
			pair<WPARAM, SF_TEV>(VK_J, TEV_KD_P1DD),
			pair<WPARAM, SF_TEV>(VK_K, TEV_KD_P1EE),
			pair<WPARAM, SF_TEV>(VK_L, TEV_KD_P1FF),
			pair<WPARAM, SF_TEV>(VK_1, TEV_KD_P1ST),
			pair<WPARAM, SF_TEV>(VK_2, TEV_KD_P1MN),
			pair<WPARAM, SF_TEV>(VK_UP, TEV_KD_P2UP),
			pair<WPARAM, SF_TEV>(VK_LEFT, TEV_KD_P2LF),
			pair<WPARAM, SF_TEV>(VK_DOWN, TEV_KD_P2DW),
			pair<WPARAM, SF_TEV>(VK_RIGHT, TEV_KD_P2RG),
			pair<WPARAM, SF_TEV>(VK_NUMPAD1, TEV_KD_P2AA),
			pair<WPARAM, SF_TEV>(VK_NUMPAD2, TEV_KD_P2BB),
			pair<WPARAM, SF_TEV>(VK_NUMPAD3, TEV_KD_P2CC),
			pair<WPARAM, SF_TEV>(VK_NUMPAD0, TEV_KD_P2DD),
			pair<WPARAM, SF_TEV>(VK_NUMPAD5, TEV_KD_P2EE),
			pair<WPARAM, SF_TEV>(VK_NUMPAD6, TEV_KD_P2FF),
			pair<WPARAM, SF_TEV>(VK_3, TEV_KD_P2ST),
			pair<WPARAM, SF_TEV>(VK_4, TEV_KD_P2MN)
		}),
		pair<UINT, MapEvent_T>(WM_KEYUP, {
			pair<WPARAM, SF_TEV>(VK_A, TEV_KU_P1LF),
			pair<WPARAM, SF_TEV>(VK_W, TEV_KU_P1UP),
			pair<WPARAM, SF_TEV>(VK_A, TEV_KU_P1LF),
			pair<WPARAM, SF_TEV>(VK_S, TEV_KU_P1DW),
			pair<WPARAM, SF_TEV>(VK_D, TEV_KU_P1RG),
			pair<WPARAM, SF_TEV>(VK_U, TEV_KU_P1AA),
			pair<WPARAM, SF_TEV>(VK_I, TEV_KU_P1BB),
			pair<WPARAM, SF_TEV>(VK_O, TEV_KU_P1CC),
			pair<WPARAM, SF_TEV>(VK_J, TEV_KU_P1DD),
			pair<WPARAM, SF_TEV>(VK_K, TEV_KU_P1EE),
			pair<WPARAM, SF_TEV>(VK_L, TEV_KU_P1FF),
			pair<WPARAM, SF_TEV>(VK_1, TEV_KU_P1ST),
			pair<WPARAM, SF_TEV>(VK_2, TEV_KU_P1MN),
			pair<WPARAM, SF_TEV>(VK_UP, TEV_KU_P2UP),
			pair<WPARAM, SF_TEV>(VK_LEFT, TEV_KU_P2LF),
			pair<WPARAM, SF_TEV>(VK_DOWN, TEV_KU_P2DW),
			pair<WPARAM, SF_TEV>(VK_RIGHT, TEV_KU_P2RG),
			pair<WPARAM, SF_TEV>(VK_NUMPAD1, TEV_KU_P2AA),
			pair<WPARAM, SF_TEV>(VK_NUMPAD2, TEV_KU_P2BB),
			pair<WPARAM, SF_TEV>(VK_NUMPAD3, TEV_KU_P2CC),
			pair<WPARAM, SF_TEV>(VK_NUMPAD0, TEV_KU_P2DD),
			pair<WPARAM, SF_TEV>(VK_NUMPAD5, TEV_KU_P2EE),
			pair<WPARAM, SF_TEV>(VK_NUMPAD6, TEV_KU_P2FF),
			pair<WPARAM, SF_TEV>(VK_3, TEV_KU_P2ST),
			pair<WPARAM, SF_TEV>(VK_4, TEV_KU_P2MN)
		}),
		pair<UINT, MapEvent_T>(WM_TIMER, {
			pair<WPARAM, SF_TEV>(TMR_ACTION, TEV_TMR_ACTION),
			pair<WPARAM, SF_TEV>(TMR_SKILL, TEV_TMR_SKILL)
		})
	}),
	m_pEventManager(NULL)
#pragma endregion
{
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