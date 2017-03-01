// DataBase.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include"DataBase.h"
#include<algorithm>

using namespace std;

int main()
{
	class aho :public DataBase<vector<double>>
	{
	public:
		bool LoadFile(const string &file_name)
		{
			return true;
		}

		bool WriteFile(const string &file_name)
		{
			vector<string> num_list(size(this->data));
			transform(begin(this->data), end(this->data), begin(num_list), [](const double &x) {return to_string(x); });

			vector<vector<string>> write(1,num_list);
			
			return this->PreWrite(file_name,write);
		}
	} obj1,obj3;
	class baka :public DataBase<vector<double>>
	{
	public:
		bool LoadFile(const string &file_name)
		{
			return true;
		}

		bool WriteFile(const string &file_name)
		{
			vector<string> num_list(size(this->data));
			transform(begin(this->data), end(this->data), begin(num_list), [](const double &x) {return to_string(x); });

			vector<vector<string>> write(1, num_list);

			return this->PreWrite(file_name, write);
		}
	} obj2;

	
	obj1.Set(vector<double>({ 1,2,3,4,5 }));
	auto t=obj2.Get();
	auto y = obj3.Get();
    return 0;
}

