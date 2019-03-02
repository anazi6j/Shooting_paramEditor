
#include "DxLib.h"
#include <memory>
#include "MainAdmin.h"


int Process(char key[256])
{
	if (ScreenFlip() != 0)return false;//表画面と裏画面を入れ替える
	if (ProcessMessage() != 0)return false;//メッセージの自動処理
	if (ClearDrawScreen() != 0)return false;//描画している画面を消去する
	if (GetHitKeyStateAll(key) != 0)return false;//キーボードの入力をする

	return true;

	//falseならループから抜ける。


}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE); // ウィンドウモードに設定
	DxLib_Init();   // DXライブラリ初期化処理
	SetWindowText("パラメーターエディター");
	unique_ptr<MainAdmin> mainadmin;
	


	

	
	

	try {
		mainadmin = make_unique<MainAdmin>();
	}
	catch (bad_alloc)
	{
		DrawString(100, 100, "mainadminのメモリ領域確保に失敗しました", GetColor(255, 255, 255));
	}

	//呼ばれてない


	while (Process(mainadmin->GetKey())) {
		mainadmin->Update();
		
	}






	

	//SetWindowText("パラメーターエディター");

	
	/*
	unique_ptr<MainAdmin> mainadmin;

	try {
		mainadmin = make_unique<MainAdmin>();
	}
	catch (bad_alloc)
	{
		DrawString(100,100,"mainadminのメモリ領域確保に失敗しました",GetColor(255,255,255));
	}

	//呼ばれてない
	
		
		mainadmin->Update();
	*/
	

	DxLib_End();    // DXライブラリ終了処理
	return 0;
}

/*
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	DxLib_Init();
	ChangeWindowMode(true);
	//SetGraphMode(640, 480, 16);
	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	SetWindowText("パラメーターエディター");
	unique_ptr<MainAdmin> mainadmin;
	if (DxLib_Init() == -1) {
		return -1;
	}
	try {
		mainadmin = make_unique<MainAdmin>();
	}
	catch (bad_alloc)
	{
		"mainadminのメモリ領域確保に失敗しました";
	}

	mainadmin->Init();
	while (IsKeyPressed(mainadmin->GetKey()))
	{
		mainadmin->Update();
	}


	DxLib_End();

	return 0;
}
*/
