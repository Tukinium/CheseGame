#include "PieceSelectingUI.h"

void PieceSelectingUI_Class::Init()
{
	m_type = Sprite;
	fillPass = "Asset/Textures/UI/PieceSelecting_UI.png";
	SetAsset(m_type, fillPass);
	m_scale = Defalut_Scale_Const;
}

void PieceSelectingUI_Class::DrawLit()
{
	//このインスタンスはModelタイプかチェック＆中身が作成されてるかチェック
	if (!m_thisModel || !m_model || !m_Alive)return;
	KdHD2DShader.DrawModel(*m_model, m_mWorld, color);
}
