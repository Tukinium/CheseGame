#pragma once
class BordObject_Class;
class Camera_Class;
class KingPieceObject_Class;
class QueenPieceObject_Class;
class SkyBox_Class;
class SelectingBord_Class;
class PieceSelectingUI_Class;
class PawnPieceObject_Class;
#include"Application/Scene/BaseScene/BaseScene.h"
class GameScene_Class : public BaseScene_Class
{
public:
	 void SetSharedPtr()override;
	 void Update()override;
	 void PreUpdate()override;
	 void PreDraw()override;


	 enum Color
	 {
		 None,
		 White,
		 Black,
	 };

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

	int m_Phase;
	struct Piece
	{
		Math::Vector3 piecePos;
	};
	Piece KingPieceWhite,KingPieceBlack,QueenPieceWhite,QueenPieceBlack;

	Math::Vector3 selectPos;
	bool m_selectObject = false;
	bool meTrun = true;
	POINT MousePos;
};
