#include"QueenPieceObject.h"

void QueenPieceObject_Class::SetDefaultPos(int n)
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
	default:
		break;
	}
}

void QueenPieceObject_Class::Init()
{
	fillPass = "Asset/Model/Piece/Queen/Queen.gltf";
	PieceBaseObject_Class::Init();
}

void QueenPieceObject_Class::GenCanMoveBordInfo()
{
	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			m_canMoveBordInfo[h][w] = 0;
		}
	}
	GenMassCenter();
	{
		for (int d = 0; centerW - d > -1; d++)
		{
			//std::cout << centerW - d << std::endl;
			m_canMoveBordInfo[centerH][centerW - d] = CanMove;
			if (m_nowBordInfo[centerH][centerW - d - 1] != None)
			{
				m_canMoveBordInfo[centerH][centerW - d - 1] = CanMove;
				break;
			}
		}
		for (int u = 0; centerW + u < 8; u++)
		{
			//std::cout <<"u_" << centerW + u << std::endl;
			m_canMoveBordInfo[centerH][centerW + u] = CanMove;
			if (m_nowBordInfo[centerH][centerW + u + 1] != None)
			{
				m_canMoveBordInfo[centerH][centerW + u + 1] = CanMove;
				break;
			}
		}
		for (int r = 0; centerH - r > -1; r++)
		{
			//std::cout << centerH - r << std::endl;
			m_canMoveBordInfo[centerH - r][centerW] = CanMove;
			if (m_nowBordInfo[centerH - r - 1][centerW] != None)
			{
				m_canMoveBordInfo[centerH - r - 1][centerW] = CanMove;
				break;
			}
		}
		for (int l = 0; centerH + l < 8; l++)
		{
			//std::cout <<"u_" << centerW + u << std::endl;
			m_canMoveBordInfo[centerH + l][centerW] = CanMove;
			if (m_nowBordInfo[centerH + l + 1][centerW] != None)
			{
				m_canMoveBordInfo[centerH + l + 1][centerW] = CanMove;
				break;
			}
		}
	}
	{
		for (int LD = 0; LD + centerH < 8 || LD + centerW < 8; LD++)
		{
			//std::cout << n + centerH << "_" << n + centerW << std::endl;
			m_canMoveBordInfo[centerH + LD][centerW + LD] = CanMove;
			if (m_nowBordInfo[centerH + LD + 1][centerW + LD + 1] != None)
			{
				m_canMoveBordInfo[centerH + LD + 1][centerW + LD + 1] = CanMove;
				break;
			}
		}
		for (int RU = 0; centerH - RU > -1 || centerW - RU > -1; RU++)
		{
			//std::cout << centerH - n << "_" << centerW - n << std::endl;
			m_canMoveBordInfo[centerH - RU][centerW - RU] = CanMove;
			if (m_nowBordInfo[centerH - RU - 1][centerW - RU - 1] != None)
			{
				m_canMoveBordInfo[centerH - RU - 1][centerW - RU - 1] = CanMove;
				break;
			}
		}
		//ここから下、制限機能不全
		for (int n = 0; centerH - n > -1; n++)
		{
			for (int n2 = 0; n2 + centerW < 8; n2++)
			{
				if (n == n2)
				{
					m_canMoveBordInfo[centerH - n][centerW + n2] = CanMove;
					if (m_nowBordInfo[centerH - n - 1][centerW + n2 + 1] != None)
					{
						m_canMoveBordInfo[centerH - n - 1][centerW + n2 + 1] = CanMove;
						break;
					}
				}
			}
		}
		for (int n = 0; centerH + n < 8; n++)
		{
			for (int n2 = 0; centerW - n2 > -1; n2++)
			{
				if (n == n2)
				{
					m_canMoveBordInfo[centerH + n][centerW - n2] = CanMove;
					if (m_nowBordInfo[centerH + n + 1][centerW - n2 - 1] != None)
					{
						m_canMoveBordInfo[centerH + n + 1][centerW - n2 - 1] = CanMove;
						break;
					}
				}
			}
		}
	}
	{
		for (int h = 0; h < 3; h++)
		{
			for (int w = 0; w < 3; w++)
			{
				m_canMoveBordInfo[centerH - 1 + h][centerW - 1 + w] = CanMove;
			}
		}
	}
	m_canMoveBordInfo[centerH][centerW] = Me;
	PieceMoveFixForTeamAreaNotMove();
}


