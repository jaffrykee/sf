#pragma once
#pragma execution_character_set("utf-8")
#include <tkmT.h>

template class __declspec(dllexport) vector<string>;
template class __declspec(dllexport) map<string, UINT>;

class _declspec(dllexport) TDIndexData
{
public:
	vector<string> m_str;
	map<string, UINT> m_map;

	TDIndexData(vector<string> strData, UINT max);
	~TDIndexData();
};