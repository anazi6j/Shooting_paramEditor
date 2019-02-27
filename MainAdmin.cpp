#include "MainAdmin.h"
#include <iomanip>
#include "DxLib.h"
#include <iostream>

using namespace std;
MainAdmin::MainAdmin():filename("savefile"),quitApplication(false)
{
	//�e�{�^���ƃv���C���[�i�Q�[���I�u�W�F�N�g�j
	//�̗̈�m��
	Player_GraphicHandle = LoadGraph("Image\\p.png", 0);
	S_button = make_unique<SaveButton>(400, 100, 200, 400, "Save");
}


MainAdmin::~MainAdmin()
{
}


void MainAdmin::Init()
{
	ifstream fileinput;
	
	

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
}

void MainAdmin::SaveFile()
{
	ofstream fileoutput;
	if (!fileoutput.is_open) {
		fileoutput.open(filename);
	}
	//�t�@�C���ɏo�͂���
	fileoutput<< Player_initX << Player_initY
		<< Player_initHP << Enemy_initHP
		<< Clear_Score_init;

	fileoutput.close();
}

void MainAdmin::end()
{
	
}
