#include "SceneManager.h"
#include "Application/Scene/BaseScene/BaseScene.h"
#include"Application/Scene/GameScene/GameScene.h"
void SceneManager::Init()
{
	m_gameScene = std::make_shared<GameScene_Class>();
	SetScene(m_gameScene);
	m_nowScene->Init();
}

void SceneManager::Update()
{
	m_nowScene->Update();
}

void SceneManager::Draw()
{
	m_nowScene->Draw();
}

void SceneManager::DrawLit()
{
	m_nowScene->DrawLit();
}

void SceneManager::GenerateDepthMapFromLight()
{
	m_nowScene->GenerateDepthMapFromLight();
}

void SceneManager::DrawBright()
{
	m_nowScene->DrawBright();
}


void SceneManager::DrawUnLit()
{
	m_nowScene->DrawUnLit();
}

void SceneManager::DrawSprite()
{
	m_nowScene->DrawSprite();
}

void SceneManager::PreDraw()
{
	m_nowScene->PreDraw();
}

void SceneManager::PostDraw()
{
	m_nowScene->PostDraw();
}

void SceneManager::PreUpdate()
{
	m_nowScene->PreUpdate();
}

void SceneManager::PostUpdate()
{
	m_nowScene->PostUpdate();
}

void SceneManager::SetSharedPtr()
{
	
}
