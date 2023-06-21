#include"GameScene.h"

//Include�����������ߕ�������

//�s�[�X�pInclude�w�b�_�t�@�C��
#include"Application/Object/PieceObject/Piece_Include_Config.h"

#include"Application/Object/SkyBox/SkyBox.h"
#include"Application/Object/SelectingBord/SelectingBord.h"
#include"Application/Object/BordObject/BordObject.h"
#include"Application/Object/CameraObject/Camera.h"

#include"Application/UI/PieceSelectingUI/PieceSelectingUI.h"
#include"Application/UI/OnTurnViewUI/OnTurnViewUI_Class.h"
#include"Application/UI/NumUI/NumUI_Class.h"
#include"Application/UI/ButtonUI/ButtonUI_Class.h"

void GameScene_Class::Init()
{
	BaseScene_Class::Init();
	for (std::shared_ptr<BaseObject_Class> obj : m_baseObjList)
	{
		obj->Init();
	}
	m_Trun = Player;

	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			m_bordInfo[h][w] = NORMAL_RULE_BORD[h][w];

		}
	}
	PieceSet();
	m_waitTime = waitTime;
}

void GameScene_Class::SetSharedPtr()
{
	std::string str;
	std::string str2;
	if (!m_camera)m_camera = std::make_shared<Camera_Class>();
	m_camera->Init();
	m_baseObjList.push_back(m_camera);

	if (!m_bord)m_bord = std::make_shared<BordObject_Class>();
	m_bord->Init();
	m_baseObjList.push_back(m_bord);

	if (!m_pieceSelectUI)m_pieceSelectUI = std::make_shared<PieceSelectingUI_Class>();
	m_baseObjList.push_back(m_pieceSelectUI);

	if (!m_onTurnViewUI)m_onTurnViewUI = std::make_shared<OnTurnStartViewUI_Class>();
	m_baseObjList.push_back(m_onTurnViewUI);

	if (!m_numUI)m_numUI = std::make_shared<NumUI_Class>();
	m_baseObjList.push_back(m_numUI);

	{
		if (!m_kingWhite)m_kingWhite = std::make_shared<KingPieceObject_Class>();
		m_kingWhite->SetColor(kWhiteColor);
		m_kingWhite->SetId(BaseObject_Class::WhiteKing);
		m_kingWhite->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/King/King.gltf");
		m_baseObjList.push_back(m_kingWhite);

		if (!m_kingBlack)m_kingBlack = std::make_shared<KingPieceObject_Class>();
		m_kingBlack->SetColor(kBlackColor);
		m_kingBlack->SetId(BaseObject_Class::BlackKing);
		m_kingBlack->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/King/King.gltf");
		m_baseObjList.push_back(m_kingBlack);

		if (!m_queenWhite)m_queenWhite = std::make_shared<QueenPieceObject_Class>();
		m_queenWhite->SetColor(kWhiteColor);
		m_queenWhite->SetId(BaseObject_Class::WhiteQueen);
		m_queenWhite->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Queen/Queen.gltf");
		m_baseObjList.push_back(m_queenWhite);

		if (!m_queenBlack)m_queenBlack = std::make_shared<QueenPieceObject_Class>();
		m_queenBlack->SetColor(kBlackColor);
		m_queenBlack->SetId(BaseObject_Class::BlackQueen);
		m_queenBlack->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Queen/Queen.gltf");
		m_baseObjList.push_back(m_queenBlack);

		if (!m_sky)m_sky = std::make_shared<SkyBox_Class>();
		m_baseObjList.push_back(m_sky);

		if (!m_nowSelectBord)m_nowSelectBord = std::make_shared<SelectingBord_Class>();
		m_nowSelectBord->SetAsset(BaseObject_Class::Model, "Asset/Model/Bord_Selecting/Now/Bord_NowSelecting.gltf");
		m_nowSelectBord->SetAlive(false);
		m_baseObjList.push_back(m_nowSelectBord);

		if (!m_afterSelectBord)m_afterSelectBord = std::make_shared<SelectingBord_Class>();
		m_afterSelectBord->SetAsset(BaseObject_Class::Model, "Asset/Model/Bord_Selecting/After/Bord_AfterSelecting.gltf");
		m_afterSelectBord->SetAlive(false);
		m_baseObjList.push_back(m_afterSelectBord);

		if (!m_beforeSelectBord)m_beforeSelectBord = std::make_shared<SelectingBord_Class>();
		m_beforeSelectBord->SetAsset(BaseObject_Class::Model, "Asset/Model/Bord_Selecting/Before/Bord_BeforeSelecting.gltf");
		m_beforeSelectBord->SetAlive(false);
		m_baseObjList.push_back(m_beforeSelectBord);

	}

	for (int n = 0; n < 8; n++)
	{
		if (!m_pawnWhite[n])m_pawnWhite[n] = std::make_shared<PawnPieceObject_Class>();
		m_pawnWhite[n]->SetColor(kWhiteColor);
		m_pawnWhite[n]->SetId(BaseObject_Class::WhitePawn0 + n);
		m_pawnWhite[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Pawn/Pawn.gltf");
		m_baseObjList.push_back(m_pawnWhite[n]);

		if (!m_pawnBlack[n])m_pawnBlack[n] = std::make_shared<PawnPieceObject_Class>();
		m_pawnBlack[n]->SetColor(kBlackColor);
		m_pawnBlack[n]->SetId(BaseObject_Class::BlackPawn0 + n);
		m_pawnBlack[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Pawn/Pawn.gltf");
		m_baseObjList.push_back(m_pawnBlack[n]);

		std::cout << str << std::endl;
	}

	for (int n = 0; n < 2; n++)
	{

		if (!m_rookWhite[n])m_rookWhite[n] = std::make_shared<RookPieceObject_Class>();
		m_rookWhite[n]->SetColor(kWhiteColor);
		m_rookWhite[n]->SetId(BaseObject_Class::WhiteRook0 + n);
		m_rookWhite[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Rook/Rook.gltf");
		m_baseObjList.push_back(m_rookWhite[n]);


		if (!m_rookBlack[n])m_rookBlack[n] = std::make_shared<RookPieceObject_Class>();
		m_rookBlack[n]->SetColor(kBlackColor);
		m_rookBlack[n]->SetId(BaseObject_Class::BlackRook0 + n);
		m_rookBlack[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Rook/Rook.gltf");
		m_baseObjList.push_back(m_rookBlack[n]);

	}

	for (int n = 0; n < 2; n++)
	{

		if (!m_knightWhite[n])m_knightWhite[n] = std::make_shared<KnightPieceObject_Class>();
		m_knightWhite[n]->SetColor(kWhiteColor);
		m_knightWhite[n]->SetId(BaseObject_Class::WhiteKnight0 + n);
		m_knightWhite[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Knight/Knight.gltf");
		m_baseObjList.push_back(m_knightWhite[n]);

		str2 = std::to_string(n);
		str = "KnightBlack";
		str.append(str2);
		if (!m_knightBlack[n])m_knightBlack[n] = std::make_shared<KnightPieceObject_Class>();
		m_knightBlack[n]->SetColor(kBlackColor);
		m_knightBlack[n]->SetId(BaseObject_Class::BlackKnight0 + n);
		m_knightBlack[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Knight/Knight.gltf");
		m_baseObjList.push_back(m_knightBlack[n]);

	}

	for (int n = 0; n < 2; n++)
	{

		if (!m_bishopWhite[n])m_bishopWhite[n] = std::make_shared<BishopPieceObject_Class>();
		m_bishopWhite[n]->SetColor(kWhiteColor);
		m_bishopWhite[n]->SetId(BaseObject_Class::WhiteBishop0 + n);
		m_bishopWhite[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Bishop/Bishop.gltf");
		m_baseObjList.push_back(m_bishopWhite[n]);

		if (!m_bishopBlack[n])m_bishopBlack[n] = std::make_shared<BishopPieceObject_Class>();
		m_bishopBlack[n]->SetColor(kBlackColor);
		m_bishopBlack[n]->SetId(BaseObject_Class::BlackBishop0 + n);
		m_bishopBlack[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Bishop/Bishop.gltf");
		m_baseObjList.push_back(m_bishopBlack[n]);

	}

	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			Math::Vector3 massPos = { h * 1.0f - 3.5f,0.01f,w * 1.0f - 3.5f };
			if (!m_selectPieceCanMoveBord[h][w])m_selectPieceCanMoveBord[h][w] = std::make_shared<SelectingBord_Class>();
			m_selectPieceCanMoveBord[h][w]->SetAsset(BaseObject_Class::Model, "Asset/Model/Bord_Selecting/CanSelect/Bord_CanSelecting.gltf");
			m_selectPieceCanMoveBord[h][w]->SetPos(massPos);
			m_selectPieceCanMoveBord[h][w]->SetAlive(false);
			m_baseObjList.push_back(m_selectPieceCanMoveBord[h][w]);
		}
	}
	std::cout << "GameScene SetSharedPtr checkOut" << std::endl;
}

void GameScene_Class::Update()
{
	m_camera->setCamViewMode(m_camera->UpperCamMode);
	PieceSet();
	BordOnMouse();
	SelectPieceUIActive();

	for (std::shared_ptr<BaseObject_Class>obj : m_baseObjList)
	{
		switch (m_Trun)
		{
		case GameScene_Class::Player:
		{
			switch (m_Phase)
			{
			case GameScene_Class::StartPhase:
			{
				if (!m_startPhaseInit)
				{
					m_movePieceID = -1;
					m_selectObject = false;
					m_beforeSelectPos = { 12345,12345,12345 };
					m_afterSelectPos = { 12345,12345,12345 };
					for (int h = 0; h < 8; h++)
					{
						for (int w = 0; w < 8; w++)
						{
							m_canMoveBordInfo[h][w] = 0;
							m_selectPieceCanMoveBord[h][w]->SetAlive(false);
						}
					}
					m_onTurnViewUI->SetRoundNum(m_round);
					m_onTurnViewUI->Entry();

					m_numUI->SetNum(m_round);
					m_numUI->SetPos2({ -150,0,0 });
					m_numUI->SetAlive(true);

				}
				if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
				{
					m_Phase = StandByPhase;
					std::cout << "StartPhaseEnd" << std::endl;
					m_onTurnViewUI->Leave();
					m_numUI->SetAlive(false);
					m_waitTime = waitTime;
				}
				break;
			}
			case GameScene_Class::StandByPhase:
			{

				if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
				{

					if (obj->thisPiece() && obj->GetColor() == kWhiteColor)
					{
						if (0.5f > (Math::Vector3::Distance(obj->GetPos(), BordOnMouse())))
						{
							m_movePieceID = obj->GetId();
							for (int h = 0; h < 8; h++)
							{
								for (int w = 0; w < 8; w++)
								{
									//�N���b�N�����I�u�W�F�N�g�Ɍ��݂̔Ֆʏ󋵂�n��
									obj->SetBordInfo(h, w, m_bordInfo[h][w]);
									printf("%d_", m_bordInfo[h][w]);
								}
								printf("\n");
							}
							for (int h = 0; h < 8; h++)
							{
								for (int w = 0; w < 8; w++)
								{
									//�I�u�W�F�N�g���瓮����͈͂��z��ŕԋp�����
									obj->GenCanMoveBordInfo();
									m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
									//printf("%d_", m_canMoveBordInfo[h][w]);
								}
								//printf("\n");

							}
							for (int h = 0; h < 8; h++)
							{
								for (int w = 0; w < 8; w++)
								{
									printf("%d_", m_canMoveBordInfo[h][w]);
								}
								printf("\n");
							}
							obj->SetfirstMoved(true);
							m_beforeSelectPos = BordOnMouse();
							m_selectObject = true;
							m_Phase = SelectPhase;
							std::cout << "StandByPhaseEnd" << std::endl;
							m_waitTime = waitTime;
						}
					}
				}
				break;
			}
			case GameScene_Class::SelectPhase:
			{
				for (int h = 0; h < 8; h++)
				{
					for (int w = 0; w < 8; w++)
					{
						//�n���ꂽ��񂩂瓮����͈͂�����
						Math::Vector3 massPos = { h * 1 - 3.5f,0,w * 1 - 3.5f };
						if (m_canMoveBordInfo[h][w] == BaseObject_Class::CanMove)
						{
							m_selectPieceCanMoveBord[h][w]->SetAlive(true);
							m_selectPieceCanMoveBord[h][w]->SetPos2(massPos);
							m_waitTime = waitTime;
							std::cout << "SelectPhaseEnd" << std::endl;
							m_Phase = SetPhase;
						}
					}
				}

				if (GetAsyncKeyState(VK_RBUTTON))
				{
					m_selectObject = false;
					m_startPhaseInit = false;
					m_movePieceID = -1;
					m_selectObject = false;
					m_beforeSelectPos = { 12345,12345,12345 };
					m_afterSelectPos = { 12345,12345,12345 };
					for (int h = 0; h < 8; h++)
					{
						for (int w = 0; w < 8; w++)
						{
							m_canMoveBordInfo[h][w] = 0;
							m_selectPieceCanMoveBord[h][w]->SetAlive(false);
						}
					}
					m_Phase = StandByPhase;
				}
				break;
			}
			case GameScene_Class::SetPhase:
			{
				if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
				{

					for (int h = 0; h < 8; h++)
					{
						for (int w = 0; w < 8; w++)
						{
							if (m_selectPieceCanMoveBord[h][w]->GetAlive())
							{
								if (0.5f > (Math::Vector3::Distance(m_selectPieceCanMoveBord[h][w]->GetPos2(), BordOnMouse())))
								{
									m_canMoveBordInfo[h][w] = BaseObject_Class::Select;

									if (m_bordInfo[h][w] != BaseObject_Class::None)
									{
										KillPiece(m_bordInfo[h][w]);
										m_bordInfo[h][w] = BaseObject_Class::None;
									}
									m_bordInfo[h][w] = m_movePieceID;

									m_Phase = EndPhase;
								}
							}
							if (0.5 > (Math::Vector3::Distance(m_beforeSelectPos, { h * 1 - 3.5f,0,w * 1 - 3.5f })))
							{
								m_bordInfo[h][w] = BaseObject_Class::None;
							}

						}
					}
				}
				if (GetAsyncKeyState(VK_RBUTTON))
				{
					m_startPhaseInit = false;
					m_movePieceID = -1;
					m_selectObject = false;
					m_beforeSelectPos = { 12345,12345,12345 };
					m_afterSelectPos = { 12345,12345,12345 };
					for (int h = 0; h < 8; h++)
					{
						for (int w = 0; w < 8; w++)
						{
							m_canMoveBordInfo[h][w] = 0;
							m_selectPieceCanMoveBord[h][w]->SetAlive(false);
						}
					}
					m_Phase = StandByPhase;
				}
				break;
			}
			case GameScene_Class::EndPhase:
			{
				m_Trun = Enemy;
				m_waitTime = waitTime;
				m_selectObject = false;
				std::cout << "EndPhaseEnd" << std::endl;
				m_startPhaseInit = false;
				m_round++;
				if (!(m_kingBlack->GetAlive()))
				{
					m_winner = Player;
					m_changeScene = ResultScene;
					CheangeThisScene();
				}
				m_Phase = StartPhase;
				break;
			}
			default:
				break;
			}
			break;
		}
		case GameScene_Class::Enemy:
		{
			switch (m_Phase)
			{
			case GameScene_Class::StartPhase:
			{
				if (!m_startPhaseInit)
				{
					m_movePieceID = -1;
					m_selectObject = false;
					m_beforeSelectPos = { 12345,12345,12345 };
					m_afterSelectPos = { 12345,12345,12345 };
					for (int h = 0; h < 8; h++)
					{
						for (int w = 0; w < 8; w++)
						{
							m_canMoveBordInfo[h][w] = 0;
							m_selectPieceCanMoveBord[h][w]->SetAlive(false);
						}
					}
					m_onTurnViewUI->SetRoundNum(m_round);
					m_onTurnViewUI->Entry();

					m_numUI->SetNum(m_round);
					m_numUI->SetPos2({ -150,0,0 });
					m_numUI->SetAlive(true);

				}
				if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
				{
					m_Phase = StandByPhase;
					std::cout << "StartPhaseEnd" << std::endl;
					m_onTurnViewUI->Leave();
					m_numUI->SetAlive(false);
					m_waitTime = waitTime;
				}
				break;
			}
			case GameScene_Class::StandByPhase:
			{

				if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
				{

					if (obj->thisPiece() && obj->GetColor() == kBlackColor)
					{
						if (0.5f > (Math::Vector3::Distance(obj->GetPos(), BordOnMouse())))
						{
							m_movePieceID = obj->GetId();
							for (int h = 0; h < 8; h++)
							{
								for (int w = 0; w < 8; w++)
								{
									//�N���b�N�����I�u�W�F�N�g�Ɍ��݂̔Ֆʏ󋵂�n��
									obj->SetBordInfo(h, w, m_bordInfo[h][w]);
									printf("%d_", m_bordInfo[h][w]);
								}
								printf("\n");
							}
							for (int h = 0; h < 8; h++)
							{
								for (int w = 0; w < 8; w++)
								{
									//�I�u�W�F�N�g���瓮����͈͂��z��ŕԋp�����
									obj->GenCanMoveBordInfo();
									m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
									//printf("%d_", m_canMoveBordInfo[h][w]);
								}
								//printf("\n");

							}
							for (int h = 0; h < 8; h++)
							{
								for (int w = 0; w < 8; w++)
								{
									printf("%d_", m_canMoveBordInfo[h][w]);
								}
								printf("\n");
							}
							obj->SetfirstMoved(true);
							m_beforeSelectPos = BordOnMouse();
							m_selectObject = true;
							m_Phase = SelectPhase;
							std::cout << "StandByPhaseEnd" << std::endl;
							m_waitTime = waitTime;
						}
					}
				}
				break;
			}
			case GameScene_Class::SelectPhase:
			{
				for (int h = 0; h < 8; h++)
				{
					for (int w = 0; w < 8; w++)
					{
						//�n���ꂽ��񂩂瓮����͈͂�����
						Math::Vector3 massPos = { h * 1 - 3.5f,0,w * 1 - 3.5f };
						if (m_canMoveBordInfo[h][w] == BaseObject_Class::CanMove)
						{
							m_selectPieceCanMoveBord[h][w]->SetAlive(true);
							m_selectPieceCanMoveBord[h][w]->SetPos2(massPos);
							m_waitTime = waitTime;
							std::cout << "SelectPhaseEnd" << std::endl;
							m_Phase = SetPhase;
						}
					}
				}

				if (GetAsyncKeyState(VK_RBUTTON))
				{
					m_selectObject = false;
					m_startPhaseInit = false;
					m_movePieceID = -1;
					m_selectObject = false;
					m_beforeSelectPos = { 12345,12345,12345 };
					m_afterSelectPos = { 12345,12345,12345 };
					for (int h = 0; h < 8; h++)
					{
						for (int w = 0; w < 8; w++)
						{
							m_canMoveBordInfo[h][w] = 0;
							m_selectPieceCanMoveBord[h][w]->SetAlive(false);
						}
					}
					m_Phase = StandByPhase;
				}
				break;
			}
			case GameScene_Class::SetPhase:
			{
				if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
				{

					for (int h = 0; h < 8; h++)
					{
						for (int w = 0; w < 8; w++)
						{
							if (m_selectPieceCanMoveBord[h][w]->GetAlive())
							{
								if (0.5f > (Math::Vector3::Distance(m_selectPieceCanMoveBord[h][w]->GetPos2(), BordOnMouse())))
								{
									m_canMoveBordInfo[h][w] = BaseObject_Class::Select;

									if (m_bordInfo[h][w] != BaseObject_Class::None)
									{
										KillPiece(m_bordInfo[h][w]);
										m_bordInfo[h][w] = BaseObject_Class::None;
									}
									m_bordInfo[h][w] = m_movePieceID;

									m_Phase = EndPhase;
								}
							}
							if (0.5 > (Math::Vector3::Distance(m_beforeSelectPos, { h * 1 - 3.5f,0,w * 1 - 3.5f })))
							{
								m_bordInfo[h][w] = BaseObject_Class::None;
							}

						}
					}
				}
				if (GetAsyncKeyState(VK_RBUTTON))
				{
					m_startPhaseInit = false;
					m_movePieceID = -1;
					m_selectObject = false;
					m_beforeSelectPos = { 12345,12345,12345 };
					m_afterSelectPos = { 12345,12345,12345 };
					for (int h = 0; h < 8; h++)
					{
						for (int w = 0; w < 8; w++)
						{
							m_canMoveBordInfo[h][w] = 0;
							m_selectPieceCanMoveBord[h][w]->SetAlive(false);
						}
					}
					m_Phase = StandByPhase;
				}
				break;
			}
			case GameScene_Class::EndPhase:
			{
				m_Trun = Player;
				m_waitTime = waitTime;
				m_selectObject = false;
				std::cout << "EndPhaseEnd" << std::endl;
				m_startPhaseInit = false;
				if (!m_kingWhite->GetAlive())
				{
					m_winner = Enemy;
					m_changeScene = ResultScene;
					CheangeThisScene();
				}
				m_Phase = StartPhase;
				break;
			}
			default:
				break;
			}
			break;
		}
		}
	}
	BaseScene_Class::Update();

}

void GameScene_Class::PreUpdate()
{
	m_camera->PreUpdate();
	BaseScene_Class::PreUpdate();
}

void GameScene_Class::PostUpdate()
{
	BaseScene_Class::PostUpdate();
}

void GameScene_Class::PreDraw()
{
	BaseScene_Class::PreDraw();

	m_camera->PreDraw();
}

void GameScene_Class::Release()
{
}

void GameScene_Class::PieceSet()
{

	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			Math::Vector3 massPos = { h * 1 - 3.5f,0,w * 1 - 3.5f };
			switch (m_bordInfo[h][w])
			{
			case BaseObject_Class::None:
				break;
			case BaseObject_Class::WhitePawn0:
				m_pawnWhite[0]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhitePawn1:
				m_pawnWhite[1]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhitePawn2:
				m_pawnWhite[2]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhitePawn3:
				m_pawnWhite[3]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhitePawn4:
				m_pawnWhite[4]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhitePawn5:
				m_pawnWhite[5]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhitePawn6:
				m_pawnWhite[6]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhitePawn7:
				m_pawnWhite[7]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhiteKnight0:
				m_knightWhite[0]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhiteKnight1:
				m_knightWhite[1]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhiteRook0:
				m_rookWhite[0]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhiteRook1:
				m_rookWhite[1]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhiteBishop0:
				m_bishopWhite[0]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhiteBishop1:
				m_bishopWhite[1]->SetPos2(massPos);
				break;
			case BaseObject_Class::WhiteQueen:
				m_queenWhite->SetPos2(massPos);
				break;
			case BaseObject_Class::WhiteKing:
				m_kingWhite->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackPawn0:
				m_pawnBlack[0]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackPawn1:
				m_pawnBlack[1]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackPawn2:
				m_pawnBlack[2]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackPawn3:
				m_pawnBlack[3]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackPawn4:
				m_pawnBlack[4]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackPawn5:
				m_pawnBlack[5]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackPawn6:
				m_pawnBlack[6]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackPawn7:
				m_pawnBlack[7]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackKnight0:
				m_knightBlack[0]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackKnight1:
				m_knightBlack[1]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackRook0:
				m_rookBlack[0]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackRook1:
				m_rookBlack[1]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackBishop0:
				m_bishopBlack[0]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackBishop1:
				m_bishopBlack[1]->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackQueen:
				m_queenBlack->SetPos2(massPos);
				break;
			case BaseObject_Class::BlackKing:
				m_kingBlack->SetPos2(massPos);
				break;
			default:
				break;
			}
		}
	}
}

void GameScene_Class::CheseAI()
{
	//�e�s�[�X�̎��̉\�Ȉ��𗅗�
	for (std::shared_ptr<BaseObject_Class>obj : m_baseObjList)
	{
		obj->GenCanMoveBordInfo();
		for (int h = 0; h < 8; h++)
		{
			for (int w = 0; w < 8; w++)
			{
				if (obj->GetId() == BaseObject_Class::WhiteKing)
				{
					WhiteKing.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhiteQueen)
				{
					WhiteQueen.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhiteRook0)
				{
					WhiteRook0.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhiteRook1)
				{
					WhiteRook1.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhiteBishop0)
				{
					WhiteBishop0.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhiteBishop1)
				{
					WhiteBishop1.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhiteKnight0)
				{
					WhiteKnight0.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhiteKnight1)
				{
					WhiteKnight1.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhitePawn0)
				{
					WhitePawn0.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhitePawn1)
				{
					WhitePawn1.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhitePawn2)
				{
					WhitePawn2.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhitePawn3)
				{
					WhitePawn3.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhitePawn4)
				{
					WhitePawn4.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhitePawn5)
				{
					WhitePawn5.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhitePawn6)
				{
					WhitePawn6.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::WhitePawn7)
				{
					WhitePawn7.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}

				if (obj->GetId() == BaseObject_Class::BlackKing)
				{
					BlackKing.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackQueen)
				{
					BlackQueen.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackRook0)
				{
					BlackRook0.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackRook1)
				{
					BlackRook1.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackBishop0)
				{
					BlackBishop0.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackBishop1)
				{
					BlackBishop1.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackKnight0)
				{
					BlackKnight0.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackKnight1)
				{
					BlackKnight1.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackPawn0)
				{
					BlackPawn0.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackPawn1)
				{
					BlackPawn1.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackPawn2)
				{
					BlackPawn2.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackPawn3)
				{
					BlackPawn3.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackPawn4)
				{
					BlackPawn4.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackPawn5)
				{
					BlackPawn5.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackPawn6)
				{
					BlackPawn6.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
				if (obj->GetId() == BaseObject_Class::BlackPawn7)
				{
					BlackPawn7.m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
				}
			}
		}
	}
	//�`�F�b�N�����̃��E���h�Ŏ���邩�H
	{
		for (std::shared_ptr<BaseObject_Class>obj : m_baseObjList)
		{
			if (obj->GetId() == BaseObject_Class::BlackKing)
			{
				for (int h = 0; h < 8; h++)
				{
					for (int w = 0; w < 8; w++)
					{
						//if(0.5<Math::Vector3::Distance())
					}
				}
			}
		}
	}
	
}

Math::Vector3 GameScene_Class::BordOnMouse()
{
	if (m_camera)
	{
		static float range = 100;

		static Math::Vector3 rayDir = Math::Vector3::Zero;

		m_camera->WorkCamera()->GenerateRayInfoFromClientPos(MousePos, m_camera->GetPos(), rayDir, range);

		if (m_bord)
		{
			Math::Vector3 endRayPos = m_camera->GetPos() + (rayDir * range);

			KdCollider::RayInfo rayInfo(KdCollider::TypeGround, m_camera->GetPos(), endRayPos);

			std::list<KdCollider::CollisionResult>result;

			m_bord->Intersects(rayInfo, &result);

			if (result.size())
			{
				for (KdCollider::CollisionResult resulted : result)
				{
					for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
					{
						for (int h = 0; h < 8; h++)
						{
							for (int w = 0; w < 8; w++)
							{
								Math::Vector3 massPos = { h * 1.0f - 3.5f,0.01f,w * 1.0f - 3.5f };
								if ((Math::Vector3::Distance(massPos, resulted.m_hitPos) <= 0.75f))
								{
									if ((Math::Vector3::Distance(gameObject->GetPos(), massPos) < 0.5f) && !m_selectObject && gameObject->thisPiece())
									{
										return massPos;
									}
									return massPos;
								}
							}
						}
					}
				}
			}
		}
	}
	return { 12345,12345,12345 };
}

void GameScene_Class::SelectPieceUIActive()
{
	m_nowSelectBord->SetAlive(true);
	m_nowSelectBord->SetPos(BordOnMouse());
	if (m_selectObject)
	{
		m_beforeSelectBord->SetPos(m_beforeSelectPos);
		m_beforeSelectBord->SetAlive(true);
		m_pieceSelectUI->SetAlive(true);
	}
	else
	{
		for (int h = 0; h < 8; h++)
		{
			for (int w = 0; w < 8; w++)
			{
				Math::Vector3 massPos = { h * 1.0f - 3.5f,0.01f,w * 1.0f - 3.5f };
				m_selectPieceCanMoveBord[h][w]->SetPos(massPos);
				m_selectPieceCanMoveBord[h][w]->SetAlive(false);
			}
		}
		m_beforeSelectBord->SetAlive(false);
		m_pieceSelectUI->SetAlive(false);
	}
}