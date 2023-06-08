#include "SelectingBord.h"

void SelectingBord_Class::Init()
{
	m_type = Model;
	fillPass = "Asset/Model/Bord_Selecting/Bord_Selecting.gltf";
	SetAsset(m_type, fillPass);
	m_scale = Defalut_Scale_Const;
	m_color = { 0,1,0,0.5 };
}

void SelectingBord_Class::DrawLit()
{
	if (!m_thisModel && !m_model && m_Alive)return;
	if (!m_Selecting)return;
	KdHD2DShader.DrawModel(*m_model, m_mWorld,m_color);
}
