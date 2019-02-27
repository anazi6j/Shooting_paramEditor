#include "DxLib.h"
#include <memory>
#include "MainAdmin.h"
using namespace std;

int IsKeyPressed(char key[256])
{
	if (GetHitKeyStateAll(key) != 0)
		return false;

	return true;
}

int main()
{
	DxLib_Init();
	ChangeWindowMode(true);
	SetGraphMode(640, 480, 16);
	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	unique_ptr<MainAdmin> mainadmin;

	try {
		mainadmin = make_unique<MainAdmin>();
	}
	catch (bad_alloc)
	{
		"mainadmin‚Ìƒƒ‚ƒŠ—ÌˆæŠm•Û‚ÉŽ¸”s‚µ‚Ü‚µ‚½";
	}

	mainadmin->Init();
	while (IsKeyPressed(mainadmin->GetKey()))
	{
		mainadmin->Update();
	}

	
	DxLib_End();
}
