#pragma once
#pragma execution_character_set("utf-8")

template<class MyData>
class _declspec(dllexport) TDataT
{
public:
	UINT m_index;
	string m_name;
	MyData m_data;

	TDataT(string name, MyData data) :m_name(name), m_data(data)
	{

	}
};

template<class MyData>
class _declspec(dllexport) TDIndexDataEx
{
public:
	vector<TDataT<MyData>> m_arr;
	map<string, TDataT<MyData>> m_map;

	TDIndexDataEx(vector<TDataT<MyData>> data)
	{
		for (UINT i = 0; i < data.size(); i++)
		{
			data[i].m_index = i;
			m_map.insert(pair<string, TDataT<MyData>>(data[i].m_name, data[i]));
		}
	}
};