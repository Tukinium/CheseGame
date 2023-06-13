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
	SetToDefault();
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
	m_kingWhite->SetId("KingWhite");
	m_baseObjList.push_back(m_kingWhite);

	if (!m_kingBlack)m_kingBlack = std::make_shared<KingPieceObject_Class>();
	m_kingBlack->SetColor(kBlackColor);
	m_kingBlack->SetId("KingBlack");
	m_baseObjList.push_back(m_kingBlack);

	if (!m_queenWhite)m_queenWhite = std::make_shared<QueenPieceObject_Class>();
	m_queenWhite->SetColor(kWhiteColor);
	m_queenWhite->SetId("QueenWhite");
	m_baseObjList.push_back(m_queenWhite);

	if (!m_queenBlack)m_queenBlack = std::make_shared<QueenPieceObject_Class>();
	m_queenBlack->SetColor(kBlackColor);
	m_queenBlack->SetId("QueenBlack");
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
		str2 = std::to_string(n);
		str = "PawnWhite";
		str.append(str2);
		if (!m_pawnWhite[n])m_pawnWhite[n] = std::make_shared<PawnPieceObject_Class>();
		m_pawnWhite[n]->SetColor(kWhiteColor);
		m_pawnWhite[n]->SetId(str);
		m_baseObjList.push_back(m_pawnWhite[n]);

		str = "PawnBlack";
		str.append(str2);
		if (!m_pawnBlack[n])m_pawnBlack[n] = std::make_shared<PawnPieceObject_Class>();
		m_pawnBlack[n]->SetColor(kBlackColor);
		m_pawnBlack[n]->SetId(str);
		m_baseObjList.push_back(m_pawnBlack[n]);
	}

	for (int n = 0; n < 2; n++)
	{
		str2 = std::to_string(n);
		str = "RookWhite";
		str.append(str2);
		if (!m_rookWhite[n])m_rookWhite[n] = std::make_shared<RookPieceObject_Class>();
		m_rookWhite[n]->SetColor(kWhiteColor);
		m_rookWhite[n]->SetId(str);
		m_baseObjList.push_back(m_rookWhite[n]);

		str2 = std::to_string(n);
		str = "RookBlack";
		str.append(str2);
		if (!m_rookBlack[n])m_rookBlack[n] = std::make_shared<RookPieceObject_Class>();
		m_rookBlack[n]->SetColor(kBlackColor);
		m_rookBlack[n]->SetId(str);
		m_baseObjList.push_back(m_rookBlack[n]);

	}

	for (int n = 0; n < 2; n++)
	{
		str2 = std::to_string(n);
		str = "KnightWhite";
		str.append(str2);
		if (!m_knightWhite[n])m_knightWhite[n] = std::make_shared<KnightPieceObject_Class>();
		m_knightWhite[n]->SetColor(kWhiteColor);
		m_knightWhite[n]->SetId(str);
		m_baseObjList.push_back(m_knightWhite[n]);

		str2 = std::to_string(n);
		str = "KnightBlack";
		str.append(str2);
		if (!m_knightBlack[n])m_knightBlack[n] = std::make_shared<KnightPieceObject_Class>();
		m_knightBlack[n]->SetColor(kBlackColor);
		m_knightBlack[n]->SetId(str);
		m_baseObjList.push_back(m_knightBlack[n]);

	}

	for (int n = 0; n < 2; n++)
	{
		str2 = std::to_string(n);
		str = "BishoptWhite";
		str.append(str2);
		if (!m_bishopWhite[n])m_bishopWhite[n] = std::make_shared<BishopPieceObject_Class>();
		m_bishopWhite[n]->SetColor(kWhiteColor);
		m_bishopWhite[n]->SetId(str);
		m_baseObjList.push_back(m_bishopWhite[n]);

		str2 = std::to_string(n);
		str = "BishopBlack";
		str.append(str2);
		if (!m_bishopBlack[n])m_bishopBlack[n] = std::make_shared<BishopPieceObject_Class>();
		m_bishopBlack[n]->SetColor(kBlackColor);
		m_bishopBlack[n]->SetId(str);
		m_baseObjList.push_back(m_bishopBlack[n]);

	}

	for (int h = 0; h < 16; h++)
	{
		for (int w = 0; w < 16; w++)
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
	GetCursorPos(&MousePos);
	m_camera->setCamViewMode(m_camera->UpperCamMode);
	PieceCanMoveMassView();
	SelectPieceUIActive();
	m_nowSelectBord->SetAlive(true);
	m_nowSelectBord->SetPos(BordOnMouse());
	BordOnMouse();

	for (std::shared_ptr<BaseObject_Class>obj : m_baseObjList)
	{

		switch (m_Phase)
		{
		case GameScene_Class::StartPhase:
		{
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
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
				if (obj->thisPiece())
				{
					if (0.5f > (Math::Vector3::Distance(obj->GetPos2(), BordOnMouse())))
					{
						m_beforeSelectPos = BordOnMouse();
						m_selectObject = true;
						m_Phase = SelectPhase;
						std::cout << "StandByPhaseEnd" << std::endl;
						m_waitTime = waitTime;
					}
				}
				if (!(obj->thisPiece()) && m_selectObject)
				{
					m_selectObject = false;
				}
			}
			break;
		}
		case GameScene_Class::SelectPhase:
		{
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
				for (int h = 0; h < 16; h++)
				{
					for (int w = 0; w < 16; w++)
					{
						if (0.5f > (Math::Vector3::Distance(m_selectPieceCanMoveBord[h][w]->GetPos(), BordOnMouse())))
						{
							if (m_selectPieceCanMoveBord[h][w]->GetAlive())
							{
								m_selectObject = true;
								m_afterSelectPos = BordOnMouse();
								m_Phase = SetPhase;
								m_waitTime = waitTime;
							}
						}
					}
				}
			}
			break;
		}
		case GameScene_Class::SetPhase:
		{
			if (obj->thisPiece())
			{
				if (0.5f > Math::Vector3::Distance(m_beforeSelectPos, obj->GetPos2()))
				{
					obj->SetPos2(m_afterSelectPos);
					m_selectObject = false;
					m_Phase = EndPhase;
					m_waitTime = waitTime;
				}
			}
			break;
		}
		case GameScene_Class::EndPhase:
		{
			if (GetAsyncKeyState(VK_LBUTTON) && m_waitTime <= 0)
			{
				m_Phase = StandByPhase;
				m_waitTime = waitTime;
			}


			break;
		}
		default:
			break;
		}

	}

	if (m_waitTime >= 0)
	{
		m_waitTime--;
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
	DestoryCons();
}

