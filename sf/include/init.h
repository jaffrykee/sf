#pragma once
#pragma execution_character_set("utf-8")

#pragma region win系统define和include
#ifndef WINVER              // Allow use of features specific to Windows 7 or later.
#define WINVER 0x0700       // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT        // Allow use of features specific to Windows 7 or later.
#define _WIN32_WINNT 0x0700 // Change this to the appropriate value to target other versions of Windows.
#endif

#define WIN32_LEAN_AND_MEAN     // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <wchar.h>
#include <tchar.h>
#include <math.h>

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

#include <string>
#include <map>
#include <list>
#include <vector>

#include <stdio.h>
#include <XmlLite.h>
#include <shlwapi.h>
#include <comutil.h>
#include <atlcomcli.h>
#include <iostream>
#include <sstream>
#include <Fcntl.h>
#include <io.h>
#pragma comment(lib, "comsuppwd.lib")
#pragma comment(lib, "XmlLite.lib")
#pragma endregion

using namespace std;

#pragma region inline和宏等
template<class Interface>
inline void
SafeRelease(
Interface **ppInterfaceToRelease
)
{
	if (*ppInterfaceToRelease != NULL)
	{
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = NULL;
	}
}

#ifndef Assert
#if defined( DEBUG ) || defined( _DEBUG )
#define Assert(b) do {if(!(b)) {OutputDebugStringA("Assert: " #b "\n");}} while(0)
#else
#define Assert(b)
#endif //DEBUG || _DEBUG
#endif


#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif
#pragma endregion

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

#pragma region 配置文件路径等
const string g_resPath = "./data/";
const string g_resPlayerInfoPrefix = "p";
const string g_resPlayerInfoFileName = "playerInfo.xml";
#pragma endregion

#pragma region 角色定义(SF_PLR)
enum SF_PLR
{
	PLR_ZERO,
	PLR_JET, PLR_BLK,
	PLR_MAX
};
#pragma endregion

#pragma region 角色皮肤定义(SF_SKN)
enum SF_SKN
{
	SKN_SK1, SKN_SK2, SKN_SK3, SKN_SK4,
	SKN_MAX
};
#define SKN_DEF SKN_SK1
#pragma endregion

#pragma region 虚拟按键事件define(SF_EK)以及技能define(SF_EKA)

enum SF_EK
{
	EK_8, EK_4, EK_2, EK_6, EK_S1, EK_S2,
	EK_A, EK_B, EK_C, EK_D, EK_E, EK_F,
	EK_MAX
};

#pragma region g_mapStrEk
const map<string, SF_EK> g_mapStrEk = {
	pair<string, SF_EK>("8", EK_8),
	pair<string, SF_EK>("4", EK_4),
	pair<string, SF_EK>("2", EK_2),
	pair<string, SF_EK>("6", EK_6),
	pair<string, SF_EK>("a", EK_S1),
	pair<string, SF_EK>("b", EK_S2),
	pair<string, SF_EK>("A", EK_A),
	pair<string, SF_EK>("B", EK_B),
	pair<string, SF_EK>("C", EK_C),
	pair<string, SF_EK>("D", EK_D),
	pair<string, SF_EK>("E", EK_E),
	pair<string, SF_EK>("F", EK_F)
};
#pragma endregion

#pragma endregion

#pragma region 计时器define(SF_TMR)
enum SF_TMR
{
	TMR_NULL, TMR_PAINT, TMR_ACTION, TMR_SKILL,
	TMR_MAX
};

const UINT gc_arrTmr[TMR_MAX] = { 0, 15, 10, 30 };
#pragma endregion

#pragma region 角色当前状态define(SF_ASH, SF_AS)
//动作状态
enum SF_ASH
{
	ASH_DEF, ASH_ATC, ASH_HITED, ASH_FLOOR, ASH_DAD,
	ASH_SAVED,
	ASH_MAX
};
const string g_strAsh[ASH_MAX] = {
	"ASH_DEF", "ASH_ATC", "ASH_HITED", "ASH_FLOOR", "ASH_DAD",
	"ASH_SAVED"
};

//位置状态
enum SF_AS
{
	AS_STAND, AS_JUMP,
	AS_MAX
};

typedef enum SF_SkillSwitchSpecialEvent
{
	SSSE_BASIC, SSSE_UP,
	SSSE_MAX
}SF_SSSE;

//通过as得到它的基准as
#define SF_SSSE_BASICAS(as)		((SF_AS)((as)%AS_MAX))
//通过as得到对应的ssse下的as
#define SF_SSSE_GETAS(as, ssse)		((SF_SSSE_BASICAS(as) + ((UINT)(ssse))*AS_MAX))
#define AS_DEF AS_STAND
#define SSSE_DEF SSSE_BASIC

const string g_strAs[AS_MAX] = {
	"def", "jump"
};
const map<string, SF_AS> g_mapAs = {
	pair<string, SF_AS>("def", AS_DEF),
	pair<string, SF_AS>("jump", AS_JUMP)
};

const string g_strSsse[SSSE_MAX] = {
	"basic", "up"
};
const map<string, SF_SSSE> g_mapSsse = {
	pair<string, SF_SSSE>("basic", SSSE_BASIC),
	pair<string, SF_SSSE>("up", SSSE_UP)
};

const string g_strAsSplit = "_";
typedef enum SF_SkillAsSplitType
{
	SAST_NAME, SAST_AS, SAST_SSSE,
	SAST_MAX
}SF_SAST;
#pragma endregion

#pragma region 带状态的虚拟按键事件连锁define(SF_EKF)
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
	EKF_8, EKF_4, EKF_2, EKF_6, EKF_44, EKF_66,
	EKF_A, EKF_B, EKF_C, EKF_D,
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

