/*
	<info>
		<creator>daomaodao@sina.com</creator>
		<date>2014-05-09</date>
		<tip>这个类存放着物体的真实位置等信息，可以提供给碰撞、显示等环节</tip>
	</info>
*/
#ifndef PACTOBJECT_H
#define PACTOBJECT_H
#pragma execution_character_set("utf-8")
#include <PActInit.h>
#include <PActGroup.h>
#include <PPoint.h>
#include <PRect.h>

extern class PActGroup;

class PActObjectMotionState
{
public:
	PRect<double,double> m_body;
	double m_vX;
	double m_vY;

public:
	PActObjectMotionState(double x, double y, double wd, double hi, double vx, double vy);
};

class PActObject
{
public:
	static size_t s_count;

	size_t m_id;
	string m_name;
	PRect<double,double> m_body;
	PActGroup* m_pParent;

public:
	PActObject(PActGroup* prnt = NULL);
	PActObject(string name, PActGroup* prnt = NULL);
	PActObject(double x, double y, double wd, double hi, PActGroup* prnt=NULL);
	PActObject(string name, double x, double y, double wd, double hi, PActGroup* prnt=NULL);
	PActObject(PRect<double,double> body, PActGroup* prnt = NULL);
	PActObject(string name, PRect<double,double> body, PActGroup* prnt = NULL);
	~PActObject();

	string getDefaultName();
	bool checkCollision(PActObject& target);
	bool getNextState();
};
#endif