#pragma once
#include"Application/Object/PieceObject/PieceBaseObject/PieceBaseObject.h"
class QueenPieceObject_Class : public PieceBaseObject_Class
{
public:

	void Init()override;

private:
	const float BlackDefaultPosX = 0.5 - 0;
	const float BlackDefaultPosZ = 0.5 - 4;

	const float WhiteDefaultPosX = 0.5 - 0;
	const float WhiteDefaultPosZ = 0.5 + 3;

};