#include "SaveButton.h"
#include "DxLib.h"
#include "MainAdmin.h"

SaveButton::SaveButton(double x,double y,double w,double h,const char* des)
{
	minX = x;
	minY = y;
	Width = w;
	Height = h;
	chara = des;
	admin = make_unique<MainAdmin>();
}


SaveButton::~SaveButton()
{
}

void SaveButton::Update()
{
	MouseClicked = isClicked();
	Mouse_Xpos = admin->mouse_x;
	Mouse_Ypos = admin->mouse_y;
	if (MouseClicked)
	{
		DoEffect();
	}
	DrawButton();
	DrawChara();
	
}

void SaveButton::DoEffect()
{
	admin->SaveFile();
	}