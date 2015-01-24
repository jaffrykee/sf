#pragma once
#pragma execution_character_set("utf-8")

#include <tkmT.h>

using namespace std;

#define StringW wstring
#define StringA string

namespace TStrTrans
{
	StringW _declspec(dllexport) AnsiToUnicode(const char* buf);
	StringA _declspec(dllexport) UnicodeToAnsi(const wchar_t* buf);
	StringW _declspec(dllexport) Utf8ToUnicode(const char* buf);
	StringA _declspec(dllexport) UnicodeToUtf8(const wchar_t* buf);
	StringA _declspec(dllexport) intIdToStrId(UINT id);
	void _declspec(dllexport) split(const string& src, const string& separator, vector<string>& dest);
}