#include "MainAdmin.h"
#include <iomanip>
#include "DxLib.h"
#include <iostream>
#include "SaveButton.h"
#include "GameObject.h"
using namespace std;
MainAdmin::MainAdmin():filename("savefile.txt"),quitApplication(false)
{
	//�e�{�^���ƃv���C���[�i�Q�[���I�u�W�F�N�g�j
	//�̗̈�m��
  
	Player_GraphicHandle = LoadGraph("Image\\p.png");
	//�l�p�`�̍���̍��W,�l�p�`�̉E���̍��W
	S_button = make_unique<SaveButton>(400, 100, 450, 150, "Save",this);

	Player = make_unique<GameObject>(Player_GraphicHandle,this);
}


MainAdmin::~MainAdmin()
{
}


void MainAdmin::Init()
{
	ifstream fileinput;
	DrawString(320, 240, "hogeee", GetColor(0, 0, 0));
	

  if (fileinput) {
	  fileinput.open(filename);
  }
 
  //�t�@�C���ɏ������݂���������t�@�C���̒l��ǂݍ���
  if (!fileinput.fail()) {
fileinput >> Player_initX >> Player_initY 
	   >> Player_initHP >> Enemy_initHP
	>>Clear_Score_init;
  }
  fileinput.close();
	
}

void MainAdmin::Update()
{
	mouse = GetMouseInput();
	GetMousePoint(&mouse_x, &mouse_y);
	S_button->Update();
	Player->Update();
}

void MainAdmin::SaveFile()
{
	ofstream fileoutput;
	if (!fileoutput.is_open()) {
		fileoutput.open(filename);
	}
	//�t�@�C���ɏo�͂���
	fileoutput<< 200 << 200
		<< 200 << 200
		<< 200;

	DrawString(320, 240, "�Z�[�u���܂���", GetColor(255, 255, 255));
	fileoutput.close();

	
}

void MainAdmin::end()
{
	
}
