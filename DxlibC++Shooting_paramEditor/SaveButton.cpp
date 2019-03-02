#include "SaveButton.h"
#include "DxLib.h"
#include "MainAdmin.h"

SaveButton::SaveButton(double x,double y,double w,double h,const char* des,MainAdmin* ad)
{
	minX = x;
	minY = y;
	Width = w;
	Height = h;
	chara = des;
	admin = ad;
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
	DrawFormatString(100, 100, GetColor(255, 255, 255), "マウスの座標＝(%d,%d)", Mouse_Xpos, Mouse_Ypos);
}

void SaveButton::DoEffect()
{
	admin->SaveFile();
	}