#include"OnTurnViewUI_Class.h"

void OnTurnStartViewUI_Class::Init()
{
	fillPass = "Asset/Textures/UI/OnTurnView_UI.png";
	UIBaseObject_Class::Init();
	m_thRoundTxtTex.Load("Asset/Textures/UI/thRound_UI.png");
}

void OnTurnStartViewUI_Class::Entry()
{
	m_Alive = true;
}

void OnTurnStartViewUI_Class::Leave()
{
	m_Alive = false;
}

void OnTurnStartViewUI_Class::DrawSprite()
{
	if (!m_thisSprite || !m_Alive)return;
	if (m_pos.z >= 0)
	{
		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mWorld);
		KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex.get(), 0, 0 /*,&m_rc*/);

		Math::Matrix mat2 = Math::Matrix::CreateTranslation({0,0,0});
		KdShaderManager::Instance().m_spriteShader.SetMatrix(mat2);
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_thRoundTxtTex, 0, 0 /*,&m_rc*/);
		
	}
}
