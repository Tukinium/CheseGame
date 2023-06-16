#include"GameScene.h"

//Include数が多いため分割する

//ピース用Includeヘッダファイル
#include"Application/Object/PieceObject/Piece_Include_Config.h"

#include"Application/Object/SkyBox/SkyBox.h"
#include"Application/Object/SelectingBord/SelectingBord.h"
#include"Application/Object/BordObject/BordObject.h"
#include"Application/Object/CameraObject/Camera.h"

#include"Application/UI/PieceSelectingUI/PieceSelectingUI.h"
#include"Application/UI/PieceSelectingUI/SelectingPieceTypeName_UI.h"

void GameScene_Class::Init()
{
	CreateCons();
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

	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			printf("%d", m_canMoveBordInfo[h][w]);

		}
		printf("\n");
	}
	PieceSet();
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

	if (!m_kingWhite)m_kingWhite = std::make_shared<KingPieceObject_Class>();
	m_kingWhite->SetColor(kWhiteColor);
	m_kingWhite->SetId(WhiteKing);
	m_kingWhite->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/King/King.gltf");
	m_baseObjList.push_back(m_kingWhite);

	if (!m_kingBlack)m_kingBlack = std::make_shared<KingPieceObject_Class>();
	m_kingBlack->SetColor(kBlackColor);
	m_kingBlack->SetId(BlackKing);
	m_kingBlack->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/King/King.gltf");
	m_baseObjList.push_back(m_kingBlack);

	if (!m_queenWhite)m_queenWhite = std::make_shared<QueenPieceObject_Class>();
	m_queenWhite->SetColor(kWhiteColor);
	m_queenWhite->SetId(WhiteQueen);
	m_queenWhite->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Queen/Queen.gltf");
	m_baseObjList.push_back(m_queenWhite);

	if (!m_queenBlack)m_queenBlack = std::make_shared<QueenPieceObject_Class>();
	m_queenBlack->SetColor(kBlackColor);
	m_queenBlack->SetId(BlackQueen);
	m_queenBlack->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Queen/Queen.gltf");
	m_baseObjList.push_back(m_queenBlack);

	if (!m_sky)m_sky = std::make_shared<SkyBox_Class>();
	m_baseObjList.push_back(m_sky);

	if (!m_nowSelectBord)m_nowSelectBord = std::make_shared<SelectingBord_Class>();
	m_nowSelectBord->SetColor(kRedColor);
	m_nowSelectBord->SetAlive(false);
	m_baseObjList.push_back(m_nowSelectBord);

	if (!m_afterSelectBord)m_afterSelectBord = std::make_shared<SelectingBord_Class>();
	m_afterSelectBord->SetColor(kBlueColor);
	m_afterSelectBord->SetAlive(false);
	m_baseObjList.push_back(m_afterSelectBord);

	if (!m_beforeSelectBord)m_beforeSelectBord = std::make_shared<SelectingBord_Class>();
	m_beforeSelectBord->SetColor({ 0,0,1,0.5f });
	m_beforeSelectBord->SetAlive(false);
	m_baseObjList.push_back(m_beforeSelectBord);

	if (!m_pieceSelectUI)m_pieceSelectUI = std::make_shared<PieceSelectingUI_Class>();
	m_baseObjList.push_back(m_pieceSelectUI);
	//m_pieceSelectUI->SetCamera(m_camera);

	if (!m_selectPieceTypeUI)m_selectPieceTypeUI = std::make_shared<SelectingPieceTypeNameUI>();
	m_baseObjList.push_back(m_selectPieceTypeUI);
	//m_selectPieceUI->SetCamera(m_camera);


	for (int n = 0; n < 8; n++)
	{
		if (!m_pawnWhite[n])m_pawnWhite[n] = std::make_shared<PawnPieceObject_Class>();
		m_pawnWhite[n]->SetColor(kWhiteColor);
		m_pawnWhite[n]->SetId(WhitePawn0 + n);
		m_pawnWhite[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Pawn/Pawn.gltf");
		m_baseObjList.push_back(m_pawnWhite[n]);

		if (!m_pawnBlack[n])m_pawnBlack[n] = std::make_shared<PawnPieceObject_Class>();
		m_pawnBlack[n]->SetColor(kBlackColor);
		m_pawnBlack[n]->SetId(BlackPawn0 + n);
		m_pawnBlack[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Pawn/Pawn.gltf");
		m_baseObjList.push_back(m_pawnBlack[n]);

		std::cout << str << std::endl;
	}

	for (int n = 0; n < 2; n++)
	{

		if (!m_rookWhite[n])m_rookWhite[n] = std::make_shared<RookPieceObject_Class>();
		m_rookWhite[n]->SetColor(kWhiteColor);
		m_rookWhite[n]->SetId(WhiteRook0 + n);
		m_rookWhite[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Rook/Rook.gltf");
		m_baseObjList.push_back(m_rookWhite[n]);


		if (!m_rookBlack[n])m_rookBlack[n] = std::make_shared<RookPieceObject_Class>();
		m_rookBlack[n]->SetColor(kBlackColor);
		m_rookBlack[n]->SetId(BlackRook0 + n);
		m_rookBlack[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Rook/Rook.gltf");
		m_baseObjList.push_back(m_rookBlack[n]);

	}

	for (int n = 0; n < 2; n++)
	{

		if (!m_knightWhite[n])m_knightWhite[n] = std::make_shared<KnightPieceObject_Class>();
		m_knightWhite[n]->SetColor(kWhiteColor);
		m_knightWhite[n]->SetId(WhiteKnight0 + n);
		m_knightWhite[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Knight/Knight.gltf");
		m_baseObjList.push_back(m_knightWhite[n]);

		str2 = std::to_string(n);
		str = "KnightBlack";
		str.append(str2);
		if (!m_knightBlack[n])m_knightBlack[n] = std::make_shared<KnightPieceObject_Class>();
		m_knightBlack[n]->SetColor(kBlackColor);
		m_knightBlack[n]->SetId(BlackKnight0 + n);
		m_knightBlack[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Knight/Knight.gltf");
		m_baseObjList.push_back(m_knightBlack[n]);

	}

	for (int n = 0; n < 2; n++)
	{

		if (!m_bishopWhite[n])m_bishopWhite[n] = std::make_shared<BishopPieceObject_Class>();
		m_bishopWhite[n]->SetColor(kWhiteColor);
		m_bishopWhite[n]->SetId(WhiteBishop0 + n);
		m_bishopWhite[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/White/Bishop/Bishop.gltf");
		m_baseObjList.push_back(m_bishopWhite[n]);

		if (!m_bishopBlack[n])m_bishopBlack[n] = std::make_shared<BishopPieceObject_Class>();
		m_bishopBlack[n]->SetColor(kBlackColor);
		m_bishopBlack[n]->SetId(BlackBishop0 + n);
		m_bishopBlack[n]->SetAsset(BaseObject_Class::Model, "Asset/Model/Piece/Black/Bishop/Bishop.gltf");
		m_baseObjList.push_back(m_bishopBlack[n]);

	}

	for (int h = 0; h < 8; h++)
	{
		for (int w = 0; w < 8; w++)
		{
			Math::Vector3 massPos = { h * 1.0f - 3.5f,0.01f,w * 1.0f - 3.5f };
			if (!m_selectPieceCanMoveBord[h][w])m_selectPieceCanMoveBord[h][w] = std::make_shared<SelectingBord_Class>();
			m_selectPieceCanMoveBord[h][w]->SetPos(massPos);
			m_selectPieceCanMoveBord[h][w]->SetAlive(false);
			m_baseObjList.push_back(m_selectPieceCanMoveBord[h][w]);
		}
	}
	std::cout << "GameScene SetSharedPtr checkOut" << std::endl;
}

void GameScene_Class::Update()
{
	PieceSet();
	GetCursorPos(&MousePos);
	m_camera->setCamViewMode(m_camera->UpperCamMode);
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
				if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
				{
					m_beforeSelectPos = { 12345,12345,12345 };
					m_afterSelectPos = { 12345,12345,12345 };
					m_Phase = StandByPhase;
					std::cout << "StartPhaseEnd" << std::endl;
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
							std::cout << obj->GetId() << std::endl;
							for (int h = 0; h < 8; h++)
							{
								for (int w = 0; w < 8; w++)
								{
									//クリックしたオブジェクトに現在の盤面状況を渡す
									//obj->SetBordInfo(h, w, m_bordInfo[h][w]);
								}
							}
							for (int h = 0; h < 8; h++)
							{
								for (int w = 0; w < 8; w++)
								{
									//オブジェクトから動ける範囲が配列で返却される
									m_canMoveBordInfo[h][w] = obj->CanMoveBordInfo(h, w);

								}

							}
							for (int w = 0; w < 8; w++)
							{
								for (int h = 0; h < 8; h++)
								{
									printf("%d_", m_canMoveBordInfo[w][h]);

								}
								printf("\n");
							}
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
						//渡された情報から動ける範囲を可視化
						Math::Vector3 massPos = { h * 1 - 3.5f,0,w * 1 - 3.5f };
						if (m_canMoveBordInfo[h][w] == BaseObject_Class::CanMove)
						{
							m_selectPieceCanMoveBord[h][w]->SetAlive(true);
							m_selectPieceCanMoveBord[h][w]->SetPos2(massPos);
							m_waitTime = waitTime;
							m_Phase = SetPhase;
						}
					}
				}

				if (GetAsyncKeyState(VK_RBUTTON))
				{
					m_selectObject = false;
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

									m_bordInfo[h][w] = obj->GetId();
									std::cout << obj->GetId() << std::endl;
									std::cout << m_bordInfo[h][w] << std::endl;
									std::cout << "テスト" << std::endl;
									
								}
								if (0.5 > (Math::Vector3::Distance(m_beforeSelectPos, { h * 1 - 3.5f,0,w * 1 - 3.5f })))
								{
									m_bordInfo[h][w] = None;
								}
							}
							m_Phase = EndPhase;

						}
					}
					std::cout << "移動情報" << std::endl;
					for (int w = 0; w < 8; w++)
					{
						for (int h = 0; h < 8; h++)
						{
							printf("%d_", m_canMoveBordInfo[w][h]);

						}
						printf("\n");
					}
					std::cout << "ボード情報" << std::endl;
					for (int w = 0; w < 8; w++)
					{
						for (int h = 0; h < 8; h++)
						{
							printf("%d_", m_bordInfo[w][h]);

						}
						printf("\n");
					}



				}
				break;
			}
			case GameScene_Class::EndPhase:
			{
				for (int h = 0; h < 8; h++)
				{
					for (int w = 0; w < 8; w++)
					{
					}
				}
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

	if (m_waitTime >= 0)
	{
		m_waitTime--;
	}

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
	DestoryCons();
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
			case GameScene_Class::None:
				break;
			case GameScene_Class::WhitePawn0:
				m_pawnWhite[0]->SetPos2(massPos);
				break;
			case GameScene_Class::WhitePawn1:
				m_pawnWhite[1]->SetPos2(massPos);
				break;
			case GameScene_Class::WhitePawn2:
				m_pawnWhite[2]->SetPos2(massPos);
				break;
			case GameScene_Class::WhitePawn3:
				m_pawnWhite[3]->SetPos2(massPos);
				break;
			case GameScene_Class::WhitePawn4:
				m_pawnWhite[4]->SetPos2(massPos);
				break;
			case GameScene_Class::WhitePawn5:
				m_pawnWhite[5]->SetPos2(massPos);
				break;
			case GameScene_Class::WhitePawn6:
				m_pawnWhite[6]->SetPos2(massPos);
				break;
			case GameScene_Class::WhitePawn7:
				m_pawnWhite[7]->SetPos2(massPos);
				break;
			case GameScene_Class::WhiteKnight0:
				m_knightWhite[0]->SetPos2(massPos);
				break;
			case GameScene_Class::WhiteKnight1:
				m_knightWhite[1]->SetPos2(massPos);
				break;
			case GameScene_Class::WhiteRook0:
				m_rookWhite[0]->SetPos2(massPos);
				break;
			case GameScene_Class::WhiteRook1:
				m_rookWhite[1]->SetPos2(massPos);
				break;
			case GameScene_Class::WhiteBishop0:
				m_bishopWhite[0]->SetPos2(massPos);
				break;
			case GameScene_Class::WhiteBishop1:
				m_bishopWhite[1]->SetPos2(massPos);
				break;
			case GameScene_Class::WhiteQueen:
				m_queenWhite->SetPos2(massPos);
				break;
			case GameScene_Class::WhiteKing:
				m_kingWhite->SetPos2(massPos);
				break;
			case GameScene_Class::BlackPawn0:
				m_pawnBlack[0]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackPawn1:
				m_pawnBlack[1]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackPawn2:
				m_pawnBlack[2]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackPawn3:
				m_pawnBlack[3]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackPawn4:
				m_pawnBlack[4]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackPawn5:
				m_pawnBlack[5]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackPawn6:
				m_pawnBlack[6]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackPawn7:
				m_pawnBlack[7]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackKnight0:
				m_knightBlack[0]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackKnight1:
				m_knightBlack[1]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackRook0:
				m_rookBlack[0]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackRook1:
				m_rookBlack[1]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackBishop0:
				m_bishopBlack[0]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackBishop1:
				m_bishopBlack[1]->SetPos2(massPos);
				break;
			case GameScene_Class::BlackQueen:
				m_queenBlack->SetPos2(massPos);
				break;
			case GameScene_Class::BlackKing:
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
	//チェスは最初有利らしい
	float m_FirstTurnScore;
	switch (m_FirstTurn)
	{
	case Player:
	{
		m_FirstTurnScore = -0.5;
		break;
	}
	case Enemy:
	{
		m_FirstTurnScore = 0.5;
		break;
	}
	default:
		break;
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

void GameScene_Class::CreateCons()
{
	AllocConsole();
	freopen_s(&fp, "CONOUT$", "w", stdout);
}

void GameScene_Class::DestoryCons()
{
	FreeConsole();
}

