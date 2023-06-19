#include"KingPieceObject.h"

void KingPieceObject_Class::Init()
{
	fillPass = "Asset/Model/Piece/King/King.gltf";
	PieceBaseObject_Class::Init();

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("Bord", m_model, KdCollider::TypeGround);
	
}

void KingPieceObject_Class::SetDefaultPos(int n)
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

void KingPieceObject_Class::GenCanMoveBordInfo()
{
	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			m_canMoveBordInfo[h][w] = 0;
		}
	}
	GenMassCenter();
	//’†S‚ðŠî€‚É”z’u
	for (int h = 0; h < 3; h++)
	{
		for (int w = 0; w < 3; w++)
		{
			m_canMoveBordInfo[centerH - 1 + h][centerW - 1 + w] = CanMove;
		}
	}
	m_canMoveBordInfo[centerH][centerW] = Me;
	PieceMoveFixForTeamAreaNotMove();
}
