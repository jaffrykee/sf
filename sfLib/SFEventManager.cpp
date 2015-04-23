#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

SFEventManager::SFEventManager() :m_pMapEvent(&g_pConf->m_mapEvent), m_pActiveScene(NULL)
{
}

bool SFEventManager::setActiveScene(SFActScene* pScene)
{
	if (pScene != NULL)
	{
		m_pActiveScene = pScene;
		return true;
	}
	else
	{
		return false;
	}
}

//
bool SFEventManager::doEvent(SF_TEV event, LPARAM lParam)
{
	if (m_pActiveScene != NULL)
	{
		return m_pActiveScene->doEvent(event);
	}
	else
	{
		return false;
	}
}

//看看该系统事件SF是否应该响应
bool SFEventManager::doSystemEvent(UINT message, WPARAM wParam, LPARAM lParam)
{
	MapEventGroup_T::iterator itEventGroup = m_pMapEvent->find(message);

	if (itEventGroup != m_pMapEvent->end())
	{
		MapEvent_T::iterator itEvent = (*m_pMapEvent)[message].find(wParam);
		if (itEvent != (*m_pMapEvent)[message].end())
		{
			//看看该系统事件的wParam SF是否应该响应
			return doEvent((*m_pMapEvent)[message][wParam], lParam);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}