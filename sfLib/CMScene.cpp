#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

typedef struct CMDrawInit_S
{
	CMScene* m_pScene;
}CMDInit_T;

#define CM_THREADINIT

//初始化图形
DWORD WINAPI threadInitDraw(LPVOID lpParam)
{
	CMDInit_T initData = *(CMDInit_T*)lpParam;

	FLOAT lenX = initData.m_pScene->m_viewLen * initData.m_pScene->m_viewScaleX;
	FLOAT lenY = initData.m_pScene->m_viewLen * initData.m_pScene->m_viewScaleY;
	FLOAT marX = initData.m_pScene->m_viewMar * initData.m_pScene->m_viewScaleX;
	FLOAT marY = initData.m_pScene->m_viewMar * initData.m_pScene->m_viewScaleY;

#pragma region 图形相关
	ID2D1PathGeometry* pPathG = NULL;

#pragma region 六边形
	HRESULT hr = g_pConf->m_pWin->m_pD2DFactory->CreatePathGeometry(&pPathG);
	if (SUCCEEDED(hr))
	{
		ID2D1GeometrySink *pSink = NULL;
		hr = pPathG->Open(&pSink);

		if (SUCCEEDED(hr))
		{
			pSink->SetFillMode(D2D1_FILL_MODE_WINDING);

			pSink->BeginFigure(
				D2D1::Point2F(0 * lenX, sqrt(3) * lenY),
				D2D1_FIGURE_BEGIN_FILLED
				);

			D2D1_POINT_2F points[6] = {
				D2D1::Point2F(1 * lenX, 0 * lenY),
				D2D1::Point2F(3 * lenX, 0 * lenY),
				D2D1::Point2F(4 * lenX, sqrt(3) * lenY),
				D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY),
				D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY),
				D2D1::Point2F(0 * lenX, sqrt(3) * lenY)
			};

			pSink->AddLines(points, ARRAYSIZE(points));
			pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
		}

		pSink->Close();
	}
