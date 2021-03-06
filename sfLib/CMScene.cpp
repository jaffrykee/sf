﻿#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

CMDInit_T CMScene::s_initData;

#pragma region 初始化相关与通用
void CMScene::initCMBmpRes(PCWSTR path, string name)
{
	HRESULT hr = S_OK;

	hr = g_pConf->m_pWin->LoadBitmapFromFile(g_pConf->m_pWin->m_pRenderTarget, g_pConf->m_pWin->m_pWICFactory, path, 0, 0, &g_pConf->m_mapD2DBmp[name]);
	hr = g_pConf->m_pWin->m_pRenderTarget->CreateBitmapBrush(g_pConf->m_mapD2DBmp[name], &g_pConf->m_mapD2DBmpBrush[name]);

	D2D1_SIZE_F szSwd = g_pConf->m_mapD2DBmp[name]->GetSize();
	hr = g_pConf->m_pWin->m_pD2DFactory->CreateRectangleGeometry(
		D2D1::RectF(0.f, 0, szSwd.width, szSwd.height),
		(ID2D1RectangleGeometry**)(&g_pConf->m_mapPtrGeo[name]));
}

UINT CMScene::createNewAreaPath(
	D2D1_POINT_2F start,
	D2D1_POINT_2F path[],
	UINT pointsCount,
	__out ID2D1PathGeometry** ppPathD)
{
	HRESULT hr;
	ID2D1GeometrySink *pSink = NULL;

	CHECK_WIN_KILLED;
	hr = g_pConf->m_pWin->m_pD2DFactory->CreatePathGeometry(ppPathD);
	if (SUCCEEDED(hr))
	{
		hr = (*ppPathD)->Open(&pSink);
		if (SUCCEEDED(hr))
		{
			pSink->SetFillMode(D2D1_FILL_MODE_WINDING);

			pSink->BeginFigure(
				start,
				D2D1_FIGURE_BEGIN_FILLED
				);

			pSink->AddLines(path, pointsCount);
			pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
		}
		pSink->Close();
	}

	return 0;
}

UINT CMScene::initSingleArea(
	UINT i,
	UINT j,
	UINT layer,
	ID2D1Geometry* pGeo,
	ID2D1Brush* pBrush,
	D2D1::Matrix3x2F* pGeoMtx,
	D2D1::Matrix3x2F* pBrushMtx,
	bool enBorder
	)
{
	if (pGeo != NULL)
	{
		CHECK_WIN_KILLED;
		if (m_arrArrMap[i][j].m_pListArea == NULL)
		{
			m_arrArrMap[i][j].m_pListArea = new list<CMSDArea_T>;
		}
		m_arrArrMap[i][j].m_pListArea->insert(m_arrArrMap[i][j].m_pListArea->end(), {});
		CHECK_WIN_KILLED;

		if (pGeoMtx != NULL)
		{
			m_arrArrMap[i][j].m_pListArea->rbegin()->m_pGeoMtx = new D2D1::Matrix3x2F(
				D2D1::Matrix3x2F::Translation(
					m_lenCellX * i,
					m_lenCellY * (j - 0.5 * (i % 2 ? 1 : 0)) - m_arrArrMap[i][j].m_height) *
				(*pGeoMtx));
		}
		else
		{
			m_arrArrMap[i][j].m_pListArea->rbegin()->m_pGeoMtx = new D2D1::Matrix3x2F(
				D2D1::Matrix3x2F::Translation(
					m_lenCellX * i,
					m_lenCellY * (j - 0.5 * (i % 2 ? 1 : 0)) - m_arrArrMap[i][j].m_height));
		}

		m_arrArrMap[i][j].m_pListArea->rbegin()->m_layer = layer;
		m_arrArrMap[i][j].m_pListArea->rbegin()->m_pGeo = pGeo;
		m_arrArrMap[i][j].m_pListArea->rbegin()->m_pBrush = pBrush;
		m_arrArrMap[i][j].m_pListArea->rbegin()->m_pBrushMtx = pBrushMtx;
		m_arrArrMap[i][j].m_pListArea->rbegin()->m_enBorder = enBorder;
	}
}

UINT CMScene::createCenterMtx(D2D1_SIZE_F& szSwd, __inout D2D1::Matrix3x2F** ppGeoMtx)
{
	if (ppGeoMtx != NULL)
	{
		*ppGeoMtx = new D2D1::Matrix3x2F(
			D2D1::Matrix3x2F::Translation(2 * m_viewLen - szSwd.width / 2 / m_viewScaleX, sqrt(3) * m_viewLen - szSwd.height / 2 / m_viewScaleY));
	}

	return 0;
}

