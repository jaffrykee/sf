#pragma once
#pragma execution_character_set("utf-8")

#pragma region SF_KD:虚拟事件
enum SF_KD{
	KD_P1UP, KD_P1LF, KD_P1DW, KD_P1RG, KD_P1AA, KD_P1BB, KD_P1CC, KD_P1DD, KD_P1EE, KD_P1FF, KD_P1ST, KD_P1MN, 
	KD_P2UP, KD_P2LF, KD_P2DW, KD_P2RG, KD_P2AA, KD_P2BB, KD_P2CC, KD_P2DD, KD_P2EE, KD_P2FF, KD_P2ST, KD_P2MN,
	KD_MAX
};
#pragma endregion


#pragma region SF_PLR:角色定义
enum SF_PLR
{
	PLR_ZERO,
	PLR_JET, PLR_BLK,
	PLR_MAX
};
#pragma endregion

#pragma region SF_SKN:角色皮肤定义
enum SF_SKN
{
	SKN_SK1, SKN_SK2, SKN_SK3, SKN_SK4,
	SKN_MAX
};
#define SKN_DEF SKN_SK1
#pragma endregion

#pragma region SF_EK:虚拟按键事件define
enum SF_EK
{
	EK_8, EK_4, EK_2, EK_6, EK_S1, EK_S2,
	EK_A, EK_B, EK_C, EK_D, EK_E, EK_F,
	EK_MAX
};
#pragma endregion

#pragma region SF_EKA:技能按键序列
enum SF_EKA
{
	EKA_DEF,
	EKA_8, EKA_4, EKA_2, EKA_6, EKA_44, EKA_66,
	EKA_A, EKA_B, EKA_C, EKA_D,
	EKA_26A, EKA_26B, EKA_26C, EKA_26D,
	EKA_24A, EKA_24B, EKA_24C, EKA_24D,
	EKA_626A, EKA_626B, EKA_626C, EKA_626D,
	EKA_424A, EKA_424B, EKA_424C, EKA_424D,
	EKA_426A, EKA_426B, EKA_426C, EKA_426D,
	EKA_624A, EKA_624B, EKA_624C, EKA_624D,
	EKA_2624A, EKA_2624B, EKA_2624C, EKA_2624D,
	EKA_2426A, EKA_2426B, EKA_2426C, EKA_2426D,
	EKA_2626A, EKA_2626B, EKA_2626C, EKA_2626D,
	EKA_2424A, EKA_2424B, EKA_2424C, EKA_2424D,
	EKA_624624A, EKA_624624B, EKA_624624C, EKA_624624D,
	EKA_426426A, EKA_426426B, EKA_426426C, EKA_426426D,
	EKA_MAX
};
#pragma endregion

#pragma region SF_TMR:计时器define
enum SF_TMR
{
	TMR_NULL, TMR_PAINT, TMR_ACTION, TMR_SKILL,
	TMR_MAX
};
#pragma endregion

#pragma region SF_ASH:角色动作状态
enum SF_ASH
{
	ASH_DEF, ASH_ATC, ASH_HITED, ASH_FLOOR, ASH_DAD,
	ASH_SAVED,
	ASH_MAX
};
#pragma endregion

#pragma region SF_AS,SF_SSSE,SF_SAST:技能分支
#pragma region SF_AS:技能所归属的位置状态(1级分支)
enum SF_AS
{
	AS_STAND, AS_JUMP,
	AS_MAX
};
#pragma endregion

#pragma region SF_SSSE:技能所归属的次级分支(2级分支)
typedef enum SF_SkillSwitchSpecialEvent
{
	SSSE_BASIC, SSSE_UP,
	SSSE_MAX
}SF_SSSE;
#pragma endregion

#pragma region SF_SAST:技能分支类型以及相关处理用define
typedef enum SF_SkillAsSplitType
{
	SAST_NAME, SAST_AS, SAST_SSSE,
	SAST_MAX
}SF_SAST;
//通过as得到它的基准as
#define SF_SSSE_BASICAS(as) ((SF_AS)((as)%AS_MAX))
//通过as得到对应的ssse下的as
#define SF_SSSE_GETAS(as, ssse) ((SF_SSSE_BASICAS(as) + ((UINT)(ssse))*AS_MAX))
#define AS_DEF AS_STAND
#define SSSE_DEF SSSE_BASIC
#pragma endregion
#pragma endregion

/*
记录目前xml解析到哪里，数组存放的是指针。PRS是parse的意思。
PRS_SKL:SFResSkill*
PRS_SKLSW:SFResSkillSwitch*
PRS_OBJ:SFResObject*
PRS_FRM:SFResFrame*
*/
enum SF_PRS
{
	PRS_SKL, PRS_OBJ, PRS_FRM,
	PRS_MAX
};

typedef struct SFSelectedPlayer
{
	UINT id;
	SF_SKN skin;
}SF_SP_T;


/* 全局配置单例类 */
class __declspec(dllexport) SFConfig
{
public:
/*
	map<string, SF_EKF> s_mEkf;
	map<string, SF_EKA> s_mEka;
*/
	bool* m_enDebug;

	string m_resPath;
	string m_resPlayerInfoPrefix;
	string m_resPlayerInfoFileName;

	TDIndexData* m_pDiEk;
	TDIndexData* m_pDiEka;
	UINT* m_aTmr;
	TDIndexData* m_pDiAsh;
	TDIndexData* m_pDiAs;
	TDIndexData* m_pDiSsse;
	string m_strAsSplit;
	TDIndexData* m_pDiFightPGN;
	MapEventGroup_T m_mapEvent;

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