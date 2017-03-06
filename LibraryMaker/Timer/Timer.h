#pragma once

#include<chrono>
#include<iostream>

using namespace std;

class Timer
{
public:
	template<typename Pre>
	static void Measure(const Pre &func)
	{
		auto start = std::chrono::system_clock::now();
		func();
		auto end = std::chrono::system_clock::now();

		auto diff = end - start;
		cout<< std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
			<< " msec."
			<< std::endl;
	}
};