void CMScene::initCenterBmpRes(UINT i, UINT j, string resName)
{
	//Cell上的位图等
	D2D1_SIZE_F szSwd = g_pConf->m_mapD2DBmp[resName]->GetSize();
	D2D1::Matrix3x2F* pGeoMtx = NULL;

	createCenterMtx(szSwd, &pGeoMtx);
	initSingleArea(i, j, 1,
		g_pConf->m_mapPtrGeo[resName], g_pConf->m_mapD2DBmpBrush[resName],
		pGeoMtx, g_pConf->m_mapPtrTranslationMtx["CMScaleInverse"]);
	SafeDelete(&pGeoMtx);
}

UINT CMScene::initSingleCellCenterItems(UINT i, UINT j)
{
	ID2D1Brush* pBrush;

	pBrush = g_pConf->m_mapStrpSCBrush["NormalGray"];
	initSingleArea(i, j, 0, g_pConf->m_mapPtrGeo["cellAreaCenter"], pBrush);

	//Cell上的位图等
	if ((FLOAT)rand() < (FLOAT)RAND_MAX * 0.1)
	{
		initCenterBmpRes(i, j, "swd");
	}
	if ((FLOAT)rand() < (FLOAT)RAND_MAX * 0.1)
	{
		initCenterBmpRes(i, j, "heart");
	}

	if (m_enBorder)
	{
		//Cell的轮廓
		initSingleArea(i, j, 0, g_pConf->m_mapPtrGeo["cellAreaCenter"], NULL, NULL, NULL, m_enBorder);
	}

	return 0;
}

