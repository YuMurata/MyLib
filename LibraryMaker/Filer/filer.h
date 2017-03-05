#pragma once

#include<vector>
#include<string>

class FilerA
{
protected:
	const char delim;

	std::vector<std::vector<std::string>> PreLoad(const std::string &file_name);

	bool PreWrite(const std::string &file_name, const std::vector<std::vector<std::string>> &data_list);

public:
	FilerA(const char &delim = ',') 
		:delim(delim){}

	virtual bool WriteFile(const std::string &file_name) = 0;
	virtual bool LoadFile(const std::string &file_name) = 0;
};

class FilerW
{
protected:
	const wchar_t delim;

	std::vector<std::vector<std::wstring>> PreLoad(const std::wstring &file_name);

	bool PreWrite(const std::wstring &file_name, const std::vector<std::vector<std::wstring>> &data_list);

public:
	FilerW(const wchar_t &delim = ',')
		:delim(delim){}

	virtual bool WriteFile(const std::wstring &file_name) = 0;
	virtual bool LoadFile(const std::wstring &file_name) = 0;
};

#ifdef UNICODE
using Filer = FilerA;
#else
using Filer =FilerW;
#endif // !UNICODE

