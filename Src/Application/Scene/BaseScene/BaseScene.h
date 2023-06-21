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
	//�}�E�X�N���b�N����͉��p�ҋ@����
	int m_waitTime = 0;
	//�ҋ@����
	const int waitTime = 10;
	//��������
	int m_winner = -1;
	//�}�E�X
	POINT MousePos;
	Math::Vector3 fixMousePos;
};