#include "MainAdmin.h"
#include <iomanip>
#include "DxLib.h"
#include <iostream>

using namespace std;
MainAdmin::MainAdmin():filename("savefile"),quitApplication(false)
{
	//各ボタンとプレイヤー（ゲームオブジェクト）
	//の領域確保
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
 
  //ファイルに書き込みがあったらファイルの値を読み込む
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
	//ファイルに出力する
	fileoutput<< Player_initX << Player_initY
		<< Player_initHP << Enemy_initHP
		<< Clear_Score_init;

	fileoutput.close();
}

void MainAdmin::end()
{
	
}
