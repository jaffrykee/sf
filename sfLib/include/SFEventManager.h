#pragma once
#pragma execution_character_set("utf-8")

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
	TEV_TMR_ACTION, TEV_TMR_SKILL,
	TEV_MAX
}SF_TEV;

//系统事件接收器，用于隔离系统事件与真实事件。
class __declspec(dllexport) SFEventManager
{
	class SFUIScene{};
	struct SFEventActNode
	{
		SFActScene* m_pScene;
		SF_TEV m_trueEvent;
		vector<int> m_arrInt;
		vector<string> m_arrStr;
	};
	struct SFEventUINode
	{
		SFUIScene* m_pScene;
		SF_TEV m_trueEvent;
		vector<int> m_arrInt;
		vector<string> m_arrStr;
	};
public:
	vector<SFEventActNode> m_aEvent;
	map<SF_KD, SF_TEV> m_mapKdTev;

	SFEventManager();
	void doEvent(SF_TEV event);
	void doSystemEvent(UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_TIMER:
			switch (wParam)
			{
			case TMR_ACTION:
				doEvent(TEV_TMR_ACTION);
				break;
			case TMR_SKILL:
				//按键超时处理（清空键盘事件列表等）
/*				g_pP1->doTimer(TMR_SKILL);
				g_pP2->doTimer(TMR_SKILL);*/
				doEvent(TEV_TMR_SKILL);
				break;
			}
			break;
		case WM_KEYDOWN:
			switch (wParam)
			{
			case KD_P1UP:
				doEvent(TEV_KD_P1UP);
				break;
			case KD_P1LF:
				doEvent(TEV_KD_P1LF);
				break;
			case KD_P1DW:
				doEvent(TEV_KD_P1DW);
				break;
			case KD_P1RG:
				doEvent(TEV_KD_P1RG);
				break;
			case KD_P1AA:
				doEvent(TEV_KD_P1AA);
				break;
			case KD_P1BB:
				doEvent(TEV_KD_P1BB);
				break;
			case KD_P1CC:
				doEvent(TEV_KD_P1CC);
				break;
			case KD_P1DD:
				doEvent(TEV_KD_P1DD);
				break;
			case KD_P2UP:
				doEvent(TEV_KD_P2UP);
				break;
			case KD_P2LF:
				g_pP2->downEvent(EK_4);
				break;
			case KD_P2DW:
				g_pP2->downEvent(EK_2);
				break;
			case KD_P2RG:
				g_pP2->downEvent(EK_6);
				break;
			case KD_P2AA:
				g_pP2->downEvent(EK_A);
				break;
			case KD_P2BB:
				g_pP2->downEvent(EK_B);
				break;
			case KD_P2CC:
				g_pP2->downEvent(EK_C);
				break;
			case KD_P2DD:
				g_pP2->downEvent(EK_D);
				break;
			}
			result = 0;
			wasHandled = true;
			break;
		case WM_KEYUP:
			switch (wParam)
			{
			case KD_P1UP:
				g_pP1->upEvent(EK_8);
				break;
			case KD_P1LF:
				g_pP1->upEvent(EK_4);
				break;
			case KD_P1DW:
				g_pP1->upEvent(EK_2);
				break;
			case KD_P1RG:
				g_pP1->upEvent(EK_6);
				break;
			case KD_P1AA:
				g_pP1->upEvent(EK_A);
				break;
			case KD_P1BB:
				g_pP1->upEvent(EK_B);
				break;
			case KD_P1CC:
				g_pP1->upEvent(EK_C);
				break;
			case KD_P1DD:
				g_pP1->upEvent(EK_D);
				break;
			case KD_P2UP:
				g_pP2->upEvent(EK_8);
				break;
			case KD_P2LF:
				g_pP2->upEvent(EK_4);
				break;
			case KD_P2DW:
				g_pP2->upEvent(EK_2);
				break;
			case KD_P2RG:
				g_pP2->upEvent(EK_6);
				break;
			case KD_P2AA:
				g_pP2->upEvent(EK_A);
				break;
			case KD_P2BB:
				g_pP2->upEvent(EK_B);
				break;
			case KD_P2CC:
				g_pP2->upEvent(EK_C);
				break;
			case KD_P2DD:
				g_pP2->upEvent(EK_D);
				break;
			}
			result = 0;
			wasHandled = true;
			break;
		case WM_PAINT:
		{
			pWinApp->OnRender();
			ValidateRect(hwnd, NULL);
		}
			result = 0;
			wasHandled = true;
			break;
		case WM_DESTROY:
		{
			PostQuitMessage(0);
		}
			result = 1;
			wasHandled = true;
			break;
		}
	}
	}
};