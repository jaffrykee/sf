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
	UINT m_dx;
	UINT m_dy;
	UINT m_mx0;
	UINT m_my0;

	CMScene();
	~CMScene();
	void loadDataFromXml(string path);
	void onDrawByCell(UINT x = 0, UINT y = 0);
	void onDraw(FLOAT x = 0.0f, FLOAT y = 0.0f);
	void drawCenter();
	bool doEvent(SF_TEV event);
	bool doMonseEvent(UINT message, WPARAM wParam, LPARAM lParam);
};