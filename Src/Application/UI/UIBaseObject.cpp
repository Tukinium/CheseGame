#include"UIBaseObject.h"
#include"Application/Object/CameraObject/Camera.h"
void UIBaseObject_Class::Init()
{
	m_modeltype = Sprite;
	if (fillPass == "")
	{
	}
	else
	{
		SetAsset(m_modeltype, fillPass);
	}
	m_scale = DEFAULT_SCALE;
	m_Alive = false;
}

void UIBaseObject_Class::DrawSprite()
{
	if (!m_tex || !m_Alive)return;

	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex.get(), GetPos().x, GetPos().y, nullptr);

}

void UIBaseObject_Class::PreUpdate()
{
}
