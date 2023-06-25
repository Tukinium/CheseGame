#include"ResultScene_Class.h"
#include"Application/Object/BaseObject/BaseObject.h"
void ResultScene_Class::SetSharedPtr()
{
	if (!m_back)m_back = std::make_shared<BaseObject_Class>();
	m_back->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/Result_Back.png");
	m_baseObjList.push_back(m_back);

	if (!m_resultWin)m_resultWin = std::make_shared<BaseObject_Class>();
	m_resultWin->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/Result_Win.png");
	m_resultWin->SetAlive(false);
	m_baseObjList.push_back(m_resultWin);

	if (!m_resultLose)m_resultLose = std::make_shared<BaseObject_Class>();
	m_resultLose->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/Result_Lose.png");
	m_resultLose->SetAlive(false);
	m_baseObjList.push_back(m_resultLose);
}

void ResultScene_Class::Update()
{
	m_resultLose->SetAlive(false);
	m_resultWin->SetAlive(false);
	BaseScene_Class::Update();
	if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
	{
		m_changeScene = BaseScene_Class::MainMenuScene;
		CheangeThisScene();
	}
	switch (m_winner)
	{
	case Player:
	{
		m_resultWin->SetAlive(true);
		break;
	}
	case Enemy:
	{
		m_resultLose->SetAlive(true);
		break;
	}
	default:
		break;
	}
}
