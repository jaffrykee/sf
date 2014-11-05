#pragma execution_character_set("utf-8")
#include <sf.h>

#pragma region 显示坐标define
#define ACT_WID 640
#define ACT_HIG 480

#define ACT_REALWID ((float)(ACT_WID) - (FRA_X))
#define ACT_REALHIG ((float)(ACT_HIG) - (FRA_Y))

#define BODY_W ((ACT_REALWID) * 0.095f)
#define BODY_H ((ACT_REALHIG) * 0.32f)
//窗口边框补差
#define FRA_X (18.f)
#define FRA_Y (40.f)

//顶部菜单高度
#define TOP_Y (40.f)
//地面
#define BTN_Y ((ACT_REALHIG) * 0.83f)
#define INIT_LX1 ((ACT_REALWID) * 0.2f)
#define INIT_LY1 ((INIT_LY2) - (BODY_H))
#define INIT_LX2 ((INIT_LX1) + (BODY_W))
#define INIT_LY2 (BTN_Y)
#define INIT_RX1 ((ACT_REALWID) * 0.7f)
#define INIT_RY1 ((INIT_RY2) - BODY_H)
#define INIT_RX2 ((INIT_RX1) + BODY_W)
#define INIT_RY2 (BTN_Y)
#pragma endregion 

#pragma region 按键设置define
#define ACT_K1UP	VK_W
#define ACT_K1LF	VK_A
#define ACT_K1DW	VK_S
#define ACT_K1RG	VK_D
#define ACT_K1AA	VK_U
#define ACT_K1BB	VK_I
#define ACT_K1CC	VK_O
#define ACT_K1DD	VK_J
#define ACT_K1EE	VK_K
#define ACT_K1FF	VK_L
#define ACT_K1ST	VK_1
#define ACT_K1MN	VK_2

#define ACT_K2UP	VK_UP
#define ACT_K2LF	VK_LEFT
#define ACT_K2DW	VK_DOWN
#define ACT_K2RG	VK_RIGHT
#define ACT_K2AA	VK_NUMPAD1
#define ACT_K2BB	VK_NUMPAD2
#define ACT_K2CC	VK_NUMPAD3
#define ACT_K2DD	VK_NUMPAD0
#define ACT_K2EE	VK_NUMPAD5
#define ACT_K2FF	VK_NUMPAD6
#define ACT_K2ST	VK_3
#define ACT_K2MN	VK_4
#pragma endregion

#pragma region 计时器define
#pragma endregion

#pragma region 运动相关参数
#define SPEED_FWD 2
#define SPEED_BCK 1
#define SPEED_JMP 3
#define SPEED_DWN 3
#pragma endregion

#pragma region 全局变量
/*
PActPlayer g_Player1 = PActPlayer(D2D1::RectF(INIT_LX1, INIT_LY1, INIT_LX2, INIT_LY2));
PActPlayer g_Player2 = PActPlayer(D2D1::RectF(INIT_RX1, INIT_RY1, INIT_RX2, INIT_RY2));
*/

SFPlayer g_p1 = SFPlayer();
SFPlayer g_p2 = SFPlayer();

string g_strEkf1 = "";
string g_strEkf2 = "";
SFConfig* g_pSfconfig = SFConfig::GetInstance();
#pragma endregion

#pragma region 入口
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	if (SUCCEEDED(CoInitialize(NULL)))
	{
		{
			WinApp app;

			if (SUCCEEDED(app.Initialize()))
			{
				app.RunMessageLoop();
			}
		}
		CoUninitialize();
	}

	return 0;
}
#pragma endregion

#pragma region Initialize members
WinApp::WinApp() :
m_hwnd(NULL),
m_pD2DFactory(NULL),
m_pWICFactory(NULL),
m_pDWriteFactory(NULL),
m_pRenderTarget(NULL),
m_pTextFormat(NULL),
m_pPathGeometry(NULL),
m_pLinearGradientBrush(NULL),
m_pBlackBrush(NULL),
m_pGridPatternBitmapBrush(NULL),
m_pBitmap(NULL),
m_pAnotherBitmap(NULL)
{
}
#pragma endregion

