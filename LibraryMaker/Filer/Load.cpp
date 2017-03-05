#include"Filer.h"
#include"StringPlus.h"
#include<fstream>

using namespace std;

vector<vector<string>> FilerA::PreLoad(const string &file_name)
{
	vector<vector<string>> ret;

	ifstream ifs(file_name);
	if (ifs)
	{
		size_t line_num;
		string line;
		for (line_num = 0; getline(ifs, line); ++line_num);

		ret.reserve(line_num);
		
		ifs.clear();
		ifs.seekg(0, ios::beg);

		while (getline(ifs, line))
		{
			auto words = SplitA(line, this->delim);

			ret.push_back(words);
		}

	}

	return ret;
}

vector<vector<wstring>> FilerW::PreLoad(const wstring &file_name)
{
	vector<vector<wstring>> ret;

	wifstream ifs(file_name);
	if (ifs)
	{
		size_t line_num;
		wstring line;
		for (line_num = 0; getline(ifs, line); ++line_num);

		ret.reserve(line_num);

		ifs.clear();
		ifs.seekg(0, ios::beg);

		while (getline(ifs, line))
		{
			auto words = SplitW(line, this->delim);

			ret.push_back(words);
		}

	}

	return ret;
}
