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
		break;
	}
	case 1:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX2,0,WhiteDefaultPosZ2 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
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

int RookPieceObject_Class::CanMoveBordInfo(int h, int w)
{
	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			m_canMoveBordInfo[h][w] = 0;
		}
	}
	GetMassCenter();

	int i = 0;
	for (int n4 = 8; n4 > -1; n4 = centerW - i)
	{
		m_canMoveBordInfo[centerH][n4] = CanMove;
		if (n4 == 8)
		{
			m_canMoveBordInfo[centerH][n4] = Empty;
		}
		i++;
	}

	i = 0;
	for (int n1 = 0; n1 <= 8; n1 = centerH + i)
	{
		i++;
		m_canMoveBordInfo[n1][centerW] = CanMove;
	}

	i = 0;
	for (int n2 = 8; n2 > -1; n2 = centerH - i)
	{
		i++;
		m_canMoveBordInfo[n2][centerW] = CanMove;
	}

	i = 0;
	for (int n3 = centerW; n3 < 8; n3++)
	{
		i++;
		m_canMoveBordInfo[centerH][n3] = CanMove;
	}

	m_canMoveBordInfo[centerH][centerW] = Me;
	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			if (m_canMoveBordInfo[h][w] == CanMove)
			{
				switch (m_nowBordInfo[h][w])
				{
				case BaseObject_Class::None:
					break;
				case BaseObject_Class::WhitePawn0:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhitePawn1:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhitePawn2:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhitePawn3:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhitePawn4:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhitePawn5:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhitePawn6:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhitePawn7:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhiteKnight0:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhiteKnight1:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhiteRook0:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhiteRook1:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhiteBishop0:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhiteBishop1:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhiteQueen:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::WhiteKing:
					m_canMoveBordInfo[h][w] = Empty;
					break;
				case BaseObject_Class::BlackPawn0:
					break;
				case BaseObject_Class::BlackPawn1:
					break;
				case BaseObject_Class::BlackPawn2:
					break;
				case BaseObject_Class::BlackPawn3:
					break;
				case BaseObject_Class::BlackPawn4:
					break;
				case BaseObject_Class::BlackPawn5:
					break;
				case BaseObject_Class::BlackPawn6:
					break;
				case BaseObject_Class::BlackPawn7:
					break;
				case BaseObject_Class::BlackKnight0:
					break;
				case BaseObject_Class::BlackKnight1:
					break;
				case BaseObject_Class::BlackRook0:
					break;
				case BaseObject_Class::BlackRook1:
					break;
				case BaseObject_Class::BlackBishop0:
					break;
				case BaseObject_Class::BlackBishop1:
					break;
				case BaseObject_Class::BlackQueen:
					break;
				case BaseObject_Class::BlackKing:
					break;
				default:
					break;
				}
			}
		}
	}
	return m_canMoveBordInfo[h][w];
}
