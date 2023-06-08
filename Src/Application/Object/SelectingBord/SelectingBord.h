#pragma once
#include"Application/Object/BaseObject/BaseObject.h"
class SelectingBord_Class : public BaseObject_Class
{
public:
	void SetSelecting(const bool _selecting)
	{
		m_Selecting = _selecting;
	}
	void Init()override;
	void DrawLit()override;
private:
	bool m_Selecting = false;
	Math::Color m_color;
};