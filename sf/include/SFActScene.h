#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>

typedef enum SF_SCN_MAP
{
	SCN_MAP_DEF, SCN_SKY, SCN_WATER,
	SCN_MAX
};

typedef enum SF_SCN_STAGE
{
	SCN_STG_FREE, SCN_STG_LOADING, SCN_STG_PAINTING, SCN_STG_KILLING,
	SCN_STG_MAX
}SF_SCN_STG;

//暂时没用
typedef enum SF_PLR_GROUP
{
	PGR_PLR, PGR_MST,
	PGR_MAX
};

#define SF_FIGHT_PLRGROUP_MAX 2
const string g_strPlayerGroup[SF_FIGHT_PLRGROUP_MAX] = {
	"p1", "p2"
};

//将来会改为继承关系，也有可能不改了
typedef SFPlayer SFSprite;

class SFSpriteGroup
{
public:
	vector<SFSprite*> m_aSprite;
};

//场景类，目前只能是单线程，将来可能会向多线程发展。
class SFActScene
{
public:
	map<string, SFSpriteGroup*> m_mapSpriteGroup;
	SF_SCN_MAP m_mapType;
	SF_SCN_STAGE m_stage;

	SFActScene(SF_SCN_MAP mapType = SCN_MAP_DEF);
	~SFActScene();
	bool addSpriteGroup(string groupName);
	bool addSprite(string groupName, SFSprite* pSprite);
};