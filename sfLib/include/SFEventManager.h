#pragma once
#pragma execution_character_set("utf-8")

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
	TEV_TMR_ACTION, TEV_TMR_SKILL,
	TEV_MAX
}SF_TEV;

typedef map<WPARAM, SF_TEV> MapEvent_T;
typedef map<UINT, MapEvent_T> MapEventGroup_T;

//系统事件接收器，用于隔离系统事件与真实事件。
class __declspec(dllexport) SFEventManager
{
	class SFUIScene{};

	MapEventGroup_T* m_pMapEvent;
	SFActScene* m_pActiveScene;

	struct SFEventUINode
	{
		SFUIScene* m_pScene;
		SF_TEV m_trueEvent;
		vector<int> m_arrInt;
		vector<string> m_arrStr;
	};
public:
	map<SF_KD, SF_TEV> m_mapKdTev;

	SFEventManager() :m_pMapEvent(&SFConfig::GetInstance()->m_mapEvent)
	{
	}

	bool doEvent(SF_TEV event, LPARAM lParam)
	{
		m_pActiveScene->doEvent(event);
	}

	bool doSystemEvent(UINT message, WPARAM wParam, LPARAM lParam)
	{
		MapEventGroup_T::iterator itEventGroup = m_pMapEvent->find(message);
		if (itEventGroup != m_pMapEvent->end())
		{
			MapEvent_T::iterator itEvent = (*m_pMapEvent)[message].find(wParam);
			if (itEvent != (*m_pMapEvent)[message].end())
			{
				return doEvent((*m_pMapEvent)[message][wParam], lParam);
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
};