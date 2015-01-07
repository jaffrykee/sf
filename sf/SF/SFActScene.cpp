#pragma execution_character_set("utf-8")
#include <SFActScene.h>

SFActScene::SFActScene(SF_SCN_MAP mapType) :m_mapType(mapType)
{
	m_stage = SCN_STG_FREE;
}

SFActScene::~SFActScene()
{
	for (UINT i = 0; i < m_aSprite.size(); i++)
	{
		if (m_aSprite[i] != NULL)
		{
			delete m_aSprite[i];
			m_aSprite[i] = NULL;
		}
	}
}


bool SFActScene::addSprite(SFSprite* pSprite)
{
	if (pSprite == NULL || m_stage != SCN_STG_FREE)
	{
		return false;
	}
	m_aSprite.insert(m_aSprite.end(), pSprite);

	return true;
}