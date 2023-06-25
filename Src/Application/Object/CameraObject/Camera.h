#pragma once
#include"Application/Object/BaseObject/BaseObject.h"
class Camera_Class : public BaseObject_Class
{
public:
	void PreDraw()override;
	void PreUpdate()override;
	void Init()override;
	void setCamViewMode(int _camViewNum)
	{
		camViewModeNum = _camViewNum;
	}
	enum CamViewType
	{
		Default = 0,
		CheseMode,
		UpperCamMode,
		SelectingMode,
	};

	std::shared_ptr<KdCamera> WorkCamera() const
	{
		return m_cam;
	}

	struct DefaultCam
	{
		const Math::Vector3 m_pos = { 0,0,-10 };
		const float m_scale = 1.0f;
		const Math::Vector3 m_rotateVec = { 0,0,0 };
	};
	struct DefaultCam defaultCam;
	struct CheseModeCam
	{
		const Math::Vector3 m_pos = { 0,10,-10 };
		const float m_scale = 1.0f;
		const Math::Vector3 m_rotateVec = { 35,0,0 };
	};
	struct CheseModeCam cheseModeCam;

	struct UpperCamModeCam
	{
		const Math::Vector3 m_pos = { 0,10,0 };
		const float m_scale = 1.0f;
		const Math::Vector3 m_rotateVec = { 90,180,0 };
	};
	struct UpperCamModeCam upperCamModeCam;

	struct SelectingModeCam
	{
		const Math::Vector3 m_pos = { 0,0,-100 };
		const float m_scale = 1.0f;
		const Math::Vector3 m_rotateVec = { 0,0,0 };
	};
	struct SelectingModeCam selectingModeCam;

private:
	//çsóÒÇÃçáê¨ = ägèk x âÒì] x à⁄ìÆ

	int camViewModeNum = Default;
	std::shared_ptr<KdCamera>m_cam = nullptr;
	
};