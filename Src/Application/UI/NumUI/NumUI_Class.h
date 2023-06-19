#pragma once
#include"Application/UI/UIBaseObject.h"
class NumUI_Class : public UIBaseObject_Class
{
public:
	void Init();
	void DrawSprite()override;
	void SetNum(int _num)
	{
		m_num = _num;
	}
private:
	KdTexture m_numTex[10];
	int m_num;
};
