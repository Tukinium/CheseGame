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
#include"Application/Object/BaseObject/BaseObject.h"
#include"Application/Scene/BaseScene/BaseScene.h"

class GameScene_Class : public BaseScene_Class
{
public:
	 void Init()override;
	 void SetSharedPtr()override;
	 void Update()override;
	 void PreUpdate()override;
	 void PostUpdate()override;
	 void PreDraw()override;

	 void Release()override;

	 //ピースの再配置
	 void PieceSet();

	 float fRandom(float min, float max)
	 {
		 std::random_device rand;
		 std::mt19937 gen(rand());
		 std::uniform_real_distribution<>dis(min, max);
		 int r = dis(gen);
		 return r;
	 }

	 int iRandom(int min, int max)
	 {
		 std::random_device rand;
		 std::mt19937 gen(rand());
		 std::uniform_int_distribution<>dis(min, max);
		 int r = dis(gen);
		 return r;
	 }

	 void CheseAI();

	 //ボード上にあるマウス判定の座標を返す
	 Math::Vector3 BordOnMouse();

	 //ピース選択中のUI
	 void SelectPieceUIActive();

	 enum Phase
	 {
		 //ゲーム開始
		 StartPhase,

		 //プレイヤーターン開始
		 StandByPhase,

		 //ピース選択
		 SelectPhase,

		 //ピース配置
		 SetPhase,

		 //諸々のリザルト
		 EndPhase,
	 };

	 enum Turn
	 {
		 Player,
		 Enemy,
	 };
	 int m_FirstTurn;

	 void CreateCons();
	 void DestoryCons();

private:
	std::shared_ptr<SkyBox_Class>m_sky;
	std::shared_ptr<Camera_Class>m_camera;
	std::shared_ptr<BordObject_Class>m_bord;

	std::shared_ptr<SelectingBord_Class>m_nowSelectBord;
	std::shared_ptr<SelectingBord_Class>m_beforeSelectBord;
	std::shared_ptr<SelectingBord_Class>m_afterSelectBord;

	std::shared_ptr<SelectingBord_Class>m_selectPieceCanMoveBord[8][8];
	
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
	int m_Trun = Player;
	POINT MousePos;
	
	FILE* fp;
	int selectBordMode;
	Math::Vector3 m_beforeSelectPos;
	Math::Vector3 m_afterSelectPos;

	int m_waitTime = 0;

	const int waitTime = 10;
	float m_aiScore;

	int m_movePieceID;

	int m_bordInfo[8][8] =
	{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	};
	int m_canMoveBordInfo[8][8] =
	{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	};
	int NORMAL_RULE_BORD[8][8] =
	{
		BaseObject_Class::BlackRook0,BaseObject_Class::BlackKnight0,BaseObject_Class::BlackBishop0,BaseObject_Class::BlackQueen,BaseObject_Class::BlackKing,BaseObject_Class::BlackBishop1,BaseObject_Class::BlackKnight1,BaseObject_Class::BlackRook1,
		BaseObject_Class::BlackPawn0,BaseObject_Class::BlackPawn1,BaseObject_Class::BlackPawn2,BaseObject_Class::BlackPawn3,BaseObject_Class::BlackPawn4,BaseObject_Class::BlackPawn5,BaseObject_Class::BlackPawn6,BaseObject_Class::BlackPawn7,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		BaseObject_Class::WhitePawn0,BaseObject_Class::WhitePawn1,BaseObject_Class::WhitePawn2,BaseObject_Class::WhitePawn3,BaseObject_Class::WhitePawn4,BaseObject_Class::WhitePawn5,BaseObject_Class::WhitePawn6,BaseObject_Class::WhitePawn7,
		BaseObject_Class::WhiteRook0,BaseObject_Class::WhiteKnight0,BaseObject_Class::WhiteBishop0,BaseObject_Class::WhiteQueen,BaseObject_Class::WhiteKing,BaseObject_Class::WhiteBishop1,BaseObject_Class::WhiteKnight1,BaseObject_Class::WhiteRook1,
	};

public:
	static GameScene_Class& instance()
	{
		static GameScene_Class instance;
		return instance;
	}
};
