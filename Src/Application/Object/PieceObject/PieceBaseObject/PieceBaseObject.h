#pragma once
#include"Application/Object/BaseObject/BaseObject.h"
class PieceBaseObject_Class : public BaseObject_Class
{
public:

	bool thisPiece()override { return true; }
	virtual void SetDefaultPos(int n) {}
	virtual void DrawLit()override;
	virtual void Init()override;
protected:
};
