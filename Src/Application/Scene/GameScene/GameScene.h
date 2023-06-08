#pragma once
class BordObject_Class;
class Camera_Class;
class SkyBox_Class;
class SelectingBord_Class;
class PieceSelectingUI_Class;

class BishopPieceObject_Class;
class KingPieceObject_Class;
class PawnPieceObject_Class;
class QueenPieceObject_Class;
class RookPieceObject_Class;
class KnightPieceObject_Class;

#include"Application/Scene/BaseScene/BaseScene.h"

class GameScene_Class : public BaseScene_Class
{
public:
	 void SetSharedPtr()override;
	 void Update()override;
	 void PreUpdate()override;
	 void PreDraw()override;
	 enum Phase
	 {
		 StartPhase,
		 SelectPhase,
		 SetPhase,
		 EndPhase,
	 };
private:
	std::shared_ptr<SkyBox_Class>m_sky;
	std::shared_ptr<Camera_Class>m_camera;
	std::shared_ptr<BordObject_Class>m_bord;

	std::shared_ptr<SelectingBord_Class>m_selectBord;

	std::shared_ptr<PieceSelectingUI_Class>m_pieceSelectUI;

	std::shared_ptr<KingPieceObject_Class>m_kingBlack;
	std::shared_ptr<KingPieceObject_Class>m_kingWhite;

	std::shared_ptr<QueenPieceObject_Class>m_queenWhite;
	std::shared_ptr<QueenPieceObject_Class>m_queenBlack;

	std::shared_ptr<PawnPieceObject_Class>m_pawnWhite[8];
	std::shared_ptr<PawnPieceObject_Class>m_pawnBkack[8];

	std::shared_ptr<RookPieceObject_Class>m_rookWhite[2];
	std::shared_ptr<RookPieceObject_Class>m_rookBlack[2];

	std::shared_ptr<KnightPieceObject_Class>m_knightWhite[2];
	std::shared_ptr<KnightPieceObject_Class>m_knightBlack[2];

	std::shared_ptr<BishopPieceObject_Class>m_bishopWhite[2];
	std::shared_ptr<BishopPieceObject_Class>m_bishopBlack[2];

	int m_Phase;

	Math::Vector3 selectPos;
	bool m_selectObject = false;
	bool meTrun = true;
	POINT MousePos;
};
