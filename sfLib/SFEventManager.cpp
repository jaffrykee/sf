#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

SFEventManager::SFEventManager() :m_pMapEvent(NULL), m_pActiveScene(NULL)
{
}

bool SFEventManager::setActiveScene(Scene* pScene)
{
	if (pScene != NULL)
	{
		m_pActiveScene = pScene;
		m_pMapEvent = pScene->m_mapEvent;

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
	if (m_pMapEvent != NULL)
	{
		MapEventGroup_T::iterator itEventGroup = m_pMapEvent->find(message);

		if (itEventGroup != m_pMapEvent->end())
		{
			MapEvent_T::iterator itEvent = (*m_pMapEvent)[message].find(wParam);
			if (message >= WM_MOUSEFIRST && message <= WM_MOUSELAST)
			{
				return m_pActiveScene->doMonseEvent(message, wParam, lParam);
			}
			else
			{
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