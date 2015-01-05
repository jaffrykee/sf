#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>

using namespace std;

#define StringW wstring
#define StringA string

namespace TStrTrans
{
	StringW AnsiToUnicode(const char* buf);
	StringA UnicodeToAnsi(const wchar_t* buf);
	StringW Utf8ToUnicode(const char* buf);
	StringA UnicodeToUtf8(const wchar_t* buf);
	StringA intIdToStrId(unsigned int id);
	void split(const string& src, const string& separator, vector<string>& dest);
}