UINT CMScene::initSingleCell(
	LPVOID lpParam,
	UINT i,
	UINT j
	)
{
	CMDInit_T initData = *(CMDInit_T*)lpParam;

	if (initData.m_pScene->m_arrArrMap[i][j].m_pListArea == NULL)
	{
		ID2D1Brush* pBrush;
		ID2D1PathGeometry* pPathD = NULL;

		FLOAT lenX = initData.m_pScene->m_viewLen;
		FLOAT lenY = initData.m_pScene->m_viewLen;
		FLOAT dH = initData.m_pScene->m_arrArrMap[i][j].m_height - initData.m_pScene->m_minH;

		if (initData.m_pScene->m_arrArrMap[i][j].m_height != 0)
		{
			D2D1_POINT_2F dPath[4] = {};

			if (initData.m_pScene->m_perRug < 0)
			{
				dH = -dH;
			}

			if (initData.m_pScene->m_perRug >= 0)
			{
				#pragma region 凸出
				//1
				pBrush = g_pConf->m_mapStrpSCBrush["LightGray"];
				dPath[0] = D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY);
				dPath[1] = D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY + dH);
				dPath[2] = D2D1::Point2F(4 * lenX, sqrt(3) * lenY + dH);
				dPath[3] = D2D1::Point2F(4 * lenX, sqrt(3) * lenY);
				initData.m_pScene->createNewAreaPath(dPath[ARRAYSIZE(dPath) - 1], dPath, ARRAYSIZE(dPath),
					(ID2D1PathGeometry**)(&g_pConf->m_mapPtrGeo["cellAreaSurface1"]));
				initData.m_pScene->initSingleArea(i, j, 0, g_pConf->m_mapPtrGeo["cellAreaSurface1"], pBrush);

				//2
				pBrush = g_pConf->m_mapStrpSCBrush["MidGray"];
				dPath[0] = D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY);
				dPath[1] = D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY + dH);
				dPath[2] = D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY + dH);
				dPath[3] = D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY);
				initData.m_pScene->createNewAreaPath(dPath[ARRAYSIZE(dPath) - 1], dPath, ARRAYSIZE(dPath),
					(ID2D1PathGeometry**)(&g_pConf->m_mapPtrGeo["cellAreaSurface2"]));
				initData.m_pScene->initSingleArea(i, j, 0, g_pConf->m_mapPtrGeo["cellAreaSurface2"], pBrush);

				//3
				pBrush = g_pConf->m_mapStrpSCBrush["DarkGray"];
				dPath[0] = D2D1::Point2F(0 * lenX, sqrt(3) * lenY);
				dPath[1] = D2D1::Point2F(0 * lenX, sqrt(3) * lenY + dH);
				dPath[2] = D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY + dH);
				dPath[3] = D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY);
				initData.m_pScene->createNewAreaPath(dPath[ARRAYSIZE(dPath) - 1], dPath, ARRAYSIZE(dPath),
					(ID2D1PathGeometry**)(&g_pConf->m_mapPtrGeo["cellAreaSurface3"]));
				initData.m_pScene->initSingleArea(i, j, 0, g_pConf->m_mapPtrGeo["cellAreaSurface3"], pBrush);

				initData.m_pScene->initSingleCellCenterItems(i, j);
				#pragma endregion
			}
			else
			{
				#pragma region 凹陷
				initData.m_pScene->initSingleCellCenterItems(i, j);

				//4
				pBrush = g_pConf->m_mapStrpSCBrush["DarkGray"];
				dPath[0] = D2D1::Point2F(0 * lenX, sqrt(3) * lenY);
				dPath[1] = D2D1::Point2F(0 * lenX, sqrt(3) * lenY + dH);
				dPath[2] = D2D1::Point2F(1 * lenX, 0 * lenY + dH);
				dPath[3] = D2D1::Point2F(1 * lenX, 0 * lenY);
				initData.m_pScene->createNewAreaPath(dPath[ARRAYSIZE(dPath) - 1], dPath, ARRAYSIZE(dPath),
					(ID2D1PathGeometry**)(&g_pConf->m_mapPtrGeo["cellAreaSurface4"]));
				initData.m_pScene->initSingleArea(i, j, 0, g_pConf->m_mapPtrGeo["cellAreaSurface4"], pBrush);

				//5
				pBrush = g_pConf->m_mapStrpSCBrush["MidGray"];
				dPath[0] = D2D1::Point2F(1 * lenX, 0 * lenY);
				dPath[1] = D2D1::Point2F(1 * lenX, 0 * lenY + dH);
				dPath[2] = D2D1::Point2F(3 * lenX, 0 * lenY + dH);
				dPath[3] = D2D1::Point2F(3 * lenX, 0 * lenY);
				initData.m_pScene->createNewAreaPath(dPath[ARRAYSIZE(dPath) - 1], dPath, ARRAYSIZE(dPath),
					(ID2D1PathGeometry**)(&g_pConf->m_mapPtrGeo["cellAreaSurface5"]));
				initData.m_pScene->initSingleArea(i, j, 0, g_pConf->m_mapPtrGeo["cellAreaSurface5"], pBrush);

				//6
				pBrush = g_pConf->m_mapStrpSCBrush["LightGray"];
				dPath[0] = D2D1::Point2F(3 * lenX, 0 * lenY);
				dPath[1] = D2D1::Point2F(3 * lenX, 0 * lenY + dH);
				dPath[2] = D2D1::Point2F(4 * lenX, sqrt(3) * lenY + dH);
				dPath[3] = D2D1::Point2F(4 * lenX, sqrt(3) * lenY);
				initData.m_pScene->createNewAreaPath(dPath[ARRAYSIZE(dPath) - 1], dPath, ARRAYSIZE(dPath),
					(ID2D1PathGeometry**)(&g_pConf->m_mapPtrGeo["cellAreaSurface6"]));
				initData.m_pScene->initSingleArea(i, j, 0, g_pConf->m_mapPtrGeo["cellAreaSurface6"], pBrush);
				#pragma endregion
			}
		}
		else
		{
			initData.m_pScene->initSingleCellCenterItems(i, j);
		}
	}

	return 0;
}

//初始化图形
DWORD WINAPI CMScene::threadInitDraw(LPVOID lpParam)
{
	CMDInit_T initData = *(CMDInit_T*)lpParam;

	srand((unsigned)time(NULL));
	#pragma region 图形相关
	for (UINT i = 0; i < initData.m_pScene->m_arrArrMap.size(); i++)
	{
		for (UINT j = 0; j < initData.m_pScene->m_arrArrMap[i].size(); j++)
		{
			initSingleCell(lpParam, i, j);
		}
	}
	#pragma endregion

	return 0;
}

