#pragma once
class BaseScene_Class;
class SceneManager
{
public:
	SceneManager() {};
	~SceneManager() {};
	void Init();
	void Update();
	void Draw();
private:
	std::list<BaseScene_Class>m_sceneList;
	enum Scene
	{
		TitleScene,
		GameScene,
	};
public:

	static SceneManager& instance()
	{
		static SceneManager instance;
		return instance;
	}
};