#pragma once
class BordObject_Class;
class Camera_Class;
class SkyBox_Class;
class SelectingBord_Class;

class BishopPieceObject_Class;
class KingPieceObject_Class;
class PawnPieceObject_Class;
class QueenPieceObject_Class;
class RookPieceObject_Class;
class KnightPieceObject_Class;

class PieceSelectingUI_Class;
class SelectingPieceTypeNameUI;

#include"Application/Scene/BaseScene/BaseScene.h"

class GameScene_Class : public BaseScene_Class
{
public:
	 void Init()override;
	 void SetSharedPtr()override;
	 void Update()override;
	 void PreUpdate()override;
	 void PreDraw()override;
	 void Release()override;

	 //ボード上にあるマウス判定の座標を返す
	 Math::Vector3 BordOnMouse();

	 void PieceCanMoveMassView();

	 enum Phase
	 {
		 StartPhase,
		 StandByPhase,
		 SelectPhase,
		 SetPhase,
		 EndPhase,
	 };
	 void AddObjList(std::shared_ptr<BaseObject_Class>& _obj)
	 {
		 m_baseObjList.push_back(_obj);
	 }
	 void SelectPieceUIActive();
	 void CreateCons();
	 void DestoryCons();
private:
	std::shared_ptr<SkyBox_Class>m_sky;
	std::shared_ptr<Camera_Class>m_camera;
	std::shared_ptr<BordObject_Class>m_bord;

	std::shared_ptr<SelectingBord_Class>m_nowSelectBord;
	std::shared_ptr<SelectingBord_Class>m_beforeSelectBord;
	std::shared_ptr<SelectingBord_Class>m_afterSelectBord;

	std::shared_ptr<SelectingBord_Class>m_selectPieceCanMoveBord[16][16];

	std::shared_ptr<PieceSelectingUI_Class>m_pieceSelectUI;
	std::shared_ptr<SelectingPieceTypeNameUI>m_selectPieceTypeUI;

	std::shared_ptr<KingPieceObject_Class>m_kingBlack;
	std::shared_ptr<KingPieceObject_Class>m_kingWhite;

	std::shared_ptr<QueenPieceObject_Class>m_queenWhite;
	std::shared_ptr<QueenPieceObject_Class>m_queenBlack;

	std::shared_ptr<PawnPieceObject_Class>m_pawnWhite[8];
	std::shared_ptr<PawnPieceObject_Class>m_pawnBlack[8];

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

	//ピースのID情報
	//[x][0] = 白,[x][1] = 黒
	//キング[0]、クイーン[1]、ビショップ[2][3]、ナイト[4][5]、ルーク[6][7]、ポーン[8][9][10][11][12][13][14][15]の順番で格納すること
	
	FILE* fp;
	int selectBordMode;
	Math::Vector3 m_beforeSelectPos;
	Math::Vector3 m_afterSelectPos;

	int waitTime = 0;
};