#pragma endregion

	for (UINT i = 0; i < initData.m_pScene->m_arrArrMap.size(); i++)
	{
		for (UINT j = 0; j < initData.m_pScene->m_arrArrMap[i].size(); j++)
		{
			FLOAT dH = initData.m_pScene->m_arrArrMap[i][j].m_height - initData.m_pScene->m_minH;

			for (UINT k = 0; k < 4; k++)
			{
				//如果为NULL说明还没有被初始化
				if (initData.m_pScene->m_arrArrMap[i][j].m_arrpCell[k] == NULL)
				{
					if (k >= 1)
					{
						if (initData.m_pScene->m_arrArrMap[i][j].m_height != 0)
						{
#pragma region 菱形
							switch (k)
							{
							case 1:
							{
#pragma region 菱形1
								ID2D1PathGeometry* pPathD1 = NULL;

								hr = g_pConf->m_pWin->m_pD2DFactory->CreatePathGeometry(&pPathD1);
								if (SUCCEEDED(hr))
								{
									ID2D1GeometrySink *pSink = NULL;
									hr = pPathD1->Open(&pSink);

									if (SUCCEEDED(hr))
									{
										pSink->SetFillMode(D2D1_FILL_MODE_WINDING);

										pSink->BeginFigure(
											D2D1::Point2F(4 * lenX, sqrt(3) * lenY),
											D2D1_FIGURE_BEGIN_FILLED
											);

										D2D1_POINT_2F points[4] = {
											D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY),
											D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY + dH),
											D2D1::Point2F(4 * lenX, sqrt(3) * lenY + dH),
											D2D1::Point2F(4 * lenX, sqrt(3) * lenY)
										};

										pSink->AddLines(points, ARRAYSIZE(points));
										pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
									}

									pSink->Close();
								}
								hr = g_pConf->m_pWin->m_pD2DFactory->CreateTransformedGeometry(
									pPathD1,
									D2D1::Matrix3x2F::Translation(
									(3 * lenX + sqrt(3) / 2 * marX) * i,
									(2 * sqrt(3) * lenY + marY) * (j - 0.5 * (i % 2 ? 1 : 0)) - initData.m_pScene->m_arrArrMap[i][j].m_height
									),
									&initData.m_pScene->m_arrArrMap[i][j].m_arrpCell[k]
									);
#pragma endregion
							}
								break;
							case 2:
							{
#pragma region 菱形2
								ID2D1PathGeometry* pPathD2 = NULL;
								hr = g_pConf->m_pWin->m_pD2DFactory->CreatePathGeometry(&pPathD2);
								if (SUCCEEDED(hr))
								{
									ID2D1GeometrySink *pSink = NULL;
									hr = pPathD2->Open(&pSink);

									if (SUCCEEDED(hr))
									{
										pSink->SetFillMode(D2D1_FILL_MODE_WINDING);

										pSink->BeginFigure(
											D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY),
											D2D1_FIGURE_BEGIN_FILLED
											);

										D2D1_POINT_2F points[4] = {
											D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY),
											D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY + dH),
											D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY + dH),
											D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY)
										};

										pSink->AddLines(points, ARRAYSIZE(points));
										pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
									}

									pSink->Close();
								}
								hr = g_pConf->m_pWin->m_pD2DFactory->CreateTransformedGeometry(
									pPathD2,
									D2D1::Matrix3x2F::Translation(
									(3 * lenX + sqrt(3) / 2 * marX) * i,
									(2 * sqrt(3) * lenY + marY) * (j - 0.5 * (i % 2 ? 1 : 0)) - initData.m_pScene->m_arrArrMap[i][j].m_height
									),
									&initData.m_pScene->m_arrArrMap[i][j].m_arrpCell[k]
									);
#pragma endregion
							}
								break;
							case 3:
							{
#pragma region 菱形3
								ID2D1PathGeometry* pPathD3 = NULL;
								hr = g_pConf->m_pWin->m_pD2DFactory->CreatePathGeometry(&pPathD3);
								if (SUCCEEDED(hr))
								{
									ID2D1GeometrySink *pSink = NULL;
									hr = pPathD3->Open(&pSink);

									if (SUCCEEDED(hr))
									{
										pSink->SetFillMode(D2D1_FILL_MODE_WINDING);

										pSink->BeginFigure(
											D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY),
											D2D1_FIGURE_BEGIN_FILLED
											);

										D2D1_POINT_2F points[4] = {
											D2D1::Point2F(0 * lenX, sqrt(3) * lenY),
											D2D1::Point2F(0 * lenX, sqrt(3) * lenY + dH),
											D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY + dH),
											D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY)
										};

										pSink->AddLines(points, ARRAYSIZE(points));
										pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
									}

									pSink->Close();
								}
								hr = g_pConf->m_pWin->m_pD2DFactory->CreateTransformedGeometry(
									pPathD3,
									D2D1::Matrix3x2F::Translation(
									(3 * lenX + sqrt(3) / 2 * marX) * i,
									(2 * sqrt(3) * lenY + marY) * (j - 0.5 * (i % 2 ? 1 : 0)) - initData.m_pScene->m_arrArrMap[i][j].m_height
									),
									&initData.m_pScene->m_arrArrMap[i][j].m_arrpCell[k]
									);
#pragma endregion
							}
								break;
							default:
								break;
							}
#pragma endregion
						}
					}
					else
					{
						hr = g_pConf->m_pWin->m_pD2DFactory->CreateTransformedGeometry(
							pPathG,
							D2D1::Matrix3x2F::Translation(
							(3 * lenX + sqrt(3) / 2 * marX) * i,
							(2 * sqrt(3) * lenY + marY) * (j - 0.5 * (i % 2 ? 1 : 0)) - initData.m_pScene->m_arrArrMap[i][j].m_height
							),
							&initData.m_pScene->m_arrArrMap[i][j].m_arrpCell[k]
							);
					}
				}
			}
		}
	}
#pragma endregion

	return 0;
}

CMDInit_T initData;

CMScene::CMScene() :
Scene()
{
#pragma region 简单赋值
	m_isDown = false;

	m_mapEvent = &g_pConf->m_mapCmEvent;
	m_viewScaleX = 1.6;
	m_viewScaleY = 1;
	m_viewLen = 5;
	m_viewMar = 0;
	m_mx0 = -1;
	m_my0 = -1;

	m_maxX = 1000;
	m_maxY = 1000;
	m_perEn = 1;
	m_rugged = 10;
	m_perRug = 0.9f;
	m_maxH = 0;
	m_minH = 0;

	m_cX = 0;
	m_cY = 0;
#pragma endregion

#pragma region 生成随机地图
	FLOAT ht = 0.0f;
	bool enView = true;

	m_arrArrMap = vector<vector<CMSMData_T>>(
		m_maxX,
		vector<CMSMData_T>(m_maxY, {{ NULL, NULL, NULL, NULL }, 0, false })
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
			m_arrArrMap[i][j] = { { NULL, NULL, NULL, NULL }, ht, enView };
		}
	}
