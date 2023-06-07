#include"Mouse.h"
#include"Application/Object/CameraObject/Camera.h"

void Mouse_Class::Init()
{
	spCamera = m_wpCamera.lock();
	spBord = m_wpBord.lock();
}

void Mouse_Class::Update()
{
	GetCursorPos(&m_mouse);

	
}
