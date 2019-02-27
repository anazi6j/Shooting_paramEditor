#pragma once
#include <memory>

class MainAdmin;
using namespace std;
class GameObject
{
protected:
	int x;
	int y;
	const double PI = 3.141592;
	bool isbeingClicked;
	unique_ptr<MainAdmin>admin;
public:
	int Graphichandle;
	GameObject();
	~GameObject();
	virtual void Update();
	virtual void SetPosition(int x, int y);
	void Draw();
	bool isClicked();
};

