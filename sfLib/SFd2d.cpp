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
}