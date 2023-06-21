#pragma once
#include"Application/UI/UIBaseObject.h"
class ButtonUI_Class : public UIBaseObject_Class
{
public:
	void Init()override;
	void DrawSprite()override;
	void SetSelecting(bool _selecting)
	{
		Selecting = _selecting;
	}
private:
	bool Selecting = false;
	std::shared_ptr<KdTexture>m_SelectingBack;
	std::shared_ptr<KdTexture>m_UnSelectingBack;
	POINT mousePos;
};