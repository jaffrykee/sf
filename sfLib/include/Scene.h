#pragma once
#pragma execution_character_set("utf-8")

class __declspec(dllexport) Scene
{
public:
	MapEventGroup_T* m_pMapEvent;

	Scene();
	~Scene();
	bool doEvent(SF_TEV event);
	virtual bool doMouseEvent(UINT message, WPARAM wParam, LPARAM lParam);
	virtual void onDraw();
};