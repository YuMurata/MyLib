#include"stdafx.h"

#include<DxLib.h>
#include"DXFunc.h"

#include<bitset>

using namespace std;

bool Init()
{
	enum
	{
		CW,
		DI,
		SD,
		NUM,
	};
	bitset<NUM> flag;

	flag[CW] = ChangeWindowMode(TRUE) == 0;
	flag[DI] = DxLib_Init() == 0;
	flag[SD] = SetDrawScreen(DX_SCREEN_BACK) == 0;

	return flag.all();
}

bool MainLoop()
{
	enum
	{
		PM,
		NUM,
	};
	bitset<NUM> flag;

	flag[PM] = ProcessMessage() == 0;

	return flag.all();
}

bool Draw(const unique_ptr<ObjectIF> &obj)
{
	ClearDrawScreen();

	obj->Draw();

	ScreenFlip();

	return true;
}

bool UpDate(const unique_ptr<ObjectIF> &obj, Input *input)
{
	input->UpDate();
	obj->UpDate(*input);

	return true;
}