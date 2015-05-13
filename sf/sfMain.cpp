#pragma execution_character_set("utf-8")
#include <sfMain.h>

#pragma region 入口以及初始配置
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	//控制台
	if (g_pConf->m_enDebug[DEBUG_COM])
	{
		AllocConsole();
		int fd = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
		FILE *file = _fdopen(fd, "w");
		*stdout = *file;
		int status = setvbuf(stdout, 0, _IONBF, 0);
	}

	SYSTEM_INFO info;
	GetSystemInfo(&info);
	g_pConf->m_numCore = info.dwNumberOfProcessors;

	if (SUCCEEDED(CoInitialize(NULL)))
	{
		{
			SFApp app;

			g_pConf->m_pWin = &app;
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
