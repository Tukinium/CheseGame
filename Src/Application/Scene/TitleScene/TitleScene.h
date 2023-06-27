#pragma once
class MouseCursor_Class;
#include"Application/Scene/BaseScene/BaseScene.h"
class TitleScene_Class : public BaseScene_Class
{
public:
	void Init()override;
	void Update()override;
	void SetSharedPtr()override;
	bool NowSceneActive()
	{
		return m_nowScene;
	}
	void ActiveTitleSceen(bool _active)
	{
		m_nowScene = _active;
	}
private:
	bool m_nowScene;
	std::shared_ptr<BaseObject_Class>m_backTex;
	std::shared_ptr< MouseCursor_Class>m_MouseCursor;
};
