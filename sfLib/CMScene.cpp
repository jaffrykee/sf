#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

CMDInit_T CMScene::s_initData;

#pragma region 初始化相关与通用
UINT CMScene::initSingleArea(
	D2D1_POINT_2F start,
	D2D1_POINT_2F path[],
	UINT pointsCount,
	UINT i,
	UINT j,
	__inout ID2D1PathGeometry** ppPathD,
	ID2D1Brush* pBrush,
	bool enBorder
	)
{
	HRESULT hr;

	if (*ppPathD == NULL)
	{
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
	}
	if (*ppPathD != NULL)
	{
		CHECK_WIN_KILLED;
		if (m_arrArrMap[i][j].m_pListArea == NULL)
		{
			m_arrArrMap[i][j].m_pListArea = new list<CMSDArea_T>;
		}
		m_arrArrMap[i][j].m_pListArea->insert(m_arrArrMap[i][j].m_pListArea->end(), {});
		hr = g_pConf->m_pWin->m_pD2DFactory->CreateTransformedGeometry(
				*ppPathD,
				D2D1::Matrix3x2F::Translation(
					(3 * m_viewLen + sqrt(3) / 2 * m_viewMar) * i,
					(2 * sqrt(3) * m_viewLen + m_viewMar) * (j - 0.5 * (i % 2 ? 1 : 0)) - m_arrArrMap[i][j].m_height
				),
				&m_arrArrMap[i][j].m_pListArea->rbegin()->m_geo
			);
		m_arrArrMap[i][j].m_pListArea->rbegin()->m_brush = pBrush;
		m_arrArrMap[i][j].m_pListArea->rbegin()->m_enBorder = enBorder;
	}
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

#pragma region 菱形
		if (initData.m_pScene->m_arrArrMap[i][j].m_height != 0)
		{
			D2D1_POINT_2F dPath[4] = {};

			//1
			pBrush = g_pConf->m_mapStrpSCBrush["LightGray"];
			dPath[0] = D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY);
			dPath[1] = D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY + dH);
			dPath[2] = D2D1::Point2F(4 * lenX, sqrt(3) * lenY + dH);
			dPath[3] = D2D1::Point2F(4 * lenX, sqrt(3) * lenY);
			initData.m_pScene->initSingleArea(dPath[ARRAYSIZE(dPath) - 1], dPath, ARRAYSIZE(dPath), i, j, &pPathD, pBrush);
			SafeRelease(&pPathD);

			//2
			pBrush = g_pConf->m_mapStrpSCBrush["MidGray"];
			dPath[0] = D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY);
			dPath[1] = D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY + dH);
			dPath[2] = D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY + dH);
			dPath[3] = D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY);
			initData.m_pScene->initSingleArea(dPath[ARRAYSIZE(dPath) - 1], dPath, ARRAYSIZE(dPath), i, j, &pPathD, pBrush);
			SafeRelease(&pPathD);

			//3
			pBrush = g_pConf->m_mapStrpSCBrush["DarkGray"];
			dPath[0] = D2D1::Point2F(0 * lenX, sqrt(3) * lenY);
			dPath[1] = D2D1::Point2F(0 * lenX, sqrt(3) * lenY + dH);
			dPath[2] = D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY + dH);
			dPath[3] = D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY);
			initData.m_pScene->initSingleArea(dPath[ARRAYSIZE(dPath) - 1], dPath, ARRAYSIZE(dPath), i, j, &pPathD, pBrush);
			SafeRelease(&pPathD);

