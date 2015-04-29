#pragma once
#pragma execution_character_set("utf-8")

namespace SFd2d
{
	D2D1_RECT_F _declspec(dllexport) moveRect(D2D1_RECT_F srcRect, D2D1_POINT_2F point);
	D2D1_POINT_2F getScenePoiFromView(ID2D1HwndRenderTarget* pRenderTarget, D2D1_POINT_2F vPoi);
	D2D1_RECT_F getSceneRectFromView(ID2D1HwndRenderTarget* pRenderTarget, D2D1_RECT_F vRect);
	D2D1_POINT_2F getViewPoiFromScene(ID2D1HwndRenderTarget* pRenderTarget, D2D1_POINT_2F sPoi);
	D2D1_RECT_F getViewRectFromScene(ID2D1HwndRenderTarget* pRenderTarget, D2D1_RECT_F sRect);
}