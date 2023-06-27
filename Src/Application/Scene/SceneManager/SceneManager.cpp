#include "SceneManager.h"
#include "Application/Scene/BaseScene/BaseScene.h"
#include"Application/Scene/GameScene/GameScene.h"
#include"Application/Scene/TitleScene/TitleScene.h"
#include"Application/Scene/MainMenu/MainMenuScene.h"
#include"Application/Scene/ResultScene/ResultScene_Class.h"
#include"Application/main.h"
#include"Application/Audio/BaseAudio_Class.h"
void SceneManager_Class::Init()
{
	//CreateCons();

	if (!m_MainMenuBgm)m_MainMenuBgm = std::make_shared<BaseAudio_Class>();
	m_MainMenuBgm->SetAudio("Asset/Sound/MainMenuBGM.wav");

	if (!m_ResultBgm)m_ResultBgm = std::make_shared<BaseAudio_Class>();
	m_ResultBgm->SetAudio("Asset/Sound/ResultBGM.wav");

	if (!m_TitleBgm)m_TitleBgm = std::make_shared<BaseAudio_Class>();
	m_TitleBgm->SetAudio("Asset/Sound/TitleBGM.wav");

	SceneChange(BaseScene_Class::TitleScene);
	m_nowScene->Init();
}

void SceneManager_Class::Update()
{
	m_nowScene->Update();

	if (m_nowScene->CheangeThisScene() != BaseScene_Class::NoneScene)
	{
		SceneChange(m_nowScene->CheangeThisScene());
	}
	ShowCursor(false);
}

void SceneManager_Class::Draw()
{
	m_nowScene->Draw();


}

void SceneManager_Class::DrawLit()
{
	m_nowScene->DrawLit();
}

void SceneManager_Class::GenerateDepthMapFromLight()
{
	m_nowScene->GenerateDepthMapFromLight();
}

void SceneManager_Class::DrawBright()
{
	m_nowScene->DrawBright();
}


void SceneManager_Class::DrawUnLit()
{
	m_nowScene->DrawUnLit();
}

void SceneManager_Class::DrawSprite()
{
	m_nowScene->DrawSprite();
}

void SceneManager_Class::PreDraw()
{
	m_nowScene->PreDraw();

}

void SceneManager_Class::PostDraw()
{
	m_nowScene->PostDraw();
}

void SceneManager_Class::PreUpdate()
{
	m_nowScene->PreUpdate();
}

void SceneManager_Class::PostUpdate()
{
	m_nowScene->PostUpdate();
}

void SceneManager_Class::Release()
{
	//DestoryCons();
	m_nowScene->Release();
}

void SceneManager_Class::SceneChange(int _scene)
{
	switch (_scene)
	{
	case BaseScene_Class::GameScene:
	{
		m_MainMenuBgm->StopAudio();
		std::cout << "GameScene Shift" << std::endl;
		m_nowScene.reset();
		m_nowScene = std::make_unique<GameScene_Class>();
		m_nowScene->Init();
		m_Scene = BaseScene_Class::GameScene;
		m_waitTime = WAIT_TIME;
		break;
	}
	case BaseScene_Class::TitleScene:
	{
		m_TitleBgm->PlayAudio();
		std::cout << "TitleScene Shift" << std::endl;
		m_nowScene.reset();
		m_nowScene = std::make_unique<TitleScene_Class>();
		m_nowScene->Init();
		m_Scene = BaseScene_Class::TitleScene;
		m_waitTime = WAIT_TIME;
		break;
	}
	case BaseScene_Class::MainMenuScene:
	{
		m_ResultBgm->StopAudio();
		m_TitleBgm->StopAudio();
		m_MainMenuBgm->PlayAudio();
		m_nowScene.reset();
		m_nowScene = std::make_unique<MainMenuScene_Class>();
		m_nowScene->Init();
		m_Scene = BaseScene_Class::MainMenuScene;
		m_waitTime = WAIT_TIME;
		break;
	}
	case BaseScene_Class::ResultScene:
	{
		m_ResultBgm->PlayAudio();
	    m_winner = m_nowScene->SetWinner();
		m_nowScene.reset();
		m_nowScene = std::make_unique<ResultScene_Class>();
		m_nowScene->Init();
		m_nowScene->SetWinner(m_winner);
		m_Scene = BaseScene_Class::ResultScene;
		m_waitTime = WAIT_TIME;
		break;
	}
	case BaseScene_Class::ExitScene:
	{
		m_exitFlg = true;
		break;
	}
	default:
		break;
	}

}

void SceneManager_Class::GetSceneChange(int _sceneNum)
{
	SceneChange(_sceneNum);
}

void SceneManager_Class::CreateCons()
{
	AllocConsole();
	freopen_s(&fp, "CONOUT$", "w", stdout);
}

void SceneManager_Class::DestoryCons()
{
	FreeConsole();
}

