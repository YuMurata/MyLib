#pragma once

#include"BaseImage.h"
#include<vector>
#include<algorithm>
using namespace std;

class ImageMGR 
{
protected:
	vector<BaseImage> images;
	ImagRate rate;

public:
	ImageMGR(){}

	virtual void Init() = 0;

	void Draw()const
	{
		auto func = [](const BaseImage &imag)
		{
			imag.Draw();
		};

		for_each(begin(this->images), end(this->images), func);
	}
};