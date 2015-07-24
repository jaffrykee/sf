#pragma execution_character_set("utf-8")
#include "stdafx.h"
#include "../INC/TypeSet.h"

//用法示例
void TestTypeset(HDC dc)
{
	//声明一个板材对象
	CTypeset typeset;
	//设置板材对象大小
	typeset.m_Desktop.m_dHeight = 9999;
	typeset.m_Desktop.m_dWidth = 100;
	//声明一个排样元素对象
	CMaterial material;
	//设置排样元素对象大小
	material.SetSize(20, 99);
	//添加进入板材对象
	typeset.Add(&material);
	//继续添加
	material.SetSize(99, 80);
	typeset.Add(&material);
	material.SetSize(10, 60);
	typeset.Add(&material);
	material.SetSize(50, 20);
	typeset.Add(&material);
	//添加完毕，进行排样
	typeset.Go();
	//排样完毕，输出
	list<CMaterial*>::iterator iter;
	//画板材对象
	::Rectangle(dc, typeset.m_Desktop.m_dX, typeset.m_Desktop.m_dY,
		typeset.m_Desktop.m_dX + typeset.m_Desktop.m_dWidth,
		typeset.m_Desktop.m_dY + typeset.m_Desktop.m_dHeight);
	//画排样元素对象
	for (iter = typeset.m_MaterialList.begin(); iter != typeset.m_MaterialList.end(); iter++)
	{
		::Rectangle(dc, (*iter)->m_dX, (*iter)->m_dY,
			(*iter)->m_dX + (*iter)->m_dWidth,
			(*iter)->m_dY + (*iter)->m_dHeight);
	}

}
//////////////////////////////////////////////////////////////////////
// CMaterial Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define ZERO 0.00001

CMaterial::CMaterial()
{
	m_dHeight = 100;
	m_dWidth = 100;
	m_dX = 0;
	m_dY = 0;
	m_bUsed = FALSE;
	m_bSeletcted = FALSE;
	m_bRotated = FALSE;
	m_iIndex = 0;
}
CMaterial::CMaterial(double dWidth, double dHeight)
{
	SetSize(dWidth, dHeight);
	m_dX = 0;
	m_dY = 0;
	m_bUsed = FALSE;
	m_bSeletcted = FALSE;
	m_bRotated = FALSE;
	m_iIndex = 0;
}
CMaterial::CMaterial(CMaterial *pMaterial)
{
	m_dX = pMaterial->m_dX;
	m_dY = pMaterial->m_dY;
	m_dHeight = pMaterial->m_dHeight;
	m_dWidth = pMaterial->m_dWidth;
	m_bUsed = pMaterial->m_bUsed;
	m_bSeletcted = pMaterial->m_bSeletcted;
	m_bRotated = pMaterial->m_bRotated;
	m_iIndex = pMaterial->m_iIndex;
}
void CMaterial::SetSize(double dWidth, double dHeight)
{
	m_dHeight = dHeight;
	m_dWidth = dWidth;

}
void CMaterial::Rotated()
{
	m_bRotated = !m_bRotated;
	double dA = m_dHeight;
	m_dHeight = m_dWidth;
	m_dWidth = dA;
}

CMaterial::~CMaterial()
{
}
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTypeset::CTypeset()
{
	Clear();
}

CTypeset::~CTypeset()
{
	Clear();
}


void CTypeset::Clear()
{
	list<CMaterial*>::iterator iter;
	for (iter = m_MaterialList.begin(); iter != m_MaterialList.end(); iter++)
	{
		delete (*iter);
	}
	m_MaterialList.clear();
	m_iCurIndex = 0;
}

void CTypeset::Add(CMaterial *pMaterial)
{
	CMaterial *p = new CMaterial(pMaterial);
	p->m_iIndex = m_iCurIndex;
	m_MaterialList.insert(m_MaterialList.end(), p);
	m_iCurIndex++;
}


