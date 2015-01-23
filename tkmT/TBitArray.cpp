#pragma execution_character_set("utf-8")
#include <TInit.h>
#include <tkmT.h>

TBitArray::TBitArray()
{
	m_pArrHead = NULL;
}

TBitArray::TBitArray(unsigned short size)
{
	m_count = size;
	m_size = size / sizeof(UINT) + ((size % sizeof(UINT)) ? 1:0);
	m_pArrHead = new UINT[m_size];
}

TBitArray::~TBitArray()
{
	delete []m_pArrHead;
}