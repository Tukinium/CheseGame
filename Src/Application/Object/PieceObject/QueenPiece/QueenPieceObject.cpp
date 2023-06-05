#include"QueenPieceObject.h"

void QueenPieceObject_Class::Init()
{
	m_type = Model;
	fillPass = "Asset/Model/Piece/Queen/Queen.gltf";
	SetAsset(m_type, fillPass);
	m_scale = Defalut_Scale_Const;
	printf("QueenPiece Init CheckOut\n");
	if (m_colorType == White)
	{
		m_pos = { WhiteDefaultPosX,0,WhiteDefaultPosZ };
		m_color = kWhiteColor;
	}
	else if (m_colorType == Black)
	{
		m_pos = { BlackDefaultPosX,0,BlackDefaultPosZ };
		m_color = kBlackColor;
	}
}
