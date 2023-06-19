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
	PieceMoveFixForTeamAreaNotMove();
}
