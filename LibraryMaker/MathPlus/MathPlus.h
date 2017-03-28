#pragma once
#include<vector>
#include<cassert>
#include<numeric>
#include<Eigen/Core>

namespace MathPlus
{
	using namespace std;
	namespace Distance
	{
		enum
		{
			Manhattan=1,
			Euclid,
		};

		template<typename T>
		double Distance(const vector<T> &x, const vector<T> &y, const int &pattern = Euclid)
		{
			assert(size(x) == size(y));


			vector<double> buff(size(x));
			transform(begin(x), end(x), begin(y), begin(buff), [](const T &x, const T &y) {return abs(x - y); });

			auto power = [&pattern](T x)
			{
				for (int i = 0; i < pattern; ++i)
				{
					x *= x;
				}

				return x;
			};

			auto func = [&power](const T &left, const T &right)
			{
				return left + power(right);
			};

			auto ret = accumulate(begin(buff), end(buff), (T)0, func);
			return ret;
		}
	}

	template<typename T,typename Pred>
	double Differential(const T &x, const Pred &f,const double &h=1e-3)
	{
		auto ret = (f(x+h) - f(x)) / h;
		return ret;
	}
}