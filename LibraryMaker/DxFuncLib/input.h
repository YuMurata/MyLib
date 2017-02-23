#pragma once

#include<Coordinate.h>

using  MouseCoord=TCoordinate<int>;

class Input
{
private:
	MouseCoord coord;
	int mouse_input;
	
public:
//UpDate

	//
	void UpDate();

//Get

	//
	MouseCoord GetMouseCoord()const;


	//
	bool GetMouseInPut(const int &button)const;
};