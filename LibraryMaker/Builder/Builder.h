#pragma once

#include"stdafx.h"

#include<map>
#include<memory>
#include<string>

//�h���N���X�����
//�e���v���[�g�����Ɋ��N���X���w��
template<typename SUPER>
class Builder
{
private:
	class IBaseBuilder
	{
	public:
		virtual std::unique_ptr<SUPER> Create() = 0;
	};

	template<typename SUB>
	class IBuilder:public IBaseBuilder
	{
	public:
		virtual std::unique_ptr<SUPER> Create() 
		{ 
			return std::unique_ptr<SUPER>(new SUB); 
		}
	};

	std::map<std::string, std::unique_ptr<IBaseBuilder>> builders;

public:
	//�h���N���X��o�^
	template<typename SUB>
	void Register(const std::string& ty_name)
	{
		this->builders[ty_name]= std::unique_ptr<IBaseBuilder>(new IBuilder<SUB>);
	}

	//���N���X�̃|�C���^��Ԃ��B
	//���g�͎w�肵���h���N���X
	std::unique_ptr<SUPER> Create(const std::string& ty_name) 
	{
		auto itr = this->builders.find(ty_name);

		if (itr == end(this->builders))
		{
			return nullptr;
		}

		return this->builders[ty_name]->Create();
	}
};