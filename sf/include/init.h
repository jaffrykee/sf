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

#include <TStrTrans.h>
#include <TDIndexData.h>
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
const string g_strEk[EK_MAX] = {
	"8", "4", "2", "6", "a", "b",
	"A", "B", "C", "D", "E", "F"
};
const TDIndexData g_diEk = TDIndexData(g_strEk, EK_MAX);
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
const string g_strEka[EKA_MAX] = {
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
const TDIndexData g_diEka = TDIndexData(g_strEka, EKA_MAX);
#pragma endregion

#pragma region SF_TMR:计时器define
enum SF_TMR
{
	TMR_NULL, TMR_PAINT, TMR_ACTION, TMR_SKILL,
	TMR_MAX
};
const UINT gc_aTmr[TMR_MAX] = {
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
const string g_strAsh[ASH_MAX] = {
	"ASH_DEF", "ASH_ATC", "ASH_HITED", "ASH_FLOOR", "ASH_DAD",
	"ASH_SAVED"
};
const TDIndexData g_diAsh = TDIndexData(g_strAsh, ASH_MAX);
#pragma endregion

#pragma region SF_AS,SF_SSSE,SF_SAST:技能分支
	#pragma region SF_AS:技能所归属的位置状态(1级分支)
	enum SF_AS
	{
		AS_STAND, AS_JUMP,
		AS_MAX
	};
	const string g_strAs[AS_MAX] = {
		"def", "jump"
	};
	const TDIndexData g_diAs = TDIndexData(g_strAs, AS_MAX);
	#pragma endregion

	#pragma region SF_SSSE:技能所归属的次级分支(2级分支)
	typedef enum SF_SkillSwitchSpecialEvent
	{
		SSSE_BASIC, SSSE_UP,
		SSSE_MAX
	}SF_SSSE;
	const string g_strSsse[SSSE_MAX] = {
		"basic", "up"
	};
	const TDIndexData g_diSsse = TDIndexData(g_strSsse, SSSE_MAX);
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
	const string g_strAsSplit = "_";
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
#include <SFActScene.h>
#include <SFResConfigReader.h>
#include <SFSceneManager.h>