#pragma once
#pragma execution_character_set("utf-8")

typedef struct CMSceneMapData_S
{
	ID2D1TransformedGeometry* m_cell;
	FLOAT m_height;
	bool m_enArrived;
}CMSMData_T;

class __declspec(dllexport) CMScene
{
public:
	vector<vector<CMSMData_T>> m_arrArrMap;
	FLOAT m_viewScaleX = 1.6;
	FLOAT m_viewScaleY = 1;
	FLOAT m_viewLen = 7;
	FLOAT m_viewMar = 2;

	CMScene();
	~CMScene();
	void loadDataFromXml(string path);
	void onDrawByCell(UINT x = 0, UINT y = 0);
	void onDraw(FLOAT x = 0.0f, FLOAT y = 0.0f);
	void drawCenter();
};