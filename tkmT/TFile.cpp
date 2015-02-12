#pragma execution_character_set("utf-8")
#include <bpt.h>

TFile::TFile(string filter) :m_filter(filter)
{
	char tmpPath[_MAX_PATH] = { '\0' };
	_getcwd(tmpPath, _MAX_PATH);
	m_strPath = tmpPath;
	refreshFileName(m_strPath, m_filter);
}

TFile::TFile(string path, string filter) :m_strPath(path), m_filter(filter)
{
	refreshFileName(m_strPath, m_filter);
}

UINT TFile::refreshFileName(string path, string filter)
{
	long hFile;
	_finddata_t fileInfo;
	UINT count = 0;

	m_arrFileName.clear();
	_chdir(path.c_str());
	if ((hFile = _findfirst(filter.c_str(), &fileInfo)) != -1)
	{
		for (; _findnext(hFile, &fileInfo) == 0;)
		{
			if (!(fileInfo.attrib & _A_SUBDIR))
			{
				string fileName;
				fileName = path + fileInfo.name;
				m_arrFileName.push_back(fileName);
			}
		}
	}

	return m_arrFileName.size();
}