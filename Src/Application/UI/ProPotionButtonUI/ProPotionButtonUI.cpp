#include "ProPotionButtonUI.h"

void ProPotionButtonUI_Class::Init()
{
	UIBaseObject_Class::Init();
	if (!m_SelectingBack)m_SelectingBack = std::make_shared<KdTexture>();
	m_SelectingBack->Load("Asset/Textures/UI/Propotion/PropotonSelecting.png");

	if (!m_UnSelectingBack)m_UnSelectingBack = std::make_shared<KdTexture>();
	m_UnSelectingBack->Load("Asset/Textures/UI/Propotion/PropotonUnSelecting.png");
}

void ProPotionButtonUI_Class::DrawSprite()
{
	if (!m_Alive)return;
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_UnSelectingBack.get(), m_pos.x, m_pos.y);

	if (Selecting)
	{
		KdShaderManager::Instance().m_spriteShader.DrawTex(m_SelectingBack.get(), m_pos.x, m_pos.y);
	}


	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex.get(), m_pos.x, m_pos.y /*,&m_rc*/);
}
