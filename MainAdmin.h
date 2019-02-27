#pragma once
#include <fstream>
using namespace std;

class SaveButton;
class MainAdmin
{
protected:
	//エディターを読み込んだ時の、自機の初期位置
	int Player_initX;
	int Player_initY;

	int Player_initHP;
	int Enemy_initHP;

	int Clear_Score_init;
	char key[256];
	bool quitApplication;
	
	int Player_GraphicHandle;
	std::unique_ptr<SaveButton>S_button;
public:
	int mouse_x;
	int mouse_y;
	int mouse;
	
	const char* filename;
	
	MainAdmin();
	~MainAdmin();
	int GetP_initX() { return Player_initX; }
	int GetP_initY() {
		return Player_initY;
	}
	int GetP_initHP() {
		return Player_initHP;
	}
	int GetE_initHP() {
		return Enemy_initHP;
	}
	int GetClear_Score_Init()
	{
		return Clear_Score_init;
	}
	void Init();

	void Update();

	void SaveFile();

	void end();
	char* GetKey() { return key; }
};

