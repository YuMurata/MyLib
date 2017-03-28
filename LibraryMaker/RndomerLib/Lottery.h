#pragma once
#include"Randomer.h"
#include<vector>
#include<cassert>

template<typename T>
class Lottery :public Randomer
{
private:
	std::vector<T> lotterys;
	T lottery;

public:
	Lottery(const int &start, const int &last)
	{
		assert(last >= start);
		this->lotterys.resize(last - start);
		std::iota(std::begin(this->lotterys), std::end(this->lotterys), start);
	}

	bool Cast()
	{
		auto ret = !this->lotterys.empty();
		if (ret)
		{
			auto index=this->rand<std::uniform_int_distribution<>>(0, std::size(this->lotterys)-1);
			this->lottery=this->lotterys[index];

			this->lotterys.erase(begin(this->lotterys) + index);
		}
		
		return ret;
	}

	T Get()const
	{
		auto ret = this->lottery;
		return ret;
	}
};