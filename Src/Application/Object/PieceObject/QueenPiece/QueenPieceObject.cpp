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

	for (int h = 0; h < 3; h++)
	{
		for (int w = 0; w < 3; w++)
		{
			m_canMoveBordInfo[centerH - 1 + h][centerW - 1 + w] = CanMove;
		}
	}

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
	}

	int w = 0;
	int h = 0;
	i = 0;
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


