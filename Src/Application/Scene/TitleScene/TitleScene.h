#pragma once
#include"Application/Scene/BaseScene/BaseScene.h"
class SceneManager_Class;
class TitleScene_Class : public BaseScene_Class
{
public:
	void Init()override;
	void Update()override;
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

	static TitleScene_Class& instance()
	{
		static TitleScene_Class instance;
		return instance;
	}
};
