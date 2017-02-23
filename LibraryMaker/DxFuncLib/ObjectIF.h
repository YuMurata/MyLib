#pragma once

#include"Input.h"

class ObjectIF
{
public:
	virtual void Init() = 0;
	virtual void UpDate(const Input &input) = 0;
	virtual void Draw() = 0;
};