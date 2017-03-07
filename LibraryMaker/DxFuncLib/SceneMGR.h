#pragma once
#include<DxFunc.h>
#include"SceneChanger.h"

class SceneMGR:public SceneChanger
{
private:
	std::unique_ptr<ObjectIF> scene;
	
public:
	void Init(const std::string &scene_name)
	{
		this->scene=(this->builder.Create(scene_name));
		this->scene_name.clear();
		this->scene->Init();
	}

	void UpDate(const Input &input)
	{
		if (!this->scene_name.empty())
		{
			this->scene = (this->builder.Create(this->scene_name));
			this->scene->Init();
			this->scene_name.clear();
		}

		this->scene->UpDate(input);
	}

	void Draw()const
	{
		this->scene->Draw();
	}

};