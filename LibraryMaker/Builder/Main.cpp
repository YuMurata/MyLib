// Builder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include"Builder.h"
#include<iostream>
#include<vector>
#include<conio.h>
#include<initializer_list>
#include"VUInitialize.h"
using namespace std;



int main()
{
	class Base
	{
	public:
		Base() :x(0), y(1) {}
		int x, y;
		virtual void Disp() 
		{
			cout << "b" << endl;
		};
	};

	class X :public Base
	{
		void Disp() { cout << x << endl; }
	};

	class Y:public Base
	{
		void Disp() { cout << y << endl; }
	};

	auto temp = { make_unique<Base>(),make_unique<Base>() };
	vector<unique_ptr<Base>> MyClass = VUInitialize<Base>(make_unique<X>(),make_unique<Y>());
	//move(begin(temp), end(temp), back_inserter(MyClass));
	for (auto &i : MyClass)
	{
		i->Disp();
	}

	_getch();

    return 0;
}

