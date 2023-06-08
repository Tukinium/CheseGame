#include"KingPieceObject.h"

void KingPieceObject_Class::Init()
{
	m_type = Model;
	fillPass = "Asset/Model/Piece/King/King.gltf";
	SetAsset(m_type, fillPass);
	m_scale = Defalut_Scale_Const;
	if (m_colorType == White)
	{
		m_pos = { WhiteDefaultPosX,0,WhiteDefaultPosZ };
		m_color = kWhiteColor;
	}
	else if (m_colorType == Black)
	{
		m_pos = { BlackDefaultPosX,0,BlackDefaultPosZ };
		m_color = kBlackColor;
	}
	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("Bord", m_model, KdCollider::TypeGround);
	
}