#pragma region Release resources
WinApp::~WinApp()
{
	SafeRelease(&m_pD2DFactory);
	SafeRelease(&m_pWICFactory);
	SafeRelease(&m_pDWriteFactory);
	SafeRelease(&m_pRenderTarget);
	SafeRelease(&m_pTextFormat);
	SafeRelease(&m_pPathGeometry);
	SafeRelease(&m_pLinearGradientBrush);
	SafeRelease(&m_pBlackBrush);
	SafeRelease(&m_pGridPatternBitmapBrush);
	SafeRelease(&m_pBitmap);
	SafeRelease(&m_pAnotherBitmap);
	KillTimer(m_hwnd, 1);
}
#pragma endregion

#pragma region 初始化设备，如分辨率等
HRESULT WinApp::Initialize()
{
	HRESULT hr = CreateDeviceIndependentResources();
	if (SUCCEEDED(hr))
	{
		WNDCLASSEX wcex = { sizeof(wcex) };
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.cbWndExtra = sizeof(LONG_PTR);
		wcex.hInstance = HINST_THISCOMPONENT;
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.lpszClassName = L"D2DWinApp";

		RegisterClassEx(&wcex);
		FLOAT dpiX, dpiY;
		m_pD2DFactory->GetDesktopDpi(&dpiX, &dpiY);
		m_hwnd = CreateWindow(
			L"D2DWinApp", L"Direct2D Demo Application", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			static_cast<UINT>(ceil(ACT_WID.f*dpiX / 96.f)), static_cast<UINT>(ceil(ACT_HIG.f*dpiY / 96.f)),
			NULL, NULL, HINST_THISCOMPONENT, this
			);
		hr = m_hwnd ? S_OK : E_FAIL;
		if (SUCCEEDED(hr))
		{
			ShowWindow(m_hwnd, SW_SHOWNORMAL);
			UpdateWindow(m_hwnd);
		}
	}

	return hr;
}
#pragma endregion

#pragma region 创建设备无关资源
HRESULT WinApp::CreateDeviceIndependentResources()
{
	static const WCHAR msc_fontName[] = L"Verdana";
	static const FLOAT msc_fontSize = 50;

	ID2D1GeometrySink *pSink = NULL;
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pD2DFactory);	//创建D2D工厂
	if (SUCCEEDED(hr))
	{
		hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pWICFactory));	//创建WIC工厂
	}
	if (SUCCEEDED(hr))
	{
		hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(m_pDWriteFactory), reinterpret_cast<IUnknown **>(&m_pDWriteFactory));
	}
	if (SUCCEEDED(hr))
	{
		hr = m_pDWriteFactory->CreateTextFormat(
			msc_fontName, NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL,
			msc_fontSize, L"", &m_pTextFormat
			);
	}
	if (SUCCEEDED(hr))
	{
		m_pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		m_pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

	}
	if (SUCCEEDED(hr))
	{
		hr = m_pD2DFactory->CreatePathGeometry(&m_pPathGeometry);
	}
	if (SUCCEEDED(hr))
	{
		hr = m_pPathGeometry->Open(&pSink);
	}
	if (SUCCEEDED(hr))
	{
		pSink->SetFillMode(D2D1_FILL_MODE_ALTERNATE);
		pSink->BeginFigure(D2D1::Point2F(0, 0), D2D1_FIGURE_BEGIN_FILLED);
		pSink->AddLine(D2D1::Point2F(200, 0));
		pSink->AddBezier(D2D1::BezierSegment(D2D1::Point2F(150, 50), D2D1::Point2F(150, 150), D2D1::Point2F(200, 200)));
		pSink->AddLine(D2D1::Point2F(0, 200));
		pSink->AddBezier(D2D1::BezierSegment(D2D1::Point2F(50, 150), D2D1::Point2F(50, 50), D2D1::Point2F(0, 0)));
		pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
		hr = pSink->Close();
	}
	SafeRelease(&pSink);

	return hr;
}
#pragma endregion

