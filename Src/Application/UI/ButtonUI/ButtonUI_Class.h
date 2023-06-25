#pragma once
#include"Application/UI/UIBaseObject.h"
class ButtonUI_Class : public UIBaseObject_Class
{
public:
	void Init()override;
	void DrawSprite()override;
	void SetSelecting(bool _selecting)
	{
		m_selecting = _selecting;
	}
private:
	bool m_selecting = false;
	std::shared_ptr<KdTexture>m_SelectingBack;
	std::shared_ptr<KdTexture>m_UnSelectingBack;
	POINT mousePos;
};