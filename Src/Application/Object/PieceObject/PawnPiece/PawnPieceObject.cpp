#include "PawnPieceObject.h"

void PawnPieceObject_Class::Init()
{
	fillPass = "Asset/Model/Piece/Pawn/Pawn.gltf";
	PieceBaseObject_Class::Init();
}

void PawnPieceObject_Class::SetDefaultPos(int n)
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

	case 2:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX3,0,WhiteDefaultPosZ3 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			m_pos = { BlackDefaultPosX3,0,BlackDefaultPosZ3 };
			m_color = kBlackColor;
		}
		break;
	}

	case 3:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX4,0,WhiteDefaultPosZ4 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			m_pos = { BlackDefaultPosX4,0,BlackDefaultPosZ4 };
			m_color = kBlackColor;
		}
		break;
	}

	case 4:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX5,0,WhiteDefaultPosZ5 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			m_pos = { BlackDefaultPosX5,0,BlackDefaultPosZ5 };
			m_color = kBlackColor;
		}
		break;
	}

	case 5:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX6,0,WhiteDefaultPosZ6 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			m_pos = { BlackDefaultPosX6,0,BlackDefaultPosZ6 };
			m_color = kBlackColor;
		}
		break;
	}

	case 6:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX7,0,WhiteDefaultPosZ7 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			m_pos = { BlackDefaultPosX7,0,BlackDefaultPosZ7 };
			m_color = kBlackColor;
		}
		break;
	}

	case 7:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX8,0,WhiteDefaultPosZ8 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			m_pos = { BlackDefaultPosX8,0,BlackDefaultPosZ8 };
			m_color = kBlackColor;
		}
		break;
	}
	default:
		break;
	}
}

int PawnPieceObject_Class::CanMoveBordInfo(int h, int w)
{
	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			m_canMoveBordInfo[h][w] = 0;
		}
	}
	GetMassCenter();
	if (m_color == kWhiteColor)
	{
		m_canMoveBordInfo[centerH - 1][centerW] = CanMove;
		if (!m_firstMoved)
		{
			m_canMoveBordInfo[centerH - 2][centerW] = CanMove;
		}
	}
	if (m_color == kBlackColor)
	{
		m_canMoveBordInfo[centerH + 1][centerW] = CanMove;
		if (!m_firstMoved)
		{
			m_canMoveBordInfo[centerH + 2][centerW] = CanMove;
		}
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

