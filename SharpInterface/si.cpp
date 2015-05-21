#pragma execution_character_set("utf-8")
#include <siLibInit.h>
#include <siLib.h>

extern "C" __declspec(dllexport) int createWin(HWND hwnd)
{
	SFApp* pSf = new SFApp(hwnd);

	return 0;
}