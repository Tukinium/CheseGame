#include "SceneManager.h"
#include "Application/Scene/BaseScene/BaseScene.h"
#include"Application/Scene/GameScene/GameScene.h"
#include"Application/Scene/TitleScene/TitleScene.h"
void SceneManager_Class::Init()
{
	SetSharedPtr();
	SetScene(m_gameScene);
	//m_titleScene->ActiveTitleSceen(true);
	m_nowScene->Init();
}

void SceneManager_Class::Update()
{
	m_nowScene->Update();
	if (!(m_titleScene->NowSceneActive()))
	{
		//SetScene(m_gameScene);
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

void SceneManager_Class::SetSharedPtr()
{
	if (!m_titleScene)m_titleScene = std::make_shared<TitleScene_Class>();
	if (!m_gameScene)m_gameScene = std::make_shared<GameScene_Class>();
}

void SceneManager_Class::Release()
{
	m_nowScene->Release();
}

void SceneManager_Class::SetScene(const std::shared_ptr<BaseScene_Class> _scene)
{
	m_nowScene = _scene;
	m_nowScene->Init();
}
