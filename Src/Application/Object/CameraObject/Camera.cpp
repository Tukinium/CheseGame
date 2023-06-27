#include"Camera.h"

void Camera_Class::PreDraw()
{
	m_cam->SetToShader();
}

void Camera_Class::PreUpdate()
{
	Math::Matrix transMat = Math::Matrix::Identity;
	Math::Matrix scaleMat = Math::Matrix::Identity;
	Math::Matrix rotateMatX = Math::Matrix::Identity;
	Math::Matrix rotateMatY = Math::Matrix::Identity;
	Math::Matrix rotateMatZ = Math::Matrix::Identity;
	switch (camViewModeNum)
	{
	case Default:
	{	
		transMat = Math::Matrix::CreateTranslation(defaultCam.m_pos);
		scaleMat = Math::Matrix::Identity;
		rotateMatX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(defaultCam.m_rotateVec.x));
		rotateMatY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(defaultCam.m_rotateVec.y));
		rotateMatZ = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(defaultCam.m_rotateVec.z));
		break;
	}
	case SideViewMode:
	{
		transMat = Math::Matrix::CreateTranslation(sideViewCam.m_pos);
		scaleMat = Math::Matrix::Identity;
		rotateMatX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(sideViewCam.m_rotateVec.x));
		rotateMatY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(sideViewCam.m_rotateVec.y));
		rotateMatZ = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(sideViewCam.m_rotateVec.z));
		break;
	}
	case UpperCamMode:
	{
		transMat = Math::Matrix::CreateTranslation(upperCamModeCam.m_pos);
		scaleMat = Math::Matrix::Identity;
		rotateMatX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(upperCamModeCam.m_rotateVec.x));
		rotateMatY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(upperCamModeCam.m_rotateVec.y));
		rotateMatZ = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(upperCamModeCam.m_rotateVec.z));
		break;
	}
	case SelectingMode:
	{
		transMat = Math::Matrix::CreateTranslation(selectingModeCam.m_pos);
		scaleMat = Math::Matrix::Identity;
		rotateMatX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(selectingModeCam.m_rotateVec.x));
		rotateMatY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(selectingModeCam.m_rotateVec.y));
		rotateMatZ = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(selectingModeCam.m_rotateVec.z));
		break;
	}
	default:
		break;
	}
	//s—ñ‚Ì‡¬ = Šgk x ‰ñ“] x ˆÚ“®
	m_mWorld = scaleMat * (rotateMatX * rotateMatY * rotateMatZ) * transMat;
	m_cam->SetCameraMatrix(m_mWorld);
}

void Camera_Class::Init()
{
	if (!m_cam)m_cam = std::make_shared<KdCamera>();
}
