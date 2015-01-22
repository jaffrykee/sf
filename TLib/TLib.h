// TLib.h
#pragma once
#pragma execution_character_set("utf-8")

using namespace System;
using namespace std;

#define StringW wstring
#define StringA string

typedef unsigned int UINT;

namespace TLib {
	public ref class TStrTrans
	{
		StringW AnsiToUnicode(const char* buf);
		StringA UnicodeToAnsi(const wchar_t* buf);
		StringW Utf8ToUnicode(const char* buf);
		StringA UnicodeToUtf8(const wchar_t* buf);
		StringA intIdToStrId(UINT id);
		void split(const string& src, const string& separator, vector<string>& dest);
	};

	public ref class TDIndexData
	{
	public:
		const string* m_str;
		map<string, UINT> m_map;

		TDIndexData(const string* strData, UINT max);
		~TDIndexData();
	};
}
