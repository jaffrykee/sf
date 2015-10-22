#pragma once
#pragma execution_character_set("utf-8")

typedef struct CMSceneDrawArea_S
{
	ID2D1Geometry* m_pGeo = NULL;
	D2D1::Matrix3x2F* m_pGeoMtx = NULL;
	ID2D1Brush* m_pBrush = NULL;
	D2D1::Matrix3x2F* m_pBrushMtx = NULL;
	bool m_enBorder = false;
	UINT m_layer = 0;
}CMSDArea_T;

typedef struct CMSceneCell_S
{
	list<CMSDArea_T>* m_pListArea;
	FLOAT m_height;
	bool m_enArrived;
}CMSCell_T;

typedef struct CMDrawInit_S
{
	CMScene* m_pScene;
}CMDInit_T;

typedef enum CM_BmpDrawType
{
	BDT_GROUND,
	BDT_CENTER,
	BDT_MAX
};

class __declspec(dllexport) CMScene : public Scene
{
public:
	vector<vector<CMSCell_T>> m_arrArrMap;
	FLOAT m_viewScaleX;
	FLOAT m_viewScaleY;
	//滚动计数
	INT m_viewWheelScale;
	//滚动缩放倍数
	FLOAT m_wheelScale;
	//滚动延时
	INT m_wheelTime;
	//滚轮初始计数
	INT m_initWheelCount;
	//滚轮计数差
	INT m_dWheelCount;
	//最大计数
	INT m_maxWheelCount;

	FLOAT m_viewLen;
	FLOAT m_viewMar;
	FLOAT m_lenCellX;
	FLOAT m_lenCellY;
	
	FLOAT m_cX;
	FLOAT m_cY;
	FLOAT m_border;

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
	//不可通行是否要连续
	bool m_isAdjoin;
	//崎岖度
	FLOAT m_rugged;
	//崎岖阀值（正负1之间）
	FLOAT m_perRug;
	FLOAT m_maxH;
	FLOAT m_minH;
	//单位高度，为0的话则没有
	FLOAT m_unitH;
	FLOAT m_viewMouseScaleX;
	FLOAT m_viewMouseScaleY;
	FLOAT m_prereadWidth;
	FLOAT m_prereadHeight;
	//六边形
	ID2D1PathGeometry* m_pPathG;
	bool m_enBorder;

	CMScene();
	~CMScene();
	void loadDataFromXml(string path);
	void onDrawByCell(UINT x = 0, UINT y = 0);
	bool drawSingleCell(UINT i, UINT j, UINT layer = 0);
	void onDraw();
	void drawWorld();
	void drawMiniMap();
	void drawCenter();
	bool doEvent(SF_TEV event);
	bool doMouseEvent(UINT message, WPARAM wParam, LPARAM lParam);
	void moveToPosByMiniMap(INT xPos, INT yPos);
	void moveToPosByMiniMap(POINT pos);

	UINT createNewAreaPath(
		D2D1_POINT_2F start,
		D2D1_POINT_2F path[],
		UINT pointsCount,
		__out ID2D1PathGeometry** ppPathD);
	UINT initSingleArea(
		UINT i,
		UINT j,
		UINT layer,
		ID2D1Geometry* pGeo,
		ID2D1Brush* pBrush,
		D2D1::Matrix3x2F* pGeoMtx = NULL,
		D2D1::Matrix3x2F* pBrushMtx = NULL,
		bool enBorder = false
		);
	UINT initSingleCellCenterItems(UINT i, UINT j);
	void initCenterBmpRes(UINT i, UINT j, string resName, CM_BmpDrawType drawType = BDT_GROUND);
	UINT createCenterMtx(D2D1_SIZE_F& szSwd, __inout D2D1::Matrix3x2F** ppGeoMtx, CM_BmpDrawType drawType = BDT_GROUND);
	void initCMBmpRes(PCWSTR path, string name);

public:
	static CMDInit_T s_initData;

	//初始化线程
	static DWORD WINAPI threadInitDraw(LPVOID lpParam);
	//初始化单个元素
	static UINT initSingleCell(LPVOID lpParam, UINT i, UINT j);
};