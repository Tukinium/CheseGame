#pragma once
#include"Application/Object/BaseObject/BaseObject.h"
class PieceBaseObject_Class : public BaseObject_Class
{
public:
	enum Color
	{
		None,
		White,
		Black,
	};
	void SetColor(int _color)
	{
		m_colorType = _color;
	}
	bool thisPiece() { return true; }
	virtual void SetDefaultPos(int n) {}
	virtual void DrawLit()override;
	virtual void Init()override;
protected:
	Math::Color m_color;
	int m_colorType = None;
};
