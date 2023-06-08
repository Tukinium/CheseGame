#pragma once
class BaseScene_Class;
class GameScene_Class;
class SceneManager
{
public:
	SceneManager() {};
	~SceneManager() {};
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

	void SetScene(const std::shared_ptr<BaseScene_Class> _scene)
	{
		m_nowScene = _scene;
	}
private:
	enum Scene
	{
		TitleScene,
		GameScene,
	};
	int m_Scene = GameScene;
	std::shared_ptr<BaseScene_Class>m_nowScene;
	std::shared_ptr<GameScene_Class>m_gameScene;
public:

	static SceneManager& instance()
	{
		static SceneManager instance;
		return instance;
	}
};