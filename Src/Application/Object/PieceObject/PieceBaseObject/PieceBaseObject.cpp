#include"PieceBaseObject.h"


void PieceBaseObject_Class::Init()
{
	m_modeltype = Model;
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
					case None:
						break;
					case WhitePawn0:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhitePawn1:
						//m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhitePawn2:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhitePawn3:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhitePawn4:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhitePawn5:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhitePawn6:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhitePawn7:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhiteKnight0:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhiteKnight1:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhiteRook0:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhiteRook1:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhiteBishop0:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhiteBishop1:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhiteQueen:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case WhiteKing:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					default:
						break;
					}
				}
			}
			
			if (GetColor() == kBlackColor)
			{
				if (m_canMoveBordInfo[h][w] == CanMove)
				{
					switch (m_nowBordInfo[h][w])
					{
					case None:
						break;
					case BlackPawn0:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackPawn1:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackPawn2:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackPawn3:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackPawn4:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackPawn5:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackPawn6:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackPawn7:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackKnight0:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackKnight1:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackRook0:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackRook1:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackBishop0:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackBishop1:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackQueen:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					case BlackKing:
						m_canMoveBordInfo[h][w] = Empty;
						break;
					default:
						break;
					}
				}
			}
			
		}
	}
}

void PieceBaseObject_Class::GenMassCenter()
{
	
	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			Math::Vector3 massPos = { h * 1 - 3.5f,0,w * 1 - 3.5f };
			if (Math::Vector3::Distance(massPos, GetPos2()) < 0.5)
			{
				centerH = h;
				centerW = w;

			}
		}
	}
	//centerH = static_cast<int>(GetPos2().x - 0.5);
	//centerW = static_cast<int>(GetPos2().y - 0.5);

}