CMScene::CMScene() :
Scene()
{
	#pragma region 简单赋值
	m_isDown = false;
	m_pPathG = NULL;

	m_pMapEvent = &g_pConf->m_mapCmEvent;
	m_viewScaleX = 1.6;
	m_viewScaleY = 1;
	g_pConf->m_mapPtrTranslationMtx["CMScaleInverse"] = new D2D1::Matrix3x2F(D2D1::Matrix3x2F::Scale(m_viewScaleX, m_viewScaleY));
	g_pConf->m_mapPtrTranslationMtx["CMScaleInverse"]->Invert();

	m_viewWheelScale = 0;
	m_viewLen = 20;
	m_viewMar = 2;
	m_lenCellX = m_viewLen * 3 + sqrt(3) / 2 * m_viewMar;
	m_lenCellY = m_viewLen * 2 * sqrt(3) + m_viewMar;

	m_mx0 = -1;
	m_my0 = -1;
	m_border = 1.0f;

	m_maxX = 100;
	m_maxY = 100;
	m_enBorder = false;
	m_perEn = 1;
	m_isAdjoin = false;
	m_rugged = m_viewLen;
	//m_rugged = 0;
	m_perRug = 0.9;
	m_maxH = 1;
	m_minH = 1;
	m_unitH = 10;

	m_cX = m_maxX * m_viewScaleX * m_lenCellX - 300;
	m_cY = m_maxY * m_viewScaleY * m_lenCellY - 300;
	m_cX = 0;
	m_cY = 0;

	m_viewMouseScaleX = 1;
	m_viewMouseScaleY = 1;

	m_wheelScale = 0.00000005;
	m_wheelTime = 20;
	m_initWheelCount = 0x1ff;
	m_dWheelCount = 0x1ff;
	m_maxWheelCount = 0x355;


	HRESULT hr;
	ID2D1GeometrySink *pSink = NULL;
	ID2D1PathGeometry** ppPathD;
	D2D1_POINT_2F geoPath[6] = {};
	FLOAT lenX = m_viewLen;
	FLOAT lenY = m_viewLen;

	geoPath[0] = D2D1::Point2F(1 * lenX, 0 * lenY);
	geoPath[1] = D2D1::Point2F(3 * lenX, 0 * lenY);
	geoPath[2] = D2D1::Point2F(4 * lenX, sqrt(3) * lenY);
	geoPath[3] = D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY);
	geoPath[4] = D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY);
	geoPath[5] = D2D1::Point2F(0 * lenX, sqrt(3) * lenY);
	createNewAreaPath(geoPath[ARRAYSIZE(geoPath) - 1], geoPath, ARRAYSIZE(geoPath),
		(ID2D1PathGeometry**)(&g_pConf->m_mapPtrGeo["cellAreaCenter"]));
	#pragma endregion

	#pragma region 生成随机地图
	FLOAT ht = 0.0f;
	bool enView = true;

	m_arrArrMap = vector<vector<CMSCell_T>>(
		m_maxX,
		vector<CMSCell_T>(m_maxY, { NULL, 0, true })
		);
	srand((unsigned)time(NULL));

	for (UINT i = 0; i < m_maxX; i++)
	{
		for (UINT j = 0; j < m_maxY; j++)
		{
			FLOAT average;
			
			if (i == 0)
			{
				if (j == 0)
				{
					average = 0;
				}
				else
				{
					average = m_arrArrMap[i][j - 1].m_height;
				}
			}
			else
			{
				if (j == 0)
				{
					average = m_arrArrMap[i - 1][j].m_height;
				}
				else
				{
					if (i % 2 == 1)
					{
						//3个相邻点
						average = (m_arrArrMap[i - 1][j].m_height + m_arrArrMap[i][j - 1].m_height + m_arrArrMap[i - 1][j - 1].m_height) / 3;
					}
					else
					{
						//2个相邻点
						average = (m_arrArrMap[i - 1][j].m_height + m_arrArrMap[i][j - 1].m_height) / 2;
					}
				}
			}
			FLOAT dh = (((FLOAT)rand()) / ((FLOAT)RAND_MAX) * 2 - 1) * m_rugged;
			if (m_perRug > 0)
			{
				ht = (dh < (m_rugged * m_perRug)) ? 0 : dh + average;
			}
			else if (m_perRug < 0)
			{
				ht = (dh > (m_rugged * m_perRug)) ? 0 : dh + average;
			}
			else
			{
				ht = dh + average;
			}
			if (ht > m_maxH)
			{
				m_maxH = ht;
			}
			if (ht < m_minH)
			{
				m_minH = ht;
			}
			if (m_unitH > 0)
			{
				ht = ((INT)(ht / m_unitH)) * m_unitH;
			}
			enView = (((FLOAT)rand()) / ((FLOAT)RAND_MAX) <= m_perEn) ? true : false;
			if (m_isAdjoin == true && enView == false)
			{
				if (i != 0 && i != m_maxX && j != 0 && j != m_maxY)
				{
					if (m_arrArrMap[i - 1][j].m_enArrived != false ||
						m_arrArrMap[i - 1][j - 1].m_enArrived != false ||
						m_arrArrMap[i][j - 1].m_enArrived != false)
					{
						enView = true;
					}
				}
			}
			m_arrArrMap[i][j] = { {}, ht, enView };
		}
	}
	#pragma endregion

	m_prereadWidth = 5;
	m_prereadHeight = (m_maxH - m_minH) * 0.1 + 5;

	DWORD threadID;
	HANDLE hThread;
	s_initData = { this };
	hThread = CreateThread(NULL, 0, threadInitDraw, &s_initData, 0, &threadID);
	//WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
}

