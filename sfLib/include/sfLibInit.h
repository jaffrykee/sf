#pragma once
#pragma execution_character_set("utf-8")

#pragma region win系统define和include
#ifndef WINVER              // Allow use of features specific to Windows 7 or later.
#define WINVER 0x0700       // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT        // Allow use of features specific to Windows 7 or later.
#define _WIN32_WINNT 0x0700 // Change this to the appropriate value to target other versions of Windows.
#endif

#define WIN32_LEAN_AND_MEAN     // Exclude rarely-used stuff from Windows headers

// C RunTime Header Files

#pragma endregion

using namespace std;

//前置include
#include <tkmT.h>
#include <sfLib.h>

#pragma region inline和宏等
template<class Interface>
inline void
SafeRelease(
Interface **ppInterfaceToRelease
)
{
	if (*ppInterfaceToRelease != NULL)
	{
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = NULL;
	}
}

template<class Interface>
inline void
SafeDelete(
Interface **ppInterfaceToRelease
)
{
	if (*ppInterfaceToRelease != NULL)
	{
		delete(*ppInterfaceToRelease);

		(*ppInterfaceToRelease) = NULL;
	}
}

//用于规避主线程提前关闭窗口的问题。
#define CHECK_WIN_KILLED				 \
do 										 \
{										 \
	if (g_pConf->m_pWin == NULL)		 \
	{									 \
		return 0;						 \
	}									 \
} while (0)

#ifndef Assert
#if defined( DEBUG ) || defined( _DEBUG )
#define Assert(b) do {if(!(b)) {OutputDebugStringA("Assert: " #b "\n");}} while(0)
#else
#define Assert(b)
#endif //DEBUG || _DEBUG
#endif


#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif
#pragma endregion
