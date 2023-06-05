#include "BaseScene.h"
#include"Application/Object/BaseObject/BaseObject.h"
void BaseScene_Class::Update()
{
	for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
	{
		gameObject->Update();
	}
}

void BaseScene_Class::Init()
{
	SetSharedPtr();
	for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
	{
		gameObject->Init();
	}
}

void BaseScene_Class::Draw()
{
	for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
	{
		gameObject->Draw();
	}
}

void BaseScene_Class::DrawLit()
{
	for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
	{
		gameObject->DrawLit();
	}
}

void BaseScene_Class::GenerateDepthMapFromLight()
{
	for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
	{
		gameObject->GenerateDepthMapFromLight();
	}
}

void BaseScene_Class::DrawBright()
{
	for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
	{
		gameObject->DrawBright();
	}
}

void BaseScene_Class::DrawUnLit()
{
	for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
	{
		gameObject->DrawUnLit();
	}
}

void BaseScene_Class::DrawSprite()
{
	for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
	{
		gameObject->DrawSprite();
	}
}

void BaseScene_Class::PreDraw()
{
	for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
	{
		gameObject->PreDraw();
	}
}

void BaseScene_Class::PostDraw()
{
	for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
	{
		gameObject->PostDraw();
	}
}

void BaseScene_Class::PreUpdate()
{
	for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
	{
		gameObject->PreUpdate();
	}
}

void BaseScene_Class::PostUpdate()
{
	for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
	{
		gameObject->PostUpdate();
	}
}

void BaseScene_Class::SetSharedPtr()
{
}

