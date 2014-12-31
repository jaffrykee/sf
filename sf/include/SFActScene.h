#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>

typedef enum SF_SCN_MAPTYPE
{
	SCN_DEF, SCN_SKY, SCN_WATER,
	SCN_MAX
}SF_SCN;

#define SFSprite SFPlayer

//场景类，目前只能是单线程，将来可能会向多线程发展。
class SFActScene
{
public:
	vector<SFSprite*> m_aSprite;
	SF_SCN m_mapType;

	SFActScene(SF_SCN mapType = SCN_DEF);
	~SFActScene();
	bool addSprite(SFSprite* p);
};