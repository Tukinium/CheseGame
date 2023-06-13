#pragma once
#include"Application/Object/PieceObject/PieceBaseObject/PieceBaseObject.h"
class PawnPieceObject_Class : public PieceBaseObject_Class
{
public:
	void Init()override;
	void SetDefaultPos(int n);
private:
	const float BlackDefaultPosX = 0.5 - 0;
	const float BlackDefaultPosZ = 0.5 - 3;

	const float WhiteDefaultPosX = 0.5 - 0;
	const float WhiteDefaultPosZ = 0.5 + 2;

	const float BlackDefaultPosX2 = 0.5 - 1;
	const float BlackDefaultPosZ2 = 0.5 - 3;

	const float WhiteDefaultPosX2 = 0.5 - 1;
	const float WhiteDefaultPosZ2 = 0.5 + 2;

	const float BlackDefaultPosX3 = 0.5 - 2;
	const float BlackDefaultPosZ3 = 0.5 - 3;

	const float WhiteDefaultPosX3 = 0.5 - 2;
	const float WhiteDefaultPosZ3 = 0.5 + 2;

	const float BlackDefaultPosX4 = 0.5 - 3;
	const float BlackDefaultPosZ4 = 0.5 - 3;

	const float WhiteDefaultPosX4 = 0.5 - 3;
	const float WhiteDefaultPosZ4 = 0.5 + 2;

	const float BlackDefaultPosX5 = 0.5 + 1;
	const float BlackDefaultPosZ5 = 0.5 - 3;

	const float WhiteDefaultPosX5 = 0.5 + 1;
	const float WhiteDefaultPosZ5 = 0.5 + 2;

	const float BlackDefaultPosX6 = 0.5 + 2;
	const float BlackDefaultPosZ6 = 0.5 - 3;

	const float WhiteDefaultPosX6 = 0.5 + 2;
	const float WhiteDefaultPosZ6 = 0.5 + 2;

	const float BlackDefaultPosX7 = 0.5 + 3;
	const float BlackDefaultPosZ7 = 0.5 - 3;

	const float WhiteDefaultPosX7 = 0.5 + 3;
	const float WhiteDefaultPosZ7 = 0.5 + 2;

	const float BlackDefaultPosX8 = 0.5 - 4;
	const float BlackDefaultPosZ8 = 0.5 - 3;

	const float WhiteDefaultPosX8 = 0.5 - 4;
	const float WhiteDefaultPosZ8 = 0.5 + 2;
};