#include"BordObject.h"

void BordObject_Class::Init()
{
	m_type = Model;
	fillPass = "Asset/Model/Bord/Bord.gltf";
	SetAsset(m_type, fillPass);
	m_scale = Defalut_Scale_Const;

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("Bord", m_model, KdCollider::TypeGround);
}
