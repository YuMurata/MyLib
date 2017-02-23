#pragma once

#include<string>
#include<vector>

std::vector<std::string> SplitA(const std::string &str, const char &delim =',');
std::vector<std::wstring> SplitW(const std::wstring &str, const wchar_t &delim = ',');
