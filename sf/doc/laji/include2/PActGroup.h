#ifndef PACTGROUP_H
#define PACTGROUP_H
#pragma execution_character_set("utf-8")
#include <PActInit.h>
#include <PActObject.h>

extern class PActObject;

class PActGroup
{
public:
	static size_t s_count;

	size_t m_id;
	string m_name;
	vector<PActObject*> m_arrObj;

public:
	PActGroup();
	PActGroup(string name);

	string getDefaultName();
	bool addObject(string objName);
	bool addObject(string objName, size_t wd, size_t hi);
	bool addObject(string objName, size_t wd, size_t hi, size_t x, size_t y);
	PActObject* getObject(string objName);
	bool deleteObject(string objName);
	bool clearAllObject();
};
#endif