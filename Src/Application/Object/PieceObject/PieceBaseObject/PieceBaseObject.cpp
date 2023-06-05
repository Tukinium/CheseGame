#include"PieceBaseObject.h"

void PieceBaseObject_Class::DrawLit()
{
	if (!m_thisModel && !m_model)return;
	KdHD2DShader.DrawModel(*m_model, m_mWorld,m_color);
}

void PieceBaseObject_Class::Init()
{
	m_type = None;
	fillPass = "";
	SetAsset(m_type, fillPass);
	m_scale = Defalut_Scale_Const;
}

