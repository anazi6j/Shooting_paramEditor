#include "MainAdmin.h"
#include <iomanip>
#include "DxLib.h"
#include <iostream>
#include "SaveButton.h"
#include "GameObject.h"
using namespace std;
MainAdmin::MainAdmin():filename("savefile.txt"),quitApplication(false)
{
	//各ボタンとプレイヤー（ゲームオブジェクト）
	//の領域確保
  
	Player_GraphicHandle = LoadGraph("Image\\p.png");
	//四角形の左上の座標,四角形の右下の座標
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
	S_button->Update();
	Player->Update();
}

void MainAdmin::SaveFile()
{
	ofstream fileoutput;
	if (!fileoutput.is_open()) {
		fileoutput.open(filename);
	}
	//ファイルに出力する
	fileoutput<< 200 << 200
		<< 200 << 200
		<< 200;

	DrawString(320, 240, "セーブしました", GetColor(255, 255, 255));
	fileoutput.close();

	
}

void MainAdmin::end()
{
	
}