#ifdef CMMIR
			//4
			pBrush = g_pConf->m_mapStrpSCBrush["DarkGray"];
			dPath[0] = D2D1::Point2F(0 * lenX, sqrt(3) * lenY);
			dPath[1] = D2D1::Point2F(0 * lenX, sqrt(3) * lenY + dH);
			dPath[2] = D2D1::Point2F(1 * lenX, 0 * lenY + dH);
			dPath[3] = D2D1::Point2F(1 * lenX, 0 * lenY);
			initData.m_pScene->initSingleArea(dPath[ARRAYSIZE(dPath) - 1], dPath, ARRAYSIZE(dPath), i, j, &pPathD, pBrush);
			SafeRelease(&pPathD);

			//5
			pBrush = g_pConf->m_mapStrpSCBrush["MidGray"];
			dPath[0] = D2D1::Point2F(1 * lenX, 0 * lenY);
			dPath[1] = D2D1::Point2F(1 * lenX, 0 * lenY + dH);
			dPath[2] = D2D1::Point2F(3 * lenX, 0 * lenY + dH);
			dPath[3] = D2D1::Point2F(3 * lenX, 0 * lenY);
			initData.m_pScene->initSingleArea(dPath[ARRAYSIZE(dPath) - 1], dPath, ARRAYSIZE(dPath), i, j, &pPathD, pBrush);
			SafeRelease(&pPathD);

			//6
			pBrush = g_pConf->m_mapStrpSCBrush["LightGray"];
			dPath[0] = D2D1::Point2F(3 * lenX, 0 * lenY);
			dPath[1] = D2D1::Point2F(3 * lenX, 0 * lenY + dH);
			dPath[2] = D2D1::Point2F(4 * lenX, sqrt(3) * lenY + dH);
			dPath[3] = D2D1::Point2F(4 * lenX, sqrt(3) * lenY);
			initData.m_pScene->initSingleArea(dPath[ARRAYSIZE(dPath) - 1], dPath, ARRAYSIZE(dPath), i, j, &pPathD, pBrush);
			SafeRelease(&pPathD);
#endif
		}
#pragma endregion

#pragma region 六边形
		D2D1_POINT_2F gPath[6] = {};
		pBrush = g_pConf->m_mapStrpSCBrush["NormalGray"];

		gPath[0] = D2D1::Point2F(1 * lenX, 0 * lenY);
		gPath[1] = D2D1::Point2F(3 * lenX, 0 * lenY);
		gPath[2] = D2D1::Point2F(4 * lenX, sqrt(3) * lenY);
		gPath[3] = D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY);
		gPath[4] = D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY);
		gPath[5] = D2D1::Point2F(0 * lenX, sqrt(3) * lenY);
		initData.m_pScene->initSingleArea(gPath[ARRAYSIZE(gPath) - 1], gPath, ARRAYSIZE(gPath), i, j, &initData.m_pScene->m_pPathG, pBrush, true);
#pragma endregion
	}


	return 0;
}

//初始化图形
DWORD WINAPI CMScene::threadInitDraw(LPVOID lpParam)
{
	CMDInit_T initData = *(CMDInit_T*)lpParam;

	FLOAT lenX = initData.m_pScene->m_viewLen;
	FLOAT lenY = initData.m_pScene->m_viewLen;
	FLOAT marX = initData.m_pScene->m_viewMar;
	FLOAT marY = initData.m_pScene->m_viewMar;

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
	m_viewWheelScale = 1.1;
	m_viewLen = 5;
	m_viewMar = 0;
	m_mx0 = -1;
	m_my0 = -1;
	m_border = 1.0f;

	m_maxX = 1000;
	m_maxY = 1000;
	m_perEn = 1;
	m_rugged = m_viewLen;
	m_perRug = 0.5;
	m_maxH = 0;
	m_minH = 0;

	m_cX = m_maxX * m_viewScaleX * m_viewLen * 3 - 300;
	m_cY = m_maxY * m_viewScaleY * m_viewLen * 2 * sqrt(3) - 300;
	m_cX = 0;
	m_cY = 0;

	m_viewMouseScaleX = 1;
	m_viewMouseScaleY = 1;
	#pragma endregion

	#pragma region 生成随机地图
	FLOAT ht = 0.0f;
	bool enView = true;

	m_arrArrMap = vector<vector<CMSCell_T>>(
		m_maxX,
		vector<CMSCell_T>(m_maxY, { NULL, 0, false })
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
			enView = (((FLOAT)rand()) / ((FLOAT)RAND_MAX) <= m_perEn) ? true : false;
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

	FLOAT lenX = m_viewLen;
	FLOAT lenY = m_viewLen;
	FLOAT marX = m_viewMar;
	FLOAT marY = m_viewMar;

	FLOAT dx = (3 * lenX + sqrt(3) / 2 * marX) * x - (sW - lenX * 4) / 2;
	FLOAT dy = ((2 * sqrt(3) * lenY + marY) * (y - 0.5 * (y % 2 ? 1 : 0)) - m_arrArrMap[x][y].m_height) - (sH - lenY * 2 * sqrt(3)) / 2;

	m_cX = dx;
	m_cY = dy;

	onDraw();
	drawCenter();
}

void CMScene::drawSingleCell(UINT i, UINT j)
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
		for (
			list<CMSDArea_T>::iterator itListArea = m_arrArrMap[i][j].m_pListArea->begin();
			itListArea != m_arrArrMap[i][j].m_pListArea->end(); itListArea++)
		{
			g_pConf->m_pWin->m_pRenderTarget->FillGeometry(itListArea->m_geo, itListArea->m_brush);
			if (m_border != 0 && itListArea->m_enBorder)
			{
				g_pConf->m_pWin->m_pRenderTarget->DrawGeometry(itListArea->m_geo, g_pConf->m_mapStrpSCBrush["White"], m_border);
			}
		}
	}
}

