#include "SelectingBord.h"

void SelectingBord_Class::Init()
{
	m_modeltype = Model;
	fillPass = "Asset/Model/Bord_Selecting/Now/Bord_NowSelecting.gltf";
	//SetAsset(m_type, fillPass);
	m_scale = DEFAULT_SCALE;
}

void SelectingBord_Class::DrawLit()
{
	if (!m_model || !m_Alive)return;
	KdHD2DShader.DrawModel(*m_model, m_mWorld);
}
