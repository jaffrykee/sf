#include <TBitArray.h>

TBitArray::TBitArray()
{
	m_pArrHead = NULL;
}

TBitArray::TBitArray(unsigned short size)
{
	m_count = size;
	m_size = size / sizeof(size_t) + ((size % sizeof(size_t)) ? 1:0);
	m_pArrHead = new size_t[m_size];
}

TBitArray::~TBitArray()
{
	delete []m_pArrHead;
}