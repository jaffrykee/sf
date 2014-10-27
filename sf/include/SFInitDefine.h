#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>
#include <map>

#pragma region 按键设置define
#define KD_P1UP VK_W
#define KD_P1LF VK_A
#define KD_P1DW VK_S
#define KD_P1RG VK_D
#define KD_P1AA VK_U
#define KD_P1BB VK_I
#define KD_P1CC VK_O
#define KD_P1DD VK_J
#define KD_P1EE VK_K
#define KD_P1FF VK_L
#define KD_P1ST VK_1
#define KD_P1MN VK_2

#define KD_P2UP VK_UP
#define KD_P2LF VK_LEFT
#define KD_P2DW VK_DOWN
#define KD_P2RG VK_RIGHT
#define KD_P2AA VK_NUMPAD1
#define KD_P2BB VK_NUMPAD2
#define KD_P2CC VK_NUMPAD3
#define KD_P2DD VK_NUMPAD0
#define KD_P2EE VK_NUMPAD5
#define KD_P2FF VK_NUMPAD6
#define KD_P2ST VK_3
#define KD_P2MN VK_4
#pragma endregion

#pragma region 虚拟按键事件define(SF_EK)
enum SF_EKD
{
	EK_8D, EK_4D, EK_2D, EK_6D, EK_S1D, EK_S2D,
	EK_AD, EK_BD, EK_CD, EK_DD, EK_ED, EK_FD,
	EKD_MAX
};

enum SF_EKU
{
	EK_8U, EK_4U, EK_2U, EK_6U, EK_S1U, EK_S2U,
	EK_AU, EK_BU, EK_CU, EK_DU, EK_EU, EK_FU,
	EKU_MAX
};
#pragma endregion

#pragma region 计时器define(TMR)
enum TMR_ID
{
	TMR_NULL, TMR_PAINT, TMR_ACTION, TMR_SKILL,
	TMR_MAX
};

const unsigned int gc_arrTmr[TMR_MAX] = { 0, 15, 10, 100 };
#pragma endregion

#pragma region 角色当前动作状态
enum SF_AS
{
	AS_STAND, AS_J, AS_B, AS_S, AS_F, AS_DF, AS_SDF, AS_JEX, AS_R, AS_DDG,
	AS_MAX
};
#pragma endregion

#pragma region 虚拟按键事件连锁define(SF_EKF)
/*
j:jump
b:back
s:squat
f:front
def:defend
defs:squat defend
jex:big jump
r:run
ddg:dodge(闪躲)
以上均为物理依赖态，需要遵照物理守则，即落在地面，且不能到地下。
作为skill数组的下标使用，所以从0开始。
*/
enum SF_EKF
{
	EKF_A, EKF_B, EKF_C, EKF_D,

	EKF_j, EKF_jex, EKF_rj, EKF_rjex,
	EKF_fj, EKF_fjex, EKF_bj, EKF_bjex,
#if 0
	EKF_jA, EKF_jB, EKF_jC, EKF_jD,
	//可能会于以后版本用到，即技能的运动轨迹与图像内容逻辑分开。
#else
	EKF_jA, EKF_jexA, EKF_rjA, EKF_rjexA,
	EKF_fjA, EKF_fjexA, EKF_bjA, EKF_bjexA,
	EKF_jB, EKF_jexB, EKF_rjB, EKF_rjexB,
	EKF_fjB, EKF_fjexB, EKF_bjB, EKF_bjexB,
	EKF_jC, EKF_jexC, EKF_rjC, EKF_rjexC,
	EKF_fjC, EKF_fjexC, EKF_bjC, EKF_bjexC,
	EKF_jD, EKF_jexD, EKF_rjD, EKF_rjexD,
	EKF_fjD, EKF_fjexD, EKF_bjD, EKF_bjexD,
#endif
	EKF_b, EKF_def, EKF_defs,
	EKF_s, EKF_sA, EKF_sB, EKF_sC, EKF_sD,
	EKF_f, EKF_fA, EKF_fB, EKF_fC, EKF_fD,
	EKF_r, EKF_ddg,
	EKF_SKILL_MIN,
	EKF_26A, EKF_26B, EKF_26C, EKF_26D,
	EKF_24A, EKF_24B, EKF_24C, EKF_24D,
	EKF_626A, EKF_626B, EKF_626C, EKF_626D,
	EKF_424A, EKF_424B, EKF_424C, EKF_424D,
	EKF_426A, EKF_426B, EKF_426C, EKF_426D,
	EKF_624A, EKF_624B, EKF_624C, EKF_624D,
	EKF_2624A, EKF_2624B, EKF_2624C, EKF_2624D,
	EKF_2426A, EKF_2426B, EKF_2426C, EKF_2426D,
	EKF_2626A, EKF_2626B, EKF_2626C, EKF_2626D,
	EKF_2424A, EKF_2424B, EKF_2424C, EKF_2424D,
	EKF_624624A, EKF_624624B, EKF_624624C, EKF_624624D,
	EKF_426426A, EKF_426426B, EKF_426426C, EKF_426426D,
	EKF_MAX
};
#pragma endregion

