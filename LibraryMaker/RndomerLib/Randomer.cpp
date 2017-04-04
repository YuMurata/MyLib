#include"Randomer.h"

using namespace std;

mt19937 Randomer::mt;

Randomer::Randomer()
{
	random_device rnd;
	this->mt.seed(rnd());
}

