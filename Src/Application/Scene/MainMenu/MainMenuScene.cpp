#include"MainMenuScene.h"
#include"Application/UI/ButtonUI/ButtonUI_Class.h"
#include"Application/Object/BaseObject/BaseObject.h"
void MainMenuScene_Class::SetSharedPtr()
{
	if (!m_backTex)m_backTex = std::make_shared<BaseObject_Class>();
	m_backTex->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/Mainmenu_Back.png");
	m_baseObjList.push_back(m_backTex);

	if (!m_uiTex)m_uiTex = std::make_shared<BaseObject_Class>();
	m_uiTex->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/Menu_UI.png");
	//m_baseObjList.push_back(m_uiTex);

	if (!m_SettingButtonUI)m_SettingButtonUI = std::make_shared<ButtonUI_Class>();
	m_SettingButtonUI->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/ButtonUI/Settei_UI.png");
	m_SettingButtonUI->SetPos({ 100,-300,0 });
	m_baseObjList.push_back(m_SettingButtonUI);

	if (!m_StartButtleButtonUI)m_StartButtleButtonUI = std::make_shared<ButtonUI_Class>();
	m_StartButtleButtonUI->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/ButtonUI/Taisen_UI.png");
	m_StartButtleButtonUI->SetPos({ -500,-300,0 });
	m_baseObjList.push_back(m_StartButtleButtonUI);

	if (!m_UnSetedButtonUI)m_UnSetedButtonUI = std::make_shared<ButtonUI_Class>();
	m_UnSetedButtonUI->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/ButtonUI/UnSetting_UI.png");
	m_UnSetedButtonUI->SetPos({ -500 + 175,-300,0 });
	m_baseObjList.push_back(m_UnSetedButtonUI);

	if (!m_ExitButtonUI)m_ExitButtonUI = std::make_shared<ButtonUI_Class>();
	m_ExitButtonUI->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/ButtonUI/Exit_UI.png");
	m_ExitButtonUI->SetPos({500,-300,0 });
	m_baseObjList.push_back(m_ExitButtonUI);
}

void MainMenuScene_Class::Update()
{
	BaseScene_Class::Update();
	m_StartButtleButtonUI->SetSelecting(false);
	m_UnSetedButtonUI->SetSelecting(false);
	m_SettingButtonUI->SetSelecting(false);
	m_ExitButtonUI->SetSelecting(false);
	if (fixMousePos.y >= 300 && fixMousePos.y <= 360)
	{
		if (fixMousePos.x >= -570 && fixMousePos.x <= -400)
		{
			m_StartButtleButtonUI->SetSelecting(true);
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
				m_changeScene = BaseScene_Class::GameScene;
				CheangeThisScene();
			}
		}
		if (fixMousePos.x >= -400 && fixMousePos.x <= -230)
		{
			m_UnSetedButtonUI->SetSelecting(true);
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
				m_changeScene = BaseScene_Class::GameScene;
				CheangeThisScene();
			}
		}
		if (fixMousePos.x <= 500 + 175 / 2 && fixMousePos.x >= 500 - 175 / 2)
		{
			m_ExitButtonUI->SetSelecting(true);
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
				m_changeScene = BaseScene_Class::ExitScene;
				CheangeThisScene();
			}
		}
	}
	std::cout << fixMousePos.x << "_" << fixMousePos.y << std::endl;
	//30/190
	//m_changeScene = BaseScene_Class::GameScene;
	//CheangeThisScene();
}

