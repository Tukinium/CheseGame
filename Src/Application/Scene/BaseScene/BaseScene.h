#pragma once
class BaseObject_Class;
class UIBaseObject_Class;
class BaseScene_Class
{
public:
	BaseScene_Class() {};
	~BaseScene_Class() {};
	virtual void Update();
	virtual void Init();
	virtual void Draw();
	virtual void DrawLit();
	virtual void GenerateDepthMapFromLight();
	virtual void DrawBright();
	virtual void DrawUnLit();
	virtual void DrawSprite();
	virtual void PreDraw();
	virtual void PostDraw();
	virtual void PreUpdate();
	virtual void PostUpdate();
	virtual void SetSharedPtr();
	virtual void Release() {};
	int CheangeThisScene()
	{
		return m_changeScene;
	}
	int SetWinner()
	{
		return m_winner;
	}
	enum Scene
	{
		NoneScene,
		TitleScene,
		MainMenuScene,
		ResultScene,
		GameScene,
		ExitScene,
	};
protected:
	std::list<std::shared_ptr<BaseObject_Class>>m_baseObjList;
	int m_changeScene = NoneScene;
	//マウスクリック誤入力回避用待機時間
	int m_waitTime = 0;
	//待機時間
	const int waitTime = 10;
	//勝った方
	int m_winner = -1;
	//マウス
	POINT MousePos;
	Math::Vector3 fixMousePos;
};