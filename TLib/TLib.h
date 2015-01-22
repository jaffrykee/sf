// TLib.h
#pragma once


using namespace System;
using namespace std;

#define StringW wstring
#define StringA string

typedef unsigned int UINT;

namespace TLib {
	StringW AnsiToUnicode(const char* buf);
	StringA UnicodeToAnsi(const wchar_t* buf);
	StringW Utf8ToUnicode(const char* buf);
	StringA UnicodeToUtf8(const wchar_t* buf);
	StringA intIdToStrId(UINT id);
	void split(const string& src, const string& separator, vector<string>& dest);

	public ref class Class1
	{
		// TODO:  在此处添加此类的方法。
	};
}
