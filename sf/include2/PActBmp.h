#ifndef PACTBMP_H
#define PACTBMP_H
#pragma execution_character_set("utf-8")

#include <PActInit.h>

template<typename MyBMPixel>
class PActBmp
{
public:
	int m_width;
	int m_height;
	MyBMPixel* m_pBmpHead;

	PActBmp(int wd = DEFAULT_WIDTH, int hi = DEFAULT_HEIGHT);
	~PActBmp();
};

template<typename MyBMPixel>
PActBmp<MyBMPixel>::PActBmp(int wd, int hi)
{
	m_pBmpHead = (MyBMPixel*)malloc(wd*hi*sizeof(MyBMPixel));
	if(NULL != m_pBmpHead)
	{
		this->m_width = wd;
		this->m_height = hi;
	}
	else
	{
		this->m_width = 0;
		this->m_height = 0;
	}
}

template<typename MyBMPixel>
PActBmp<MyBMPixel>::~PActBmp()
{
	if(NULL != m_pBmpHead)
	{
		free(m_pBmpHead);
	}
}

#endif