//渲染世界
void CMScene::drawWorld()
{
	FLOAT sW = m_screenSize.width;
	FLOAT sH = m_screenSize.height;
	INT i0 = m_cX / (3 * m_viewLen) - m_prereadWidth;
	INT j0 = m_cY / (2 * sqrt(3) * m_viewLen) - m_prereadHeight;
	INT iMax = sW / (3 * m_viewLen * m_viewScaleX) + i0 + m_prereadWidth * 2;
	INT jMax = sH / (2 * sqrt(3) * m_viewLen * m_viewScaleY) + j0 + m_prereadHeight * 2;

	i0 = i0 < 0 ? 0 : i0;
	j0 = j0 < 0 ? 0 : j0;
	iMax = iMax < m_maxX ? iMax : m_maxX;
	jMax = jMax < m_maxY ? jMax : m_maxY;
	iMax = iMax < 0 ? 0 : iMax;
	jMax = jMax < 0 ? 0 : jMax;

	UINT i01 = (i0 % 2 == 1) ? i0 : i0 + 1;
	UINT i02 = (i0 % 2 == 0) ? i0 : i0 + 1;

	g_pConf->m_pWin->m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(-m_cX, -m_cY) * D2D1::Matrix3x2F::Scale(m_viewScaleX, m_viewScaleY));
	for (UINT j = j0; j < jMax; j++)
	{
		for (UINT i = i01; i < iMax; i += 2)
		{
			drawSingleCell(i, j);
		}
		for (UINT i = i02; i < iMax; i += 2)
		{
			drawSingleCell(i, j);
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

	FLOAT maxPoiX = m_maxX * m_viewScaleX * m_viewLen * 3;
	FLOAT maxPoiY = m_maxY * m_viewScaleY * m_viewLen * 2 * sqrt(3);

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
	FLOAT vMaxX = m_maxX * m_viewLen * 3;
	FLOAT vMaxY = m_maxY * m_viewLen * 2 * sqrt(3);
	FLOAT perVl = m_cX / vMaxX;
	FLOAT perVt = m_cY / vMaxY;
	FLOAT perVr = (m_cX + sW / m_viewScaleX) / vMaxX;
	FLOAT perVb = (m_cY + sH / m_viewScaleY) / vMaxY;

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
	FLOAT vMaxX = m_maxX * m_viewLen * 3;
	FLOAT vMaxY = m_maxY * m_viewLen * 2 * sqrt(3);
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
	m_cX = vMaxX * perCx - sW / m_viewScaleX / 2;
	m_cY = vMaxY * perCy - sH / m_viewScaleY / 2;
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
		if ((INT)wParam > 0)
		{
			m_viewScaleX *= m_viewWheelScale;
			m_viewScaleY *= m_viewWheelScale;
		}
		else if ((INT)wParam < 0)
		{
			m_viewScaleX /= m_viewWheelScale;
			m_viewScaleY /= m_viewWheelScale;
		}
		break;
	default:
		break;
	}
	return true;
}
#pragma endregion
