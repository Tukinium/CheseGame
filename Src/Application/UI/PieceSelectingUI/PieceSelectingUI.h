#pragma once
#include"Application/UI/UIBaseObject.h"
class PieceSelectingUI_Class : public UIBaseObject_Class
{
public:
	void Init()override;
private:
	
	Math::Color color = { 0,0,1,1 };
};