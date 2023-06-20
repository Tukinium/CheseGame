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
	for (int n = 8; n > -1; n = centerW - i)
	{
		m_canMoveBordInfo[centerH][n] = CanMove;
		if (n == 8)
		{
			m_canMoveBordInfo[centerH][n] = Empty;
		}
		if (m_nowBordInfo[centerH][n] != None)
		{
			m_canMoveBordInfo[centerH][n + 1] = CanMove;
			break;
		}
		i++;
	}

	i = 0;
	for (int n = 0; n <= 8; n = centerW + i)
	{
		i++;
		m_canMoveBordInfo[centerH][n] = CanMove;
		if (m_nowBordInfo[centerH][n] != None)
		{
			m_canMoveBordInfo[centerH][n + 1] = CanMove;
			break;
		}
	}

	i = 0;
	for (int n = 0; n <= 8; n = centerH + i)
	{
		i++;
		m_canMoveBordInfo[n][centerW] = CanMove;
	}

	i = 0;
	for (int n = 8; n > -1; n = centerH - i)
	{
		i++;
		m_canMoveBordInfo[n][centerW] = CanMove;
	}

	m_canMoveBordInfo[centerH][centerW] = Me;
	PieceMoveFixForTeamAreaNotMove();
}
