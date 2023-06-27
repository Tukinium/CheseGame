#include"MainMenuScene.h"
#include"Application/UI/ButtonUI/ButtonUI_Class.h"
#include"Application/Object/BaseObject/BaseObject.h"
#include"Application/Audio/BaseAudio_Class.h"
#include"Application/Object/Mouse/Mouse_Class.h"

void MainMenuScene_Class::SetSharedPtr()
{
	if (!m_backTex)m_backTex = std::make_shared<BaseObject_Class>();
	m_backTex->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/Mainmenu_Back.png");
	m_baseObjList.push_back(m_backTex);

	if (!m_uiTex)m_uiTex = std::make_shared<BaseObject_Class>();
	m_uiTex->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/Menu_UI.png");
	m_baseObjList.push_back(m_uiTex);

	if (!m_SettingButtonUI)m_SettingButtonUI = std::make_shared<ButtonUI_Class>();
	m_SettingButtonUI->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/ButtonUI/Settei_UI.png");
	m_SettingButtonUI->SetPos({ -500 + 175 * 4,-300,0 });
	m_baseObjList.push_back(m_SettingButtonUI);

	if (!m_StartButtleButtonUI)m_StartButtleButtonUI = std::make_shared<ButtonUI_Class>();
	m_StartButtleButtonUI->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/ButtonUI/Taisen_UI.png");
	m_StartButtleButtonUI->SetPos({ -500,-300,0 });
	m_baseObjList.push_back(m_StartButtleButtonUI);

	if (!m_ExitButtonUI)m_ExitButtonUI = std::make_shared<ButtonUI_Class>();
	m_ExitButtonUI->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/ButtonUI/Exit_UI.png");
	m_ExitButtonUI->SetPos({500,-300,0 });
	m_baseObjList.push_back(m_ExitButtonUI);


	//–¢ŽÀ‘•
	if (!m_PartyButtonUI)m_PartyButtonUI = std::make_shared<ButtonUI_Class>();
	m_PartyButtonUI->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/ButtonUI/Party_UI.png");
	m_PartyButtonUI->SetPos({ -500 + 175 * 2,-300,0 });
	m_baseObjList.push_back(m_PartyButtonUI);

	if (!m_UnSetedButtonUI3)m_UnSetedButtonUI3 = std::make_shared<ButtonUI_Class>();
	m_UnSetedButtonUI3->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/ButtonUI/UnSetting_UI.png");
	m_UnSetedButtonUI3->SetPos({ -500 + 175 * 2,-300,0 });
	m_baseObjList.push_back(m_UnSetedButtonUI3);

	//–¢ŽÀ‘•
	if (!m_GatchaButtonUI)m_GatchaButtonUI = std::make_shared<ButtonUI_Class>();
	m_GatchaButtonUI->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/ButtonUI/Gatcha_UI.png");
	m_GatchaButtonUI->SetPos({ -500 + 175 * 3,-300,0 });
	m_baseObjList.push_back(m_GatchaButtonUI);

	if (!m_UnSetedButtonUI2)m_UnSetedButtonUI2 = std::make_shared<ButtonUI_Class>();
	m_UnSetedButtonUI2->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/ButtonUI/UnSetting_UI.png");
	m_UnSetedButtonUI2->SetPos({ -500 + 175 * 3,-300,0 });
	m_baseObjList.push_back(m_UnSetedButtonUI2);

	if (!m_MouseCursor)m_MouseCursor = std::make_shared<MouseCursor_Class>();
	m_baseObjList.push_back(m_MouseCursor);

	
}

void MainMenuScene_Class::Update()
{
	BaseScene_Class::Update();

	m_StartButtleButtonUI->SetSelecting(false);
	m_UnSetedButtonUI2->SetSelecting(false);
	m_UnSetedButtonUI3->SetSelecting(false);
	m_SettingButtonUI->SetSelecting(false);
	m_ExitButtonUI->SetSelecting(false);
	m_PartyButtonUI->SetSelecting(false);
	m_GatchaButtonUI->SetSelecting(false);
	if (fixMousePos.y >= 300 && fixMousePos.y <= 360)
	{
		if (fixMousePos.x <= m_StartButtleButtonUI->GetPos().x + 175/2 && fixMousePos.x >= m_StartButtleButtonUI->GetPos().x -175/2)
		{
			m_StartButtleButtonUI->SetSelecting(true);
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
				m_changeScene = BaseScene_Class::GameScene;

				CheangeThisScene();
			}
		}
		if (fixMousePos.x <= m_UnSetedButtonUI2->GetPos().x + 175 / 2 && fixMousePos.x >= m_UnSetedButtonUI2->GetPos().x - 175 / 2)
		{
			m_UnSetedButtonUI2->SetSelecting(true);
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
				m_changeScene = BaseScene_Class::GameScene;
				CheangeThisScene();
			}
		}
		if (fixMousePos.x <= m_UnSetedButtonUI3->GetPos().x + 175 / 2 && fixMousePos.x >= m_UnSetedButtonUI3->GetPos().x - 175 / 2)
		{
			m_UnSetedButtonUI3->SetSelecting(true);
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
				m_changeScene = BaseScene_Class::GameScene;
				CheangeThisScene();
			}
		}
		if (fixMousePos.x <= m_ExitButtonUI->GetPos().x + 175 / 2 && fixMousePos.x >= m_ExitButtonUI->GetPos().x - 175 / 2)
		{
			m_ExitButtonUI->SetSelecting(true);
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
				m_changeScene = BaseScene_Class::ExitScene;
				CheangeThisScene();
			}
		}
		if (fixMousePos.x <= m_PartyButtonUI->GetPos().x + 175 / 2 && fixMousePos.x >= m_PartyButtonUI->GetPos().x - 175 / 2)
		{
			m_PartyButtonUI->SetSelecting(true);
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
			}
		}
		if (fixMousePos.x <= m_GatchaButtonUI->GetPos().x + 175 / 2 && fixMousePos.x >= m_GatchaButtonUI->GetPos().x - 175 / 2)
		{
			m_GatchaButtonUI->SetSelecting(true);
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
			}
		}
		if (fixMousePos.x <= m_SettingButtonUI->GetPos().x + 175 / 2 && fixMousePos.x >= m_SettingButtonUI->GetPos().x - 175 / 2)
		{
			m_SettingButtonUI->SetSelecting(true);
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
			}
		}
	}
}

