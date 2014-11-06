#ifndef PPOINT_H
#define PPOINT_H

template <typename MyPointType>
class PPoint
{
public:
	MyPointType m_x, m_y;

public:
	PPoint();
	PPoint(MyPointType x, MyPointType y);

	~PPoint();
};

template <typename MyPointType>
PPoint<MyPointType>::PPoint()
{
}

template <typename MyPointType>
PPoint<MyPointType>::PPoint(MyPointType x, MyPointType y)
{
	m_x = x;
	m_y = y;
}

template <typename MyPointType>
PPoint<MyPointType>::~PPoint()
{
}

#endif
