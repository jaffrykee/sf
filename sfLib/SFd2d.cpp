#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

namespace SFd2d
{
	D2D1_RECT_F moveRect(D2D1_RECT_F srcRect, D2D1_POINT_2F point)
	{
		D2D1_RECT_F dstRect = srcRect;

		dstRect.top = srcRect.top + point.y;
		dstRect.bottom = srcRect.bottom + point.y;
		dstRect.left = srcRect.left + point.x;
		dstRect.right = srcRect.right + point.x;

		return dstRect;
	}

	D2D1_POINT_2F getScenePoiFromView(ID2D1HwndRenderTarget* pRenderTarget, D2D1_POINT_2F vPoi)
	{
		D2D1_POINT_2F ret;

		ret.x = vPoi.x*(g_pConf->m_viewBenchmark.width / pRenderTarget->GetSize().width);
		ret.y = vPoi.y*(g_pConf->m_viewBenchmark.height / pRenderTarget->GetSize().height);
		return ret;
	}

	D2D1_RECT_F getSceneRectFromView(ID2D1HwndRenderTarget* pRenderTarget, D2D1_RECT_F vRect)
	{
		D2D1_RECT_F ret;

		ret.top = vRect.top*(g_pConf->m_viewBenchmark.height / pRenderTarget->GetSize().height);
		ret.left = vRect.left*(g_pConf->m_viewBenchmark.width / pRenderTarget->GetSize().width);
		ret.bottom = vRect.bottom*(g_pConf->m_viewBenchmark.height / pRenderTarget->GetSize().height);
		ret.right = vRect.right*(g_pConf->m_viewBenchmark.width / pRenderTarget->GetSize().width);
		return ret;
	}

	D2D1_POINT_2F getViewPoiFromScene(ID2D1HwndRenderTarget* pRenderTarget, D2D1_POINT_2F sPoi)
	{
		D2D1_POINT_2F ret;

		ret.x = sPoi.x*(pRenderTarget->GetSize().width / g_pConf->m_viewBenchmark.width);
		ret.y = sPoi.y*(pRenderTarget->GetSize().height / g_pConf->m_viewBenchmark.height);
		return ret;
	}

	D2D1_RECT_F getViewRectFromScene(ID2D1HwndRenderTarget* pRenderTarget, D2D1_RECT_F sRect)
	{
		D2D1_RECT_F ret;

		ret.top = sRect.top*(pRenderTarget->GetSize().height / g_pConf->m_viewBenchmark.height);
		ret.left = sRect.left*(pRenderTarget->GetSize().width / g_pConf->m_viewBenchmark.width);
		ret.bottom = sRect.bottom*(pRenderTarget->GetSize().height / g_pConf->m_viewBenchmark.height);
		ret.right = sRect.right*(pRenderTarget->GetSize().width / g_pConf->m_viewBenchmark.width);
		return ret;
	}
}