#pragma region 创建设备相关资源，如图像、视频等
HRESULT WinApp::CreateDeviceResources()
{
	HRESULT hr = S_OK;

	if (!m_pRenderTarget)
	{
		RECT rc;
		GetClientRect(m_hwnd, &rc);
		D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

		hr = m_pD2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(m_hwnd, size), &m_pRenderTarget);
		if (SUCCEEDED(hr))
		{
			hr = m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &m_pBlackBrush);	// Create a black brush.
		}
		if (SUCCEEDED(hr))
		{
			ID2D1GradientStopCollection *pGradientStops = NULL;
			static const D2D1_GRADIENT_STOP stops[] = { { 0.f, { 0.f, 1.f, 1.f, 0.25f } }, { 1.f, { 0.f, 0.f, 1.f, 1.f } } };	// Create a linear gradient.
			hr = m_pRenderTarget->CreateGradientStopCollection(stops, ARRAYSIZE(stops), &pGradientStops);
			if (SUCCEEDED(hr))
			{
				hr = m_pRenderTarget->CreateLinearGradientBrush(
					D2D1::LinearGradientBrushProperties(D2D1::Point2F(100, 0), D2D1::Point2F(100, 200)), D2D1::BrushProperties(),
					pGradientStops,
					&m_pLinearGradientBrush
					);
				pGradientStops->Release();
			}
		}

		//通过文件创建位图
		hr = LoadBitmapFromFile(m_pRenderTarget, m_pWICFactory, L".\\img\\blue.png", 100, 0, &m_pBitmap);
		hr = LoadBitmapFromFile(m_pRenderTarget, m_pWICFactory, L".\\img\\black.png", 100, 0, &m_pAnotherBitmap);
#if 0
		//通过资源创建一个位图
		hr = LoadResourceBitmap(m_pRenderTarget, m_pWICFactory, L"blue", L"Image", 100, 0, &m_pBitmap);
		if (SUCCEEDED(hr))
		{
			//通过文件创建一个位图
			hr = LoadBitmapFromFile(m_pRenderTarget, m_pWICFactory, L".\\sampleImage.jpg", 100, 0, &m_pAnotherBitmap);
		}
#endif
		if (SUCCEEDED(hr))
		{
			hr = CreateGridPatternBrush(m_pRenderTarget, &m_pGridPatternBitmapBrush);
		}
		if (SUCCEEDED(hr))
		{
			SetTimer(m_hwnd, TMR_PAINT, gc_arrTmr[TMR_PAINT], NULL);
			SetTimer(m_hwnd, TMR_ACTION, gc_arrTmr[TMR_ACTION], NULL);
			SetTimer(m_hwnd, TMR_SKILL, gc_arrTmr[TMR_SKILL], NULL);
		}
	}

	return hr;
}
#pragma endregion

#pragma region CreateGridPatternBrush
HRESULT WinApp::CreateGridPatternBrush(ID2D1RenderTarget *pRenderTarget, ID2D1BitmapBrush **ppBitmapBrush)
{
	ID2D1BitmapRenderTarget *pCompatibleRenderTarget = NULL;
	HRESULT hr = pRenderTarget->CreateCompatibleRenderTarget(D2D1::SizeF(10.0f, 10.0f), &pCompatibleRenderTarget);
	if (SUCCEEDED(hr))
	{
		ID2D1SolidColorBrush *pGridBrush = NULL;
		hr = pCompatibleRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF(0.93f, 0.94f, 0.96f, 1.0f)), &pGridBrush);
		if (SUCCEEDED(hr))
		{
			pCompatibleRenderTarget->BeginDraw();
			pCompatibleRenderTarget->FillRectangle(D2D1::RectF(0.0f, 0.0f, 10.0f, 1.0f), pGridBrush);
			pCompatibleRenderTarget->FillRectangle(D2D1::RectF(0.0f, 0.1f, 1.0f, 10.0f), pGridBrush);
			pCompatibleRenderTarget->EndDraw();

			// Retrieve the bitmap from the render target.
			ID2D1Bitmap *pGridBitmap = NULL;
			hr = pCompatibleRenderTarget->GetBitmap(&pGridBitmap);
			if (SUCCEEDED(hr))
			{
				D2D1_BITMAP_BRUSH_PROPERTIES brushProperties = D2D1::BitmapBrushProperties(D2D1_EXTEND_MODE_WRAP, D2D1_EXTEND_MODE_WRAP);	// Choose the tiling mode for the bitmap brush.
				hr = m_pRenderTarget->CreateBitmapBrush(pGridBitmap, brushProperties, ppBitmapBrush);	// Create the bitmap brush.
				pGridBitmap->Release();
			}
			pGridBrush->Release();
		}
		pCompatibleRenderTarget->Release();
	}

	return hr;
}
#pragma endregion

