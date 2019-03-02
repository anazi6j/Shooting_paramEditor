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
	return(minX<=Mouse_Xpos&&Mouse_Xpos<=minX+Width&&minY<=Mouse_Ypos&&Mouse_Ypos<=minY+Height)&&(GetMouseInput()&MOUSE_INPUT_LEFT==1);
}

void Button::DrawButton()
{
	DrawBox(minX, Height, Width, minY, yellow,false);
}

void Button::DrawChara()
{
	int XCenter = (minX + Width) / 2;
	int Ycenter = (minY + Height) / 2;
	if (!MouseClicked) {
		DrawString(XCenter, Ycenter, chara, GetColor(255, 255, 255));
	}
	else if (MouseClicked)
	{
		DrawString(XCenter, Ycenter, chara, GetColor(255, 255, 0));
	}
}