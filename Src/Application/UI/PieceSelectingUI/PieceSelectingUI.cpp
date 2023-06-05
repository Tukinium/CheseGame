#include "PieceSelectingUI.h"

void PieceSelectingUI_Class::Init()
{
	m_type = Sprite;
	fillPass = "Asset/Textures/UI/PieceSelecting_UI.png";
	SetAsset(m_type, fillPass);
	m_scale = Defalut_Scale_Const;
}
