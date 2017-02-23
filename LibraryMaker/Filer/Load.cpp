#include"stdafx.h"
#include"Filer.h"

#include<fstream>
#include<sstream>

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
			stringstream temp(line);

			vector<string> words;
			string word;
			size_t word_num;

			for (word_num = 0; getline(temp, word, this->delim); ++word_num);

			temp.clear();
			temp.seekg(0, ios::beg);

			while (getline(temp, word, this->delim))
			{
				words.push_back(word);
			}

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
			wstringstream temp(line);

			vector<wstring> words;
			wstring word;

			while (getline(temp, word, this->delim))
			{
				words.push_back(word);
			}

			ret.push_back(words);
		}

	}

	return ret;
}
