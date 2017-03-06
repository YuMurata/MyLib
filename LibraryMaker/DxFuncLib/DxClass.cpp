#include<DxLib.h>
#include"DXClass.h"
#include"Resource.h"
#include<bitset>

using namespace std;

DxClass::DxClass(const std::string &title)
{
	this->Init(title);
}

DxClass::~DxClass()
{
	DxLib_End();
}

bool DxClass::Init(const std::string &title)
{
	enum
	{
		CW,
		WI,
		ALV,
		WT,
		DI,
		SD,
		NUM,
	};
	bitset<NUM> flag;

	flag[ALV] = SetOutApplicationLogValidFlag(FALSE) == 0;
	flag[CW] = ChangeWindowMode(TRUE) == 0;
	flag[WI] = SetWindowIconID(IDI_MAINICON) == 0;
	flag[WT] = SetWindowText(title.c_str()) == 0;
	flag[DI] = DxLib_Init() == 0;
	flag[SD] = SetDrawScreen(DX_SCREEN_BACK) == 0;
	auto a = (bool)flag[ALV];
	return flag.all();
}

	bool DxClass::MainLoop()
	{
		enum
		{
			SF,
			PM,
			CD,
			NUM,
		};
		bitset<NUM> flag;


		flag[SF]=ScreenFlip()==0;
		flag[PM] = ProcessMessage() == 0;
		flag[CD]=ClearDrawScreen()==0;

		return flag.all();
	}

	bool DxClass::Draw(const unique_ptr<ObjectIF> &obj)
	{
		obj->Draw();

		return true;
	}

	bool DxClass::UpDate(const unique_ptr<ObjectIF> &obj, Input *input)
	{
		input->UpDate();
		obj->UpDate(*input);

		return true;
	}
