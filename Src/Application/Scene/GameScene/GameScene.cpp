#include"GameScene.h"

//Include数が多いため分割する

//ピース用Includeヘッダファイル
#include"Application/Object/PieceObject/Piece_Include_Config.h"

#include"Application/Object/SkyBox/SkyBox.h"
#include"Application/Object/SelectingBord/SelectingBord.h"
#include"Application/Object/BordObject/BordObject.h"
#include"Application/Object/CameraObject/Camera.h"

#include"Application/UI/UIBaseObject.h"
#include"Application/UI/PieceSelectingUI/PieceSelectingUI.h"
#include"Application/UI/OnTurnViewUI/OnTurnViewUI_Class.h"
#include"Application/UI/NumUI/NumUI_Class.h"
#include"Application/UI/ButtonUI/ButtonUI_Class.h"
#include"Application/UI/ProPotionButtonUI/ProPotionButtonUI.h"

#include"Application/Audio/BaseAudio_Class.h"
#include"Application/Object/PieceObject/PieceBaseObject/PieceBaseObject.h"

void GameScene_Class::SetSharedPtr()
{
	if (!m_bgm1)m_bgm1 = std::make_shared<BaseAudio_Class>();
	m_bgm1->SetAudio("Asset/Sound/GameBGM1.wav");

	if (!m_piecePlaceSound)m_piecePlaceSound = std::make_shared<BaseAudio_Class>();
	m_piecePlaceSound->SetAudio("Asset/Sound/PlacePieceSound.wav");

	std::string str;
	std::string str2;
	if (!m_camera)m_camera = std::make_shared<Camera_Class>();
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

	if (!m_PlayerTurnView)m_PlayerTurnView = std::make_shared<UIBaseObject_Class>();
	m_PlayerTurnView->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/PlayerTurn.png");
	m_PlayerTurnView->SetPos({ 0,100,0 });
	m_baseObjList.push_back(m_PlayerTurnView);

	if (!m_EnemyTurnView)m_EnemyTurnView = std::make_shared<UIBaseObject_Class>();
	m_EnemyTurnView->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/EnemyTurn.png");
	m_EnemyTurnView->SetPos({ 0,100,0 });
	m_baseObjList.push_back(m_EnemyTurnView);

	if (!m_ProPotionBishopView)m_ProPotionBishopView = std::make_shared<ProPotionButtonUI_Class>();
	m_ProPotionBishopView->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/Propotion/ProptionBishop.png");
	m_ProPotionBishopView->SetPos({ 100,0,0 });
	m_baseObjList.push_back(m_ProPotionBishopView);

	if (!m_ProPotionKnightView)m_ProPotionKnightView = std::make_shared<ProPotionButtonUI_Class>();
	m_ProPotionKnightView->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/Propotion/ProptionKnight.png");
	m_ProPotionKnightView->SetPos({ -100,0,0 });
	m_baseObjList.push_back(m_ProPotionKnightView);

	if (!m_ProPotionRookView)m_ProPotionRookView = std::make_shared<ProPotionButtonUI_Class>();
	m_ProPotionRookView->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/Propotion/ProptionRook.png");
	m_ProPotionRookView->SetPos({ 0,-100,0 });
	m_baseObjList.push_back(m_ProPotionRookView);

	if (!m_ProPotionQueenView)m_ProPotionQueenView = std::make_shared<ProPotionButtonUI_Class>();
	m_ProPotionQueenView->SetAsset(BaseObject_Class::Sprite, "Asset/Textures/UI/Propotion/ProptionQueen.png");
	m_ProPotionQueenView->SetPos({ 0,100,0 });
	m_baseObjList.push_back(m_ProPotionQueenView);

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

	{
		if (!m_kingWhite)m_kingWhite = std::make_shared<KingPieceObject_Class>();
		m_kingWhite->SetColor(kWhiteColor);
		m_kingWhite->SetId(PieceBaseObject_Class::WhiteKing);
		m_kingWhite->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/King/King.gltf");
		m_pieceList.push_back(m_kingWhite);

		if (!m_kingBlack)m_kingBlack = std::make_shared<KingPieceObject_Class>();
		m_kingBlack->SetColor(kBlackColor);
		m_kingBlack->SetId(PieceBaseObject_Class::BlackKing);
		m_kingBlack->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/King/King.gltf");
		m_pieceList.push_back(m_kingBlack);

		if (!m_queenWhite)m_queenWhite = std::make_shared<QueenPieceObject_Class>();
		m_queenWhite->SetColor(kWhiteColor);
		m_queenWhite->SetId(PieceBaseObject_Class::WhiteQueen);
		m_queenWhite->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Queen/Queen.gltf");
		m_pieceList.push_back(m_queenWhite);

		if (!m_queenBlack)m_queenBlack = std::make_shared<QueenPieceObject_Class>();
		m_queenBlack->SetColor(kBlackColor);
		m_queenBlack->SetId(PieceBaseObject_Class::BlackQueen);
		m_queenBlack->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Queen/Queen.gltf");
		m_pieceList.push_back(m_queenBlack);

	}

	for (int n = 0; n < 8; n++)
	{
		if (!m_pawnWhite[n])m_pawnWhite[n] = std::make_shared<PawnPieceObject_Class>();
		m_pawnWhite[n]->SetColor(kWhiteColor);
		m_pawnWhite[n]->SetId(PieceBaseObject_Class::WhitePawn0 + n);
		m_pawnWhite[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Pawn/Pawn.gltf");
		m_pieceList.push_back(m_pawnWhite[n]);

		if (!m_pawnBlack[n])m_pawnBlack[n] = std::make_shared<PawnPieceObject_Class>();
		m_pawnBlack[n]->SetColor(kBlackColor);
		m_pawnBlack[n]->SetId(PieceBaseObject_Class::BlackPawn0 + n);
		m_pawnBlack[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Pawn/Pawn.gltf");
		m_pieceList.push_back(m_pawnBlack[n]);

		std::cout << str << std::endl;
	}

	for (int n = 0; n < 2; n++)
	{

		if (!m_rookWhite[n])m_rookWhite[n] = std::make_shared<RookPieceObject_Class>();
		m_rookWhite[n]->SetColor(kWhiteColor);
		m_rookWhite[n]->SetId(PieceBaseObject_Class::WhiteRook0 + n);
		m_rookWhite[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Rook/Rook.gltf");
		m_pieceList.push_back(m_rookWhite[n]);


		if (!m_rookBlack[n])m_rookBlack[n] = std::make_shared<RookPieceObject_Class>();
		m_rookBlack[n]->SetColor(kBlackColor);
		m_rookBlack[n]->SetId(PieceBaseObject_Class::BlackRook0 + n);
		m_rookBlack[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Rook/Rook.gltf");
		m_pieceList.push_back(m_rookBlack[n]);

	}

	for (int n = 0; n < 2; n++)
	{

		if (!m_knightWhite[n])m_knightWhite[n] = std::make_shared<KnightPieceObject_Class>();
		m_knightWhite[n]->SetColor(kWhiteColor);
		m_knightWhite[n]->SetId(PieceBaseObject_Class::WhiteKnight0 + n);
		m_knightWhite[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Knight/Knight.gltf");
		m_pieceList.push_back(m_knightWhite[n]);

		str2 = std::to_string(n);
		str = "KnightBlack";
		str.append(str2);
		if (!m_knightBlack[n])m_knightBlack[n] = std::make_shared<KnightPieceObject_Class>();
		m_knightBlack[n]->SetColor(kBlackColor);
		m_knightBlack[n]->SetId(PieceBaseObject_Class::BlackKnight0 + n);
		m_knightBlack[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Knight/Knight.gltf");
		m_pieceList.push_back(m_knightBlack[n]);

	}

	for (int n = 0; n < 2; n++)
	{

		if (!m_bishopWhite[n])m_bishopWhite[n] = std::make_shared<BishopPieceObject_Class>();
		m_bishopWhite[n]->SetColor(kWhiteColor);
		m_bishopWhite[n]->SetId(PieceBaseObject_Class::WhiteBishop0 + n);
		m_bishopWhite[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Bishop/Bishop.gltf");
		m_pieceList.push_back(m_bishopWhite[n]);

		if (!m_bishopBlack[n])m_bishopBlack[n] = std::make_shared<BishopPieceObject_Class>();
		m_bishopBlack[n]->SetColor(kBlackColor);
		m_bishopBlack[n]->SetId(PieceBaseObject_Class::BlackBishop0 + n);
		m_bishopBlack[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Bishop/Bishop.gltf");
		m_pieceList.push_back(m_bishopBlack[n]);

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

void GameScene_Class::Init()
{
	BaseScene_Class::Init();
	for (std::shared_ptr<BaseObject_Class> obj : m_baseObjList)
	{
		obj->Init();
	}
	for (std::shared_ptr<PieceBaseObject_Class> obj : m_pieceList)
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
	m_waitTime = WAIT_TIME;

	m_bgm1->PlayAudio();
}

void GameScene_Class::Update()
{
	//KdCamera camera;
	//Math::Matrix mat;
	//camera.SetCameraMatrix(mat);
	///camera.SetToShader();

	m_camera->setCamViewMode(m_camera->UpperCamMode);
	PieceSet();
	BordOnMouse();
	SelectPieceUIActive();
	for (std::shared_ptr<PieceBaseObject_Class>obj : m_pieceList)
	{
		obj->Update();
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
					m_selectPieceId = -1;
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
					m_onTurnViewUI->SetAlive(true);
					m_PlayerTurnView->SetAlive(true);
					m_numUI->SetNum(m_round);
					m_numUI->SetPos({ -150,0,0 });
					m_numUI->SetAlive(true);

				}
				if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
				{
					m_Phase = StandByPhase;
					std::cout << "StartPhaseEnd" << std::endl;
					m_onTurnViewUI->Leave();
					m_numUI->SetAlive(false);
					m_PlayerTurnView->SetAlive(false);
					m_waitTime = WAIT_TIME;
				}
				break;
			}
			case GameScene_Class::StandByPhase:
			{

				if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
				{
					if (obj->GetColor() == kWhiteColor)
					{
						if (0.5f > (Math::Vector3::Distance(obj->GetPos(), BordOnMouse())))
						{
							m_selectPieceId = obj->GetId();
							for (int h = 0; h < 8; h++)
							{
								for (int w = 0; w < 8; w++)
								{
									//クリックしたオブジェクトに現在の盤面状況を渡す
									obj->SetBordInfo(h, w, m_bordInfo[h][w]);
								}
							}
							for (int h = 0; h < 8; h++)
							{
								for (int w = 0; w < 8; w++)
								{
									//オブジェクトから動ける範囲が配列で返却される
									obj->GenCanMoveBordInfo();
									m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
								}

							}
							if (obj->GetCanPropotion() && !obj->GetPropotined())
							{
								m_selectPieceId = obj->GetId();
								m_Phase = ProPotionPhase;
							}
							else
							{
								m_ProPotionBishopView->SetAlive(false);
								m_ProPotionKnightView->SetAlive(false);
								m_ProPotionQueenView->SetAlive(false);
								m_ProPotionRookView->SetAlive(false);
								obj->SetfirstMoved(true);
								m_beforeSelectPos = BordOnMouse();
								m_selectObject = true;
								m_Phase = SelectPhase;
								std::cout << "StandByPhaseEnd" << std::endl;
								m_waitTime = WAIT_TIME;
							}

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
						//渡された情報から動ける範囲を可視化
						Math::Vector3 massPos = { h * 1 - 3.5f,0,w * 1 - 3.5f };
						if (m_canMoveBordInfo[h][w] == PieceBaseObject_Class::CanMove)
						{
							m_selectPieceCanMoveBord[h][w]->SetAlive(true);
							m_selectPieceCanMoveBord[h][w]->SetPos(massPos);
							m_waitTime = WAIT_TIME;
							std::cout << "SelectPhaseEnd" << std::endl;
							m_Phase = SetPhase;
						}


					}
				}

				if (GetAsyncKeyState(VK_RBUTTON))
				{
					m_selectObject = false;
					m_startPhaseInit = false;
					m_selectPieceId = -1;
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
								if (0.5f > (Math::Vector3::Distance(m_selectPieceCanMoveBord[h][w]->GetPos(), BordOnMouse())))
								{
									m_canMoveBordInfo[h][w] = PieceBaseObject_Class::Select;

									if (m_bordInfo[h][w] != PieceBaseObject_Class::None)
									{
										KillPiece(m_bordInfo[h][w]);
										m_bordInfo[h][w] = PieceBaseObject_Class::None;
									}
									m_bordInfo[h][w] = m_selectPieceId;
									m_piecePlaceSound->PlayAudio();
									m_Phase = EndPhase;
								}
							}
							if (0.5 > (Math::Vector3::Distance(m_beforeSelectPos, { h * 1 - 3.5f,0,w * 1 - 3.5f })))
							{
								m_bordInfo[h][w] = PieceBaseObject_Class::None;
							}

						}
					}
				}
				if (GetAsyncKeyState(VK_RBUTTON))
				{
					m_startPhaseInit = false;
					m_selectPieceId = -1;
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
				m_ProPotionBishopView->SetSelecting(false);
				m_ProPotionKnightView->SetSelecting(false);
				m_ProPotionQueenView->SetSelecting(false);
				m_ProPotionRookView->SetSelecting(false);

				m_Trun = Enemy;
				m_waitTime = WAIT_TIME;
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
			case GameScene_Class::ProPotionPhase:
			{
				if (obj->GetId() == m_selectPieceId)
				{
					m_ProPotionBishopView->SetSelecting(false);
					m_ProPotionKnightView->SetSelecting(false);
					m_ProPotionQueenView->SetSelecting(false);
					m_ProPotionRookView->SetSelecting(false);

					m_ProPotionBishopView->SetAlive(true);
					m_ProPotionKnightView->SetAlive(true);
					m_ProPotionQueenView->SetAlive(true);
					m_ProPotionRookView->SetAlive(true);

					m_ProPotionBishopView->SetPos({ -100,0,0 });
					m_ProPotionKnightView->SetPos({ 100,0,0 });
					m_ProPotionQueenView->SetPos({ 0,100,0 });
					m_ProPotionRookView->SetPos({ 0,-100,0 });
					if (fixMousePos.y <= m_ProPotionBishopView->GetPos().y + 100 / 2 && fixMousePos.y >= m_ProPotionBishopView->GetPos().y - 100 / 2)
					{
						if (fixMousePos.x <= m_ProPotionBishopView->GetPos().x + 100 / 2 && fixMousePos.x >= m_ProPotionBishopView->GetPos().x - 100 / 2)
						{
							m_ProPotionBishopView->SetSelecting(true);
							if (GetAsyncKeyState(VK_LBUTTON))
							{
								obj->SetPropotion(1);
								m_ProPotionBishopView->SetAlive(false);
								m_ProPotionKnightView->SetAlive(false);
								m_ProPotionQueenView->SetAlive(false);
								m_ProPotionRookView->SetAlive(false);

								m_Phase = EndPhase;
							}
						}
					}
					if (fixMousePos.y <= m_ProPotionKnightView->GetPos().y + 100 / 2 && fixMousePos.y >= m_ProPotionKnightView->GetPos().y - 100 / 2)
					{
						if (fixMousePos.x <= m_ProPotionKnightView->GetPos().x + 100 / 2 && fixMousePos.x >= m_ProPotionKnightView->GetPos().x - 100 / 2)
						{
							m_ProPotionKnightView->SetSelecting(true);
							if (GetAsyncKeyState(VK_LBUTTON))
							{
								obj->SetPropotion(2);
								m_ProPotionBishopView->SetAlive(false);
								m_ProPotionKnightView->SetAlive(false);
								m_ProPotionQueenView->SetAlive(false);
								m_ProPotionRookView->SetAlive(false);
								m_Phase = EndPhase;
							}
						}
					}
					if (fixMousePos.y <= m_ProPotionRookView->GetPos().y + 100 / 2 && fixMousePos.y >= m_ProPotionRookView->GetPos().y - 100 / 2)
					{
						if (fixMousePos.x <= m_ProPotionRookView->GetPos().x + 100 / 2 && fixMousePos.x >= m_ProPotionRookView->GetPos().x - 100 / 2)
						{
							m_ProPotionRookView->SetSelecting(true);
							if (GetAsyncKeyState(VK_LBUTTON))
							{
								obj->SetPropotion(0);
								m_ProPotionBishopView->SetAlive(false);
								m_ProPotionKnightView->SetAlive(false);
								m_ProPotionQueenView->SetAlive(false);
								m_ProPotionRookView->SetAlive(false);
								m_Phase = EndPhase;
							}
						}
					}
					if (fixMousePos.y <= m_ProPotionQueenView->GetPos().y + 100 / 2 && fixMousePos.y >= m_ProPotionQueenView->GetPos().y - 100 / 2)
					{
						if (fixMousePos.x <= m_ProPotionQueenView->GetPos().x + 100 / 2 && fixMousePos.x >= m_ProPotionQueenView->GetPos().x - 100 / 2)
						{
							m_ProPotionQueenView->SetSelecting(true);
							if (GetAsyncKeyState(VK_LBUTTON))
							{
								obj->SetPropotion(3);
								m_ProPotionBishopView->SetAlive(false);
								m_ProPotionKnightView->SetAlive(false);
								m_ProPotionQueenView->SetAlive(false);
								m_ProPotionRookView->SetAlive(false);
								m_Phase = EndPhase;
							}

						}
					}
				}
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
					m_selectPieceId = -1;
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
					m_onTurnViewUI->SetAlive(true);
					m_EnemyTurnView->SetAlive(true);
					m_numUI->SetNum(m_round);
					m_numUI->SetPos({ -150,0,0 });
					m_numUI->SetAlive(true);
					m_aiPoint = 0;

				}
				if (m_waitTime <= 0)
				{
					m_Phase = StandByPhase;
					std::cout << "StartPhaseEnd" << std::endl;
					m_onTurnViewUI->Leave();
					m_numUI->SetAlive(false);
					m_EnemyTurnView->SetAlive(false);
					m_waitTime = WAIT_TIME;
				}

				break;
			}
			case GameScene_Class::StandByPhase:
			{
				OnAI();
				if (m_waitTime <= 0)
				{
					if (obj->GetColor() == kBlackColor)
					{
						if (0.5f > (Math::Vector3::Distance(obj->GetPos(), m_beforeSelectPos)))
						{
							m_selectPieceId = obj->GetId();
							for (int h = 0; h < 8; h++)
							{
								for (int w = 0; w < 8; w++)
								{
									//クリックしたオブジェクトに現在の盤面状況を渡す
									obj->SetBordInfo(h, w, m_bordInfo[h][w]);
								}
							}
							for (int h = 0; h < 8; h++)
							{
								for (int w = 0; w < 8; w++)
								{
									//オブジェクトから動ける範囲が配列で返却される
									obj->GenCanMoveBordInfo();
									m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
								}

							}
							if (obj->GetCanPropotion() && !obj->GetPropotined())
							{
								m_selectPieceId = obj->GetId();
								m_Phase = ProPotionPhase;
							}
							else
							{
								m_ProPotionBishopView->SetAlive(false);
								m_ProPotionKnightView->SetAlive(false);
								m_ProPotionQueenView->SetAlive(false);
								m_ProPotionRookView->SetAlive(false);
								obj->SetfirstMoved(true);
								m_selectObject = true;
								m_Phase = SelectPhase;
								std::cout << "StandByPhaseEnd" << std::endl;
								m_waitTime = WAIT_TIME;
							}

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
						//渡された情報から動ける範囲を可視化
						Math::Vector3 massPos = { h * 1 - 3.5f,0,w * 1 - 3.5f };
						if (m_canMoveBordInfo[h][w] == PieceBaseObject_Class::CanMove)
						{
							m_selectPieceCanMoveBord[h][w]->SetAlive(true);
							m_selectPieceCanMoveBord[h][w]->SetPos(massPos);
							m_waitTime = WAIT_TIME;
							std::cout << "SelectPhaseEnd" << std::endl;
							m_Phase = SetPhase;
						}
					}
				}
				break;
			}
			case GameScene_Class::SetPhase:
			{
				if (m_waitTime <= 0)
				{

					for (int h = 0; h < 8; h++)
					{
						for (int w = 0; w < 8; w++)
						{
							if (m_selectPieceCanMoveBord[h][w]->GetAlive())
							{
								if (0.5f > (Math::Vector3::Distance(m_selectPieceCanMoveBord[h][w]->GetPos(), m_afterSelectPos)))
								{
									m_canMoveBordInfo[h][w] = PieceBaseObject_Class::Select;

									if (m_bordInfo[h][w] != PieceBaseObject_Class::None)
									{
										KillPiece(m_bordInfo[h][w]);
										m_bordInfo[h][w] = PieceBaseObject_Class::None;
									}
									m_bordInfo[h][w] = m_selectPieceId;
									m_piecePlaceSound->PlayAudio();
									m_Phase = EndPhase;
								}
							}
							if (0.5 > (Math::Vector3::Distance(m_beforeSelectPos, { h * 1 - 3.5f,0,w * 1 - 3.5f })))
							{
								m_bordInfo[h][w] = PieceBaseObject_Class::None;
							}

						}
					}
				}
				break;
			}
			case GameScene_Class::EndPhase:
			{
				m_ProPotionBishopView->SetSelecting(false);
				m_ProPotionKnightView->SetSelecting(false);
				m_ProPotionQueenView->SetSelecting(false);
				m_ProPotionRookView->SetSelecting(false);

				m_Trun = Player;
				m_waitTime = WAIT_TIME;
				m_selectObject = false;
				std::cout << "EndPhaseEnd" << std::endl;
				m_startPhaseInit = false;
				m_round++;
				if (!(m_kingWhite->GetAlive()))
				{
					m_winner = Enemy;
					m_changeScene = ResultScene;
					CheangeThisScene();
				}
				m_Phase = StartPhase;
				break;
			}
			case GameScene_Class::ProPotionPhase:
			{
				break;
			}
			default:
				break;
			}
		}
		}
	}
	BaseScene_Class::Update();
}

void GameScene_Class::PreUpdate()
{
	BaseScene_Class::PreUpdate();
	for (std::shared_ptr<PieceBaseObject_Class> obj : m_pieceList)
	{
		obj->PreUpdate();
	}
}

void GameScene_Class::PostUpdate()
{
	BaseScene_Class::PostUpdate();
	for (std::shared_ptr<PieceBaseObject_Class> obj : m_pieceList)
	{
		obj->PostUpdate();
	}
}

void GameScene_Class::PreDraw()
{
	BaseScene_Class::PreDraw();
	for (std::shared_ptr<PieceBaseObject_Class> obj : m_pieceList)
	{
		obj->PreDraw();
	}
}

void GameScene_Class::Draw()
{
	for (auto obj : m_pieceList)
	{
		obj->Draw();
	}
	BaseScene_Class::Draw();
}

void GameScene_Class::DrawLit()
{
	for (auto obj : m_pieceList)
	{
		obj->DrawLit();
	}
	BaseScene_Class::DrawLit();
}

void GameScene_Class::GenerateDepthMapFromLight()
{
	for (auto obj : m_pieceList)
	{
		obj->GenerateDepthMapFromLight();
	}
	BaseScene_Class::GenerateDepthMapFromLight();
}

void GameScene_Class::DrawBright()
{
	for (auto obj : m_pieceList)
	{
		obj->DrawBright();
	}
	BaseScene_Class::DrawBright();
}

void GameScene_Class::DrawUnLit()
{
	for (auto obj : m_pieceList)
	{
		obj->DrawUnLit();
	}
	BaseScene_Class::DrawUnLit();
}

void GameScene_Class::DrawSprite()
{
	for (auto obj : m_pieceList)
	{
		obj->DrawSprite();
	}
	BaseScene_Class::DrawSprite();
}

void GameScene_Class::PostDraw()
{
	for (auto obj : m_pieceList)
	{
		obj->PostUpdate();
	}
	BaseScene_Class::PostDraw();
}

void GameScene_Class::KillPiece(int _id)
{

	for (std::shared_ptr<PieceBaseObject_Class>obj : m_pieceList)
	{
		if (obj->GetId() == _id)
		{
			obj->SetAlive(false);
			obj->SetPos({ 12345,12345,12345 });
		}
	}

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
			case PieceBaseObject_Class::None:
				break;
			case PieceBaseObject_Class::WhitePawn0:
				m_pawnWhite[0]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhitePawn1:
				m_pawnWhite[1]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhitePawn2:
				m_pawnWhite[2]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhitePawn3:
				m_pawnWhite[3]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhitePawn4:
				m_pawnWhite[4]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhitePawn5:
				m_pawnWhite[5]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhitePawn6:
				m_pawnWhite[6]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhitePawn7:
				m_pawnWhite[7]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhiteKnight0:
				m_knightWhite[0]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhiteKnight1:
				m_knightWhite[1]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhiteRook0:
				m_rookWhite[0]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhiteRook1:
				m_rookWhite[1]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhiteBishop0:
				m_bishopWhite[0]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhiteBishop1:
				m_bishopWhite[1]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhiteQueen:
				m_queenWhite->SetPos(massPos);
				break;
			case PieceBaseObject_Class::WhiteKing:
				m_kingWhite->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackPawn0:
				m_pawnBlack[0]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackPawn1:
				m_pawnBlack[1]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackPawn2:
				m_pawnBlack[2]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackPawn3:
				m_pawnBlack[3]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackPawn4:
				m_pawnBlack[4]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackPawn5:
				m_pawnBlack[5]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackPawn6:
				m_pawnBlack[6]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackPawn7:
				m_pawnBlack[7]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackKnight0:
				m_knightBlack[0]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackKnight1:
				m_knightBlack[1]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackRook0:
				m_rookBlack[0]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackRook1:
				m_rookBlack[1]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackBishop0:
				m_bishopBlack[0]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackBishop1:
				m_bishopBlack[1]->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackQueen:
				m_queenBlack->SetPos(massPos);
				break;
			case PieceBaseObject_Class::BlackKing:
				m_kingBlack->SetPos(massPos);
				break;
			default:
				break;
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
					for (std::shared_ptr<BaseObject_Class> obj : m_baseObjList)
					{
						for (int h = 0; h < 8; h++)
						{
							for (int w = 0; w < 8; w++)
							{
								Math::Vector3 massPos = { h * 1.0f - 3.5f,0.01f,w * 1.0f - 3.5f };
								if ((Math::Vector3::Distance(massPos, resulted.m_hitPos) <= 0.75f))
								{
									if ((Math::Vector3::Distance(obj->GetPos(), massPos) < 0.5f) && !m_selectObject)
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

void GameScene_Class::OnAI()
{
	int n = PieceBaseObject_Class::BlackPawn0;
	while (1)
	{
		for (auto obj : m_pieceList)
		{
			//動ける範囲に取れる駒がある場合
			if (obj->GetId() == n && obj->GetAlive())
			{

				//現在の盤面を渡す
				for (int h = 0; h < 8; h++)
				{
					for (int w = 0; w < 8; w++)
					{
						obj->SetBordInfo(h, w, m_bordInfo[h][w]);
					}
				}
				//動ける範囲を生成
				obj->GenCanMoveBordInfo();

				//動ける範囲を取得
				for (int h = 0; h < 8; h++)
				{
					for (int w = 0; w < 8; w++)
					{
						m_canMoveBordInfo[h][w] = obj->SetCanMoveBordInfo(h, w);
					}
				}
				
				for (int h = 0; h < 8; h++)
				{
					for (int w = 0; w < 8; w++)
					{
						//ピースがある場所を検索
						if (m_bordInfo[h][w] != PieceBaseObject_Class::None)
						{
							//そこが移動できる場所か検索
							if (m_canMoveBordInfo[h][w] == PieceBaseObject_Class::CanMove)
							{
								//移動できる場所にあるピースを検索
								//取れる可能性のあるピースに点を付けてより高い点を取るように仕向ける
								switch (m_bordInfo[h][w])
								{
								case PieceBaseObject_Class::WhiteKing:
								{
									m_selectPieceId = obj->GetId();
									m_beforeSelectPos = obj->GetPos();
									m_aiPoint = 10000;
									m_afterSelectPos.x = h * 1 - 3.5f;
									m_afterSelectPos.z = w * 1 - 3.5f;
									break;
								}
								case PieceBaseObject_Class::WhiteBishop0:
								case PieceBaseObject_Class::WhiteBishop1:
								{
									if (m_aiPoint < 130)
									{
										m_beforeSelectPos = obj->GetPos();
										m_selectPieceId = obj->GetId();
										m_afterSelectPos.x = h * 1 - 3.5f;
										m_afterSelectPos.z = w * 1 - 3.5f;
										m_aiPoint = 130;
									}
									break;
								}
								case PieceBaseObject_Class::WhiteKnight0:
								case PieceBaseObject_Class::WhiteKnight1:
								{
									if (m_aiPoint < 150)
									{
										m_beforeSelectPos = obj->GetPos();
										m_selectPieceId = obj->GetId();
										m_afterSelectPos.x = h * 1 - 3.5f;
										m_afterSelectPos.z = w * 1 - 3.5f;
										m_aiPoint = 150;
									}
									break;
								}
								case PieceBaseObject_Class::WhiteRook0:
								case PieceBaseObject_Class::WhiteRook1:
								{
									if (m_aiPoint < 170)
									{
										m_beforeSelectPos = obj->GetPos();
										m_selectPieceId = obj->GetId();
										m_afterSelectPos.x = h * 1 - 3.5f;
										m_afterSelectPos.z = w * 1 - 3.5f;
										m_aiPoint = 170;
									}
									break;
								}
								case PieceBaseObject_Class::WhiteQueen:
								{
									if (m_aiPoint < 200)
									{
										m_beforeSelectPos = obj->GetPos();
										m_selectPieceId = obj->GetId();
										m_afterSelectPos.x = h * 1 - 3.5f;
										m_afterSelectPos.z = w * 1 - 3.5f;
										m_aiPoint = 200;
									}
									break;
								}
								case PieceBaseObject_Class::WhitePawn0:
								case PieceBaseObject_Class::WhitePawn1:
								case PieceBaseObject_Class::WhitePawn2:
								case PieceBaseObject_Class::WhitePawn3:
								case PieceBaseObject_Class::WhitePawn4:
								case PieceBaseObject_Class::WhitePawn5:
								case PieceBaseObject_Class::WhitePawn6:
								case PieceBaseObject_Class::WhitePawn7:
								{
									if (m_aiPoint < 100)
									{
										m_beforeSelectPos = obj->GetPos();
										m_selectPieceId = obj->GetId();
										m_afterSelectPos.x = h * 1 - 3.5f;
										m_afterSelectPos.z = w * 1 - 3.5f;
										m_aiPoint = 100;
									}
									break;
								}
								}
							}

						}
						//ピースが無い場合
						if (m_bordInfo[h][w] == PieceBaseObject_Class::None)
						{
							//検索中のピースを特定
							switch (obj->GetId())
							{
							case PieceBaseObject_Class::BlackKing:
							{
								if (m_aiPoint < 30)
								{
									m_beforeSelectPos = obj->GetPos();
									m_afterSelectPos =  obj->GenRandomMove();
									m_selectPieceId = obj->GetId();
									m_aiPoint = 30;
									
								}
								break;
							}
							case PieceBaseObject_Class::BlackQueen:
							{
								if (m_aiPoint < 70)
								{
									m_beforeSelectPos = obj->GetPos();
									obj->GenRandomMove();
									m_selectPieceId = obj->GetId();
									m_aiPoint = 70;
									break;
								}
								break;
							}
							case PieceBaseObject_Class::BlackPawn0:
							case PieceBaseObject_Class::BlackPawn1:
							case PieceBaseObject_Class::BlackPawn2:
							case PieceBaseObject_Class::BlackPawn3:
							case PieceBaseObject_Class::BlackPawn4:
							case PieceBaseObject_Class::BlackPawn5:
							case PieceBaseObject_Class::BlackPawn6:
							case PieceBaseObject_Class::BlackPawn7:
							{
								if (m_aiPoint < 99)
								{
									m_beforeSelectPos = obj->GetPos();
									m_afterSelectPos = obj->GenRandomMove();
									m_selectPieceId = obj->GetId();
									m_aiPoint = 99;
									
								}
								break;
							}
							case PieceBaseObject_Class::BlackBishop0:
							case PieceBaseObject_Class::BlackBishop1:
							{
								if (m_aiPoint < 80)
								{
									m_beforeSelectPos = obj->GetPos();
									m_afterSelectPos = obj->GenRandomMove();
									m_selectPieceId = obj->GetId();
									m_aiPoint = 80;
									
								}
								break;
							}
							case PieceBaseObject_Class::BlackKnight0:
							case PieceBaseObject_Class::BlackKnight1:
							{
								if (m_aiPoint < 85)
								{
									m_beforeSelectPos = obj->GetPos();
									m_afterSelectPos = obj->GenRandomMove();
									m_selectPieceId = obj->GetId();
									m_aiPoint = 80;
									
								}
								break;
							}
							case PieceBaseObject_Class::BlackRook0:
							case PieceBaseObject_Class::BlackRook1:
							{
								if (m_aiPoint < 90)
								{
									m_beforeSelectPos = obj->GetPos();
									m_afterSelectPos = obj->GenRandomMove();
									m_selectPieceId = obj->GetId();
									m_aiPoint = 90;
									
								}
								break;
							}
							default:
								break;
							}
						}
					}
				}

			}

			
		}
		n++;
		if (n >= PieceBaseObject_Class::BlackKing + 1)
		{
			break;
		}

	}
}