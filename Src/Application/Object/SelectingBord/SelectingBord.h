#pragma once
#include"Application/Object/BaseObject/BaseObject.h"
class SelectingBord_Class : public BaseObject_Class
{
public:
	void Init()override;
	void DrawLit()override;
private:
	bool m_Selecting = false;
	Math::Color m_color;
};