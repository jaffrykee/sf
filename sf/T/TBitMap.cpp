#include <TBitMap.h>

TBitMap::TBitMap(unsigned short wd,unsigned short hi)
{
	m_pMapHead = new TBitArray*[wd];
	for(unsigned short i=0; i<wd; i++)
	{
		m_pMapHead[i] = new TBitArray(hi);
	}
	m_width = wd;
	m_height = hi;
}

TBitMap::~TBitMap()
{
	for(unsigned short i=0; i<m_width; i++)
	{
		delete m_pMapHead[i];
		m_pMapHead[i] = NULL;
	}
	delete []m_pMapHead;
}

TBitArray& TBitMap::operator [](unsigned short id)
{
	return *m_pMapHead[id];
}