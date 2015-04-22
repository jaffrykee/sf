#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>

using namespace std;

/******************************************************************
*                                                                 *
*  WinApp                                                         *
*                                                                 *
******************************************************************/

class WinApp
{
public:
	WinApp();
	~WinApp();

	HRESULT Initialize();

	void RunMessageLoop();

private:
	HRESULT CreateDeviceIndependentResources();
	HRESULT CreateDeviceResources();

	HRESULT CreateGridPatternBrush(
		ID2D1RenderTarget *pRenderTarget,
		ID2D1BitmapBrush **ppBitmapBrush
		);

	void DiscardDeviceResources();

	HRESULT OnRender();
	HRESULT OnHardRender();

	void OnResize(
		UINT width,
		UINT height
		);

	static LRESULT CALLBACK WndProc(
		HWND hWnd,
		UINT message,
		WPARAM wParam,
		LPARAM lParam
		);

	HRESULT LoadResourceBitmap(
		ID2D1RenderTarget *pRenderTarget,
		IWICImagingFactory *pIWICFactory,
		PCWSTR resourceName,
		PCWSTR resourceType,
		UINT destinationWidth,
		UINT destinationHeight,
		ID2D1Bitmap **ppBitmap
		);

	HRESULT LoadBitmapFromFile(
		ID2D1RenderTarget *pRenderTarget,
		IWICImagingFactory *pIWICFactory,
		PCWSTR uri,
		UINT destinationWidth,
		UINT destinationHeight,
		ID2D1Bitmap **ppBitmap
		);

private:
	HWND m_hwnd;
	ID2D1Factory *m_pD2DFactory;
	IWICImagingFactory *m_pWICFactory;
	IDWriteFactory *m_pDWriteFactory;
	ID2D1HwndRenderTarget *m_pRenderTarget;
	IDWriteTextFormat *m_pTextFormat;
	ID2D1PathGeometry *m_pPathGeometry;
	ID2D1LinearGradientBrush *m_pLinearGradientBrush;
	ID2D1SolidColorBrush *m_pBlackBrush;
	ID2D1BitmapBrush *m_pGridPatternBitmapBrush;
	ID2D1Bitmap *m_pBitmap;
	ID2D1Bitmap *m_pAnotherBitmap;

	ID2D1SolidColorBrush *m_pBlueB;
	ID2D1SolidColorBrush *m_pRedB;
};

class PActPlayer
{
public:
	D2D1_RECT_F m_body;
	FLOAT m_vx;
	FLOAT m_vy;
	string m_name;
	map<string, int> m_skill;

	PActPlayer(D2D1_RECT_F body) :m_body(body), m_vx(0), m_vy(0){}
	PActPlayer(D2D1_RECT_F body, FLOAT vx, FLOAT vy) :m_body(body), m_vx(vx), m_vy(vy){}
	PActPlayer(D2D1_RECT_F body, FLOAT vx, FLOAT vy, string name) :m_body(body), m_vx(vx), m_vy(vy), m_name(name)
	{
		if (getSkillDictionary())
		{
		}
	}

	int moveToNextFrame()
	{
		m_body.top += m_vy;
		m_body.bottom += m_vy;
		m_body.left += m_vx;
		m_body.right += m_vx;

		return 0;
	}

	float getMidX()
	{
		return (m_body.left + m_body.right) / 2.0f;
	}

	float getMidY()
	{
		return (m_body.top + m_body.bottom) / 2.0f;
	}

	bool isLeft(PActPlayer another)
	{
		if (this->getMidX() < another.getMidX())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool getSkillDictionary()
	{
		return true;
	}
};

class PActSkill
{
public:
	string m_name;
};
