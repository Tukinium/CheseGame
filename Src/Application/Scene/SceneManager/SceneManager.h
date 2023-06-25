#pragma once
#include"Application/Scene/BaseScene/BaseScene.h"
class BaseAudio_Class;
class GameScene_Class;
class TitleScene_Class;
class MainMenuScene_Class;
class ResultScene_Class;
class SceneManager_Class
{
public:
	SceneManager_Class() {};
	~SceneManager_Class() {};
	void Update();
	void Init();
	void Draw();
	void DrawLit();
	void GenerateDepthMapFromLight();
	void DrawBright();
	void DrawUnLit();
	void DrawSprite();
	void PreDraw();
	void PostDraw();
	void PreUpdate();
	void PostUpdate();
	void Release();
	void SceneChange(int _scene);
	void GetSceneChange(int _sceneNum);
	void CreateCons();
	void DestoryCons();
	bool SetExit() { return m_exitFlg; }
private:
	//デバッグ
	FILE* fp;
	int m_Scene = BaseScene_Class::TitleScene;
	std::unique_ptr<BaseScene_Class>m_nowScene;
	int m_waitTime = 0;
	const int WAIT_TIME = 10;
	bool m_exitFlg = false;
	int m_winner;

	std::shared_ptr<BaseAudio_Class>m_TitleBgm;
	std::shared_ptr<BaseAudio_Class>m_MainMenuBgm;
	std::shared_ptr<BaseAudio_Class>m_ResultBgm;

public:

	static SceneManager_Class& instance()
	{
		static SceneManager_Class instance;
		return instance;
	}
};