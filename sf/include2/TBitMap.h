/*
name:
	TBitMap
class:
	T
type:
	template
creator:
	daomaodao@sina.com
description:
	cn:二维数组通用类模板，有[][]运算符重载
date:
	2014-04-28
version:
	1
*/
#ifndef TBITMAP_H
#define TBITMAP_H
#pragma execution_character_set("utf-8")
#include <TInit.h>
#include <TBitArray.h>

class TBitMap
{
public:
	unsigned short m_width;
	unsigned short m_height;
	TBitArray** m_pMapHead;

	TBitMap(unsigned short wd,unsigned short hi);
	~TBitMap();
	TBitArray& operator[](unsigned short id);

protected:
private:
};

#endif
