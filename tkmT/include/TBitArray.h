#pragma once
#pragma execution_character_set("utf-8")
#include <tkmT.h>

class TBitArray
{
public:
	TBitArray();
	TBitArray(unsigned short size);
	~TBitArray();
	bool& operator[](unsigned short id);

protected:
	unsigned short m_size;
	unsigned short m_count;
	UINT* m_pArrHead;

private:
};