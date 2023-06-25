#include"KnightPieceObject.h"

void KnightPieceObject_Class::Init()
{
	fillPass = "Asset/Model/Piece/Knight/Knight.gltf";
	PieceBaseObject_Class::Init();
	m_point = 10;
}

void KnightPieceObject_Class::SetDefaultPos(int n)
{
	switch (n)
	{
	case 0:
	{
		if (m_color == kWhiteColor)
		{
			SetPos({ WhiteDefaultPosX,0,WhiteDefaultPosZ });
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			SetPos({ BlackDefaultPosX,0,BlackDefaultPosZ });
			m_color = kBlackColor;
		}
		break;
	}
	case 1:
	{
		if (m_color == kWhiteColor)
		{
			SetPos({ WhiteDefaultPosX2,0,WhiteDefaultPosZ2 });
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			SetPos({ BlackDefaultPosX2,0,BlackDefaultPosZ2 });
			m_color = kBlackColor;
		}
		break;
	}
	default:
		break;
	}
}

void KnightPieceObject_Class::GenCanMoveBordInfo()
{
	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			m_canMoveBordInfo[h][w] = 0;
		}
	}


	GenMassCenter();
	if (centerH + 2 < 8)
	{
		if (centerW + 1 < 8)
		{
			m_canMoveBordInfo[centerH + 2][centerW + 1] = CanMove;
		}
		if (centerW - 1 < 8)
		{
			m_canMoveBordInfo[centerH + 2][centerW - 1] = CanMove;
		}
	}
	if (centerH - 2 > 0)
	{
		if (centerW - 1 > 0)
		{
			m_canMoveBordInfo[centerH - 2][centerW - 1] = CanMove;
		}
		if (centerW + 1 < 8)
		{
			m_canMoveBordInfo[centerH - 2][centerW + 1] = CanMove;
		}
	}
	if (centerW + 2 < 8)
	{
		if (centerH - 1 > 0)
		{
			m_canMoveBordInfo[centerH - 1][centerW + 2] = CanMove;
		}
		if (centerH + 1 < 8)
		{
			m_canMoveBordInfo[centerH + 1][centerW + 2] = CanMove;
		}
	}
	if (centerW - 2 < 8)
	{
		if (centerH - 1 > 0)
		{
			m_canMoveBordInfo[centerH - 1][centerW - 2] = CanMove;
		}
		if (centerH + 1 < 8)
		{
			m_canMoveBordInfo[centerH + 1][centerW - 2] = CanMove;
		}
	}
	PieceMoveFixForTeamAreaNotMove();
}
