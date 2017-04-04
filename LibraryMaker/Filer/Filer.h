#pragma once

#include<vector>
#include<string>

class FilerA
{
protected:
	using DataList = std::vector<std::vector<std::string>>;
	
	const char delim;

	DataList PreLoad(const std::string &file_name);

	bool PreWrite(const std::string &file_name, const DataList &data_list);

public:
	FilerA(const char &delim = ',') 
		:delim(delim){}

	virtual bool WriteFile(const std::string &file_name) = 0;
	virtual bool LoadFile(const std::string &file_name) = 0;
};

class FilerW
{
protected:
	using DataList = std::vector<std::vector<std::wstring>>;

	const wchar_t delim;

	DataList PreLoad(const std::wstring &file_name);

	bool PreWrite(const std::wstring &file_name, const DataList &data_list);

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

