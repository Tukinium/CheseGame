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
}

void GameScene_Class::SetSharedPtr()
{
	if (!m_camera)m_camera = std::make_shared<Camera_Class>();
	m_camera->Init();
	m_baseObjList.push_back(m_camera);

	if (!m_bord)m_bord = std::make_shared<BordObject_Class>();
	m_baseObjList.push_back(m_bord);

	if (!m_kingWhite)m_kingWhite = std::make_shared<KingPieceObject_Class>();
	m_kingWhite->SetColor(kWhiteColor);
	m_pieceId[0][0] = m_kingWhite->GetId();
	m_baseObjList.push_back(m_kingWhite);

	if (!m_kingBlack)m_kingBlack = std::make_shared<KingPieceObject_Class>();
	m_kingBlack->SetColor(kBlackColor);
	m_pieceId[0][1] = m_kingBlack->GetId();
	m_baseObjList.push_back(m_kingBlack);

	if (!m_queenWhite)m_queenWhite = std::make_shared<QueenPieceObject_Class>();
	m_queenWhite->SetColor(kWhiteColor);
	m_pieceId[1][0] = m_queenWhite->GetId();
	m_baseObjList.push_back(m_queenWhite);

	if (!m_queenBlack)m_queenBlack = std::make_shared<QueenPieceObject_Class>();
	m_queenBlack->SetColor(kBlackColor);
	m_pieceId[1][1] = m_queenBlack->GetId();
	m_baseObjList.push_back(m_queenBlack);

	if (!m_sky)m_sky = std::make_shared<SkyBox_Class>();
	m_baseObjList.push_back(m_sky);

	if (!m_selectBord)m_selectBord = std::make_shared<SelectingBord_Class>();
	m_selectBord->SetColor(kRedColor);
	m_selectBord->SetAlive(false);
	m_baseObjList.push_back(m_selectBord);

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
		m_pawnWhite[n]->SetDefaultPos(n);
		m_pieceId[8 + n][0] = m_pawnWhite[n]->GetId();
		m_baseObjList.push_back(m_pawnWhite[n]);

		if (!m_pawnBlack[n])m_pawnBlack[n] = std::make_shared<PawnPieceObject_Class>();
		m_pawnBlack[n]->SetColor(kBlackColor);
		m_pawnBlack[n]->SetDefaultPos(n);
		m_pieceId[8 + n][1] = m_pawnBlack[n]->GetId();
		m_baseObjList.push_back(m_pawnBlack[n]);
	}

	for (int n = 0; n < 2; n++)
	{
		if (!m_rookWhite[n])m_rookWhite[n] = std::make_shared<RookPieceObject_Class>();
		m_rookWhite[n]->SetColor(kWhiteColor);
		m_rookWhite[n]->SetDefaultPos(n);
		m_pieceId[6 + n][0] = m_rookWhite[n]->GetId();
		m_baseObjList.push_back(m_rookWhite[n]);

		if (!m_rookBlack[n])m_rookBlack[n] = std::make_shared<RookPieceObject_Class>();
		m_rookBlack[n]->SetColor(kBlackColor);
		m_rookBlack[n]->SetDefaultPos(n);
		m_pieceId[6 + n][1] = m_rookBlack[n]->GetId();
		m_baseObjList.push_back(m_rookBlack[n]);

	}

	for (int n = 0; n < 2; n++)
	{
		if (!m_knightWhite[n])m_knightWhite[n] = std::make_shared<KnightPieceObject_Class>();
		m_knightWhite[n]->SetColor(kWhiteColor);
		m_knightWhite[n]->SetDefaultPos(n);
		m_pieceId[4 + n][0] = m_knightWhite[n]->GetId();
		m_baseObjList.push_back(m_knightWhite[n]);

		if (!m_knightBlack[n])m_knightBlack[n] = std::make_shared<KnightPieceObject_Class>();
		m_knightBlack[n]->SetColor(kBlackColor);
		m_knightBlack[n]->SetDefaultPos(n);
		m_pieceId[4 + n][1] = m_knightBlack[n]->GetId();
		m_baseObjList.push_back(m_knightBlack[n]);

	}

	for (int n = 0; n < 2; n++)
	{

		if (!m_bishopWhite[n])m_bishopWhite[n] = std::make_shared<BishopPieceObject_Class>();
		m_bishopWhite[n]->SetColor(kWhiteColor);
		m_bishopWhite[n]->SetDefaultPos(n);
		m_pieceId[2 + n][0] = m_bishopWhite[n]->GetId();
		m_baseObjList.push_back(m_bishopWhite[n]);

		if (!m_bishopBlack[n])m_bishopBlack[n] = std::make_shared<BishopPieceObject_Class>();
		m_bishopBlack[n]->SetColor(kBlackColor);
		m_bishopBlack[n]->SetDefaultPos(n);
		m_pieceId[2 + n][1] = m_bishopBlack[n]->GetId();
		m_baseObjList.push_back(m_bishopBlack[n]);

	}
	std::cout << "GameScene SetSharedPtr checkOut" << std::endl;

	for (int w = 0; w < 16; w++)
	{
		for (int h = 0; h < 2; h++)
		{
			std::cout << m_pieceId[w][h] << w << h << std::endl;
		}
	}
}

