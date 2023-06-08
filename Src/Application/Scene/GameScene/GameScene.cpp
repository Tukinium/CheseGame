#include"GameScene.h"
#include"Application/Object/BordObject/BordObject.h"
#include"Application/Object/CameraObject/Camera.h"
#include"Application/Object/PieceObject/KingPiece/KingPieceObject.h"
#include"Application/Object/PieceObject/QueenPiece/QueenPieceObject.h"
#include"Application/Object/SkyBox/SkyBox.h"
#include"Application/Object/SelectingBord/SelectingBord.h"
#include"Application/UI/PieceSelectingUI/PieceSelectingUI.h"
#include"Application/Object/PieceObject/PawnPiece/PawnPieceObject.h"

void GameScene_Class::SetSharedPtr()
{
	if (!m_camera)m_camera = std::make_shared<Camera_Class>();
	m_camera->Init();

	if (!m_bord)m_bord = std::make_shared<BordObject_Class>();
	m_baseObjList.push_back(m_bord);

	if (!m_kingWhite)m_kingWhite = std::make_shared<KingPieceObject_Class>();
	m_kingWhite->SetColor(White);
	m_baseObjList.push_back(m_kingWhite);

	if (!m_kingBlack)m_kingBlack = std::make_shared<KingPieceObject_Class>();
	m_kingBlack->SetColor(Black);
	m_baseObjList.push_back(m_kingBlack);

	if (!m_queenBlack)m_queenBlack = std::make_shared<QueenPieceObject_Class>();
	m_queenBlack->SetColor(Black);
	m_baseObjList.push_back(m_queenBlack);

	if (!m_queenWhite)m_queenWhite = std::make_shared<QueenPieceObject_Class>();
	m_queenWhite->SetColor(White);
	m_baseObjList.push_back(m_queenWhite);

	if (!m_sky)m_sky = std::make_shared<SkyBox_Class>();
	m_baseObjList.push_back(m_sky);

	if (!m_selectBord)m_selectBord = std::make_shared<SelectingBord_Class>();
	m_baseObjList.push_back(m_selectBord);

	if (!m_pieceSelectUI)m_pieceSelectUI = std::make_shared<PieceSelectingUI_Class>();
	m_baseObjList.push_back(m_pieceSelectUI);

	for (int n = 0; n < 8; n++)
	{
		if (!m_pawnBkack[n])m_pawnBkack[n] = std::make_shared<PawnPieceObject_Class>();
		m_pawnBkack[n]->SetColor(Black);
		m_pawnBkack[n]->SetDefaultPos(n);
		m_baseObjList.push_back(m_pawnBkack[n]);

		if (!m_pawnWhite[n])m_pawnWhite[n] = std::make_shared<PawnPieceObject_Class>();
		m_pawnWhite[n]->SetColor(White);
		m_pawnWhite[n]->SetDefaultPos(n);
		m_baseObjList.push_back(m_pawnWhite[n]);
	}

	printf("GameScene SetSharedPtr checkOut\n");
}

void GameScene_Class::Update()
{
	BaseScene_Class::Update();

	if (GetAsyncKeyState('1'))m_camera->setCamViewMode(m_camera->CheseMode);
	if (GetAsyncKeyState('2'))m_camera->setCamViewMode(m_camera->Default);
	if (GetAsyncKeyState('3'))m_camera->setCamViewMode(m_camera->UpperCamMode);

	GetCursorPos(&MousePos);

	switch (m_Phase)
	{
	case GameScene_Class::StartPhase:
	{

		break;
	}
	case GameScene_Class::SelectPhase:
	{

		break;
	}
	case GameScene_Class::SetPhase:
	{

		break;
	}
	case GameScene_Class::EndPhase:
	{

		break;
	}
	default:
		break;
	}
	MousePos.y += 0.05;
	if (m_camera)
	{
		static float range = 10000;

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
							Math::Vector3 massPos = { h * 1.0f - 3.5f,0.2f,w * 1.0f - 3.5f };
							//-3.5開始地点
							if ((Math::Vector3::Distance(massPos, resulted.m_hitPos) <= 0.75f))
							{
								m_selectBord->SetSelecting(true);
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
										else if (gameObject == m_bord)
										{
											if (m_selectObject && sec <= 0)
											{
												m_selectObject = false;
											}
										}
									}
									if (m_selectBord)
									{
										sec -= 1;
									}
								}
							}
						}
					}
				}
			}
			else
			{
				m_selectBord->SetSelecting(false);
			}
		}
	}
	if (m_selectObject)
	{
		m_pieceSelectUI->SetAlive(true);
	}
	else
	{
		m_pieceSelectUI->SetAlive(false);
	}

}

void GameScene_Class::PreUpdate()
{
	BaseScene_Class::PreUpdate();

	m_camera->PreUpdate();
	KingPieceBlack.piecePos = m_kingBlack->GetPos();
	KingPieceWhite.piecePos = m_kingWhite->GetPos();
}

void GameScene_Class::PreDraw()
{
	BaseScene_Class::PreDraw();

	m_camera->PreDraw();
}

