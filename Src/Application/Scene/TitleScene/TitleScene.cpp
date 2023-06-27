#include "TitleScene.h"
#include"Application/Object/BaseObject/BaseObject.h"
#include"Application/UI/UIBaseObject.h"
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

	m_clickToStart->SetPos({ 0,m_posY,0 });

	if (m_upping)
	{
		m_posY++;
	}
	else
	{
		m_posY--;
	}
	if (m_posY >= 20)
	{
		m_upping = false;
	}
	if (m_posY <= -20)
	{
		m_upping = true;
	}

}

void TitleScene_Class::SetSharedPtr()
{

	if (!m_backTex)m_backTex = std::make_shared<BaseObject_Class>();
	m_backTex->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/Title_Back.png");
	m_baseObjList.push_back(m_backTex);

	if (!m_clickToStart)m_clickToStart = std::make_shared<BaseObject_Class>();
	m_clickToStart->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/ClickToStart.png");
	m_baseObjList.push_back(m_clickToStart);
}
