#include "PawnPieceObject.h"

void PawnPieceObject_Class::Init()
{
	fillPass = "Asset/Model/Piece/Pawn/Pawn.gltf";
	PieceBaseObject_Class::Init();
}

void PawnPieceObject_Class::SetDefaultPos(int n)
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

	case 2:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX3,0,WhiteDefaultPosZ3 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			m_pos = { BlackDefaultPosX3,0,BlackDefaultPosZ3 };
			m_color = kBlackColor;
		}
		break;
	}

	case 3:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX4,0,WhiteDefaultPosZ4 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			m_pos = { BlackDefaultPosX4,0,BlackDefaultPosZ4 };
			m_color = kBlackColor;
		}
		break;
	}

	case 4:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX5,0,WhiteDefaultPosZ5 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			m_pos = { BlackDefaultPosX5,0,BlackDefaultPosZ5 };
			m_color = kBlackColor;
		}
		break;
	}

	case 5:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX6,0,WhiteDefaultPosZ6 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			m_pos = { BlackDefaultPosX6,0,BlackDefaultPosZ6 };
			m_color = kBlackColor;
		}
		break;
	}

	case 6:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX7,0,WhiteDefaultPosZ7 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			m_pos = { BlackDefaultPosX7,0,BlackDefaultPosZ7 };
			m_color = kBlackColor;
		}
		break;
	}

	case 7:
	{
		if (m_color == kWhiteColor)
		{
			m_pos = { WhiteDefaultPosX8,0,WhiteDefaultPosZ8 };
			m_color = kWhiteColor;
		}
		else if (m_color == kBlackColor)
		{
			m_pos = { BlackDefaultPosX8,0,BlackDefaultPosZ8 };
			m_color = kBlackColor;
		}
		break;
	}
	default:
		break;
	}
}

int PawnPieceObject_Class::CanMoveBordInfo(int h, int w)
{
	int centerH;
	int centerW;
	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			Math::Vector3 massPos = { h * 1 - 3.5f,0,h * 1 - 3.5f };
			if (0.5f < Math::Vector3::Distance(massPos, m_pos))
			{
				centerH = h;
				centerW = w;
			}
		}
	}

	for (int h = 0; h < 9; h++)
	{
		for (int w = 0; w < 9; w++)
		{
			m_canMoveBordInfo[centerH - 1 + h][centerW - 1 + w] = CanMove;
		}
	}
	m_canMoveBordInfo[centerH][centerW] = Me;
	return m_canMoveBordInfo[h][w];
}

