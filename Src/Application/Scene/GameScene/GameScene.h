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

	 //�w�肳�ꂽID�̃s�[�X���E��
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

	 //�s�[�X�̍Ĕz�u
	 void PieceSet();

	 //float�^�����_��
	 float fRandom(float min, float max)
	 {
		 std::random_device rand;
		 std::mt19937 gen(rand());
		 std::uniform_real_distribution<>dis(min, max);
		 int r = dis(gen);
		 return r;
	 }
	 //int�^�����_��
	 int iRandom(int min, int max)
	 {
		 std::random_device rand;
		 std::mt19937 gen(rand());
		 std::uniform_int_distribution<>dis(min, max);
		 int r = dis(gen);
		 return r;
	 }

	 void CheseAI();
	 //�{�[�h��ɂ���}�E�X����̍��W��Ԃ�
	 Math::Vector3 BordOnMouse();

	 //�s�[�X�I�𒆂�UI
	 void SelectPieceUIActive();

	 enum Phase
	 {
		 //�Q�[���J�n
		 StartPhase,

		 //�v���C���[�^�[���J�n
		 StandByPhase,

		 //�s�[�X�I��
		 SelectPhase,

		 //�s�[�X�z�u
		 SetPhase,

		 //���X�̃��U���g
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

	//�t�F�[�Y�Ǘ�
	int m_Phase;

	//�ǂ��炪�ŏ��̃^�[����
	int m_FirstTurn;

	//�I���������W
	Math::Vector3 selectPos;
	//�s�[�X(�I�u�W�F�N�g)���I������Ă��邩
	bool m_selectObject = false;
	//���݂ǂ���̃^�[����
	int m_Trun = Player;

	//�ړ��O�I�����W
	Math::Vector3 m_beforeSelectPos;
	//�ړ���I�����W
	Math::Vector3 m_afterSelectPos;

	//���̃^�[����
	int m_round = 0;

	//�ړ������s�[�X��ID
	int m_movePieceID;

	//�J�n�t�F�[�Y�̊eInit�������I��������
	bool m_startPhaseInit = false;

	//�`�F�b�N���C�g
	bool m_check = false;

	bool m_GameStartCall;

	//���݂̔Ֆʏ�
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

	//�I������Ă����̈ړ��ł����
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

	//�����z�u
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

	//AI�p
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
