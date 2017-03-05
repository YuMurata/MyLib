#pragma once
#include<Coordinate.h>
#include<DxLib.h>

using ImagCoord = TCoordinate<float>;
using ImagSize = TCoordinate<float>;
using ImagRate = TCoordinate<float>;

class BaseImage
{
protected:
	ImagCoord coord;
	int handle;
	ImagSize size;
	ImagSize apparent_size;
	ImagRate rate;

public:
	BaseImage() 
		:handle(-1),rate(1)
	{}

	void Init(const ImagCoord &coord, const int &handle,const ImagRate &rate)
	{
		this->coord = coord;
		this->handle = handle;
		this->rate = rate;
		GetGraphSizeF(handle, &this->size.x, &this->size.y);
	
		this->apparent_size = this->size*this->rate;
	}

	virtual void Draw()const
	{
		DrawExtendGraphF(this->coord.x, this->coord.y, this->coord.x+this->apparent_size.x, this->coord.y+this->apparent_size.y, this->handle, TRUE);
	}

	virtual void UpDate()
	{

	}

	ImagSize GetSize()const
	{
		return this->size;
	}

	ImagSize GetAppSize()const
	{
		return this->apparent_size;
	}
};