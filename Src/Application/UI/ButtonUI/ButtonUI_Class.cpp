#include"ButtonUI_Class.h"

void ButtonUI_Class::Init()
{
	UIBaseObject_Class::Init();
	if (!m_SelectingBack)m_SelectingBack = std::make_shared<KdTexture>();
	m_SelectingBack->Load("Asset/Textures/UI/ButtonUI/SelectingBack.png");

	if (!m_UnSelectingBack)m_UnSelectingBack = std::make_shared<KdTexture>();
	m_UnSelectingBack->Load("Asset/Textures/UI/ButtonUI/UnSelectingBack.png");
}

void ButtonUI_Class::DrawSprite()
{

	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mWorld);
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_UnSelectingBack.get(), 0, 0);

	if (Selecting)
	{
		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mWorld);
		KdShaderManager::Instance().m_spriteShader.DrawTex(m_SelectingBack.get(), 0, 0);
	}


	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mWorld);
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex.get(), 0, 0 /*,&m_rc*/);
}
