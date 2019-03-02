#include "GameObject.h"
#include "MainAdmin.h"
#include "DxLib.h"

GameObject::GameObject(int graphic,MainAdmin* ad)
{
	admin = ad;
	Graphichandle = graphic;
	
}


GameObject::~GameObject()
{
}

bool GameObject::isClicked()
{
	//正確じゃないと捕まえてくれない点が問題になる。四角形のあたり判定をつくるのがいいと思われる
	return (x == admin->mouse_x&&y == admin->mouse_y&&MOUSE_INPUT_LEFT);
}

void GameObject::Update()
{
	isbeingClicked = isClicked();
	Draw();
	if (isbeingClicked)
	{
		SetPosition(admin->mouse_x,admin->mouse_y);
	}
}

void GameObject::Draw()
{
	DrawRotaGraph(x, y, 1.0, -PI / 2, Graphichandle, 1, 0);
}

void GameObject::SetPosition(int m_x, int m_y)
{
	x = m_x;
	y = m_y;
}