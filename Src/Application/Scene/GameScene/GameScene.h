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
class OnTurnStartViewUI_Class;
class NumUI_Class;
class ButtonUI_Class;
class UIBaseObject_Class;
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

	 //指定されたIDのピースを殺す
	 void KillPiece(int _id)
	 {
		 for (std::shared_ptr<BaseObject_Class>obj : m_baseObjList)
		 {
			 if (obj->GetId() == _id)
			 {
				 obj->SetAlive(false);
			 }
		 }
	 }

	 void Release()override;

	 //ピースの再配置
	 void PieceSet();

	 //float型ランダム
	 float fRandom(float min, float max)
	 {
		 std::random_device rand;
		 std::mt19937 gen(rand());
		 std::uniform_real_distribution<>dis(min, max);
		 int r = dis(gen);
		 return r;
	 }
	 //int型ランダム
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



	 

private:
	std::shared_ptr<SkyBox_Class>m_sky;
	std::shared_ptr<Camera_Class>m_camera;
	std::shared_ptr<BordObject_Class>m_bord;

	std::shared_ptr<SelectingBord_Class>m_nowSelectBord;
	std::shared_ptr<SelectingBord_Class>m_beforeSelectBord;
	std::shared_ptr<SelectingBord_Class>m_afterSelectBord;

	std::shared_ptr<SelectingBord_Class>m_selectPieceCanMoveBord[8][8];
	
	std::shared_ptr<PieceSelectingUI_Class>m_pieceSelectUI;
	std::shared_ptr<OnTurnStartViewUI_Class>m_onTurnViewUI;
	std::shared_ptr<NumUI_Class>m_numUI;
	std::shared_ptr<UIBaseObject_Class>m_PlayerTurnView;
	std::shared_ptr<UIBaseObject_Class>m_EnemyTurnView;


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

	//フェーズ管理
	int m_Phase;

	//どちらが最初のターンか
	int m_FirstTurn;

	//選択した座標
	Math::Vector3 selectPos;
	//ピース(オブジェクト)が選択されているか
	bool m_selectObject = false;
	//現在どちらのターンか
	int m_Trun = Player;

	//移動前選択座標
	Math::Vector3 m_beforeSelectPos;
	//移動先選択座標
	Math::Vector3 m_afterSelectPos;

	//今のターン数
	int m_round = 0;

	//移動したピースのID
	int m_movePieceID;

	//開始フェーズの各Init処理が終了したか
	bool m_startPhaseInit = false;

	//チェックメイト
	bool m_check = false;

	bool m_GameStartCall;

	//現在の盤面状況
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

	//選択されている駒の移動できる先
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

	//初期配置
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

	//AI用
	float m_aiScore;

	const int QUEEN_POINT = 10;
	const int ROOK_POINT = 5;
	const int BISHOP_POINT = 4;
	const int KNIGHT_POINT = 3;
	const int PAWN_POINT = 1;
	const int KING_POINT = 100;

	struct AICheck
	{
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

	};
	AICheck WhiteKing, WhiteQueen, WhiteRook0,WhiteRook1,WhiteBishop0,WhiteBishop1,WhiteKnight0,WhiteKnight1,WhitePawn0,WhitePawn1,WhitePawn2,WhitePawn3,WhitePawn4,WhitePawn5,WhitePawn6,WhitePawn7;
	AICheck BlackKing, BlackQueen, BlackRook0, BlackRook1, BlackBishop0, BlackBishop1, BlackKnight0, BlackKnight1, BlackPawn0, BlackPawn1, BlackPawn2, BlackPawn3, BlackPawn4, BlackPawn5, BlackPawn6, BlackPawn7;
};
