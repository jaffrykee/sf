#ifndef PRECT_H
#define PRECT_H

template <typename MyPointType, typename MyBodyType>
class PRect
{
	public:
		PPoint<MyPointType> m_position;
		MyBodyType m_width,m_height;

	public:
		PRect();
		PRect(MyPointType x,MyPointType y, MyBodyType wd, MyBodyType hi);

		~PRect();
};

template <typename MyPointType, typename MyBodyType>
PRect<MyPointType, MyBodyType>::PRect()
{
}

template <typename MyPointType, typename MyBodyType>
PRect<MyPointType, MyBodyType>::PRect(MyPointType x,MyPointType y, MyBodyType wd, MyBodyType hi)
{
	m_position = PPoint<MyPointType>(x, y);
	m_width = wd;
	m_height = hi;
}

template <typename MyPointType, typename MyBodyType>
PRect<MyPointType, MyBodyType>::~PRect()
{
}

#endif