void GameScene_Class::Update()
{
	MousePos.y += 0.05;
	BaseScene_Class::Update();

	if (GetAsyncKeyState('1'))m_camera->setCamViewMode(m_camera->CheseMode);
	if (GetAsyncKeyState('2'))m_camera->setCamViewMode(m_camera->Default);
	if (GetAsyncKeyState('3'))m_camera->setCamViewMode(m_camera->UpperCamMode);
	GetCursorPos(&MousePos);

	switch (m_Phase)
	{
	case GameScene_Class::StartPhase:
	{
		m_camera->setCamViewMode(m_camera->UpperCamMode);
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			m_Phase = CheckPhase;
		}
		break;
	}
	case GameScene_Class::CheckPhase:
	{
		m_camera->setCamViewMode(m_camera->UpperCamMode);
		/*
		if (m_camera)
		{
			static float range = 1000;

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

						for (int h = 0; h < 8; h++)
						{
							for (int w = 0; w < 8; w++)
							{
								Math::Vector3 massPos = { h * 1.0f - 3.5f,0.01f,w * 1.0f - 3.5f };
								//-3.5開始地点
								if ((Math::Vector3::Distance(massPos, resulted.m_hitPos) <= 0.75f))
								{
									m_selectBord->SetAlive(true);
									m_selectBord->SetPos(massPos);
									if (GetAsyncKeyState(VK_LBUTTON))
									{
										//連続入力による誤選択防止用
										static int sec;

										//リスト内検索
										for (std::shared_ptr<BaseObject_Class> gameObject : m_baseObjList)
										{
											//リストの中でピースだけを検索
											if (!(gameObject == m_sky || gameObject == m_camera || gameObject == m_selectBord || gameObject == m_bord))
											{
												//一番近いピースを検索
												if ((Math::Vector3::Distance(gameObject->GetPos(), massPos) <= 0.5f) && !m_selectObject)
												{
													sec = 6;
													selectPos = massPos;
													m_selectObject = true;

												}
											}

											//触れたオブジェクトが板だった場合かつ
											else if (gameObject == m_sky)
											{
												if (m_selectObject && sec <= 0)
												{
													m_selectObject = false;
												}
											}
										}
										if (m_selectBord)
										{
											m_selectBord->SetAlive(false);
										}
									}
								}
							}
						}
					}
				}
				else
				{
					m_selectObject = false;
					m_selectBord->SetAlive(false);
				}
			}
		}
		*/
		Test();
		if (m_selectObject)
		{
			m_pieceSelectUI->SetAlive(true);
			m_selectPieceTypeUI->SetAlive(true);
			for (std::shared_ptr<BaseObject_Class> obj : m_baseObjList)
			{
				if ((0.01 >= Math::Vector3::Distance(selectPos, obj->GetPos()) && obj->thisPiece()))
				{
					if (obj->GetId() == m_pieceId[0][0])
					{

					}
					if (obj->GetId() == m_pieceId[0][1])
					{

					}
					if (obj->GetId() == m_pieceId[1][0])
					{

					}
					if (obj->GetId() == m_pieceId[1][1])
					{

					}
				}
			}
		}
		else
		{
			m_beforeSelectBord->SetAlive(false);
			m_pieceSelectUI->SetAlive(false);
			m_selectPieceTypeUI->SetAlive(false);
		}

		//後々変更
		if (GetAsyncKeyState(VK_RBUTTON))
		{
			m_Phase = SelectPhase;
		}
		break;
	}
	case GameScene_Class::SelectPhase:
	{
		m_camera->setCamViewMode(m_camera->UpperCamMode);
		break;
	}
	case GameScene_Class::SetPhase:
		break;
	case GameScene_Class::EndPhase:
		break;
	default:
		break;
	}
}

void GameScene_Class::PreUpdate()
{
	BaseScene_Class::PreUpdate();

	m_camera->PreUpdate();
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

void GameScene_Class::Test()
{
	if (m_camera)
	{
		static float range = 1000;

		static Math::Vector3 rayDir = Math::Vector3::Zero;

		m_camera->WorkCamera()->GenerateRayInfoFromClientPos(MousePos, m_camera->GetPos(), rayDir, range);

		if (m_bord)
		{
			Math::Vector3 endRayPos = m_camera->GetPos() + (rayDir * range);

			KdCollider::RayInfo rayInfo(KdCollider::TypeGround, m_camera->GetPos(), endRayPos);

			std::list<KdCollider::CollisionResult>result;

			m_bord->Intersects(rayInfo, &result);

			static int sec;
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
								//-3.5開始地点
								if ((Math::Vector3::Distance(massPos, resulted.m_hitPos) <= 0.75f))
								{
									m_selectBord->SetAlive(true);
									m_selectBord->SetPos(massPos);
									if ((Math::Vector3::Distance(gameObject->GetPos(), massPos) <= 0.5f) && !m_selectObject && sec <= 0 && gameObject->thisPiece())
									{
										if (GetAsyncKeyState(VK_LBUTTON))
										{

											//連続入力による誤選択防止用
											sec = 10;
											selectPos = massPos;
											m_selectObject = true;

										}
									}
									if ((Math::Vector3::Distance(gameObject->GetPos(), massPos) <= 0.5f) && m_selectObject && sec <= 0 &&  !(gameObject->thisPiece()))
									{
										m_selectObject = false;
									}

									if (sec >= 0)
									{
										sec--;
									}


									//リスト精査
								}

							}
						}
					}
				}
			}
			else
			{
				m_selectObject = false;
				m_selectBord->SetAlive(false);
			}
		}
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

