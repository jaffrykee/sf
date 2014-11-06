#pragma execution_character_set("utf-8")
#include <PActObject.h>

size_t PActObject::s_count = 0;

PActObjectMotionState::PActObjectMotionState(double x, double y, double wd, double hi, double vx, double vy):m_body(x,y,wd,hi)
{
	m_vX = vx;
	m_vY = vy;
}

PActObject::PActObject(PActGroup* prnt):m_body(0,0,ACT_DEFWD,ACT_DEFHI)
{
	s_count++;
	m_id = s_count;
	m_name = getDefaultName();
	m_pParent = prnt;
}

PActObject::PActObject(string name, PActGroup* prnt):m_body(0,0,ACT_DEFWD,ACT_DEFHI)
{
	s_count++;
	m_id = s_count;
	m_name = name;
	m_pParent = prnt;
}

PActObject::PActObject(double x, double y, double wd, double hi, PActGroup* prnt):m_body(x,y,wd,hi)
{
	s_count++;
	m_id = s_count;
	m_name = getDefaultName();
	m_pParent = prnt;
}

PActObject::PActObject(string name, double x, double y, double wd, double hi, PActGroup* prnt):m_body(x,y,wd,hi)
{
	s_count++;
	m_id = s_count;
	m_name = name;
	m_pParent = prnt;
}

PActObject::PActObject(PRect<double,double> body, PActGroup* prnt)
{
	m_body=body;
	s_count++;
	m_id = s_count;
	m_name = getDefaultName();
	m_pParent = prnt;
}

PActObject::PActObject(string name, PRect<double,double> body, PActGroup* prnt)
{
	m_body=body;
	s_count++;
	m_id = s_count;
	m_name = name;
	m_pParent = prnt;
}

string PActObject::getDefaultName()
{
	string ret;
	string temp;

	temp = m_id;
	ret = m_pParent->getDefaultName() + "_o" + temp;

	return ret;
}

bool PActObject::checkCollision(PActObject& target)
{
	return false;
}