class SFConfig
{
public:
	map<string, int> m_mEkf;

	SFConfig()
	{
		int i = 0;

		m_mEkf.insert(pair<string, int>("EKF_A", EKF_A));
		m_mEkf.insert(pair<string, int>("EKF_B", EKF_B));
		m_mEkf.insert(pair<string, int>("EKF_C", EKF_C));
		m_mEkf.insert(pair<string, int>("EKF_D", EKF_D));
		m_mEkf.insert(pair<string, int>("EKF_j", EKF_j));
		m_mEkf.insert(pair<string, int>("EKF_jex", EKF_jex));
		m_mEkf.insert(pair<string, int>("EKF_rj", EKF_rj));
		m_mEkf.insert(pair<string, int>("EKF_rjex", EKF_rjex));
		m_mEkf.insert(pair<string, int>("EKF_fj", EKF_fj));
		m_mEkf.insert(pair<string, int>("EKF_fjex", EKF_fjex));
		m_mEkf.insert(pair<string, int>("EKF_bj", EKF_bj));
		m_mEkf.insert(pair<string, int>("EKF_bjex", EKF_bjex));
		m_mEkf.insert(pair<string, int>("EKF_jA", EKF_jA));
		m_mEkf.insert(pair<string, int>("EKF_jexA", EKF_jexA));
		m_mEkf.insert(pair<string, int>("EKF_rjA", EKF_rjA));
		m_mEkf.insert(pair<string, int>("EKF_rjexA", EKF_rjexA));
		m_mEkf.insert(pair<string, int>("EKF_fjA", EKF_fjA));
		m_mEkf.insert(pair<string, int>("EKF_fjexA", EKF_fjexA));
		m_mEkf.insert(pair<string, int>("EKF_bjA", EKF_bjA));
		m_mEkf.insert(pair<string, int>("EKF_bjexA", EKF_bjexA));
		m_mEkf.insert(pair<string, int>("EKF_jB", EKF_jB));
		m_mEkf.insert(pair<string, int>("EKF_jexB", EKF_jexB));
		m_mEkf.insert(pair<string, int>("EKF_rjB", EKF_rjB));
		m_mEkf.insert(pair<string, int>("EKF_rjexB", EKF_rjexB));
		m_mEkf.insert(pair<string, int>("EKF_fjB", EKF_fjB));
		m_mEkf.insert(pair<string, int>("EKF_fjexB", EKF_fjexB));
		m_mEkf.insert(pair<string, int>("EKF_bjB", EKF_bjB));
		m_mEkf.insert(pair<string, int>("EKF_bjexB", EKF_bjexB));
		m_mEkf.insert(pair<string, int>("EKF_jC", EKF_jC));
		m_mEkf.insert(pair<string, int>("EKF_jexC", EKF_jexC));
		m_mEkf.insert(pair<string, int>("EKF_rjC", EKF_rjC));
		m_mEkf.insert(pair<string, int>("EKF_rjexC", EKF_rjexC));
		m_mEkf.insert(pair<string, int>("EKF_fjC", EKF_fjC));
		m_mEkf.insert(pair<string, int>("EKF_fjexC", EKF_fjexC));
		m_mEkf.insert(pair<string, int>("EKF_bjC", EKF_bjC));
		m_mEkf.insert(pair<string, int>("EKF_bjexC", EKF_bjexC));
		m_mEkf.insert(pair<string, int>("EKF_jD", EKF_jD));
		m_mEkf.insert(pair<string, int>("EKF_jexD", EKF_jexD));
		m_mEkf.insert(pair<string, int>("EKF_rjD", EKF_rjD));
		m_mEkf.insert(pair<string, int>("EKF_rjexD", EKF_rjexD));
		m_mEkf.insert(pair<string, int>("EKF_fjD", EKF_fjD));
		m_mEkf.insert(pair<string, int>("EKF_fjexD", EKF_fjexD));
		m_mEkf.insert(pair<string, int>("EKF_bjD", EKF_bjD));
		m_mEkf.insert(pair<string, int>("EKF_bjexD", EKF_bjexD));
		m_mEkf.insert(pair<string, int>("EKF_b", EKF_b));
		m_mEkf.insert(pair<string, int>("EKF_def", EKF_def));
		m_mEkf.insert(pair<string, int>("EKF_defs", EKF_defs));
		m_mEkf.insert(pair<string, int>("EKF_s", EKF_s));
		m_mEkf.insert(pair<string, int>("EKF_sA", EKF_sA));
		m_mEkf.insert(pair<string, int>("EKF_sB", EKF_sB));
		m_mEkf.insert(pair<string, int>("EKF_sC", EKF_sC));
		m_mEkf.insert(pair<string, int>("EKF_sD", EKF_sD));
		m_mEkf.insert(pair<string, int>("EKF_f", EKF_f));
		m_mEkf.insert(pair<string, int>("EKF_fA", EKF_fA));
		m_mEkf.insert(pair<string, int>("EKF_fB", EKF_fB));
		m_mEkf.insert(pair<string, int>("EKF_fC", EKF_fC));
		m_mEkf.insert(pair<string, int>("EKF_fD", EKF_fD));
		m_mEkf.insert(pair<string, int>("EKF_r", EKF_r));
		m_mEkf.insert(pair<string, int>("EKF_ddg", EKF_ddg));
		m_mEkf.insert(pair<string, int>("EKF_26A", EKF_26A));
		m_mEkf.insert(pair<string, int>("EKF_26B", EKF_26B));
		m_mEkf.insert(pair<string, int>("EKF_26C", EKF_26C));
		m_mEkf.insert(pair<string, int>("EKF_26D", EKF_26D));
		m_mEkf.insert(pair<string, int>("EKF_24A", EKF_24A));
		m_mEkf.insert(pair<string, int>("EKF_24B", EKF_24B));
		m_mEkf.insert(pair<string, int>("EKF_24C", EKF_24C));
		m_mEkf.insert(pair<string, int>("EKF_24D", EKF_24D));
		m_mEkf.insert(pair<string, int>("EKF_626A", EKF_626A));
		m_mEkf.insert(pair<string, int>("EKF_626B", EKF_626B));
		m_mEkf.insert(pair<string, int>("EKF_626C", EKF_626C));
		m_mEkf.insert(pair<string, int>("EKF_626D", EKF_626D));
		m_mEkf.insert(pair<string, int>("EKF_424A", EKF_424A));
		m_mEkf.insert(pair<string, int>("EKF_424B", EKF_424B));
		m_mEkf.insert(pair<string, int>("EKF_424C", EKF_424C));
		m_mEkf.insert(pair<string, int>("EKF_424D", EKF_424D));
		m_mEkf.insert(pair<string, int>("EKF_426A", EKF_426A));
		m_mEkf.insert(pair<string, int>("EKF_426B", EKF_426B));
		m_mEkf.insert(pair<string, int>("EKF_426C", EKF_426C));
		m_mEkf.insert(pair<string, int>("EKF_426D", EKF_426D));
		m_mEkf.insert(pair<string, int>("EKF_624A", EKF_624A));
		m_mEkf.insert(pair<string, int>("EKF_624B", EKF_624B));
		m_mEkf.insert(pair<string, int>("EKF_624C", EKF_624C));
		m_mEkf.insert(pair<string, int>("EKF_624D", EKF_624D));
		m_mEkf.insert(pair<string, int>("EKF_2624A", EKF_2624A));
		m_mEkf.insert(pair<string, int>("EKF_2624B", EKF_2624B));
		m_mEkf.insert(pair<string, int>("EKF_2624C", EKF_2624C));
		m_mEkf.insert(pair<string, int>("EKF_2624D", EKF_2624D));
		m_mEkf.insert(pair<string, int>("EKF_2426A", EKF_2426A));
		m_mEkf.insert(pair<string, int>("EKF_2426B", EKF_2426B));
		m_mEkf.insert(pair<string, int>("EKF_2426C", EKF_2426C));
		m_mEkf.insert(pair<string, int>("EKF_2426D", EKF_2426D));
		m_mEkf.insert(pair<string, int>("EKF_2626A", EKF_2626A));
		m_mEkf.insert(pair<string, int>("EKF_2626B", EKF_2626B));
		m_mEkf.insert(pair<string, int>("EKF_2626C", EKF_2626C));
		m_mEkf.insert(pair<string, int>("EKF_2626D", EKF_2626D));
		m_mEkf.insert(pair<string, int>("EKF_2424A", EKF_2424A));
		m_mEkf.insert(pair<string, int>("EKF_2424B", EKF_2424B));
		m_mEkf.insert(pair<string, int>("EKF_2424C", EKF_2424C));
		m_mEkf.insert(pair<string, int>("EKF_2424D", EKF_2424D));
		m_mEkf.insert(pair<string, int>("EKF_624624A", EKF_624624A));
		m_mEkf.insert(pair<string, int>("EKF_624624B", EKF_624624B));
		m_mEkf.insert(pair<string, int>("EKF_624624C", EKF_624624C));
		m_mEkf.insert(pair<string, int>("EKF_624624D", EKF_624624D));
		m_mEkf.insert(pair<string, int>("EKF_426426A", EKF_426426A));
		m_mEkf.insert(pair<string, int>("EKF_426426B", EKF_426426B));
		m_mEkf.insert(pair<string, int>("EKF_426426C", EKF_426426C));
		m_mEkf.insert(pair<string, int>("EKF_426426D", EKF_426426D));
		m_mEkf.insert(pair<string, int>("EKF_MAX", EKF_MAX));
	}
};