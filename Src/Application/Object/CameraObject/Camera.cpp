#include"Camera.h"

void Camera_Class::PreDraw()
{
	m_cam->SetToShader();
}

void Camera_Class::PreUpdate()
{
	switch (camViewModeNum)
	{
	case Default:
	{	
		
		break;
	}
	case CheseMode:
	{

		break;
	}
	case UpperCamMode:
	{

		break;
	}
	case SelectingMode:
	{

		break;
	}
	default:
		break;
	}
	
	Math::Matrix transMat= Math::Matrix::CreateTranslation({ 0,10,0 });
	Math::Matrix scaleMat = Math::Matrix::Identity;
	Math::Matrix rotateMatX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(90));
	Math::Matrix rotateMatY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(180));
	Math::Matrix rotateMatZ = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(0));
	//s—ñ‚Ì‡¬ = Šgk x ‰ñ“] x ˆÚ“®
	m_mWorld = scaleMat * (rotateMatX * rotateMatY * rotateMatZ) * transMat;
	m_cam->SetCameraMatrix(m_mWorld);
}

void Camera_Class::Init()
{
	if (!m_cam)m_cam = std::make_shared<KdCamera>();
}
