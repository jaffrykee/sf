#pragma once
#pragma execution_character_set("utf-8")

typedef struct CMSceneMapData_S
{
	ID2D1TransformedGeometry* m_cell;
	FLOAT m_height;
	bool m_enArrived;
}CMSMData_T;

class __declspec(dllexport) CMScene : public Scene
{
public:
	vector<vector<CMSMData_T>> m_arrArrMap;
	FLOAT m_viewScaleX;
	FLOAT m_viewScaleY;
	FLOAT m_viewLen;
	FLOAT m_viewMar;
	FLOAT m_cX;
	FLOAT m_cY;

	bool m_isDown;
	FLOAT m_mx0;
	FLOAT m_my0;

	CMScene();
	~CMScene();
	void loadDataFromXml(string path);
	void onDrawByCell(UINT x = 0, UINT y = 0);
	void onDraw();
	void drawCenter();
	bool doEvent(SF_TEV event);
	bool doMonseEvent(UINT message, WPARAM wParam, LPARAM lParam);
};