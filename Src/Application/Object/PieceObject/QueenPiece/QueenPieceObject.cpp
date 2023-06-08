#include"QueenPieceObject.h"

void QueenPieceObject_Class::Init()
{
	m_type = Model;
	fillPass = "Asset/Model/Piece/Queen/Queen.gltf";
	SetAsset(m_type, fillPass);
	m_scale = Defalut_Scale_Const;
	if (m_color == kWhiteColor)
	{
		m_pos = { WhiteDefaultPosX,0,WhiteDefaultPosZ };
		m_color = kWhiteColor;
	}
	else if (m_color == kBlackColor)
	{
		m_pos = { BlackDefaultPosX,0,BlackDefaultPosZ };
		m_color = kBlackColor;
	}
}
