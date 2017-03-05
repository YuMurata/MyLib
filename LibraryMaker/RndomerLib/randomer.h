#pragma once

#include"stdafx.h"

#include<random>
#include<numeric>

class Randomer
{
public:
	static std::mt19937 mt;

	Randomer();

	template<typename T>
	typename T::result_type rand(const int &min = 0, const int &max = std::numeric_limits<typename T::result_type>::max())
	{
		T distribution(min, max);
		return distribution(this->mt);
	}
};