#pragma endregion


#pragma region 图形相关
#ifdef CM_THREADINIT
	DWORD threadID;
	HANDLE hThread;

	initData = { this };
	hThread = CreateThread(NULL, 0, threadInitDraw, &initData, 0, &threadID);
	CloseHandle(hThread);
#else
	FLOAT lenX = m_viewLen * m_viewScaleX;
	FLOAT lenY = m_viewLen * m_viewScaleY;
	FLOAT marX = m_viewMar * m_viewScaleX;
	FLOAT marY = m_viewMar * m_viewScaleY;

	ID2D1PathGeometry* pPathG = NULL;

#pragma region 六边形
	HRESULT hr = g_pConf->m_pWin->m_pD2DFactory->CreatePathGeometry(&pPathG);
	if (SUCCEEDED(hr))
	{
		ID2D1GeometrySink *pSink = NULL;
		hr = pPathG->Open(&pSink);

		if (SUCCEEDED(hr))
		{
			pSink->SetFillMode(D2D1_FILL_MODE_WINDING);

			pSink->BeginFigure(
				D2D1::Point2F(0 * lenX, sqrt(3) * lenY),
				D2D1_FIGURE_BEGIN_FILLED
				);

			D2D1_POINT_2F points[6] = {
				D2D1::Point2F(1 * lenX, 0 * lenY),
				D2D1::Point2F(3 * lenX, 0 * lenY),
				D2D1::Point2F(4 * lenX, sqrt(3) * lenY),
				D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY),
				D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY),
				D2D1::Point2F(0 * lenX, sqrt(3) * lenY)
			};

			pSink->AddLines(points, ARRAYSIZE(points));
			pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
		}

		pSink->Close();
	}
#pragma endregion

	for (UINT i = 0; i < m_arrArrMap.size(); i++)
	{
		for (UINT j = 0; j < m_arrArrMap[i].size(); j++)
		{
			FLOAT dH = m_arrArrMap[i][j].m_height - m_minH;

			for (UINT k = 0; k < 4; k++)
			{
				//如果为NULL说明还没有被初始化
				if (m_arrArrMap[i][j].m_arrpCell[k] == NULL)
				{
					if (k >= 1)
					{
						if (m_arrArrMap[i][j].m_height != 0)
						{
#pragma region 菱形
							switch (k)
							{
							case 1:
							{
#pragma region 菱形1
								ID2D1PathGeometry* pPathD1 = NULL;

								hr = g_pConf->m_pWin->m_pD2DFactory->CreatePathGeometry(&pPathD1);
								if (SUCCEEDED(hr))
								{
									ID2D1GeometrySink *pSink = NULL;
									hr = pPathD1->Open(&pSink);

									if (SUCCEEDED(hr))
									{
										pSink->SetFillMode(D2D1_FILL_MODE_WINDING);

										pSink->BeginFigure(
											D2D1::Point2F(4 * lenX, sqrt(3) * lenY),
											D2D1_FIGURE_BEGIN_FILLED
											);

										D2D1_POINT_2F points[4] = {
											D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY),
											D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY + dH),
											D2D1::Point2F(4 * lenX, sqrt(3) * lenY + dH),
											D2D1::Point2F(4 * lenX, sqrt(3) * lenY)
										};

										pSink->AddLines(points, ARRAYSIZE(points));
										pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
									}

									pSink->Close();
								}
								hr = g_pConf->m_pWin->m_pD2DFactory->CreateTransformedGeometry(
									pPathD1,
									D2D1::Matrix3x2F::Translation(
									(3 * lenX + sqrt(3) / 2 * marX) * i,
									(2 * sqrt(3) * lenY + marY) * (j - 0.5 * (i % 2 ? 1 : 0)) - m_arrArrMap[i][j].m_height
									),
									&m_arrArrMap[i][j].m_arrpCell[k]
									);
#pragma endregion
							}
								break;
							case 2:
							{
#pragma region 菱形2
								ID2D1PathGeometry* pPathD2 = NULL;
								hr = g_pConf->m_pWin->m_pD2DFactory->CreatePathGeometry(&pPathD2);
								if (SUCCEEDED(hr))
								{
									ID2D1GeometrySink *pSink = NULL;
									hr = pPathD2->Open(&pSink);

									if (SUCCEEDED(hr))
									{
										pSink->SetFillMode(D2D1_FILL_MODE_WINDING);

										pSink->BeginFigure(
											D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY),
											D2D1_FIGURE_BEGIN_FILLED
											);

										D2D1_POINT_2F points[4] = {
											D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY),
											D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY + dH),
											D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY + dH),
											D2D1::Point2F(3 * lenX, 2 * sqrt(3) * lenY)
										};

										pSink->AddLines(points, ARRAYSIZE(points));
										pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
									}

									pSink->Close();
								}
								hr = g_pConf->m_pWin->m_pD2DFactory->CreateTransformedGeometry(
									pPathD2,
									D2D1::Matrix3x2F::Translation(
									(3 * lenX + sqrt(3) / 2 * marX) * i,
									(2 * sqrt(3) * lenY + marY) * (j - 0.5 * (i % 2 ? 1 : 0)) - m_arrArrMap[i][j].m_height
									),
									&m_arrArrMap[i][j].m_arrpCell[k]
									);
#pragma endregion
							}
								break;
							case 3:
							{
#pragma region 菱形3
								ID2D1PathGeometry* pPathD3 = NULL;
								hr = g_pConf->m_pWin->m_pD2DFactory->CreatePathGeometry(&pPathD3);
								if (SUCCEEDED(hr))
								{
									ID2D1GeometrySink *pSink = NULL;
									hr = pPathD3->Open(&pSink);

									if (SUCCEEDED(hr))
									{
										pSink->SetFillMode(D2D1_FILL_MODE_WINDING);

										pSink->BeginFigure(
											D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY),
											D2D1_FIGURE_BEGIN_FILLED
											);

										D2D1_POINT_2F points[4] = {
											D2D1::Point2F(0 * lenX, sqrt(3) * lenY),
											D2D1::Point2F(0 * lenX, sqrt(3) * lenY + dH),
											D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY + dH),
											D2D1::Point2F(1 * lenX, 2 * sqrt(3) * lenY)
										};

										pSink->AddLines(points, ARRAYSIZE(points));
										pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
									}

									pSink->Close();
								}
								hr = g_pConf->m_pWin->m_pD2DFactory->CreateTransformedGeometry(
									pPathD3,
									D2D1::Matrix3x2F::Translation(
									(3 * lenX + sqrt(3) / 2 * marX) * i,
									(2 * sqrt(3) * lenY + marY) * (j - 0.5 * (i % 2 ? 1 : 0)) - m_arrArrMap[i][j].m_height
									),
									&m_arrArrMap[i][j].m_arrpCell[k]
									);
