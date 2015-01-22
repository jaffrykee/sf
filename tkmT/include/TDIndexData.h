#pragma once
#pragma execution_character_set("utf-8")
#include <tkmT.h>

class TDIndexData
{
public:
	const string* m_str;
	map<string, UINT> m_map;

	TDIndexData(const string* strData, UINT max);
	~TDIndexData();
};