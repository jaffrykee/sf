#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

SFCamera::SFCamera() :m_pCurScene(NULL), m_poiCenter({ 0, 0 }), m_width(0), m_height(0)
{

}

SFCamera::~SFCamera()
{

}

bool SFCamera::setCurrentScene(SFActScene* pCurScene)
{
	m_pCurScene = pCurScene;

	m_width = pCurScene->m_pResScene
}