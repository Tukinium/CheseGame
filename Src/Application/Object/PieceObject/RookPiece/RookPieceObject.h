#pragma once
#include"Application/Object/PieceObject/PieceBaseObject/PieceBaseObject.h"
class RookPieceObject_Class : public PieceBaseObject_Class
{
public:
	void Init()override;

private:
	const float BlackDefaultPosX = 0.5 - 0;
	const float BlackDefaultPosZ = 0.5 - 4;

	const float WhiteDefaultPosX = 0.5 - 0;
	const float WhiteDefaultPosZ = 0.5 + 3;

	const float BlackDefaultPosX2 = 0.5 - 0;
	const float BlackDefaultPosZ2 = 0.5 - 4;

	const float WhiteDefaultPosX2 = 0.5 - 0;
	const float WhiteDefaultPosZ2 = 0.5 + 3;

};