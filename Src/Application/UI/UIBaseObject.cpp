#include"UIBaseObject.h"
#include"Application/Object/CameraObject/Camera.h"
void UIBaseObject_Class::Init()
{
	m_type = Sprite;
	SetAsset(m_type, fillPass);
	m_scale = DEFAULT_SCALE;
	m_Alive = false;
}

void UIBaseObject_Class::DrawSprite()
{
	if (!m_thisSprite || !m_Alive)return;
	if (m_pos.z >= 0)
	{
		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mWorld);
		KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex.get(), 0, 0 /*,&m_rc*/);
	}
}

void UIBaseObject_Class::PreUpdate()
{
}
