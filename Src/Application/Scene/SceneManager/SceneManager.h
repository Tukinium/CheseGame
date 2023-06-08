#pragma once
class SceneManager
{
public:
	SceneManager() {};
	~SceneManager() {};
	void Init();
	void Update();
	void Draw();
private:
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