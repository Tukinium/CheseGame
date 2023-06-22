#include "RookPieceObject.h"
#include"Application/Object/PieceObject/RookPiece/RookPieceObject.h"

void RookPieceObject_Class::Init()
{
	m_modeltype = Model;
	fillPass = "Asset/Model/Piece/Rook/Rook.gltf";
	SetAsset(m_modeltype, fillPass);
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
	const int max = 8;
	for (int d = 0; centerW - d > -1; d++)
	{
		//std::cout << centerW - d << std::endl;
		m_canMoveBordInfo[centerH][centerW -d] = CanMove;
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
		if (m_nowBordInfo[centerH - r -1][centerW] != None)
		{
			m_canMoveBordInfo[centerH - r -1][centerW] = CanMove;
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

	m_canMoveBordInfo[centerH][centerW] = Me;
	PieceMoveFixForTeamAreaNotMove();
}
