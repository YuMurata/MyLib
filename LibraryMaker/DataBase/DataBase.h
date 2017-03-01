#pragma once

#include<Filer.h>

template<typename Data>
class DataBase:public Filer
{
protected:
	static Data data;
	
public:
	void Set(const Data &data)
	{
		this->data = data;
	}

	Data Get()const
	{
		return this->data;
	}

	bool Get(Data *data)
	{
		if (!data)
		{
			return false;
		}

		*data = this->data;
		return true;
	}
};

template<typename Data>
Data DataBase<Data>::data;