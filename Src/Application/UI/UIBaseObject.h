#pragma once
class Camera_Class;
#include"Application/Object/BaseObject/BaseObject.h"
class UIBaseObject_Class : public BaseObject_Class
{
public:
	virtual void Init()override;
	virtual void DrawSprite()override;
	virtual void PreUpdate()override;
	void SetCamera(const std::shared_ptr<Camera_Class>& _camera)
	{
		m_wpCamera = _camera;
	}
protected:
	std::weak_ptr<Camera_Class> m_wpCamera;
};
