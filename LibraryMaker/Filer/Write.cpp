#include"stdafx.h"
#include"Filer.h"

#include<fstream>
#include<iterator>
#include<algorithm>

using namespace std;

void FilerA::PreWrite(const string &file_name, const vector<vector<string>> &data_list)
{
	ofstream ofs(file_name);
	
	auto func = [&](const vector<string> &input)
	{
		copy(begin(input), end(input), ostream_iterator<string>(ofs, string({ this->delim }).c_str()));
		ofs << endl;
	};

	for_each(begin(data_list), end(data_list), func);
}

void FilerW::PreWrite(const wstring &file_name, const vector<vector<wstring>> &data_list)
{
	wofstream ofs(file_name);
	
	auto func = [&](const vector<wstring> &input)
	{
		copy(begin(input), end(input), ostream_iterator<wstring,wchar_t>(ofs, wstring({ this->delim }).c_str()));
		ofs << endl;
	};

	for_each(begin(data_list), end(data_list), func);
}