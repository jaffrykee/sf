#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

SFConfig::SFConfig() :
	g_resPath("./data/"),
	g_resPlayerInfoPrefix("p"),
	g_resPlayerInfoFileName("playerInfo.xml"),
	g_pDiEk(new TDIndexData({
		"8", "4", "2", "6", "a", "b",
		"A", "B", "C", "D", "E", "F"
	}, EK_MAX)),
	g_pDiEka(new TDIndexData({
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
	g_aTmr(new UINT[]{
		0, 15, 10, 30
	})
{
}

SFConfig* SFConfig::GetInstance()
{
	if (m_pInstance == NULL)  //判断是否第一次调用  
		m_pInstance = new SFConfig();
	return m_pInstance;
}

SFConfig::SFCGarbo::~SFCGarbo()
{
	if (SFConfig::m_pInstance)
		delete SFConfig::m_pInstance;
}