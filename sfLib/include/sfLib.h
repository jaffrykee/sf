#pragma once
#pragma execution_character_set("utf-8")

#include <windows.h>
#include <windowsx.h>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <wchar.h>
#include <tchar.h>
#include <math.h>

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

#include <string>
#include <map>
#include <list>
#include <vector>

#include <stdio.h>
#include <XmlLite.h>
#include <shlwapi.h>
#include <comutil.h>
#include <atlcomcli.h>
#include <iostream>
#include <sstream>
#include <Fcntl.h>
#include <io.h>

#pragma comment(lib, "comsuppwd.lib")
#pragma comment(lib, "XmlLite.lib")
#pragma comment(lib, "Shlwapi.lib")

#include <tkmT.h>
#include <SFd2d.h>

class SFConfig;

class SFXmlReader;
class SFXmlPlayer;
class SFXmlScene;

class SFResPlayerMap;
class SFResPlayer;
class SFResSkill;
class SFResSkillSwitch;
class SFResObject;
class SFResFrame;
class SFPlayer;
class SFActScene;
class SFSpriteGroup;

class SFEventManager;
class Scene;

//后置include
#include <SFConfig.h>
#include <SFEventManager.h>
#include <SFDebug.h>
#include <SFResource.h>
#include <SFEventKey.h>
#include <SFPlayer.h>

#include <SFResConfigReader.h>
#include <SFCamera.h>

#include <Scene.h>
#include <SFActScene.h>
#include <CMScene.h>
