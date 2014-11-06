#ifndef TARRAY_H
#define TARRAY_H
#pragma execution_character_set("utf-8")
#include <TInit.h>

template<class MyBMPixel>
class TArray
{
public:
	TArray();
	TArray(size_t size);
	~TArray();
	MyBMPixel& operator[](size_t id);

protected:
	size_t m_size;
	MyBMPixel* m_pArrHead;

private:
};

template<class MyBMPixel>
TArray<MyBMPixel>::TArray()
{
	m_pArrHead = NULL;
}

template<class MyBMPixel>
TArray<MyBMPixel>::TArray(size_t size)
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
MyBMPixel& TArray<MyBMPixel>::operator[](size_t id)
{
	return m_pArrHead[id];
}

#endif