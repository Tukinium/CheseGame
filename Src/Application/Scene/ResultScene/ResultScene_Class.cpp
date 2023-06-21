#include"ResultScene_Class.h"

void ResultScene_Class::SetSharedPtr()
{
}

void ResultScene_Class::Update()
{
	BaseScene_Class::Update();
	if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
	{
		m_changeScene = BaseScene_Class::MainMenuScene;
		CheangeThisScene();
	}
}
