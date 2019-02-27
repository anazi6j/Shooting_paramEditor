#include "Button.h"
#include "DxLib.h"
#include "MainAdmin.h"

Button::Button()
{
	
}


Button::~Button()
{
}

bool Button::isClicked()
{
	return minX <= Mouse_Xpos && Mouse_Xpos <= minX + Width
		&& Mouse_Ypos <= minY && Mouse_Ypos <= minY + Height;
}

void Button::DrawButton()
{
	DrawBox(minX, Height, Width, minY, yellow,false);
}

void Button::DrawChara()
{
	int XCenter = (minX + Width / 2);
	int Ycenter = (minY + Height) / 2;
	DrawString(XCenter, Ycenter, chara, black);
}