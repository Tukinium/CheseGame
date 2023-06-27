#pragma once
#include"Application/Object/BaseObject/BaseObject.h"
class MouseCursor_Class : public BaseObject_Class
{
public:
	void Update()override;
	void Init()override;
	void DrawSprite()override;
private:
	POINT MousePos;
	Math::Vector3 fixMousePos;
};
