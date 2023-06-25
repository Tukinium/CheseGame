#pragma once
#include"Application/UI/UIBaseObject.h"
class ProPotionButtonUI_Class : public UIBaseObject_Class
{
public:

	void Init()override;
	void DrawSprite()override;
private:
	std::shared_ptr<KdTexture>m_SelectingBack;
	std::shared_ptr<KdTexture>m_UnSelectingBack;
};