CMScene::~CMScene()
{

}

void CMScene::loadDataFromXml(string path)
{

}
#pragma endregion

#pragma region 绘制相关
void CMScene::drawCenter()
{
	double sW = g_pConf->m_pWin->m_pRenderTarget->GetSize().width;
	double sH = g_pConf->m_pWin->m_pRenderTarget->GetSize().height;
	ID2D1PathGeometry* pPathG1 = NULL;
	ID2D1PathGeometry* pPathG2 = NULL;

	HRESULT hr = g_pConf->m_pWin->m_pD2DFactory->CreatePathGeometry(&pPathG1);
	g_pConf->m_pWin->m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	if (SUCCEEDED(hr))
	{
		ID2D1GeometrySink *pSink = NULL;
		hr = pPathG1->Open(&pSink);

		if (SUCCEEDED(hr))
		{
			pSink->SetFillMode(D2D1_FILL_MODE_WINDING);

			pSink->BeginFigure(
				D2D1::Point2F(sW / 2 - 10, sH / 2),
				D2D1_FIGURE_BEGIN_FILLED
				);

			D2D1_POINT_2F points[2] = {
				D2D1::Point2F(sW / 2 + 10, sH / 2),
				D2D1::Point2F(sW / 2 - 10, sH / 2)
			};

			pSink->AddLines(points, ARRAYSIZE(points));
			pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
		}

		pSink->Close();
	}
	g_pConf->m_pWin->m_pRenderTarget->DrawGeometry(pPathG1, g_pConf->m_pWin->m_pBrushRed, 1.f);

	hr = g_pConf->m_pWin->m_pD2DFactory->CreatePathGeometry(&pPathG2);
	if (SUCCEEDED(hr))
	{
		ID2D1GeometrySink *pSink = NULL;
		hr = pPathG2->Open(&pSink);

		if (SUCCEEDED(hr))
		{
			pSink->SetFillMode(D2D1_FILL_MODE_WINDING);

			pSink->BeginFigure(
				D2D1::Point2F(sW / 2, sH / 2 - 10),
				D2D1_FIGURE_BEGIN_FILLED
				);

			D2D1_POINT_2F points[2] = {
				D2D1::Point2F(sW / 2, sH / 2 + 10),
				D2D1::Point2F(sW / 2, sH / 2 - 10)
			};

			pSink->AddLines(points, ARRAYSIZE(points));
			pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
		}

		pSink->Close();
	}
	g_pConf->m_pWin->m_pRenderTarget->DrawGeometry(pPathG2, g_pConf->m_pWin->m_pBrushRed, 1.f);
}

void CMScene::onDrawByCell(UINT x, UINT y)
{
	double sW = g_pConf->m_pWin->m_pRenderTarget->GetSize().width;
	double sH = g_pConf->m_pWin->m_pRenderTarget->GetSize().height;

	//FLOAT dx = m_lenCellX * x - (sW - m_viewLen * 4) / 2;
	FLOAT dx = m_lenCellX * x - (sW - m_lenCellX) / 2;
	FLOAT dy = (m_lenCellY * (y - 0.5 * (y % 2 ? 1 : 0)) - m_arrArrMap[x][y].m_height) - (sH - m_lenCellY) / 2;

	m_cX = dx;
	m_cY = dy;

	onDraw();
	drawCenter();
}

