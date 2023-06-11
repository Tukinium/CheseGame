#pragma once
#include"Application/UI/UIBaseObject.h"
class SelectingPieceTypeNameUI : public	UIBaseObject_Class
{
public:
	void Init()override;
	void SetPieceType(int _piecetype);
private:
	int m_pieceType;
	Math::Color color = { 0,0,1,1 };
};