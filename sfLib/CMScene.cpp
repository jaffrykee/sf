#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

CMScene::CMScene() :
Scene(),
m_arrArrMap(
{
	{
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 0, true }
	},
	{
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 0, true }
	},
	{
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 5, true },
		{ NULL, 0, true },
		{ NULL, 0, true }
	},
	{
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 0, true },
		{ NULL, 12, true },
		{ NULL, 0, true }
	}
}
)
{
	ID2D1PathGeometry* pPathG = NULL;
	HRESULT hr = g_pConf->m_pWin->m_pD2DFactory->CreatePathGeometry(&pPathG);
	m_isDown = false;

	m_mapEvent = &g_pConf->m_mapCmEvent;
	m_viewScaleX = 1.6;
	m_viewScaleY = 1;
	m_viewLen = 7;
	m_viewMar = 0;
	m_cX = 0;
	m_cY = 0;
	m_mx0 = -1;
	m_my0 = -1;

	FLOAT lenX = m_viewLen * m_viewScaleX;
	FLOAT lenY = m_viewLen * m_viewScaleY;
	FLOAT marX = m_viewMar * m_viewScaleX;
	FLOAT marY = m_viewMar * m_viewScaleY;

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

	for (UINT i = 0; i < m_arrArrMap.size(); i++)
	{
		for (UINT j = 0; j < m_arrArrMap[i].size(); j++)
		{
			hr = g_pConf->m_pWin->m_pD2DFactory->CreateTransformedGeometry(
				pPathG,
				D2D1::Matrix3x2F::Translation(
				(3 * lenX + sqrt(3) / 2 * marX) * i,
				(2 * sqrt(3) * lenY + marY) * (j - 0.5 * (i % 2 ? 1 : 0)) - m_arrArrMap[i][j].m_height
				),
				&m_arrArrMap[i][j].m_cell
				);
		}
	}
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
	for (UINT i = 0; i < m_arrArrMap.size(); i++)
	{
		for (UINT j = 0; j < m_arrArrMap[i].size(); j++)
		{
			g_pConf->m_pWin->m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(m_cX, m_cY));
			g_pConf->m_pWin->m_pRenderTarget->DrawGeometry(m_arrArrMap[i][j].m_cell, g_pConf->m_pWin->m_pBrushWhite, 1.f);
			g_pConf->m_pWin->m_pRenderTarget->FillGeometry(m_arrArrMap[i][j].m_cell, g_pConf->m_pWin->m_pBrushBlue);
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