void CTypeset::Sort()
{
	list<CMaterial*> MaterialList;
	list<CMaterial*>::iterator iter1, iter2, iter3;
	bool bSourceInvert = false;
	while (!m_MaterialList.empty())
	{
		double dMaxLen = 0;
		iter2 = m_MaterialList.begin();
		CMaterial *p = NULL;
		iter1 = m_MaterialList.end()--;
		iter3 = iter2;
		while (iter2 != iter1)
		{
			if ((*iter2)->m_dWidth > dMaxLen)
			{
				p = *iter2;
				iter3 = iter2;
				dMaxLen = (*iter2)->m_dWidth;
				bSourceInvert = false;
			}
			if ((*iter2)->m_dHeight > dMaxLen)
			{
				p = *iter2;
				iter3 = iter2;
				dMaxLen = (*iter2)->m_dHeight;
				bSourceInvert = true;
			}
			iter2++;
		}
		if (p != NULL)
		{
			if (bSourceInvert)
				p->Rotated();
			MaterialList.insert(MaterialList.end(), p);
			m_MaterialList.erase(iter3);
		}
	}
	m_MaterialList.clear();
	for (iter1 = MaterialList.begin(); iter1 != MaterialList.end(); iter1++)
	{
		m_MaterialList.insert(m_MaterialList.end(), (*iter1));
	}
	MaterialList.clear();
}
double CTypeset::Go()
{
	double dRet = 0;
	list<CMaterial*> List;
	list<CMaterial*>::iterator iter;
	Sort();
	Typeset(m_Desktop.m_dX, m_Desktop.m_dY,
		m_Desktop.m_dWidth, m_Desktop.m_dHeight, &List);
	m_MaterialList.clear();
	for (iter = List.begin(); iter != List.end(); iter++)
	{
		if ((*iter)->m_dX < ZERO)
		{
			dRet += (*iter)->m_dY;
		}
		(*iter)->m_bUsed = FALSE;
		(*iter)->m_bSeletcted = FALSE;
		m_MaterialList.insert(m_MaterialList.end(), (*iter));
	}
	List.clear();
	return dRet;
}