#define EKF_STR_MAX 10
const string g_strEkf[] = {
	"j", "jex", "rj", "rjex",
	"fj", "fjex", "bj", "bjex",
#if 0
	"jA", "jB", "jC", "jD",
	//可能会于以后版本用到，即技能的运动轨迹与图像内容逻辑分开。
#else
	"jA", "jexA", "rjA", "rjexA",
	"fjA", "fjexA", "bjA", "bjexA",
	"jB", "jexB", "rjB", "rjexB",
	"fjB", "fjexB", "bjB", "bjexB",
	"jC", "jexC", "rjC", "rjexC",
	"fjC", "fjexC", "bjC", "bjexC",
	"jD", "jexD", "rjD", "rjexD",
	"fjD", "fjexD", "bjD", "bjexD",
#endif
	"b", "def", "defs",
	"s", "sA", "sB", "sC", "sD",
	"f", "fA", "fB", "fC", "fD",
	"r", "ddg",

	"SKILL_MIN",
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
	"426426A", "426426B", "426426C", "426426D",
	"MAX"
};
#pragma endregion

#pragma region 虚拟按键事件连锁define(SF_EKA)
/*
动作决策判断。
*/
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

#pragma region g_mapStrEka
const map<string, SF_EKA> g_mapStrEka = {
	pair<string, SF_EKA>("A", EKA_A),
	pair<string, SF_EKA>("B", EKA_B),
	pair<string, SF_EKA>("C", EKA_C),
	pair<string, SF_EKA>("D", EKA_D),
	pair<string, SF_EKA>("8", EKA_8),
	pair<string, SF_EKA>("4", EKA_4),
	pair<string, SF_EKA>("2", EKA_2),
	pair<string, SF_EKA>("6", EKA_6),
	pair<string, SF_EKA>("44", EKA_44),
	pair<string, SF_EKA>("66", EKA_66),
	pair<string, SF_EKA>("26A", EKA_26A),
	pair<string, SF_EKA>("26B", EKA_26B),
	pair<string, SF_EKA>("26C", EKA_26C),
	pair<string, SF_EKA>("26D", EKA_26D),
	pair<string, SF_EKA>("24A", EKA_24A),
	pair<string, SF_EKA>("24B", EKA_24B),
	pair<string, SF_EKA>("24C", EKA_24C),
	pair<string, SF_EKA>("24D", EKA_24D),
	pair<string, SF_EKA>("626A", EKA_626A),
	pair<string, SF_EKA>("626B", EKA_626B),
	pair<string, SF_EKA>("626C", EKA_626C),
	pair<string, SF_EKA>("626D", EKA_626D),
	pair<string, SF_EKA>("424A", EKA_424A),
	pair<string, SF_EKA>("424B", EKA_424B),
	pair<string, SF_EKA>("424C", EKA_424C),
	pair<string, SF_EKA>("424D", EKA_424D),
	pair<string, SF_EKA>("426A", EKA_426A),
	pair<string, SF_EKA>("426B", EKA_426B),
	pair<string, SF_EKA>("426C", EKA_426C),
	pair<string, SF_EKA>("426D", EKA_426D),
	pair<string, SF_EKA>("624A", EKA_624A),
	pair<string, SF_EKA>("624B", EKA_624B),
	pair<string, SF_EKA>("624C", EKA_624C),
	pair<string, SF_EKA>("624D", EKA_624D),
	pair<string, SF_EKA>("2624A", EKA_2624A),
	pair<string, SF_EKA>("2624B", EKA_2624B),
	pair<string, SF_EKA>("2624C", EKA_2624C),
	pair<string, SF_EKA>("2624D", EKA_2624D),
	pair<string, SF_EKA>("2426A", EKA_2426A),
	pair<string, SF_EKA>("2426B", EKA_2426B),
	pair<string, SF_EKA>("2426C", EKA_2426C),
	pair<string, SF_EKA>("2426D", EKA_2426D),
	pair<string, SF_EKA>("2626A", EKA_2626A),
	pair<string, SF_EKA>("2626B", EKA_2626B),
	pair<string, SF_EKA>("2626C", EKA_2626C),
	pair<string, SF_EKA>("2626D", EKA_2626D),
	pair<string, SF_EKA>("2424A", EKA_2424A),
	pair<string, SF_EKA>("2424B", EKA_2424B),
	pair<string, SF_EKA>("2424C", EKA_2424C),
	pair<string, SF_EKA>("2424D", EKA_2424D),
	pair<string, SF_EKA>("624624A", EKA_624624A),
	pair<string, SF_EKA>("624624B", EKA_624624B),
	pair<string, SF_EKA>("624624C", EKA_624624C),
	pair<string, SF_EKA>("624624D", EKA_624624D),
	pair<string, SF_EKA>("426426A", EKA_426426A),
	pair<string, SF_EKA>("426426B", EKA_426426B),
	pair<string, SF_EKA>("426426C", EKA_426426C),
	pair<string, SF_EKA>("426426D", EKA_426426D),
	pair<string, SF_EKA>("MAX", EKA_MAX)
};
#pragma endregion

#define EKA_ZERO EKA_DEF

const string g_strEka[] = {
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
	"426426A", "426426B", "426426C", "426426D",
	"MAX"
};

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
}SF_SP;

class SFConfig;

class SFResPlayerMap;
class SFResPlayer;
class SFResSkill;
class SFResSkillSwitch;
class SFResObject;
class SFResFrame;
class SFPlayer;
class SFActScene;
class SFSpriteGroup;

#include <SFDebug.h>
#include <SFConfig.h>
#include <SFResource.h>
#include <SFEventKey.h>
#include <SFPlayer.h>
#include <TStrTrans.h>
#include <SFActScene.h>
#include <SFResConfigReader.h>
#include <SFSceneManager.h>