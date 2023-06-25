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

	 //�w�肳�ꂽID�̃s�[�X���E��
	 void KillPiece(int _id);

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

		 //����A�v���|�[�V����
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

	//�t�F�[�Y�Ǘ�
	int m_Phase;

	//�ǂ��炪�ŏ��̃^�[����
	int m_FirstTurn;

	//�I���������W
	Math::Vector3 selectPos;
	//�s�[�X(�I�u�W�F�N�g)���I������Ă��邩
	bool m_selectObject = false;
	//���݂ǂ���̃^�[����
	int m_Trun = Enemy;

	//�ړ��O�I�����W
	Math::Vector3 m_beforeSelectPos;
	//�ړ���I�����W
	Math::Vector3 m_afterSelectPos;

	//���̃^�[����
	int m_round = 0;

	//�ړ������s�[�X��ID
	int m_selectPieceId = -1;

	int m_aiPoint = 0;
	//�J�n�t�F�[�Y�̊eInit�������I��������
	bool m_startPhaseInit = false;

	//�`�F�b�N���C�g
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
		PieceBaseObject_Class::BlackRook0,PieceBaseObject_Class::BlackKnight0,PieceBaseObject_Class::BlackBishop0,PieceBaseObject_Class::BlackQueen,PieceBaseObject_Class::BlackKing,PieceBaseObject_Class::BlackBishop1,PieceBaseObject_Class::BlackKnight1,PieceBaseObject_Class::BlackRook1,
		PieceBaseObject_Class::BlackPawn0,PieceBaseObject_Class::BlackPawn1,PieceBaseObject_Class::BlackPawn2,PieceBaseObject_Class::BlackPawn3,PieceBaseObject_Class::BlackPawn4,PieceBaseObject_Class::BlackPawn5,PieceBaseObject_Class::BlackPawn6,PieceBaseObject_Class::BlackPawn7,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		PieceBaseObject_Class::WhitePawn0,PieceBaseObject_Class::WhitePawn1,PieceBaseObject_Class::WhitePawn2,PieceBaseObject_Class::WhitePawn3,PieceBaseObject_Class::WhitePawn4,PieceBaseObject_Class::WhitePawn5,PieceBaseObject_Class::WhitePawn6,PieceBaseObject_Class::WhitePawn7,
		PieceBaseObject_Class::WhiteRook0,PieceBaseObject_Class::WhiteKnight0,PieceBaseObject_Class::WhiteBishop0,PieceBaseObject_Class::WhiteQueen,PieceBaseObject_Class::WhiteKing,PieceBaseObject_Class::WhiteBishop1,PieceBaseObject_Class::WhiteKnight1,PieceBaseObject_Class::WhiteRook1,
	};

	//AI�p
	float m_aiScore;

	const int QUEEN_POINT = 10;
	const int ROOK_POINT = 5;
	const int BISHOP_POINT = 4;
	const int KNIGHT_POINT = 3;
	const int PAWN_POINT = 1;
	const int KING_POINT = 100;

};
