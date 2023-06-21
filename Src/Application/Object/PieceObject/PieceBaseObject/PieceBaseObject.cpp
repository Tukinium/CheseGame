#include"PieceBaseObject.h"

void PieceBaseObject_Class::DrawLit()
{
	if (!m_thisModel && !m_model)return;
	if (!m_Alive)return;
	KdHD2DShader.DrawModel(*m_model, m_mWorld);
}

void PieceBaseObject_Class::Init()
{
	m_type = Model;
	//SetAsset(m_type, fillPass);
	m_scale = DEFAULT_SCALE;
	m_Alive = true;
}

void PieceBaseObject_Class::PieceMoveFixForTeamAreaNotMove()
{
	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			if (GetColor() == kWhiteColor)
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
						//m_canMoveBordInfo[h][w] = Empty;
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
					default:
						break;
					}
				}
			}
			/*
			if (GetColor() == kBlackColor)
			{
				if (m_canMoveBordInfo[h][w] == CanMove)
				{
					switch (m_nowBordInfo[h][w])
					{
					case BaseObject_Class::None:
						break;
					case BaseObject_Class::BlackPawn0:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackPawn1:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackPawn2:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackPawn3:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackPawn4:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackPawn5:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackPawn6:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackPawn7:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackKnight0:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackKnight1:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackRook0:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackRook1:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackBishop0:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackBishop1:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackQueen:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BaseObject_Class::BlackKing:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					default:
						break;
					}
				}
			}
			*/
		}
	}
}
