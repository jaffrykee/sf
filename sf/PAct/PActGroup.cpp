#pragma execution_character_set("utf-8")
#include <PActGroup.h>

size_t PActGroup::s_count = 0;

PActGroup::PActGroup()
{
	s_count++;
	m_id = s_count;
	m_name = getDefaultName();
}

PActGroup::PActGroup(string name)
{
	s_count++;
	m_id = s_count;
	m_name = name;
}

string PActGroup::getDefaultName()
{
	string ret;
	string temp;

	temp = m_id;
	ret = "_g";
	ret += temp;

	return ret;
}


bool PActGroup::addObject(string objName)
{
	m_arrObj.insert(m_arrObj.end(),new PActObject(objName,this));

	return true;
}

bool PActGroup::addObject(string objName, size_t wd, size_t hi)
{
	m_arrObj.insert(m_arrObj.end(),new PActObject(objName, 0, 0, wd, hi, this));

	return true;
}

bool PActGroup::addObject(string objName, size_t wd, size_t hi, size_t x, size_t y)
{
	m_arrObj.insert(m_arrObj.end(),new PActObject(objName, x, y, wd, hi, this));

	return true;
}

PActObject* PActGroup::getObject(string objName)
{
	return NULL;
}

bool PActGroup::deleteObject(string objName)
{
	return false;
}

bool PActGroup::clearAllObject()
{
	return false;
}