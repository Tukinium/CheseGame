#include"SkyBox.h"

void SkyBox_Class::Init()
{
	m_modeltype = Model;
	fillPass = "Asset/Model/SkyBox/Test/SkyBoxTest.gltf";
	SetAsset(m_modeltype, fillPass);
	m_scale = DEFAULT_SCALE;

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("SkyBox", m_model, KdCollider::TypeGround);
}