#pragma endregion
							}
								break;
							default:
								break;
							}
#pragma endregion
						}
					}
					else
					{
						hr = g_pConf->m_pWin->m_pD2DFactory->CreateTransformedGeometry(
							pPathG,
							D2D1::Matrix3x2F::Translation(
							(3 * lenX + sqrt(3) / 2 * marX) * i,
							(2 * sqrt(3) * lenY + marY) * (j - 0.5 * (i % 2 ? 1 : 0)) - m_arrArrMap[i][j].m_height
							),
							&m_arrArrMap[i][j].m_arrpCell[k]
							);
					}
				}
			}
		}
	}
#endif
#pragma endregion
}

CMScene::~CMScene()
{

}

void CMScene::loadDataFromXml(string path)
{

}

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

	FLOAT lenX = m_viewLen * m_viewScaleX;
	FLOAT lenY = m_viewLen * m_viewScaleY;
	FLOAT marX = m_viewMar * m_viewScaleX;
	FLOAT marY = m_viewMar * m_viewScaleY;

	FLOAT dx = -(3 * lenX + sqrt(3) / 2 * marX) * x + (sW - lenX * 4) / 2;
	FLOAT dy = -((2 * sqrt(3) * lenY + marY) * (y - 0.5 * (y % 2 ? 1 : 0)) - m_arrArrMap[x][y].m_height) + (sH - lenY * 2 * sqrt(3)) / 2;

	m_cX = dx;
	m_cY = dy;
	onDraw();
	drawCenter();
}

