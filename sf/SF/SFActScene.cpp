#pragma execution_character_set("utf-8")
#include <SFActScene.h>

SFSpriteGroup::SFSpriteGroup(string name) :m_name(name)
{

}

SFSpriteGroup::~SFSpriteGroup()
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

bool SFSpriteGroup::addSprite(SFSprite* pSprite)
{
	if (pSprite == NULL)
	{
		return false;
	}
	m_aSprite.insert(m_aSprite.end(), pSprite);

	return true;
}

SFActScene::SFActScene(SF_SCN_MAP mapType) :m_mapType(mapType)
{
	m_stage = SCN_STG_FREE;
}

SFActScene::~SFActScene()
{
	map<string, SFSpriteGroup*>::iterator itSpriteGroup;
	for (itSpriteGroup = m_mapSpriteGroup.begin(); itSpriteGroup != m_mapSpriteGroup.end(); ++itSpriteGroup)
	{
		if (itSpriteGroup->second != NULL)
		{
			delete itSpriteGroup->second;
			itSpriteGroup->second = NULL;
		}
	}
}


bool SFActScene::addSprite(string groupName, SFSprite* pSprite)
{
	if (pSprite == NULL || m_stage != SCN_STG_FREE)
	{
		return false;
	}

	map<string, SFSpriteGroup*>::iterator itSpriteGroup = m_mapSpriteGroup.find(groupName);
	SFSpriteGroup* pSpriteGroup = NULL;

	if (itSpriteGroup != m_mapSpriteGroup.end())
	{
		pSpriteGroup = m_mapSpriteGroup[groupName];
	}
	else
	{
		pSpriteGroup = new SFSpriteGroup(groupName);
		m_mapSpriteGroup[groupName] = pSpriteGroup;
	}
	if (pSpriteGroup->addSprite(pSprite))
	{
		return true;
	}
	else
	{
		return false;
	}
}