double CTypeset::Typeset(double dStartX, double dStartY, double dStartHei, double dStartWid,
	list<CMaterial*> *pList)
{
	CMaterial  *tmpunit = NULL;
	list<CMaterial*>::iterator iter, iter1;
	double  dArea1, dArea2, dArea;//横放和竖放时的排样面积,和最后方案的排样面积
	double  dRestArea1, dRestArea2;//横放和竖放时排样后的剩余面积
	list<CMaterial*> List1, List2;////横放和竖放时的最佳排样序列
	double  dHeight, dWidth;


	dHeight = dStartHei;
	dWidth = dStartWid;

	if (m_MaterialList.empty())
		return 0;
	for (iter = m_MaterialList.begin(); iter != m_MaterialList.end(); iter++)
	{
		if ((*iter)->m_bUsed != FALSE)
			continue;
		if ((*iter)->m_dWidth<(*iter)->m_dHeight)
		{
			MessageBox(NULL, "错误", "ERROR", MB_OK);
			return 0;
		}

		//找出一张能放入的最大的没有排过的板材
		//如果板材横竖都能放入
		if (((dHeight>(*iter)->m_dWidth - ZERO) && (dWidth > (*iter)->m_dHeight - ZERO))
			&& ((dHeight > (*iter)->m_dHeight - ZERO) && (dWidth > (*iter)->m_dWidth - ZERO)))
		{
			if (dStartX < ZERO)
				dWidth = (*iter)->m_dHeight;

			(*iter)->SetUsed(TRUE);//对该图排样

			//先横着放入继续排样，计算剩余面积
			dArea1 = Typeset(dStartX + (*iter)->m_dWidth, dStartY,
				dHeight - (*iter)->m_dWidth, (*iter)->m_dHeight, &List1);
			dRestArea1 = dHeight*dWidth - dArea1 - (*iter)->GetArea();
			dRestArea1 = dRestArea1 / (dHeight*dWidth);//剩余面积率


			//将刚才排过的板材状态还原，再竖直放入该图继续排样，计算剩余面积
			if (dStartX < ZERO)
				dWidth = (*iter)->m_dWidth;

			SetStatus(&List1, FALSE);
			tmpunit = (*iter)->Copy();
			tmpunit->Rotated();
			dArea2 = Typeset(dStartX + tmpunit->m_dWidth, dStartY,
				dHeight - tmpunit->m_dWidth, tmpunit->m_dHeight, &List2);
			dRestArea2 = dHeight*dWidth - dArea2 - tmpunit->GetArea();
			dRestArea2 = dRestArea2 / (dHeight*dWidth);//剩余面积率
		}
		else if ((dHeight > (*iter)->m_dWidth - ZERO) && (dWidth > (*iter)->m_dHeight - ZERO))//如果板材只能横着放入
		{
			if (dStartX < ZERO)
				dWidth = (*iter)->m_dHeight;

			(*iter)->SetUsed(TRUE);//对该图排样
			dArea1 = Typeset(dStartX + (*iter)->m_dWidth, dStartY,
				dHeight - (*iter)->m_dWidth, (*iter)->m_dHeight, &List1);
			dRestArea1 = dHeight*dWidth - dArea1 - (*iter)->GetArea();
			dRestArea1 = dRestArea1 / (dHeight*dWidth);//剩余面积率

			dRestArea2 = dRestArea1 + 10;//不再尝试竖放，将竖放剩余面积设大
		}
		else if ((dHeight > (*iter)->m_dHeight - ZERO) && (dWidth > (*iter)->m_dWidth - ZERO))//如果板材只能竖着放入
		{
			if (dStartX < ZERO)
				dWidth = (*iter)->m_dWidth;

			(*iter)->SetUsed(TRUE);//对该图排样
			tmpunit = (*iter)->Copy();
			tmpunit->Rotated();
			dArea2 = Typeset(dStartX + tmpunit->m_dWidth, dStartY,
				dHeight - tmpunit->m_dWidth, tmpunit->m_dHeight, &List2);
			dRestArea2 = dHeight*dWidth - dArea2 - tmpunit->GetArea();
			dRestArea2 = dRestArea2 / (dHeight*dWidth);//剩余面积率

			dRestArea1 = dRestArea2 + 10;//不再尝试横放，将横放剩余面积设大
		}
		else
			continue;

		//记录优化的排样序列
		CMaterial *tmp = NULL;
		if (dRestArea1 < dRestArea2 + ZERO)//当前板材横向排结果优化
		{
			SetStatus(&List2, FALSE);//将纵向排的排样序列还原状态
			SetStatus(&List1, TRUE);//将横向排的排样序列标志为使用
			dArea = dArea1 + (*iter)->GetArea();;
			tmp = (*iter)->Copy();
			tmp->m_dX = (int)dStartX;
			tmp->m_dY = (int)dStartY;
			pList->insert(pList->end(), tmp);
			while (!List1.empty())
			{
				iter1 = List1.begin();
				pList->insert(pList->end(), *iter1);
				List1.erase(iter1);
			}
			//释放不好的序列
			for (iter1 = List2.begin(); iter1 != List2.end(); iter1++)
			{
				delete (*iter1);
			}
			List2.clear();
			delete tmpunit;
		}
		else//当前板材纵向排结果优化
		{
			SetStatus(&List1, FALSE);//将横向排的排样序列还原状态
			SetStatus(&List2, TRUE);//将纵向排的排样序列标志为使用
			if (tmpunit == NULL)
			{
				MessageBox(NULL, "错误", "ERROR", MB_OK);
				return 0;
			}

			dArea = dArea2 + (*iter)->GetArea();
			tmp = tmpunit->Copy();
			tmp->m_dX = (int)dStartX;
			tmp->m_dY = (int)dStartY;
			pList->insert(pList->end(), tmp);
			while (!List2.empty())
			{
				iter1 = List2.begin();
				pList->insert(pList->end(), *iter1);
				List2.erase(iter1);
			}
			//释放不好的序列
			for (iter1 = List1.begin(); iter1 != List1.end(); iter1++)
			{
				delete (*iter1);
			}
			List1.clear();

			delete tmpunit;
		}
		double next_x, next_y, next_len, next_wid;
		next_x = dStartX;
		next_y = dStartY + tmp->m_dHeight;
		next_len = dHeight;
		next_wid = dStartWid - tmp->m_dHeight;
		if (next_wid > ZERO)//板材还有剩余
		{
			//继续排下一行
			dArea = dArea + Typeset(next_x, next_y, next_len, next_wid, &List1);
			//记录排样序列
			SetStatus(&List1, TRUE);
			for (iter1 = List1.begin(); iter1 != List1.end(); iter1++)
			{
				pList->insert(pList->end(), (*iter1));
			}
			List1.clear();
		}
		return dArea;
	}
	return 0;
}


