#pragma once
#include<iostream>

template<typename _T>
class TCoordinate
{
public:
	_T x;
	_T y;

public:
	TCoordinate() :TCoordinate(0, 0) 
	{}

	TCoordinate(const _T &x, const _T &y)
		: x(x), y(y) {}

	TCoordinate(const _T &obj)
		:TCoordinate(obj, obj) {}

public://++++++++++++++++++++++++++++++++++++++++++++++++++
	template<typename _U>
	TCoordinate operator+(const TCoordinate<_U> &obj)const
	{
		return TCoordinate(this->x + obj.x, this->y + obj.y);
	}

	template<typename _U>
	TCoordinate operator+=(const TCoordinate<_U> &obj)
	{
		*this = *this + obj;
		return *this;
	}

public://---------------------------------------------------
	template<typename _U>
	TCoordinate operator-(const TCoordinate<_U> &obj)const
	{
		return TCoordinate(this->x - obj.x, this->y - obj.y);
	}

public://****************************************************
	template<typename _U>
	TCoordinate operator*(const TCoordinate<_U> &obj)const
	{
		return TCoordinate(this->x*obj.x, this->y*obj.y);
	}

public:////////////////////////////////////////////////////////////
	template<typename _U>
	TCoordinate& operator/=(const TCoordinate<_U> &obj)
	{
		*this = *this / obj;
		return *this;
	}

	template<typename _U>
	TCoordinate operator/(const TCoordinate<_U> &obj)const
	{
		return TCoordinate(this->x / obj.x, this->y / obj.y);
	}

public://=========================================================
	TCoordinate& operator=(const TCoordinate &obj)
	{
		this->x = obj.x;
		this->y = obj.y;

		return *this;
	}

	template<typename _U>
	TCoordinate& operator=(const TCoordinate<_U> &obj)
	{
		this->x = (_T)obj.x;
		this->y = (_T)obj.y;

		return *this;
	}

public://()()()()()()()()()()()()()()()()()()()()()()()()()()()()
	template<typename _U>
	operator TCoordinate<_U>()const
	{
		return TCoordinate<_U>(this->x, this->y);
	}

public://==~==~==~==~==~==~==~==~==~==~==~==~==~==~
	template<typename _U>
	bool operator==(const TCoordinate<_U> &obj)const
	{
		bool x = this->x == obj.x;
		bool y = this->y == obj.y;

		return x&&y;
	}

public://<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	template<typename _U>
	bool operator<(const TCoordinate<_U> &obj)const
	{
		bool x = this->x < obj.x;
		bool y = this->y < obj.y;

		return x&&y;
	}

public://<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=
	template<typename _U>
	bool operator<=(const TCoordinate<_U> &obj)const
	{
		bool x = this->x <= obj.x;
		bool y = this->y <= obj.y;

		return x&&y;
	}

	friend std::ostream& operator<<(std::ostream& stream, const TCoordinate<_T>& value)
	{
		stream << value.x << "," << value.y << ",";
		return stream;
	}
	
};

