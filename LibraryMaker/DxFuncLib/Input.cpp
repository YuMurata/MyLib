#include"stdafx.h"

#include"Input.h"

#include<DxLib.h>
#include<Coordinate.h>

//UpDate

//
void Input::UpDate()
{
	GetMousePoint(&this->coord.x, &this->coord.y);
	this->mouse_input = GetMouseInput();
}

//Get

//
MouseCoord Input::GetMouseCoord()const
{
	return this->coord;
}


//
bool Input::GetMouseInPut(const int &button)const
{
	return (this->mouse_input&button) != 0;
}