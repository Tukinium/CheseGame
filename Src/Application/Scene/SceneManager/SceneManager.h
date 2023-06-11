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
	void SetSharedPtr();
	void Release();
	void SetScene(const std::shared_ptr<BaseScene_Class> _scene);

private:
	enum Scene
	{
		TitleScene,
		GameScene,
	};
	int m_Scene = GameScene;
	std::shared_ptr<BaseScene_Class>m_nowScene;
	std::shared_ptr<GameScene_Class>m_gameScene;
	std::shared_ptr<TitleScene_Class>m_titleScene;
public:

	static SceneManager_Class& instance()
	{
		static SceneManager_Class instance;
		return instance;
	}
};