#include"QueenPieceObject.h"

void QueenPieceObject_Class::Init()
{
	fillPass = "Asset/Model/Piece/Queen/Queen.gltf";
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
	PieceBaseObject_Class::Init();
}
