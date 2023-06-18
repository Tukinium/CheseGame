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
		m_pos = defaultCam.m_pos;
		m_rotateVec = defaultCam.m_rotateVec;
		break;
	}
	case CheseMode:
	{
		m_pos = cheseModeCam.m_pos;
		m_rotateVec = cheseModeCam.m_rotateVec;
		break;
	}
	case UpperCamMode:
	{
		m_pos = upperCamModeCam.m_pos;
		m_rotateVec = upperCamModeCam.m_rotateVec;
		break;
	}
	case SelectingMode:
	{
		m_rotateVec = selectingModeCam.m_rotateVec;
		break;
	}
	default:
		break;
	}
	m_transMat = Math::Matrix::CreateTranslation(m_pos);
	m_scaleMat = Math::Matrix::CreateScale(m_scale);
	m_rotateX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(m_rotateVec.x));
	m_rotateY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_rotateVec.y));
	m_rotateZ = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(m_rotateVec.z));
	m_rotateMat = m_rotateX * m_rotateY * m_rotateZ;

	//s—ñ‚Ì‡¬ = Šgk x ‰ñ“] x ˆÚ“®
	m_mWorld = m_scaleMat * m_rotateMat * m_transMat;

	m_cam->SetCameraMatrix(m_mWorld);
}

void Camera_Class::Init()
{
	if (!m_cam)m_cam = std::make_shared<KdCamera>();
}
