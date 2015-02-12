#pragma once
#pragma execution_character_set("utf-8")

class TFile
{
public:
	string m_strPath;
	vector<string> m_arrFileName;
	string m_filter;

	TFile(string filter = "*.*");
	TFile(string path, string filter = "*.*");
	UINT refreshFileName(string path, string filter);
};