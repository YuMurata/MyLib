#pragma once

#include"ObjectIF.h"
#include<memory>

class DxClass
{
public:
	DxClass();

	~DxClass();
	
	bool Init();

	bool MainLoop();

	bool Draw(const std::unique_ptr<ObjectIF> &obj);

	bool UpDate(const std::unique_ptr<ObjectIF> &obj, Input *input);
};