#pragma once

#include"ObjectIF.h"
#include<memory>

class DxClass
{
public:
	DxClass(const std::string &title="DxLib");

	~DxClass();
	
	bool Init(const std::string &title);

	bool MainLoop();

	bool Draw(const std::unique_ptr<ObjectIF> &obj);

	bool UpDate(const std::unique_ptr<ObjectIF> &obj, Input *input);
};