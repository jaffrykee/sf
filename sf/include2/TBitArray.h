#ifndef TBITARRAY_H
#define TBITARRAY_H
#pragma execution_character_set("utf-8")
#include <TInit.h>

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
	size_t* m_pArrHead;

private:
};

#endif
