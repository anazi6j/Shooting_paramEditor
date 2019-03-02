#pragma once
#include "Button.h"

using namespace std;

class MainAdmin;
class SaveButton:public Button 
{
protected:
	MainAdmin* admin;

public:
	SaveButton(double x, double y, double w, double h, const char* des,MainAdmin* ad);
	~SaveButton();

	virtual void Update()override;
	virtual void DoEffect()override;
};

