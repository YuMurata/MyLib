#pragma once

#include<Builder.h>
#include"ObjectIF.h"

class SceneChanger
{
public:
	static Builder<ObjectIF> builder;

protected:
	static std::string scene_name;
};

