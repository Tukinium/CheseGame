#include "SelectingBord.h"

void SelectingBord_Class::Init()
{
	m_type = Model;
	fillPass = "Asset/Model/Bord_Selecting/Now/Bord_NowSelecting.gltf";
	//SetAsset(m_type, fillPass);
	m_scale = Defalut_Scale_Const;
}

void SelectingBord_Class::DrawLit()
{
	if (!m_thisModel || !m_model || !m_Alive)return;
	KdHD2DShader.DrawModel(*m_model, m_mWorld);
}
