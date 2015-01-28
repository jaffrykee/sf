#pragma once
#pragma execution_character_set("utf-8")

//系统事件接收器，用于隔离系统事件与真实事件。
class __declspec(dllexport) SFEventManager
{
	class SFUIScene{};

	struct SFEventUINode
	{
		SFUIScene* m_pScene;
		SF_TEV m_trueEvent;
		vector<int> m_arrInt;
		vector<string> m_arrStr;
	};
public:
	MapEventGroup_T* m_pMapEvent;
	SFActScene* m_pActiveScene;
	map<SF_KD, SF_TEV> m_mapKdTev;

	SFEventManager();
	bool setActiveScene(SFActScene* pScene);
	bool doEvent(SF_TEV event, LPARAM lParam);
	bool doSystemEvent(UINT message, WPARAM wParam, LPARAM lParam);
};