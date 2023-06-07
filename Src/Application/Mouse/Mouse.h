#pragma once
class Camera_Class;
class BordObject_Class;
#include"Application/Object/BaseObject/BaseObject.h"
class Mouse_Class : public BaseObject_Class
{
public:
	Mouse_Class() {};
	~Mouse_Class() {};
	void Init();
	void SetCamera(const std::shared_ptr<Camera_Class>& _camera)
	{
		m_wpCamera = _camera;
	}
	void SetBord(const std::shared_ptr<BordObject_Class>& _Bord)
	{
		m_wpBord = _Bord;
	}
	POINT m_mouse;
	void Update()override;
private:
	std::weak_ptr<Camera_Class>m_wpCamera;
	std::weak_ptr<BordObject_Class>m_wpBord;
	std::shared_ptr<Camera_Class>spCamera;
	std::shared_ptr<BordObject_Class>spBord;
};