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
	m_point = 5;
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

	if (m_propotioned)
	{
		for (int h = 0; h < 8; h++)
		{
			for (int w = 0; w < 8; w++)
			{
				m_canMoveBordInfo[h][w] = 0;
			}
		}
		switch (m_PropotionType)
		{
		case 0:
		{
			const int max = 8;
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
			break;
		}
		case 1:
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
			break;
		}
		case 2:
		{
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
			break;
		}
		case 3:
		{
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
			break;
		}
		default:
			break;
		}
	}
	PieceMoveFixForTeamAreaNotMove();
	
}

void PawnPieceObject_Class::DrawLit()
{
	if (!m_thisModel && !m_model)return;
	if (!m_Alive)return;
	if (!m_propotioned)
	{
		KdHD2DShader.DrawModel(*m_model, m_mWorld);
	}
	if (m_propotioned)
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
