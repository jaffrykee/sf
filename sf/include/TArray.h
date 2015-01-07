#ifndef TARRAY_H
#define TARRAY_H
#pragma execution_character_set("utf-8")
#include <init.h>

template<class MyBMPixel>
class TArray
{
public:
	TArray();
	TArray(UINT size);
	~TArray();
	MyBMPixel& operator[](UINT id);

protected:
	UINT m_size;
	MyBMPixel* m_pArrHead;

private:
};

template<class MyBMPixel>
TArray<MyBMPixel>::TArray()
{
	m_pArrHead = NULL;
}

template<class MyBMPixel>
TArray<MyBMPixel>::TArray(UINT size)
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
MyBMPixel& TArray<MyBMPixel>::operator[](UINT id)
{
	return m_pArrHead[id];
}

#endif