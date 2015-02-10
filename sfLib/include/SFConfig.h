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
//4代表的是后，而不是左；同理，6代表的是前，而不是右
enum SF_EK
{
	EK_8, EK_4, EK_2, EK_6, EK_S1, EK_S2,
	EK_A, EK_B, EK_C, EK_D, EK_E, EK_F,
	EK_MAX
};
const vector<string> conf_aStrEk = {
	"8", "4", "2", "6", "a", "b",
	"A", "B", "C", "D", "E", "F"
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

const vector<string> conf_aStrEka = {
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
};
#pragma endregion

#pragma region SF_TMR:计时器define
enum SF_TMR
{
	TMR_NULL, TMR_PAINT, TMR_ACTION, TMR_SKILL,
	TMR_MAX
};
const vector<UINT> conf_aIntTmr = {
	0, 15, 10, 30
};
#pragma endregion

#pragma region SF_ASH:角色动作状态
enum SF_ASH
{
	ASH_DEF, ASH_ATC, ASH_HITED, ASH_FLOOR, ASH_DAD,
	ASH_SAVED,
	ASH_MAX
};
const vector<string> conf_aStrAsh = {
	"ASH_DEF", "ASH_ATC", "ASH_HITED", "ASH_FLOOR", "ASH_DAD",
	"ASH_SAVED"
};
#pragma endregion

#pragma region SF_AS,SF_SSSE,SF_SAST:技能分支
	#pragma region SF_AS:技能所归属的位置状态(1级分支)
	enum SF_AS
	{
		AS_STAND, AS_JUMP,
		AS_MAX
	};
	const vector<string> conf_aStrAs = {
		"def", "jump"
	};
	#pragma endregion

	#pragma region SF_SSSE:技能所归属的次级分支(2级分支)
	typedef enum SF_SkillSwitchSpecialEvent
	{
		SSSE_BASIC, SSSE_UP,
		SSSE_MAX
	}SF_SSSE;
	const vector<string> conf_aStrSsse = {
		"basic", "up"
	};
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

typedef struct SFSelectedPlayer
{
	UINT id;
	SF_SKN skin;
}SF_SP_T;

#pragma region 事件处理相关
	#pragma region WIN系统的按键定义，VK
	//定义数据字符0~9  
	#define   VK_0         0x30   
	#define   VK_1         0x31   
	#define   VK_2         0x32   
	#define   VK_3         0x33   
	#define   VK_4         0x34   
	#define   VK_5         0x35   
	#define   VK_6         0x36   
	#define   VK_7         0x37   
	#define   VK_8         0x38   
	#define   VK_9         0x39  

	//定义数据字符A~Z  
	#define   VK_A  0x41   
	#define   VK_B  0x42   
	#define   VK_C  0x43   
	#define   VK_D  0x44   
	#define   VK_E  0x45   
	#define   VK_F  0x46   
	#define   VK_G  0x47   
	#define   VK_H  0x48   
	#define   VK_I  0x49   
	#define   VK_J  0x4A   
	#define   VK_K  0x4B   
	#define   VK_L  0x4C   
	#define   VK_M  0x4D   
	#define   VK_N  0x4E   
	#define   VK_O  0x4F   
	#define   VK_P  0x50   
	#define   VK_Q  0x51   
	#define   VK_R  0x52   
	#define   VK_S  0x53   
	#define   VK_T  0x54   
	#define   VK_U  0x55   
	#define   VK_V  0x56   
	#define   VK_W  0x57   
	#define   VK_X  0x58   
	#define   VK_Y  0x59   
	#define   VK_Z  0x5A   

	//定义数据字符a~z  
	#define   VK_a  0x61   
	#define   VK_b  0x62   
	#define   VK_c  0x63   
	#define   VK_d  0x64   
	#define   VK_e  0x65   
	#define   VK_f  0x66   
	#define   VK_g  0x67   
	#define   VK_h  0x68   
	#define   VK_i  0x69   
	#define   VK_j  0x6A   
	#define   VK_k  0x6B   
	#define   VK_l  0x6C   
	#define   VK_m  0x6D   
	#define   VK_n  0x6E   
	#define   VK_o  0x6F   
	#define   VK_p  0x70   
	#define   VK_q  0x71   
	#define   VK_r  0x72   
	#define   VK_s  0x73   
	#define   VK_t  0x74   
	#define   VK_u  0x75   
	#define   VK_v  0x76   
	#define   VK_w  0x77   
	#define   VK_x  0x78   
	#define   VK_y  0x79   
	#define   VK_z  0x7A   
	#pragma endregion

	typedef enum SF_EVENT_TYPE
	{
		EVT_KEY_DOWN, EVT_KEY_UP, EVT_TMR,
		EVT_MOUSE_DOWN, EVT_MOUSE_UP,
		EVT_MAX
	}SF_EVT;

	typedef enum SF_EVENT_SCENE
	{
		EVS_ACT, EVS_UI,
		EVS_MAX
	}SF_EVS;

	typedef enum SF_TRUE_EVENT
	{
		TEV_KD_P1UP, TEV_KD_P1LF, TEV_KD_P1DW, TEV_KD_P1RG,
		TEV_KD_P1AA, TEV_KD_P1BB, TEV_KD_P1CC, TEV_KD_P1DD, TEV_KD_P1EE, TEV_KD_P1FF, TEV_KD_P1ST, TEV_KD_P1MN,
		TEV_KD_P2UP, TEV_KD_P2LF, TEV_KD_P2DW, TEV_KD_P2RG,
		TEV_KD_P2AA, TEV_KD_P2BB, TEV_KD_P2CC, TEV_KD_P2DD, TEV_KD_P2EE, TEV_KD_P2FF, TEV_KD_P2ST, TEV_KD_P2MN,
		TEV_KU_P1UP, TEV_KU_P1LF, TEV_KU_P1DW, TEV_KU_P1RG,
		TEV_KU_P1AA, TEV_KU_P1BB, TEV_KU_P1CC, TEV_KU_P1DD, TEV_KU_P1EE, TEV_KU_P1FF, TEV_KU_P1ST, TEV_KU_P1MN,
		TEV_KU_P2UP, TEV_KU_P2LF, TEV_KU_P2DW, TEV_KU_P2RG,
		TEV_KU_P2AA, TEV_KU_P2BB, TEV_KU_P2CC, TEV_KU_P2DD, TEV_KU_P2EE, TEV_KU_P2FF, TEV_KU_P2ST, TEV_KU_P2MN,
		TEV_TMR_ACTION, TEV_TMR_SKILL, TEV_TMR_PAINT,
		TEV_MAX
	}SF_TEV;

	#define TEV_KD_P1MIN TEV_KD_P1UP
	#define TEV_KD_P1MAX TEV_KD_P1MN
	#define TEV_KD_P2MIN TEV_KD_P2UP
	#define TEV_KD_P2MAX TEV_KD_P2MN
	#define TEV_KD_MIN TEV_KD_P1MIN
	#define TEV_KD_MAX TEV_KD_P2MAX

	#define TEV_KU_P1MIN TEV_KU_P1UP
	#define TEV_KU_P1MAX TEV_KU_P1MN
	#define TEV_KU_P2MIN TEV_KU_P2UP
	#define TEV_KU_P2MAX TEV_KU_P2MN
	#define TEV_KU_MIN TEV_KU_P1MIN
	#define TEV_KU_MAX TEV_KU_P2MAX

	#define TEV_KEY_MIN TEV_KD_MIN
	#define TEV_KEY_MAX TEV_KU_MAX
	#define TEV_TMR_MIN TEV_TMR_ACTION
	#define TEV_TMR_MAX TEV_TMR_PAINT

	typedef map<WPARAM, SF_TEV> MapEvent_T;
	typedef map<UINT, MapEvent_T> MapEventGroup_T;

	const MapEventGroup_T conf_mapEvent = {
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
			pair<WPARAM, SF_TEV>(TMR_SKILL, TEV_TMR_SKILL),
			pair<WPARAM, SF_TEV>(TMR_PAINT, TEV_TMR_PAINT)
		})
	};
#pragma endregion

#define g_pConf SFConfig::GetInstance()
#define g_pEventManager SFConfig::GetInstance()->m_pEventManager

/* 全局配置单例类 */
class __declspec(dllexport) SFConfig
{
public:
/*
	map<string, SF_EKF> s_mEkf;
	map<string, SF_EKA> s_mEka;
*/
	bool* m_enDebug;

	string m_resPlayerFramePath;
	string m_resSceneFramePath;
	string m_resSceneDataPath;
	string m_resPath;
	string m_resPlayerInfoPrefix;
	string m_resPlayerInfoFileName;

	TDIndexData* m_pDiEk;
	TDIndexData* m_pDiEka;
	vector<UINT> m_aTmr;
	TDIndexData* m_pDiAsh;
	TDIndexData* m_pDiAs;
	TDIndexData* m_pDiSsse;
	string m_strAsSplit;
	TDIndexData* m_pDiFightPGN;
	MapEventGroup_T m_mapEvent;

	SFEventManager* m_pEventManager;

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