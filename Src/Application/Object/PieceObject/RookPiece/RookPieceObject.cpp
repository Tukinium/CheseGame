#include "RookPieceObject.h"
#include"Application/Object/PieceObject/RookPiece/RookPieceObject.h"

void RookPieceObject_Class::Init()
{
	m_type = Model;
	fillPass = "Asset/Model/Piece/Rook/Rook.gltf";
	SetAsset(m_type, fillPass);
	m_scale = DEFAULT_SCALE;
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



void RookPieceObject_Class::GenCanMoveBordInfo()
{
	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			m_canMoveBordInfo[h][w] = 0;
		}
	}
	GenMassCenter();

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
		if (m_nowBordInfo[n1][centerH] != None)
		{
			//break;
		}
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
		if (m_nowBordInfo[centerH][n3 += 1] != None)
		{
			std::cout << i << "‰ñ–Ú" << std::endl;
			//m_canMoveBordInfo[centerH][n3 += 1] = CanMove;
			//break;
		}
	}

	m_canMoveBordInfo[centerH][centerW] = Me;
	PieceMoveFixForTeamAreaNotMove();
}