#pragma region 释放资源？
void WinApp::DiscardDeviceResources()
{
	SafeRelease(&m_pRenderTarget);
	SafeRelease(&m_pBitmap);
	SafeRelease(&m_pBlackBrush);
	SafeRelease(&m_pLinearGradientBrush);
	SafeRelease(&m_pAnotherBitmap);
	SafeRelease(&m_pGridPatternBitmapBrush);
}
#pragma endregion

#pragma region MessageLoop
void WinApp::RunMessageLoop()
{
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
#pragma endregion

#pragma region 主画图逻辑关键帧
HRESULT WinApp::OnHardRender()
{
	HRESULT hr = CreateDeviceResources();
	char tmp[100] = { 0 };

	if (SUCCEEDED(hr))
	{
		D2D1_SIZE_F renderTargetSize = m_pRenderTarget->GetSize();

		m_pRenderTarget->BeginDraw();
		m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
		m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
		m_pRenderTarget->FillRectangle(D2D1::RectF(0.0f, 0.0f, renderTargetSize.width, renderTargetSize.height), m_pGridPatternBitmapBrush);	// 画格子背景
		m_pRenderTarget->DrawBitmap(m_pBitmap, g_Player1.m_body);	//添加A位图
		m_pRenderTarget->DrawBitmap(m_pAnotherBitmap, g_Player2.m_body);	//添加B位图

#if 0
		D2D1_SIZE_F size = m_pBitmap->GetSize();

		size.width = BLU_W;
		size.height = BLU_H;
		m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(45, D2D1::Point2F(renderTargetSize.width / 2, renderTargetSize.height / 2)));	//旋转45度
		m_pRenderTarget->DrawText(sc_helloWorld, ARRAYSIZE(sc_helloWorld) - 1, m_pTextFormat, D2D1::RectF(0, 0, renderTargetSize.width, renderTargetSize.height), m_pBlackBrush);	//显示文字
		m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(0, renderTargetSize.height - 200));
		m_pRenderTarget->FillGeometry(m_pPathGeometry, m_pLinearGradientBrush);
		m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(renderTargetSize.width - 200, 0));
		m_pRenderTarget->FillGeometry(m_pPathGeometry, m_pLinearGradientBrush);
#endif
		hr = m_pRenderTarget->EndDraw();
		if (hr == D2DERR_RECREATE_TARGET)
		{
			hr = S_OK;
			DiscardDeviceResources();
		}
	}

	return hr;
}
#pragma endregion

#pragma region 主画图逻辑
HRESULT WinApp::OnRender()
{
	HRESULT hr = CreateDeviceResources();
	char tmp[100] = { 0 };

	if (SUCCEEDED(hr))
	{
		static const WCHAR sc_helloWorld[] = L"Hello, World!";
		D2D1_SIZE_F renderTargetSize = m_pRenderTarget->GetSize();

		m_pRenderTarget->BeginDraw();
		m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
		m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
		m_pRenderTarget->FillRectangle(D2D1::RectF(0.0f, 0.0f, renderTargetSize.width, renderTargetSize.height), m_pGridPatternBitmapBrush);	// 画格子背景
		m_pRenderTarget->DrawBitmap(m_pBitmap, g_Player1.m_body);	//添加A位图
		m_pRenderTarget->DrawBitmap(m_pAnotherBitmap, g_Player2.m_body);	//添加B位图

#if 0
		D2D1_SIZE_F size = m_pBitmap->GetSize();

		size.width = BLU_W;
		size.height = BLU_H;
		m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(45, D2D1::Point2F(renderTargetSize.width / 2, renderTargetSize.height / 2)));	//旋转45度
		m_pRenderTarget->DrawText(sc_helloWorld, ARRAYSIZE(sc_helloWorld) - 1, m_pTextFormat, D2D1::RectF(0, 0, renderTargetSize.width, renderTargetSize.height), m_pBlackBrush);	//显示文字
		m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(0, renderTargetSize.height - 200));
		m_pRenderTarget->FillGeometry(m_pPathGeometry, m_pLinearGradientBrush);
		m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(renderTargetSize.width - 200, 0));
		m_pRenderTarget->FillGeometry(m_pPathGeometry, m_pLinearGradientBrush);
#endif
		hr = m_pRenderTarget->EndDraw();
		if (hr == D2DERR_RECREATE_TARGET)
		{
			hr = S_OK;
			DiscardDeviceResources();
		}
	}

	return hr;
}
#pragma endregion

