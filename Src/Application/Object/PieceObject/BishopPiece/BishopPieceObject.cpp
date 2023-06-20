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

	GenMassCenter();

	for (int LD = 0;  LD + centerH < 8 ||  LD + centerW < 8; LD++)
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
				std::cout << centerH - n << "_" << centerW + n2 << std::endl;
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
		for (int n2 = 0;centerW - n2 > -1; n2++)
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
	m_canMoveBordInfo[centerH][centerW] = Me;
	//PieceMoveFixForTeamAreaNotMove();
}
