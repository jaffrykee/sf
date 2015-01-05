﻿#pragma execution_character_set("utf-8")
#include <TStrTrans.h>

namespace TStrTrans
{
	StringW AnsiToUnicode(const char* buf)
	{
		int len = ::MultiByteToWideChar(CP_ACP, 0, buf, -1, NULL, 0);
		if (len == 0) return L"";

		std::vector<wchar_t> unicode(len);
		::MultiByteToWideChar(CP_ACP, 0, buf, -1, &unicode[0], len);

		return &unicode[0];
	}

	StringA UnicodeToAnsi(const wchar_t* buf)
	{
		int len = ::WideCharToMultiByte(CP_ACP, 0, buf, -1, NULL, 0, NULL, NULL);
		if (len == 0) return "";

		std::vector<char> utf8(len);
		::WideCharToMultiByte(CP_ACP, 0, buf, -1, &utf8[0], len, NULL, NULL);

		return &utf8[0];
	}

	StringW Utf8ToUnicode(const char* buf)
	{
		int len = ::MultiByteToWideChar(CP_UTF8, 0, buf, -1, NULL, 0);
		if (len == 0) return L"";

		std::vector<wchar_t> unicode(len);
		::MultiByteToWideChar(CP_UTF8, 0, buf, -1, &unicode[0], len);

		return &unicode[0];
	}

	StringA UnicodeToUtf8(const wchar_t* buf)
	{
		int len = ::WideCharToMultiByte(CP_UTF8, 0, buf, -1, NULL, 0, NULL, NULL);
		if (len == 0) return "";

		std::vector<char> utf8(len);
		::WideCharToMultiByte(CP_UTF8, 0, buf, -1, &utf8[0], len, NULL, NULL);

		return &utf8[0];
	}

	StringA intIdToStrId(unsigned int id)
	{
		stringstream ss;
		string tmp;

		ss << id;
		ss >> tmp;
		if (id < 10)
		{
			return "00" + tmp;
		}
		if (id < 100)
		{
			return "0" + tmp;
		}
		if (id < 1000)
		{
			return "" + tmp;
		}
		
		return "";
	}

	void split(const string& src, const string& separator, vector<string>& dest)
	{
		string str = src;
		string substring;
		string::size_type start = 0, index;

		do
		{
			index = str.find_first_of(separator, start);
			if (index != string::npos)
			{
				substring = str.substr(start, index - start);
				dest.push_back(substring);
				start = str.find_first_not_of(separator, index);
				if (start == string::npos) return;
			}
		} while (index != string::npos);

		//the last token
		substring = str.substr(start);
		dest.push_back(substring);
	}
}