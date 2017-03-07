#pragma once

#include"SceneMGR.h"
#include"input.h"
#include<memory>

class DxClass
{
public:
	DxClass(const std::string &title="DxLib");

	~DxClass();
	
	bool Init(const std::string &title);

	bool MainLoop();

	bool Draw(const SceneMGR &scene);

	bool UpDate(SceneMGR *scene, Input *input);
};