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
	MathMatrix();

	m_cam->SetCameraMatrix(m_mWorld);
	if (GetAsyncKeyState('D'))
	{
		if (!m_cam)printf("Camera Err\n");
		printf("CameraMatrix\nPos = {%f ,%f, %f}\nRotate = {%f ,%f, %f}\nScale = %f\n", m_pos.x, m_pos.y, m_pos.z, m_rotateVec.x, m_rotateVec.z, m_rotateVec.z, m_scale);
	}
}

void Camera_Class::Init()
{
	printf("Camera Init CheckOut\n");
	if (!m_cam)m_cam = std::make_shared<KdCamera>();
}
