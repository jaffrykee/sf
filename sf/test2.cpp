#pragma execution_character_set("utf-8")
#include <SFResConfigReader.h>
#include <SFResource.h>

char path[] = "./data/p001/playerInfo.xml";

void main()
{
	SFResPlayer resPlayer(SKN_SK1);

	SFResConfigReader::readFromXML(path, &resPlayer);
}