void CMaterial::SetUsed(BOOL bUsed)
{
	m_bUsed = bUsed;
}

void CTypeset::SetStatus(list<CMaterial*> *pList, BOOL bUsed)
{
	list<CMaterial*>::iterator iter1, iter2;
	for (iter1 = m_MaterialList.begin(); iter1 != m_MaterialList.end(); iter1++)
	{
		for (iter2 = pList->begin(); iter2 != pList->end(); iter2++)
		{
			if ((*iter1)->m_iIndex == (*iter2)->m_iIndex)
			{
				(*iter1)->m_bUsed = bUsed;
			}
		}
	}
}

CMaterial* CMaterial::Copy()
{
	CMaterial* p = new CMaterial(this);
	return p;
}



// TypeSet.h: interface for the CTypeset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TYPESET_H__46213FAE_D2D6_42A6_B801_41D9109CD0FB__INCLUDED_)
#define AFX_TYPESET_H__46213FAE_D2D6_42A6_B801_41D9109CD0FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#pragma warning(disable:4786)
#pragma warning(disable:4251)
#include <list>
#include <string>
using namespace std;

#ifdef TYPESETLIB_EXPORTS
#define TYPESETLIB_API __declspec(dllexport)
#else
#define TYPESETLIB_API __declspec(dllimport)
#endif


TYPESETLIB_API void TestTypeset(HDC dc);

class TYPESETLIB_API CMaterial
{
public:
	virtual CMaterial* Copy();
	virtual void SetUsed(BOOL bUsed);
	virtual void Rotated();
	virtual void SetSize(double dWidth, double dHeight);
	virtual double GetArea(){ return m_dHeight*m_dWidth; }
	CMaterial();
	CMaterial(CMaterial *pMaterial);
	CMaterial(double dWidth, double dHeight);
	virtual ~CMaterial();
	double m_dHeight, m_dWidth;
	double m_dX, m_dY;
	BOOL m_bUsed;
	BOOL m_bSeletcted;
	BOOL m_bRotated;
	int m_iIndex;

};
class TYPESETLIB_API CTypeset
{
public:
	virtual double Go();
	virtual void Add(CMaterial *pMaterial);
	CTypeset();
	virtual ~CTypeset();
	list<CMaterial*> m_MaterialList;
	CMaterial m_Desktop;
protected:
	virtual void SetStatus(list<CMaterial*> *pList, BOOL bUsed);
	virtual double Typeset(double dStatrX, double dStatrY, double dStatrHei, double dStatrWid,
		list<CMaterial*> *pList);
	virtual void Sort();
	virtual void Clear();
	int m_iCurIndex;
};


#endif // !defined(AFX_TYPESET_H__46213FAE_D2D6_42A6_B801_41D9109CD0FB__INCLUDED_)