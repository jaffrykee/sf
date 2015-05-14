#pragma once
#pragma execution_character_set("utf-8")

typedef struct CMSceneMapData_S
{
	ID2D1TransformedGeometry* m_arrpCell[4];
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

	//地图宽
	UINT m_maxX;
	//地图长
	UINT m_maxY;
	//可通行率
	FLOAT m_perEn;
	//崎岖度
	FLOAT m_rugged;
	//崎岖阀值（正负1之间）
	FLOAT m_perRug;
	FLOAT m_maxH;
	FLOAT m_minH;
	FLOAT m_viewMouseScaleX;
	FLOAT m_viewMouseScaleY;

	CMScene();
	~CMScene();
	void loadDataFromXml(string path);
	void onDrawByCell(UINT x = 0, UINT y = 0);
	void onDraw();
	void drawCenter();
	bool doEvent(SF_TEV event);
	bool doMonseEvent(UINT message, WPARAM wParam, LPARAM lParam);
};