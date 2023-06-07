#pragma once
#include"Application/Object/BaseObject/BaseObject.h"
class PieceSelectingUI_Class : public BaseObject_Class
{
public:
	void Init()override;
	void DrawLit()override;
private:

	Math::Color color = { 0,0,1,1 };
};