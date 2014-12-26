#ifndef TARRAY_H
#define TARRAY_H
#pragma execution_character_set("utf-8")
#include <init.h>

template<class MyBMPixel>
class TArray
{
public:
	TArray();
	TArray(unsigned int size);
	~TArray();
	MyBMPixel& operator[](unsigned int id);

protected:
	unsigned int m_size;
	MyBMPixel* m_pArrHead;

private:
};

template<class MyBMPixel>
TArray<MyBMPixel>::TArray()
{
	m_pArrHead = NULL;
}

template<class MyBMPixel>
TArray<MyBMPixel>::TArray(unsigned int size)
{
	m_size = size;
	m_pArrHead = new MyBMPixel[size];
}

template<class MyBMPixel>
TArray<MyBMPixel>::~TArray()
{
	delete []m_pArrHead;
}

template<class MyBMPixel>
MyBMPixel& TArray<MyBMPixel>::operator[](unsigned int id)
{
	return m_pArrHead[id];
}

#endif