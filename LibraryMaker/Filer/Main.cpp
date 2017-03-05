// Filer.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include"Filer.h"
#include<vector>
#include<string>
#include"StringPlus.h"
#include<iostream>
using namespace std;

int main()
{
	wstring file_name = L"1,2,4,5,6";

	auto a = SplitW(file_name);
	auto itr = begin(a);
	for (;itr!=end(a);++itr)
	{
		wcout << *itr << endl;
	}
    return 0;
}

