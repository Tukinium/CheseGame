#include "PawnPieceObject.h"

void PawnPieceObject_Class::Init()
{
	fillPass = "Asset/Model/Piece/Pawn/Pawn.gltf";
	PieceBaseObject_Class::Init();
	std::string str = "Asset/Model/Piece/";
	KnightModel = std::make_shared<KdModelWork>();
	BishopModel = std::make_shared<KdModelWork>();
	RookModel = std::make_shared<KdModelWork>();
	QueenModel = std::make_shared<KdModelWork>();
	if (m_color == kWhiteColor)
	{
		KnightModel->SetModelData("Asset/Model/Piece/White/Knight/Knight.gltf");
		RookModel->SetModelData("Asset/Model/Piece/White/Rook/Rook.gltf");
		BishopModel->SetModelData("Asset/Model/Piece/White/Bishop/Bishop.gltf");
		QueenModel->SetModelData("Asset/Model/Piece/White/Queen/Queen.gltf");
	}
	if (m_color == kBlackColor)
	{
		KnightModel->SetModelData("Asset/Model/Piece/Black/Knight/Knight.gltf");
		RookModel->SetModelData("Asset/Model/Piece/Black/Rook/Rook.gltf");
		BishopModel->SetModelData("Asset/Model/Piece/Black/Bishop/Bishop.gltf");
		QueenModel->SetModelData("Asset/Model/Piece/Black/Queen/Queen.gltf");
	}
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

void PawnPieceObject_Class::GenCanMoveBordInfo()
{
	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			m_canMoveBordInfo[h][w] = 0;
		}
	}
	GenMassCenter();
	if (m_color == kWhiteColor)
	{
		m_canMoveBordInfo[centerH - 1][centerW] = CanMove;
		if (!m_firstMoved)
		{
			m_canMoveBordInfo[centerH - 2][centerW] = CanMove;
			if (m_nowBordInfo[centerH - 2][centerW] != None)
			{
				m_canMoveBordInfo[centerH - 2][centerW] = None;
			}
		}
		if (m_nowBordInfo[centerH - 1][centerW - 1] != None)
		{
			m_canMoveBordInfo[centerH - 1][centerW - 1] = CanMove;
		}
		if (m_nowBordInfo[centerH - 1][centerW + 1] != None)
		{
			m_canMoveBordInfo[centerH - 1][centerW + 1] = CanMove;
		}
		if (m_nowBordInfo[centerH - 1][centerW] != None)
		{
			m_canMoveBordInfo[centerH - 1][centerW] = None;
		}
	}
	if (m_color == kBlackColor)
	{
		m_canMoveBordInfo[centerH + 1][centerW] = CanMove;
		if (!m_firstMoved)
		{
			m_canMoveBordInfo[centerH + 2][centerW] = CanMove;
			if (m_nowBordInfo[centerH + 2][centerW] != None)
			{
				m_canMoveBordInfo[centerH + 2][centerW] = None;
			}
		}
		if (m_nowBordInfo[centerH + 1][centerW - 1] == WhitePawn0 || m_nowBordInfo[centerH + 1][centerW - 1] == WhitePawn1 || m_nowBordInfo[centerH + 1][centerW - 1] == WhitePawn2 || m_nowBordInfo[centerH + 1][centerW - 1] == WhitePawn3 || m_nowBordInfo[centerH + 1][centerW - 1] == WhitePawn4 || m_nowBordInfo[centerH + 1][centerW - 1] == WhitePawn5 || m_nowBordInfo[centerH + 1][centerW - 1] == WhitePawn6 || m_nowBordInfo[centerH + 1][centerW - 1] == WhitePawn7)
		{
			m_canMoveBordInfo[centerH + 1][centerW - 1] = CanMove;
		}
		if (m_nowBordInfo[centerH + 1][centerW + 1] == WhitePawn0 || m_nowBordInfo[centerH + 1][centerW + 1] == WhitePawn1 || m_nowBordInfo[centerH + 1][centerW + 1] == WhitePawn2 || m_nowBordInfo[centerH + 1][centerW + 1] == WhitePawn3 || m_nowBordInfo[centerH + 1][centerW + 1] == WhitePawn4 || m_nowBordInfo[centerH + 1][centerW + 1] == WhitePawn5 || m_nowBordInfo[centerH + 1][centerW + 1] == WhitePawn6 || m_nowBordInfo[centerH + 1][centerW + 1] == WhitePawn7)
		{
			m_canMoveBordInfo[centerH + 1][centerW + 1] = CanMove;
		}
		if (m_nowBordInfo[centerH + 1][centerW] != None)
		{
			m_canMoveBordInfo[centerH + 1][centerW] = None;
		}
	}
	m_canMoveBordInfo[centerH][centerW] = Me;

	if (centerH == 0 && m_color == kWhiteColor)
	{
		m_canPropotion = true;
	}
	if (centerH == 8 && m_color == kWhiteColor)
	{
		m_canPropotion = true;
	}
	PieceMoveFixForTeamAreaNotMove();
	
}

void PawnPieceObject_Class::DrawLit()
{
	if (!m_thisModel && !m_model)return;
	if (!m_Alive)return;
	if (!Propotioned)
	{
		KdHD2DShader.DrawModel(*m_model, m_mWorld);
	}
	if (Propotioned)
	{
		switch (m_PropotionType)
		{
		case 0:
		{
			KdHD2DShader.DrawModel(*RookModel, m_mWorld);
			break;
		}
		case 1:
		{
			KdHD2DShader.DrawModel(*BishopModel, m_mWorld);
			break;
		}
		case 2:
		{
			KdHD2DShader.DrawModel(*KnightModel, m_mWorld);
			break;
		}
		case 3:
		{
			KdHD2DShader.DrawModel(*QueenModel, m_mWorld);
			break;
		}
		default:
			break;
		}
	}
}
