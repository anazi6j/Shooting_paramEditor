
#include "DxLib.h"
#include <memory>
#include "MainAdmin.h"


int Process(char key[256])
{
	if (ScreenFlip() != 0)return false;//�\��ʂƗ���ʂ����ւ���
	if (ProcessMessage() != 0)return false;//���b�Z�[�W�̎�������
	if (ClearDrawScreen() != 0)return false;//�`�悵�Ă����ʂ���������
	if (GetHitKeyStateAll(key) != 0)return false;//�L�[�{�[�h�̓��͂�����

	return true;

	//false�Ȃ烋�[�v���甲����B


}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɐݒ�
	DxLib_Init();   // DX���C�u��������������
	SetWindowText("�p�����[�^�[�G�f�B�^�[");
	unique_ptr<MainAdmin> mainadmin;
	


	

	
	

	try {
		mainadmin = make_unique<MainAdmin>();
	}
	catch (bad_alloc)
	{
		DrawString(100, 100, "mainadmin�̃������̈�m�ۂɎ��s���܂���", GetColor(255, 255, 255));
	}

	//�Ă΂�ĂȂ�


	while (Process(mainadmin->GetKey())) {
		mainadmin->Update();
		
	}






	

	//SetWindowText("�p�����[�^�[�G�f�B�^�[");

	
	/*
	unique_ptr<MainAdmin> mainadmin;

	try {
		mainadmin = make_unique<MainAdmin>();
	}
	catch (bad_alloc)
	{
		DrawString(100,100,"mainadmin�̃������̈�m�ۂɎ��s���܂���",GetColor(255,255,255));
	}

	//�Ă΂�ĂȂ�
	
		
		mainadmin->Update();
	*/
	

	DxLib_End();    // DX���C�u�����I������
	return 0;
}

/*
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	DxLib_Init();
	ChangeWindowMode(true);
	//SetGraphMode(640, 480, 16);
	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	SetWindowText("�p�����[�^�[�G�f�B�^�[");
	unique_ptr<MainAdmin> mainadmin;
	if (DxLib_Init() == -1) {
		return -1;
	}
	try {
		mainadmin = make_unique<MainAdmin>();
	}
	catch (bad_alloc)
	{
		"mainadmin�̃������̈�m�ۂɎ��s���܂���";
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
