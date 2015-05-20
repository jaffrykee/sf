#pragma once
#pragma execution_character_set("utf-8")

typedef struct CMSceneMapData_S
{
	ID2D1TransformedGeometry* m_arrpCell[4];
	FLOAT m_height;
	bool m_enArrived;
}CMSMData_T;

typedef struct CMDrawInit_S
{
	CMScene* m_pScene;
}CMDInit_T;

class __declspec(dllexport) CMScene : public Scene
{
public:
	vector<vector<CMSMData_T>> m_arrArrMap;
	FLOAT m_viewScaleX;
	FLOAT m_viewScaleY;
	FLOAT m_viewWheelScale;
	FLOAT m_viewLen;
	FLOAT m_viewMar;
	FLOAT m_cX;
	FLOAT m_cY;

	D2D1_SIZE_F m_screenSize;
	D2D1_RECT_F m_miniMap;
	D2D1_RECT_F m_miniMapTexture;

	bool m_isDown;
	bool m_isMiniDown;
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
	FLOAT m_prereadWidth;
	FLOAT m_prereadHeight;
	//六边形
	ID2D1PathGeometry* m_pPathG;

	CMScene();
	~CMScene();
	void loadDataFromXml(string path);
	void onDrawByCell(UINT x = 0, UINT y = 0);
	void drawSingleCell(UINT i, UINT j);
	void onDraw();
	void drawWorld();
	void drawMiniMap();
	void drawCenter();
	bool doEvent(SF_TEV event);
	bool doMouseEvent(UINT message, WPARAM wParam, LPARAM lParam);
	void moveToPosByMiniMap(INT xPos, INT yPos);
	void moveToPosByMiniMap(POINT pos);

public:
	static CMDInit_T s_initData;

	//初始化线程
	static DWORD WINAPI threadInitDraw(LPVOID lpParam);
	//初始化单个元素
	static UINT initSingleCell(LPVOID lpParam, UINT i, UINT j);
};