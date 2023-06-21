#pragma once
#include"Application/Scene/BaseScene/BaseScene.h"
class BaseObject;
class ButtonUI_Class;
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
	std::shared_ptr<ButtonUI_Class>m_ExitButtonUI;
};