#pragma region If the application receives a WM_SIZE message, this method resize the render target appropriately.
void WinApp::OnResize(UINT width, UINT height)
{
	if (m_pRenderTarget)
	{
		D2D1_SIZE_U size;
		size.width = width;
		size.height = height;

		// Note: This method can fail, but it's okay to ignore the
		// error here -- it will be repeated on the next call to
		// EndDraw.
		m_pRenderTarget->Resize(size);
	}
}
#pragma endregion

#pragma region 消息处理
LRESULT CALLBACK WinApp::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	string strTmp = "";
	int st = 0;

	if (message == WM_CREATE)
	{
		LPCREATESTRUCT pcs = (LPCREATESTRUCT)lParam;
		WinApp *pWinApp = (WinApp*)pcs->lpCreateParams;

		::SetWindowLongPtrW(hwnd, GWLP_USERDATA, PtrToUlong(pWinApp));
		result = 1;
	}
	else
	{
		WinApp *pWinApp = reinterpret_cast<WinApp *>(static_cast<LONG_PTR>(::GetWindowLongPtrW(hwnd, GWLP_USERDATA)));
		bool wasHandled = false;

		if (pWinApp)
		{
			switch (message)
			{
				case WM_SIZE:
					{
						UINT width = LOWORD(lParam);
						UINT height = HIWORD(lParam);
						pWinApp->OnResize(width, height);
					}
					result = 0;
					wasHandled = true;
					break;
				case WM_TIMER:
					switch (wParam)
					{
						case TMR_PAINT:
							pWinApp->OnRender();
							ValidateRect(hwnd, NULL);
							break;
						case TMR_ACTION:
							break;
						case TMR_SKILL:
							break;
					}
					result = 0;
					wasHandled = true;
					break;
				case WM_DISPLAYCHANGE:
					{
						 InvalidateRect(hwnd, NULL, FALSE);
					}
					result = 0;
					wasHandled = true;
					break;
				case WM_KEYDOWN:
					//只有非纯硬直状态才可以进入selectSkill阶段
					if (g_p1.m_actionStatus <= AS_CHAIN)
					{
						switch (wParam)
						{
							case KD_P1UP:
								g_p1.selectSkill(EK_8D);
								break;
							case KD_P1LF:
								g_p1.selectSkill(EK_4D);
								break;
							case KD_P1DW:
								g_p1.selectSkill(EK_2D);
								break;
							case KD_P1RG:
								g_p1.selectSkill(EK_6D);
								break;
							case KD_P1AA:
								g_p1.selectSkill(EK_AD);
								break;
							case KD_P1BB:
								g_p1.selectSkill(EK_BD);
								break;
							case KD_P1CC:
								g_p1.selectSkill(EK_CD);
								break;
							case KD_P1DD:
								g_p1.selectSkill(EK_DD);
								break;
						}
					}
					if (g_p2.m_actionStatus <= AS_CHAIN)
					{
						switch (wParam)
						{
							case KD_P2UP:
								g_p2.selectSkill(EK_8D);
								break;
							case KD_P2LF:
								g_p2.selectSkill(EK_4D);
								break;
							case KD_P2DW:
								g_p2.selectSkill(EK_2D);
								break;
							case KD_P2RG:
								g_p2.selectSkill(EK_6D);
								break;
							case KD_P2AA:
								g_p2.selectSkill(EK_AD);
								break;
							case KD_P2BB:
								g_p2.selectSkill(EK_BD);
								break;
							case KD_P2CC:
								g_p2.selectSkill(EK_CD);
								break;
							case KD_P2DD:
								g_p2.selectSkill(EK_DD);
								break;
						}
					}
					result = 0;
					wasHandled = true;
					break;
				case WM_KEYUP:
					switch (wParam)
					{
						case KD_P1UP:
							g_p1.addEvent(EK_8U);
							break;
						case KD_P1LF:
							g_p1.addEvent(EK_4U);
							break;
						case KD_P1DW:
							g_p1.addEvent(EK_2U);
							break;
						case KD_P1RG:
							g_p1.addEvent(EK_6U);
							break;
						case KD_P1AA:
							g_p1.addEvent(EK_AU);
							break;
						case KD_P1BB:
							g_p1.addEvent(EK_BU);
							break;
						case KD_P1CC:
							g_p1.addEvent(EK_CU);
							break;
						case KD_P1DD:
							g_p1.addEvent(EK_DU);
							break;
						case KD_P2UP:
							g_p2.addEvent(EK_8U);
							break;
						case KD_P2LF:
							g_p2.addEvent(EK_4U);
							break;
						case KD_P2DW:
							g_p2.addEvent(EK_2U);
							break;
						case KD_P2RG:
							g_p2.addEvent(EK_6U);
							break;
						case KD_P2AA:
							g_p2.addEvent(EK_AU);
							break;
						case KD_P2BB:
							g_p2.addEvent(EK_BU);
							break;
						case KD_P2CC:
							g_p2.addEvent(EK_CU);
							break;
						case KD_P2DD:
							g_p2.addEvent(EK_DU);
							break;
					}
					result = 0;
					wasHandled = true;
					break;
				case WM_PAINT:
					{
						pWinApp->OnRender();
						ValidateRect(hwnd, NULL);
					}
					result = 0;
					wasHandled = true;
					break;
				case WM_DESTROY:
					{
						PostQuitMessage(0);
					}
					result = 1;
					wasHandled = true;
					break;
			}
		}
		if (!wasHandled)
		{
			result = DefWindowProc(hwnd, message, wParam, lParam);
		}
	}

	return result;
}
#pragma endregion

