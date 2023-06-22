#include"BordObject.h"

void BordObject_Class::Init()
{
	m_modeltype = Model;
	fillPass = "Asset/Model/Bord/Bord.gltf";
	SetAsset(m_modeltype, fillPass);
	m_scale = DEFAULT_SCALE;

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("Bord", m_model, KdCollider::TypeGround);
}
