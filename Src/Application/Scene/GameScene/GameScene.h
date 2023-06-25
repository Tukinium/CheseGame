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
class ProPotionButtonUI_Class;

class BaseAudio_Class;
#include"Application/Object/PieceObject/PieceBaseObject/PieceBaseObject.h"
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

	 virtual void Draw()override;
	 virtual void DrawLit()override;
	 virtual void GenerateDepthMapFromLight()override;
	 virtual void DrawBright()override;
	 virtual void DrawUnLit()override;
	 virtual void DrawSprite()override;
	 virtual void PostDraw()override;

	 //指定されたIDのピースを殺す
	 void KillPiece(int _id);

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

		 //特殊、プロポーション
		 ProPotionPhase,
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

	std::shared_ptr<ProPotionButtonUI_Class>m_ProPotionQueenView;
	std::shared_ptr<ProPotionButtonUI_Class>m_ProPotionRookView;
	std::shared_ptr<ProPotionButtonUI_Class>m_ProPotionBishopView;
	std::shared_ptr<ProPotionButtonUI_Class>m_ProPotionKnightView;

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

	std::shared_ptr<BaseAudio_Class>m_bgm1;

	std::list<std::shared_ptr<PieceBaseObject_Class>>m_pieceList;

	//フェーズ管理
	int m_Phase;

	//どちらが最初のターンか
	int m_FirstTurn;

	//選択した座標
	Math::Vector3 selectPos;
	//ピース(オブジェクト)が選択されているか
	bool m_selectObject = false;
	//現在どちらのターンか
	int m_Trun = Enemy;

	//移動前選択座標
	Math::Vector3 m_beforeSelectPos;
	//移動先選択座標
	Math::Vector3 m_afterSelectPos;

	//今のターン数
	int m_round = 0;

	//移動したピースのID
	int m_selectPieceId = -1;

	int m_aiPoint = 0;
	//開始フェーズの各Init処理が終了したか
	bool m_startPhaseInit = false;

	//チェックメイト
	bool m_check = false;

	bool m_GameStartCall;

	Math::Matrix m_transMat = Math::Matrix::Identity;
	Math::Vector3 m_pos = {};

	Math::Matrix m_rotateMat;
	Math::Matrix m_rotateX;
	Math::Matrix m_rotateY;
	Math::Matrix m_rotateZ;
	Math::Vector3 m_rotateVec = {};

	Math::Matrix m_scaleMat;

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
		PieceBaseObject_Class::BlackRook0,PieceBaseObject_Class::BlackKnight0,PieceBaseObject_Class::BlackBishop0,PieceBaseObject_Class::BlackQueen,PieceBaseObject_Class::BlackKing,PieceBaseObject_Class::BlackBishop1,PieceBaseObject_Class::BlackKnight1,PieceBaseObject_Class::BlackRook1,
		PieceBaseObject_Class::BlackPawn0,PieceBaseObject_Class::BlackPawn1,PieceBaseObject_Class::BlackPawn2,PieceBaseObject_Class::BlackPawn3,PieceBaseObject_Class::BlackPawn4,PieceBaseObject_Class::BlackPawn5,PieceBaseObject_Class::BlackPawn6,PieceBaseObject_Class::BlackPawn7,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		PieceBaseObject_Class::WhitePawn0,PieceBaseObject_Class::WhitePawn1,PieceBaseObject_Class::WhitePawn2,PieceBaseObject_Class::WhitePawn3,PieceBaseObject_Class::WhitePawn4,PieceBaseObject_Class::WhitePawn5,PieceBaseObject_Class::WhitePawn6,PieceBaseObject_Class::WhitePawn7,
		PieceBaseObject_Class::WhiteRook0,PieceBaseObject_Class::WhiteKnight0,PieceBaseObject_Class::WhiteBishop0,PieceBaseObject_Class::WhiteQueen,PieceBaseObject_Class::WhiteKing,PieceBaseObject_Class::WhiteBishop1,PieceBaseObject_Class::WhiteKnight1,PieceBaseObject_Class::WhiteRook1,
	};

	//AI用
	float m_aiScore;

	const int QUEEN_POINT = 10;
	const int ROOK_POINT = 5;
	const int BISHOP_POINT = 4;
	const int KNIGHT_POINT = 3;
	const int PAWN_POINT = 1;
	const int KING_POINT = 100;

};
