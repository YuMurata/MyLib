#pragma once

#include<vector>
#include<memory>

// vector<unique_ptr<Base>>‚ð•Ô‹p‚·‚é
template <class BaseType, class... Args>
std::vector<std::unique_ptr<BaseType>> VUInitialize(Args&&... args)
{
	using namespace std;
	unique_ptr<BaseType> init[]{ forward<Args>(args)... };
	vector<unique_ptr<BaseType>> ret{ make_move_iterator(begin(init)), make_move_iterator(end(init)) };

	return ret;
}