//绘制
void CMScene::onDraw()
{
	double sW = g_pConf->m_pWin->m_pRenderTarget->GetSize().width;
	double sH = g_pConf->m_pWin->m_pRenderTarget->GetSize().height;
	if (m_isDown)
	{
		POINT pt;
		RECT rect;

		GetCursorPos(&pt);
		m_cX += (pt.x - m_mx0);
		m_cY += (pt.y - m_my0);
		m_mx0 = pt.x;
		m_my0 = pt.y;
	}
	g_pConf->m_pWin->m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
	g_pConf->m_pWin->m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	INT i0 = -m_cX / (3 * m_viewLen * m_viewScaleX);
	INT j0 = -m_cY / (2 * sqrt(3) * m_viewLen * m_viewScaleY);
	INT iMax = sW / (3 * m_viewLen * m_viewScaleX) + i0 + 2;
	INT jMax = sH / (2 * sqrt(3) * m_viewLen * m_viewScaleY) + j0 + 2;

	i0 = i0 < 0 ? 0 : i0;
	j0 = j0 < 0 ? 0 : j0;
	iMax = iMax < m_maxX ? iMax : m_maxX;
	jMax = jMax < m_maxY ? jMax : m_maxY;
	iMax = iMax < 0 ? 0 : iMax;
	jMax = jMax < 0 ? 0 : jMax;

	UINT i01 = (i0 % 2 == 1) ? i0 : i0 + 1;
	UINT i02 = (i0 % 2 == 0) ? i0 : i0 + 1;

	for (UINT j = j0; j < jMax; j++)
	{
		for (UINT i = i01; i < iMax; i += 2)
		{
			if (m_arrArrMap[i][j].m_enArrived)
			{
				for (UINT k = 0; k < ARRAYSIZE(m_arrArrMap[i][j].m_arrpCell); k++)
				{
					if (m_arrArrMap[i][j].m_arrpCell[k] != NULL)
					{
						if (k >= 1)
						{
							if (m_arrArrMap[i][j].m_height != 0)
							{
								g_pConf->m_pWin->m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(m_cX, m_cY));
								g_pConf->m_pWin->m_pRenderTarget->DrawGeometry(m_arrArrMap[i][j].m_arrpCell[k], g_pConf->m_pWin->m_pBrushWhite, 1.f);
								g_pConf->m_pWin->m_pRenderTarget->FillGeometry(m_arrArrMap[i][j].m_arrpCell[k], g_pConf->m_pWin->m_pBrushBlueHalf);
							}
						}
						else
						{
							g_pConf->m_pWin->m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(m_cX, m_cY));
							g_pConf->m_pWin->m_pRenderTarget->DrawGeometry(m_arrArrMap[i][j].m_arrpCell[k], g_pConf->m_pWin->m_pBrushWhite, 1.f);
							g_pConf->m_pWin->m_pRenderTarget->FillGeometry(m_arrArrMap[i][j].m_arrpCell[k], g_pConf->m_pWin->m_pBrushBlue);
						}
					}
				}
			}
		}
		for (UINT i = i02; i < iMax; i += 2)
		{
			if (m_arrArrMap[i][j].m_enArrived)
			{
				for (UINT k = 0; k < ARRAYSIZE(m_arrArrMap[i][j].m_arrpCell); k++)
				{
					if (m_arrArrMap[i][j].m_arrpCell[k] != NULL)
					{
						if (k >= 1)
						{
							if (m_arrArrMap[i][j].m_height != 0)
							{
								g_pConf->m_pWin->m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(m_cX, m_cY));
								g_pConf->m_pWin->m_pRenderTarget->DrawGeometry(m_arrArrMap[i][j].m_arrpCell[k], g_pConf->m_pWin->m_pBrushWhite, 1.f);
								g_pConf->m_pWin->m_pRenderTarget->FillGeometry(m_arrArrMap[i][j].m_arrpCell[k], g_pConf->m_pWin->m_pBrushBlueHalf);
							}
						}
						else
						{
							g_pConf->m_pWin->m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(m_cX, m_cY));
							g_pConf->m_pWin->m_pRenderTarget->DrawGeometry(m_arrArrMap[i][j].m_arrpCell[k], g_pConf->m_pWin->m_pBrushWhite, 1.f);
							g_pConf->m_pWin->m_pRenderTarget->FillGeometry(m_arrArrMap[i][j].m_arrpCell[k], g_pConf->m_pWin->m_pBrushBlue);
						}
					}
				}
			}
		}
	}
}

bool CMScene::doEvent(SF_TEV event)
{
	return true;
}

bool CMScene::doMonseEvent(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		{
			POINT pt;

			m_isDown = true;
			GetCursorPos(&pt);
			m_mx0 = pt.x;
			m_my0 = pt.y;
		}
		break;
	case WM_LBUTTONUP:
		m_isDown = false;
		break;
	case WM_MOUSEMOVE:
		break;
	default:
		break;
	}
	return true;
}