bool CMScene::drawSingleCell(UINT i, UINT j, UINT layer)
{
	HRESULT hr;

	if (m_arrArrMap[i][j].m_enArrived)
	{
		if (m_arrArrMap[i][j].m_pListArea == NULL || m_arrArrMap[i][j].m_pListArea->size() == 0)
		{
			//不存在则初始化
			s_initData = { this };
			initSingleCell(&s_initData, i, j);
		}
		for (list<CMSDArea_T>::iterator itListArea = m_arrArrMap[i][j].m_pListArea->begin();
			itListArea != m_arrArrMap[i][j].m_pListArea->end();
			itListArea++)
		{
			if (itListArea->m_layer == layer)
			{
				if (itListArea->m_pGeo != NULL && itListArea->m_pBrush != NULL)
				{
					if (itListArea->m_pBrushMtx != NULL)
					{
						itListArea->m_pBrush->SetTransform(itListArea->m_pBrushMtx);
					}

					if (itListArea->m_pGeoMtx != NULL)
					{
						D2D1::Matrix3x2F oldTrans;

						g_pConf->m_pWin->m_pRenderTarget->GetTransform(&oldTrans);

						g_pConf->m_pWin->m_pRenderTarget->SetTransform((*itListArea->m_pGeoMtx) * oldTrans);
						g_pConf->m_pWin->m_pRenderTarget->FillGeometry(itListArea->m_pGeo, itListArea->m_pBrush);
						g_pConf->m_pWin->m_pRenderTarget->SetTransform(oldTrans);
					}
					else
					{
						g_pConf->m_pWin->m_pRenderTarget->FillGeometry(itListArea->m_pGeo, itListArea->m_pBrush);
					}
				}
				if (m_border != 0 && itListArea->m_enBorder)
				{
					if (itListArea->m_pGeoMtx != NULL)
					{
						D2D1::Matrix3x2F oldTrans;

						g_pConf->m_pWin->m_pRenderTarget->GetTransform(&oldTrans);

						g_pConf->m_pWin->m_pRenderTarget->SetTransform((*itListArea->m_pGeoMtx) * oldTrans);
						g_pConf->m_pWin->m_pRenderTarget->DrawGeometry(itListArea->m_pGeo, g_pConf->m_mapStrpSCBrush["White"], m_border);
						g_pConf->m_pWin->m_pRenderTarget->SetTransform(oldTrans);
					}
					else
					{
						g_pConf->m_pWin->m_pRenderTarget->DrawGeometry(itListArea->m_pGeo, g_pConf->m_mapStrpSCBrush["White"], m_border);
					}
				}
			}
		}
	}

	return false;
}

//渲染世界
void CMScene::drawWorld()
{
	FLOAT sW = m_screenSize.width;
	FLOAT sH = m_screenSize.height;

	INT iLen = sW / (m_lenCellX * m_viewScaleX);
	INT jLen = sH / (m_lenCellY * m_viewScaleY);
	INT iMid = m_cX / m_lenCellX;
	INT jMid = m_cY / m_lenCellY;
	INT iMin = iMid - iLen / 2 - m_prereadWidth;
	INT jMin = jMid - jLen / 2 - m_prereadWidth;
	INT iMax = iMid + iLen / 2 + m_prereadWidth;
	INT jMax = jMid + jLen / 2 + m_prereadWidth;

	iMin = iMin < 0 ? 0 : iMin;
	jMin = jMin < 0 ? 0 : jMin;
	iMax = iMax < m_maxX ? iMax : m_maxX;
	jMax = jMax < m_maxY ? jMax : m_maxY;
	iMax = iMax < 0 ? 0 : iMax;
	jMax = jMax < 0 ? 0 : jMax;

	UINT i01 = (iMin % 2 == 1) ? iMin : iMin + 1;
	UINT i02 = (iMin % 2 == 0) ? iMin : iMin + 1;

	const D2D1::Matrix3x2F mtxSrc(
		D2D1::Matrix3x2F::Translation(-m_cX, -m_cY) *
		D2D1::Matrix3x2F::Scale(m_viewScaleX, m_viewScaleY) *
		D2D1::Matrix3x2F::Translation(sW / 2, sH / 2)
		);
	g_pConf->m_pWin->m_pRenderTarget->SetTransform(mtxSrc);
	for (UINT j = jMin; j < jMax; j++)
	{
		//todo变成线程处理，超过16列的用8线程
		for (UINT i = i01; i < iMax; i += 2)
		{
			drawSingleCell(i, j, 0);
		}
		for (UINT i = i02; i < iMax; i += 2)
		{
			drawSingleCell(i, j, 0);
		}
	}
	for (UINT j = jMin; j < jMax; j++)
	{
		//todo变成线程处理，超过16列的用8线程
		for (UINT i = i01; i < iMax; i += 2)
		{
			drawSingleCell(i, j, 1);
		}
		for (UINT i = i02; i < iMax; i += 2)
		{
			drawSingleCell(i, j, 1);
		}
	}
}

