#include"BishopPieceObject.h"

void BishopPieceObject_Class::Init()
{
	fillPass = "Asset/Model/Piece/Bishop/Bishop.gltf";
	PieceBaseObject_Class::Init();
}

void BishopPieceObject_Class::SetDefaultPos(int n)
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

void BishopPieceObject_Class::GenCanMoveBordInfo()
{
	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			m_canMoveBordInfo[h][w] = 0;
		}
	}

	GetMassCenter();

	int w = 0;
	int h = 0;
	int i = 0;
	for (int n = 0; n < 8; n++)
	{
		h = centerH + n;
		w = centerW + n;
		if (h > 8 || w > 8)
		{
			break;
		}
		m_canMoveBordInfo[h][w] = CanMove;
	}

	for (int n = 0; n < 8; n++)
	{
		h = centerH - n;
		w = centerW - n;
		if (h < 0 || w < 0)
		{
			break;
		}
		m_canMoveBordInfo[h][w] = CanMove;
	}

	for (int n = 0; n < 8; n++)
	{
		h = centerH - n;
		w = centerW + n;
		if (h < 0 || w > 8)
		{
			break;
		}
		m_canMoveBordInfo[h][w] = CanMove;
	}

	for (int n = 0; n < 8; n++)
	{
		h = centerH + n;
		w = centerW - n;
		if (h > 8 || w < 0)
		{
			break;
		}
		m_canMoveBordInfo[h][w] = CanMove;
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
}
