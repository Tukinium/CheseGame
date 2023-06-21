#include"ResultScene_Class.h"
#include"Application/Object/BaseObject/BaseObject.h"
void ResultScene_Class::SetSharedPtr()
{
	if (!m_back)m_back = std::make_shared<BaseObject_Class>();
	m_back->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/Result_Back.png");
	m_baseObjList.push_back(m_back);
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
