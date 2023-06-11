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
	bool LeaveScene()
	{
		return m_sceneNow;
	}
protected:
	std::list<std::shared_ptr<BaseObject_Class>>m_baseObjList;
	bool m_sceneNow;
};