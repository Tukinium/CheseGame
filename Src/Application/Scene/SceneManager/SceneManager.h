#pragma once
class BaseScene_Class;
class GameScene_Class;
class TitleScene_Class;
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

private:
	enum Scene
	{
		TitleScene,
		GameScene,
	};
	int m_Scene = GameScene;
	std::unique_ptr<BaseScene_Class>m_nowScene;
public:

	static SceneManager_Class& instance()
	{
		static SceneManager_Class instance;
		return instance;
	}
};