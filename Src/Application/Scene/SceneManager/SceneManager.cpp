#include "SceneManager.h"
#include "Application/Scene/BaseScene/BaseScene.h"
#include"Application/Scene/GameScene/GameScene.h"
#include"Application/Scene/TitleScene/TitleScene.h"
void SceneManager_Class::Init()
{
	m_nowScene = std::make_unique<GameScene_Class>();
	m_nowScene->Init();
}

void SceneManager_Class::Update()
{
	m_nowScene->Update();
	if (GetAsyncKeyState(VK_RETURN))
	{
		if (m_Scene == GameScene)
		{
			std::cout << "TitleScene Shift" << std::endl;
			m_nowScene.reset();
			m_nowScene = std::make_unique<TitleScene_Class>();
			m_nowScene->Init();
			m_Scene = TitleScene;

		}
	}
	if (GetAsyncKeyState(VK_UP))
	{
		if (m_Scene == TitleScene)
		{
			std::cout << "GameScene Shift" << std::endl;
			m_nowScene.reset();
			m_nowScene = std::make_unique<GameScene_Class>();
			m_nowScene->Init();
			m_Scene = GameScene;
		}
	}
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
	m_nowScene->Release();
}