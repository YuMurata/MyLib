#include"stdafx.h"

#include"Split.h"

#include<string>
#include<sstream>

using namespace std;
;
vector<wstring> SplitW(const wstring &str, const wchar_t &delim)
{
	vector<wstring> ret;
	wstringstream input(str);

	wstring word;
	size_t line_num;

	for (line_num = 0; getline(input, word, delim); ++line_num);
	ret.reserve(line_num);

	input.clear();
	input.seekg(0, ios_base::beg);
	while (getline(input, word, delim))
	{
		ret.push_back(word);
	}

	return ret;
}

vector<string> SplitA(const string &str, const char &delim)
{
	vector<string> ret;
	stringstream input(str);

	string word;
	size_t line_num;

	for (line_num = 0; getline(input, word, delim); ++line_num);
	ret.reserve(line_num);

	input.clear();
	input.seekg(0, ios_base::beg);
	while (getline(input, word, delim))
	{
		ret.push_back(word);
	}

	return ret;
}
