#pragma once
#pragma execution_character_set("utf-8")
#include <init.h>

class TDIndexData
{
	map<string, UINT> m_map;
	const string* m_str;

public:
	TDIndexData(const string* strData, UINT max) :m_str(strData)
	{
		for (UINT i = 0; i < max; i++)
		{
			m_map.insert(pair<string, UINT>(m_str[i], i));
		}
	}

	~TDIndexData();
};