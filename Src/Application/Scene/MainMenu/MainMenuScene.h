#pragma once
#include"Application/Scene/BaseScene/BaseScene.h"]
class BaseObject;
class ButtonUI_Class;
class BaseAudio_Class;
class MouseCursor_Class;
class MainMenuScene_Class : public BaseScene_Class
{
public:
	void SetSharedPtr()override;
	void Update()override;
private:
	std::shared_ptr<BaseObject_Class>m_backTex;
	std::shared_ptr<BaseObject_Class>m_uiTex;
	
	std::shared_ptr<ButtonUI_Class>m_SettingButtonUI;
	std::shared_ptr<ButtonUI_Class>m_StartButtleButtonUI;
	std::shared_ptr<ButtonUI_Class>m_UnSetedButtonUI;
	std::shared_ptr<ButtonUI_Class>m_UnSetedButtonUI2;
	std::shared_ptr<ButtonUI_Class>m_UnSetedButtonUI3;
	std::shared_ptr<ButtonUI_Class>m_PartyButtonUI;
	std::shared_ptr<ButtonUI_Class>m_ExitButtonUI;
	std::shared_ptr<ButtonUI_Class>m_GatchaButtonUI;
	std::shared_ptr<MouseCursor_Class>m_MouseCursor;

	std::string m_UserName = "UnSetName";
};