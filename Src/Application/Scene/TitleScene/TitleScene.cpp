#include "TitleScene.h"
#include"Application/Object/Mouse/Mouse_Class.h"
#include"Application/Object/BaseObject/BaseObject.h"
void TitleScene_Class::Init()
{
	BaseScene_Class::Init();
}

void TitleScene_Class::Update()
{
	BaseScene_Class::Update();
	if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
	{
		m_changeScene = BaseScene_Class::MainMenuScene;
		CheangeThisScene();
	}
}

void TitleScene_Class::SetSharedPtr()
{
	if (!m_backTex)m_backTex = std::make_shared<BaseObject_Class>();
	m_backTex->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/Title_Back.png");
	m_baseObjList.push_back(m_backTex);

	if (!m_MouseCursor)m_MouseCursor = std::make_shared<MouseCursor_Class>();
	m_baseObjList.push_back(m_MouseCursor);

}
