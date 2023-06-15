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
	 void PostUpdate()override;
	 void PreDraw()override;

	 void Release()override;

	 //�s�[�X�̍Ĕz�u
	 void SetToDefault();

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

	 //�{�[�h��ɂ���}�E�X����̍��W��Ԃ�
	 Math::Vector3 BordOnMouse();

	 //�s�[�X�I�𒆂Ƀs�[�X�̈ړ��ł���ʒu��\������ђ�`
	 void PieceCanMoveMassView();

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
	bool m_Trun = true;
	POINT MousePos;
	bool m_pieceMoved;
	
	FILE* fp;
	int selectBordMode;
	Math::Vector3 m_beforeSelectPos;
	Math::Vector3 m_afterSelectPos;

	int m_waitTime = 0;

	const int waitTime = 10;

	enum PieceType
	{
		Pawn,
		Knight,
		Bishop,
		Rook,
		Queen,
		King,
	};
	float m_aiScore;
};
