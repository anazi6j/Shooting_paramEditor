#pragma once
#include <memory>
#include "DxLib.h"
using namespace std;
class MainAdmin;
class Button
{

protected:
	unique_ptr<MainAdmin>admin;
	double minX;
	double minY;
	double Width;
	double Height;
	bool MouseClicked;
	const char* chara;
	const unsigned int yellow = GetColor(255, 255, 0);
	const unsigned int black = GetColor(0, 0, 0);
	//�e�{�^���̊��
public:
	int Mouse_Xpos;
	int Mouse_Ypos;
	Button();
	~Button();
	
	//�{�^���̕��ƍ����̊J�n�_�ƏI���_���L������
	virtual void Update() = 0;
	virtual void DoEffect() = 0;
	void DrawButton();
	virtual void DrawChara();
	bool isClicked();
};