//渲染小地图
void CMScene::drawMiniMap()
{
	FLOAT sW = m_screenSize.width;
	FLOAT sH = m_screenSize.height;

#pragma region 底子
	FLOAT perRd = 0.7;
	FLOAT rdw = sW - sH * (1 - perRd);
	FLOAT rdh = sH * perRd;

	FLOAT maxPoiX = m_maxX * m_viewScaleX * m_lenCellX;
	FLOAT maxPoiY = m_maxY * m_viewScaleY * m_lenCellY;

	m_miniMap = D2D1::RectF(rdw, rdh, sW, sH);
	g_pConf->m_pWin->m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	g_pConf->m_pWin->m_pRenderTarget->DrawRectangle(m_miniMap, g_pConf->m_mapStrpSCBrush["White"], 5.0f);
	g_pConf->m_pWin->m_pRenderTarget->FillRectangle(m_miniMap, g_pConf->m_mapStrpSCBrush["Black"]);
#pragma endregion

#pragma region 地图轮廓
	FLOAT mapL, mapT, mapR, mapB;
	if (m_maxX * 2 * sqrt(3) > m_maxY * 3)
	{
		FLOAT th = (sW - rdw) * (m_maxY * 3) / (m_maxX * 2 * sqrt(3));

		mapL = rdw;
		mapT = (sH - th + rdh) / 2;
		mapR = sW;
		mapB = (sH - th + rdh) / 2 + th;
	}
	else
	{
		FLOAT tw = (sH - rdh) * (m_maxX * 2 * sqrt(3)) / (m_maxY * 3);

		mapL = (sW - tw + rdw) / 2;
		mapT = rdh;
		mapR = (sW - tw + rdw) / 2 + tw;
		mapB = sH;
	}
	m_miniMapTexture = D2D1::RectF(mapL, mapT, mapR, mapB);
	g_pConf->m_pWin->m_pRenderTarget->FillRectangle(m_miniMapTexture, g_pConf->m_mapStrpSCBrush["Blue"]);
#pragma endregion

#pragma region 地图定位
	FLOAT vMaxX = m_maxX * m_lenCellX;
	FLOAT vMaxY = m_maxY * m_lenCellY;
	FLOAT perVl = (m_cX - sW / m_viewScaleX / 2) / vMaxX;
	FLOAT perVt = (m_cY - sH / m_viewScaleY / 2) / vMaxY;
	FLOAT perVr = (m_cX + sW / m_viewScaleX / 2) / vMaxX;
	FLOAT perVb = (m_cY + sH / m_viewScaleY / 2) / vMaxY;

	g_pConf->m_pWin->m_pRenderTarget->DrawRectangle(D2D1::RectF(
		mapL + (mapR - mapL) * perVl,
		mapT + (mapB - mapT) * perVt,
		mapL + (mapR - mapL) * perVr,
		mapT + (mapB - mapT) * perVb
		), g_pConf->m_mapStrpSCBrush["White"], 1.0f);
#pragma endregion

#pragma region 坐标文字
	wstringstream ss;
	wstring wsX, wsY;
	wstring wstrPoi;
	FLOAT minTxtWid = 100;
	ss << (INT)(m_cX + sW / 2 / m_viewScaleX);
	ss >> wsX;
	ss.clear();
	ss << (INT)(m_cY + sH / 2 / m_viewScaleY);
	ss >> wsY;
	wstrPoi = L"(" + wsX + L", " + wsY + L")";

	//显示坐标
	g_pConf->m_pWin->m_pRenderTarget->DrawText(
		wstrPoi.c_str(),
		wstrPoi.length(),
		g_pConf->m_pWin->m_pTextFormat,
		D2D1::RectF(sW - minTxtWid, rdh - 15, sW, rdh),
		g_pConf->m_pWin->m_pBrushWhite
		);
#pragma endregion
}