#pragma region LoadResourceBitmap
HRESULT WinApp::LoadResourceBitmap(
	ID2D1RenderTarget *pRenderTarget,
	IWICImagingFactory *pIWICFactory,
	PCWSTR resourceName,
	PCWSTR resourceType,
	UINT destinationWidth,
	UINT destinationHeight,
	ID2D1Bitmap **ppBitmap
	)
{
	IWICBitmapDecoder *pDecoder = NULL;
	IWICBitmapFrameDecode *pSource = NULL;
	IWICStream *pStream = NULL;
	IWICFormatConverter *pConverter = NULL;
	IWICBitmapScaler *pScaler = NULL;
	HRSRC imageResHandle = NULL;
	HGLOBAL imageResDataHandle = NULL;
	void *pImageFile = NULL;
	DWORD imageFileSize = 0;

	imageResHandle = FindResourceW(HINST_THISCOMPONENT, resourceName, resourceType);	// Locate the resource.
	HRESULT hr = imageResHandle ? S_OK : E_FAIL;
	if (SUCCEEDED(hr))
	{
		imageResDataHandle = LoadResource(HINST_THISCOMPONENT, imageResHandle);	// Load the resource.
		hr = imageResDataHandle ? S_OK : E_FAIL;
	}
	if (SUCCEEDED(hr))
	{
		pImageFile = LockResource(imageResDataHandle);	// Lock it to get a system memory pointer.
		hr = pImageFile ? S_OK : E_FAIL;
	}
	if (SUCCEEDED(hr))
	{
		imageFileSize = SizeofResource(HINST_THISCOMPONENT, imageResHandle);	// Calculate the size.
		hr = imageFileSize ? S_OK : E_FAIL;
	}
	if (SUCCEEDED(hr))
	{
		hr = pIWICFactory->CreateStream(&pStream);	// Create a WIC stream to map onto the memory.
	}
	if (SUCCEEDED(hr))
	{
		hr = pStream->InitializeFromMemory(reinterpret_cast<BYTE*>(pImageFile), imageFileSize);	// Initialize the stream with the memory pointer and size.
	}
	if (SUCCEEDED(hr))
	{
		hr = pIWICFactory->CreateDecoderFromStream(pStream, NULL, WICDecodeMetadataCacheOnLoad, &pDecoder);	// Create a decoder for the stream.
	}
	if (SUCCEEDED(hr))
	{
		hr = pDecoder->GetFrame(0, &pSource);	// Create the initial frame.
	}
	if (SUCCEEDED(hr))
	{
		hr = pIWICFactory->CreateFormatConverter(&pConverter);	// Convert the image format to 32bppPBGRA(DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
	}
	if (SUCCEEDED(hr))
	{
		// If a new width or height was specified, create an
		// IWICBitmapScaler and use it to resize the image.
		if (destinationWidth != 0 || destinationHeight != 0)
		{
			UINT originalWidth, originalHeight;

			hr = pSource->GetSize(&originalWidth, &originalHeight);
			if (SUCCEEDED(hr))
			{
				if (destinationWidth == 0)
				{
					FLOAT scalar = static_cast<FLOAT>(destinationHeight) / static_cast<FLOAT>(originalHeight);
					destinationWidth = static_cast<UINT>(scalar * static_cast<FLOAT>(originalWidth));
				}
				else
				{
					if (destinationHeight == 0)
					{
						FLOAT scalar = static_cast<FLOAT>(destinationWidth) / static_cast<FLOAT>(originalWidth);
						destinationHeight = static_cast<UINT>(scalar * static_cast<FLOAT>(originalHeight));
					}
				}
				hr = pIWICFactory->CreateBitmapScaler(&pScaler);
				if (SUCCEEDED(hr))
				{
					hr = pScaler->Initialize(pSource, destinationWidth, destinationHeight, WICBitmapInterpolationModeCubic);
					if (SUCCEEDED(hr))
					{
						hr = pConverter->Initialize(pScaler, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeMedianCut);
					}
				}
			}
		}
		else
		{
			hr = pConverter->Initialize(pSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeMedianCut);
		}
	}
	if (SUCCEEDED(hr))
	{
		hr = pRenderTarget->CreateBitmapFromWicBitmap(pConverter, NULL, ppBitmap);	//create a Direct2D bitmap from the WIC bitmap.
	}
	SafeRelease(&pDecoder);
	SafeRelease(&pSource);
	SafeRelease(&pStream);
	SafeRelease(&pConverter);
	SafeRelease(&pScaler);

	return hr;
}
#pragma endregion

