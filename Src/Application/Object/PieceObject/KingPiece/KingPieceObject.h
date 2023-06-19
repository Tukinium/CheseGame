#pragma once
#include"Application/Object/PieceObject/PieceBaseObject/PieceBaseObject.h"
class KingPieceObject_Class : public PieceBaseObject_Class
{
public:
	void Init()override;
	void SetDefaultPos(int n)override;
	void GenCanMoveBordInfo()override;
private:
	
	const float BlackDefaultPosX = 0.5 - 1;
	const float BlackDefaultPosZ = 0.5 - 4;

	const float WhiteDefaultPosX = 0.5 - 1;
	const float WhiteDefaultPosZ = 0.5 + 3;
};