//渲染
void CMScene::onDraw()
{
	if (m_viewWheelScale != 0)
	{
		if (m_viewWheelScale > 0)
		{
			m_viewScaleX *= (1 + m_wheelScale * m_viewWheelScale * m_viewWheelScale);
			m_viewScaleY *= (1 + m_wheelScale * m_viewWheelScale * m_viewWheelScale);
		}
		else
		{
			m_viewScaleX *= (1 - m_wheelScale * m_viewWheelScale * m_viewWheelScale);
			m_viewScaleY *= (1 - m_wheelScale * m_viewWheelScale * m_viewWheelScale);
		}

		if (m_viewWheelScale > 0)
		{
			if (m_viewWheelScale >= m_wheelTime * 3 / 2)
			{
				m_viewWheelScale = m_viewWheelScale * m_wheelTime / (m_wheelTime + 1);
			}
			else
			{
				m_viewWheelScale = 0;
			}
		}
		else
		{
			if (m_viewWheelScale <= -m_wheelTime * 3 / 2)
			{
				m_viewWheelScale = m_viewWheelScale * m_wheelTime / (m_wheelTime + 1);
			}
			else
			{
				m_viewWheelScale = 0;
			}
		}
	}
	m_screenSize = g_pConf->m_pWin->m_pRenderTarget->GetSize();
	FLOAT sW = m_screenSize.width;
	FLOAT sH = m_screenSize.height;

	g_pConf->m_pWin->m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
	g_pConf->m_pWin->m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	drawWorld();
	drawMiniMap();

	//鼠标响应
	if (m_isDown)
	{
		POINT pt;

		GetCursorPos(&pt);
		m_cX -= m_viewMouseScaleX * (pt.x - m_mx0) / m_viewScaleX;
		m_cY -= m_viewMouseScaleY * (pt.y - m_my0) / m_viewScaleY;
		m_mx0 = pt.x;
		m_my0 = pt.y;
	}
	else if (m_isMiniDown)
	{
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(g_pConf->m_pWin->m_hwnd, &pt);
		moveToPosByMiniMap(pt);
	}
}
#pragma endregion

#pragma region 响应相关
bool CMScene::doEvent(SF_TEV event)
{
	return true;
}

void CMScene::moveToPosByMiniMap(INT xPos, INT yPos)
{
	FLOAT perCx, perCy;
	FLOAT vMaxX = m_maxX * m_lenCellX;
	FLOAT vMaxY = m_maxY * m_lenCellY;
	FLOAT sW = m_screenSize.width;
	FLOAT sH = m_screenSize.height;

	m_isMiniDown = true;

	if (xPos > m_miniMapTexture.right)
	{
		xPos = m_miniMapTexture.right;
	}
	else if (xPos < m_miniMapTexture.left)
	{
		xPos = m_miniMapTexture.left;
	}
	if (yPos < m_miniMapTexture.top)
	{
		yPos = m_miniMapTexture.top;
	}
	else if (yPos > m_miniMapTexture.bottom)
	{
		yPos = m_miniMapTexture.bottom;
	}
	perCx = (xPos - m_miniMapTexture.left) / (m_miniMapTexture.right - m_miniMapTexture.left);
	perCy = (yPos - m_miniMapTexture.top) / (m_miniMapTexture.bottom - m_miniMapTexture.top);
	m_cX = vMaxX * perCx;
	m_cY = vMaxY * perCy;
}

void CMScene::moveToPosByMiniMap(POINT pos)
{
	moveToPosByMiniMap(pos.x, pos.y);
}

bool CMScene::doMouseEvent(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		{
			POINT pos;
			pos.x = GET_X_LPARAM(lParam);
			pos.y = GET_Y_LPARAM(lParam);

			if (pos.x > m_miniMap.left && pos.x < m_miniMap.right && pos.y > m_miniMap.top && pos.y < m_miniMap.bottom)
			{
				moveToPosByMiniMap(pos);
			}
			else
			{
				POINT pt;

				m_isDown = true;
				GetCursorPos(&pt);
				m_mx0 = pt.x;
				m_my0 = pt.y;
			}
		}
		break;
	case WM_LBUTTONUP:
		m_isDown = false;
		m_isMiniDown = false;
		break;
	case WM_MOUSEMOVE:
		break;
	case WM_MOUSEWHEEL:
		{
			if ((INT)wParam > 0)
			{
				if (m_viewWheelScale <= 0)
				{
					m_viewWheelScale = m_initWheelCount;
				}
				else
				{
					m_viewWheelScale = m_viewWheelScale + m_dWheelCount;
					if (m_viewWheelScale > m_maxWheelCount)
					{
						m_viewWheelScale = m_maxWheelCount;
					}
				}
			}
			else if ((INT)wParam < 0)
			{
				if (m_viewWheelScale >= 0)
				{
					m_viewWheelScale = -m_initWheelCount;
				}
				else
				{
					m_viewWheelScale = m_viewWheelScale - m_dWheelCount;
					if (m_viewWheelScale < -m_maxWheelCount)
					{
						m_viewWheelScale = -m_maxWheelCount;
					}
				}
			}
		}
		break;
	default:
		break;
	}
	return true;
}
#pragma endregion
