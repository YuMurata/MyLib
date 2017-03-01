// Builder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include"Builder.h"
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	class Base
	{
	public:
		Base() :x(0), y(1) {}
		int x, y;
		virtual void Disp()=0;
	};

	class X :public Base
	{
		void Disp() { cout << x << endl; }
	};

	class Y:public Base
	{
		void Disp() { cout << y << endl; }
	};

	Builder<Base> obj;
	obj.Register<X>("X");
	obj.Register<Y>("Y");

	unique_ptr<Base> MyClass[2];
	MyClass[0] = obj.Create("X");
	MyClass[1] = obj.Create("Y");

	for (auto &i : MyClass)
	{
		i->Disp();
	}

	_getch();
    return 0;
}

