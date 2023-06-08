#include "RookPieceObject.h"
#include"Application/Object/PieceObject/RookPiece/RookPieceObject.h"

void RookPieceObject_Class::Init()
{
	m_type = Model;
	fillPass = "Asset/Model/Piece/Rook/Rook.gltf";
	SetAsset(m_type, fillPass);
	m_scale = Defalut_Scale_Const;
}

void RookPieceObject_Class::SetDefaultPos(int n)
{
	switch (n)
	{
	case 0:
	{
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
		break;
	}
	case 1:
	{
		if (m_colorType == White)
		{
			m_pos = { WhiteDefaultPosX2,0,WhiteDefaultPosZ2 };
			m_color = kWhiteColor;
		}
		else if (m_colorType == Black)
		{
			m_pos = { BlackDefaultPosX2,0,BlackDefaultPosZ2 };
			m_color = kBlackColor;
		}
		break;
	}
	default:
		break;
	}
}
