#pragma once
#include<Coordinate.h>
#include<DxLib.h>

using ImagCoord=TCoordinate<double>;

class BaseImage
{
protected:
	ImagCoord coord;
	int handle;

public:
	BaseImage() 
		:handle(-1)
	{}

	void Draw()const
	{
		DrawGraphF(coord.x, coord.y, this->handle, TRUE);
	}
};