void GameScene_Class::SetToDefault()
{
	m_kingBlack->SetDefaultPos(0);
	m_kingWhite->SetDefaultPos(0);
	m_queenBlack->SetDefaultPos(0);
	m_queenWhite->SetDefaultPos(0);
	for (int n = 0; n < 8; n++)
	{
		m_pawnWhite[n]->SetDefaultPos(n);
		m_pawnBlack[n]->SetDefaultPos(n);
	}
	for (int n = 0; n < 2; n++)
	{
		m_bishopWhite[n]->SetDefaultPos(n);
		m_bishopBlack[n]->SetDefaultPos(n);
		m_knightBlack[n]->SetDefaultPos(n);
		m_knightWhite[n]->SetDefaultPos(n);
		m_rookBlack[n]->SetDefaultPos(n);
		m_rookWhite[n]->SetDefaultPos(n);
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

void GameScene_Class::PieceCanMoveMassView()
{
	std::string pieceType;
	if (m_selectObject)
	{

		for (std::shared_ptr<BaseObject_Class> obj : m_baseObjList)
		{
			if (obj->thisPiece())
			{
				if (0.05f > Math::Vector3::Distance(obj->GetPos(), m_beforeSelectPos))
				{
					pieceType = obj->GetId().substr(0, 4);
					if (pieceType == "King")
					{
						for (int h = 0; h < 3; h++)
						{
							for (int w = 0; w < 3; w++)
							{
								Math::Vector3 SetPos = { m_beforeSelectPos.x - 1 + h,m_beforeSelectPos.y,m_beforeSelectPos.z - 1 + w, };
								m_selectPieceCanMoveBord[h][w]->SetPos(SetPos);
								m_selectPieceCanMoveBord[h][w]->SetAlive(true);
							}
						}
					}
					if (pieceType == "Quee")
					{
						for (int w = 0; w < 16; w++)
						{
							Math::Vector3 SetPos = { m_beforeSelectPos.x - 8 + w,m_beforeSelectPos.y,m_beforeSelectPos.z - 8 + w, };
							m_selectPieceCanMoveBord[w][0]->SetPos(SetPos);
							m_selectPieceCanMoveBord[w][0]->SetAlive(true);
						}
						for (int h = 0; h < 16; h++)
						{
							Math::Vector3 SetPos = { m_beforeSelectPos.x - 8 + h,m_beforeSelectPos.y,m_beforeSelectPos.z + 8 - h, };
							m_selectPieceCanMoveBord[h][1]->SetPos(SetPos);
							m_selectPieceCanMoveBord[h][1]->SetAlive(true);
						}
						for (int n = 0; n < 16; n++)
						{
							Math::Vector3 SetPos = { m_beforeSelectPos.x - 8 + n,m_beforeSelectPos.y,m_beforeSelectPos.z, };
							m_selectPieceCanMoveBord[n][2]->SetPos(SetPos);
							m_selectPieceCanMoveBord[n][2]->SetAlive(true);
						}
						for (int n = 0; n < 16; n++)
						{
							Math::Vector3 SetPos = { m_beforeSelectPos.x,m_beforeSelectPos.y,m_beforeSelectPos.z - 8 + n, };
							m_selectPieceCanMoveBord[n][3]->SetPos(SetPos);
							m_selectPieceCanMoveBord[n][3]->SetAlive(true);
						}
						for (int h = 0; h < 3; h++)
						{
							for (int w = 0; w < 3; w++)
							{
								for (int n = 0; n < 10; n++)
								{
									Math::Vector3 SetPos = { m_beforeSelectPos.x - 1 + h,m_beforeSelectPos.y,m_beforeSelectPos.z - 1 + w, };
									m_selectPieceCanMoveBord[n][4]->SetPos(SetPos);
									m_selectPieceCanMoveBord[n][4]->SetAlive(true);
								}
							}
						}
					}
					if (pieceType == "Pawn")
					{
						if (!obj->GetfirstMoved())
						{
							if (obj->GetColor() == kBlackColor)
							{
								for (int n = 1; n <= 2; n++)
								{
									Math::Vector3 SetPos = { m_beforeSelectPos.x,m_beforeSelectPos.y,m_beforeSelectPos.z + n, };
									m_selectPieceCanMoveBord[n][0]->SetPos(SetPos);
									m_selectPieceCanMoveBord[n][0]->SetAlive(true);
								}
							}
							if (obj->GetColor() == kWhiteColor)
							{
								for (int n = 1; n <= 2; n++)
								{
									Math::Vector3 SetPos = { m_beforeSelectPos.x,m_beforeSelectPos.y,m_beforeSelectPos.z - n, };
									m_selectPieceCanMoveBord[n][0]->SetPos(SetPos);
									m_selectPieceCanMoveBord[n][0]->SetAlive(true);
								}
							}
						}
					}
					if (pieceType == "Rook")
					{
						for (int h = 0; h < 16; h++)
						{
							Math::Vector3 SetPos = { m_beforeSelectPos.x - 8 + h,m_beforeSelectPos.y,m_beforeSelectPos.z, };
							m_selectPieceCanMoveBord[h][0]->SetPos(SetPos);
							m_selectPieceCanMoveBord[h][0]->SetAlive(true);
						}
						for (int w = 0; w < 16; w++)
						{
							Math::Vector3 SetPos = { m_beforeSelectPos.x,m_beforeSelectPos.y,m_beforeSelectPos.z - 8 + w, };
							m_selectPieceCanMoveBord[0][w]->SetPos(SetPos);
							m_selectPieceCanMoveBord[0][w]->SetAlive(true);
						}
					}
					if (pieceType == "Bish")
					{
						for (int w = 0; w < 16; w++)
						{
							Math::Vector3 SetPos = { m_beforeSelectPos.x - 8 + w,m_beforeSelectPos.y,m_beforeSelectPos.z - 8 + w, };
							m_selectPieceCanMoveBord[0][w]->SetPos(SetPos);
							m_selectPieceCanMoveBord[0][w]->SetAlive(true);
						}
						for (int h = 0; h < 16; h++)
						{
							Math::Vector3 SetPos = { m_beforeSelectPos.x - 8 + h,m_beforeSelectPos.y,m_beforeSelectPos.z + 8 - h, };
							m_selectPieceCanMoveBord[h][0]->SetPos(SetPos);
							m_selectPieceCanMoveBord[h][0]->SetAlive(true);
						}
					}
					if (pieceType == "Knig")
					{
						m_selectPieceCanMoveBord[0][0]->SetPos({ m_beforeSelectPos.x + 2,m_beforeSelectPos.y,m_beforeSelectPos.z + 1, });
						m_selectPieceCanMoveBord[0][0]->SetAlive(true);

						m_selectPieceCanMoveBord[0][1]->SetPos({ m_beforeSelectPos.x + 1,m_beforeSelectPos.y,m_beforeSelectPos.z + 2, });
						m_selectPieceCanMoveBord[0][1]->SetAlive(true);

						m_selectPieceCanMoveBord[0][2]->SetPos({ m_beforeSelectPos.x - 1,m_beforeSelectPos.y,m_beforeSelectPos.z - 2, });
						m_selectPieceCanMoveBord[0][2]->SetAlive(true);

						m_selectPieceCanMoveBord[0][3]->SetPos({ m_beforeSelectPos.x - 2,m_beforeSelectPos.y,m_beforeSelectPos.z - 1, });
						m_selectPieceCanMoveBord[0][3]->SetAlive(true);

						m_selectPieceCanMoveBord[1][0]->SetPos({ m_beforeSelectPos.x + 2,m_beforeSelectPos.y,m_beforeSelectPos.z - 1, });
						m_selectPieceCanMoveBord[1][0]->SetAlive(true);

						m_selectPieceCanMoveBord[1][1]->SetPos({ m_beforeSelectPos.x + 1,m_beforeSelectPos.y,m_beforeSelectPos.z - 2, });
						m_selectPieceCanMoveBord[1][1]->SetAlive(true);

						m_selectPieceCanMoveBord[1][2]->SetPos({ m_beforeSelectPos.x + 1,m_beforeSelectPos.y,m_beforeSelectPos.z - 2, });
						m_selectPieceCanMoveBord[1][2]->SetAlive(true);

						m_selectPieceCanMoveBord[1][3]->SetPos({ m_beforeSelectPos.x + 2,m_beforeSelectPos.y,m_beforeSelectPos.z - 1, });
						m_selectPieceCanMoveBord[1][3]->SetAlive(true);
					}
				}
			}
		}
	}
}

void GameScene_Class::SelectPieceUIActive()
{
	if (m_selectObject)
	{
		m_beforeSelectBord->SetPos(m_beforeSelectPos);
		m_beforeSelectBord->SetAlive(true);
		m_pieceSelectUI->SetAlive(true);
	}
	else
	{
		for (int h = 0; h < 16; h++)
		{
			for (int w = 0; w < 16; w++)
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

