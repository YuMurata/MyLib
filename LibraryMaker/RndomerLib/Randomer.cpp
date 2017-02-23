#include"stdafx.h"

#include"Randomer.h"

using namespace std;

Randomer::Randomer()
{
	random_device rnd;
	this->mt.seed(rnd());
}