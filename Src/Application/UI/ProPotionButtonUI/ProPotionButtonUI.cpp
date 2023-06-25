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
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_UnSelectingBack.get(), GetPos().x, GetPos().y);

	if (m_selecting)
	{
		KdShaderManager::Instance().m_spriteShader.DrawTex(m_SelectingBack.get(), GetPos().x, GetPos().y);
	}


	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex.get(), GetPos().x, GetPos().y /*,&m_rc*/);
}
