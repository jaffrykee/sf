#pragma execution_character_set("utf-8")
#include <TInit.h>
#include <tkmT.h>

//string不可重复，否则mapIndex后一个会把前一个覆盖
TDIndexData::TDIndexData(vector<string> strData) :m_str(strData)
{
	for (UINT i = 0; i < strData.size(); i++)
	{
		m_map.insert(pair<string, UINT>(m_str[i], i));
	}
}

TDIndexData::~TDIndexData()
{

}