#pragma region LoadBitmapFromFile
HRESULT WinApp::LoadBitmapFromFile(
	ID2D1RenderTarget *pRenderTarget,
	IWICImagingFactory *pIWICFactory,
	PCWSTR uri,
	UINT destinationWidth,
	UINT destinationHeight,
	ID2D1Bitmap **ppBitmap
	)
{
	IWICBitmapDecoder *pDecoder = NULL;
	IWICBitmapFrameDecode *pSource = NULL;
	IWICStream *pStream = NULL;
	IWICFormatConverter *pConverter = NULL;
	IWICBitmapScaler *pScaler = NULL;

	HRESULT hr = pIWICFactory->CreateDecoderFromFilename(uri, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &pDecoder);

	if (SUCCEEDED(hr))
	{
		// Create the initial frame.
		hr = pDecoder->GetFrame(0, &pSource);
	}
	if (SUCCEEDED(hr))
	{

		// Convert the image format to 32bppPBGRA
		// (DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
		hr = pIWICFactory->CreateFormatConverter(&pConverter);

	}
	if (SUCCEEDED(hr))
	{
		// If a new width or height was specified, create an
		// IWICBitmapScaler and use it to resize the image.
		if (destinationWidth != 0 || destinationHeight != 0)
		{
			UINT originalWidth, originalHeight;
			hr = pSource->GetSize(&originalWidth, &originalHeight);
			if (SUCCEEDED(hr))
			{
				if (destinationWidth == 0)
				{
					FLOAT scalar = static_cast<FLOAT>(destinationHeight) / static_cast<FLOAT>(originalHeight);
					destinationWidth = static_cast<UINT>(scalar * static_cast<FLOAT>(originalWidth));
				}
				else if (destinationHeight == 0)
				{
					FLOAT scalar = static_cast<FLOAT>(destinationWidth) / static_cast<FLOAT>(originalWidth);
					destinationHeight = static_cast<UINT>(scalar * static_cast<FLOAT>(originalHeight));
				}

				hr = pIWICFactory->CreateBitmapScaler(&pScaler);
				if (SUCCEEDED(hr))
				{
					hr = pScaler->Initialize(pSource, destinationWidth, destinationHeight, WICBitmapInterpolationModeCubic);
				}
				if (SUCCEEDED(hr))
				{
					hr = pConverter->Initialize(pScaler, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeMedianCut);
				}
			}
		}
		else // Don't scale the image.
		{
			hr = pConverter->Initialize(pSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeMedianCut);
		}
	}
	if (SUCCEEDED(hr))
	{
		// Create a Direct2D bitmap from the WIC bitmap.
		hr = pRenderTarget->CreateBitmapFromWicBitmap(pConverter, NULL, ppBitmap);
	}
	SafeRelease(&pDecoder);
	SafeRelease(&pSource);
	SafeRelease(&pStream);
	SafeRelease(&pConverter);
	SafeRelease(&pScaler);

	return hr;
}
#pragma endregion
