#include"SkyBox.h"

void SkyBox_Class::Init()
{
	m_type = Model;
	fillPass = "Asset/Model/SkyBox/Test/SkyBoxTest.gltf";
	SetAsset(m_type, fillPass);
	m_scale = Defalut_Scale_Const;

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("SkyBox", m_model, KdCollider::TypeGround);

	printf("BordObject Init CheckOut\n");
}
