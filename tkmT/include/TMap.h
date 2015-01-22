#pragma once
#pragma execution_character_set("utf-8")
#include <tkmT.h>
#include <TArray.h>

/*
name:
	TMap
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

#define TBM_WD_MAX 65535
#define TBM_HI_MAX 65535

template <class MyBMPixel>
class TMap
{
public:
	size_t m_width;
	size_t m_height;
	TArray<MyBMPixel>** m_pMapHead;

	TMap(size_t wd,size_t hi);
	~TMap();
	TArray<MyBMPixel>& operator[](size_t id);

protected:
private:
};

template <class MyBMPixel>
TMap<MyBMPixel>::TMap(size_t wd,size_t hi)
{
	m_pMapHead = new TArray<MyBMPixel>*[wd];
	for(size_t i=0; i<wd; i++)
	{
		m_pMapHead[i] = new TArray<MyBMPixel>(hi);
	}
	m_width = wd;
	m_height = hi;
}

template <class MyBMPixel>
TMap<MyBMPixel>::~TMap()
{
	for(size_t i=0; i<m_width; i++)
	{
		delete m_pMapHead[i];
		m_pMapHead[i] = NULL;
	}
	delete []m_pMapHead;
}

template <class MyBMPixel>
TArray<MyBMPixel>& TMap<MyBMPixel>::operator [](size_t id)
{
	return *m_pMapHead[id];
}