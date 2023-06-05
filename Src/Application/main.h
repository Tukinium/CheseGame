#pragma once
class BaseObject_Class;
class GameScene_Class;
#include"Application/Object/BordObject/BordObject.h"
//============================================================
// アプリケーションクラス
//	APP.～ でどこからでもアクセス可能
//============================================================
class Application
{
// メンバ
public:

	// アプリケーション実行
	void Execute();

	// アプリケーション終了
	void End() { m_endFlag = true; }

	HWND GetWindowHandle() const { return m_window.GetWndHandle(); }
	int GetMouseWheelValue() const { return m_window.GetMouseWheelVal(); }

	int GetNowFPS() const { return m_fpsController.m_nowfps; }
	int GetMaxFPS() const { return m_fpsController.m_maxFps; }

private:

	void PreUpdate();
	void Update();
	void PostUpdate();

	void PreDraw();
	void Draw();
	void PostDraw();

	void DrawSprite();

	// アプリケーション初期化
	bool Init(int w, int h);

	// アプリケーション解放
	void Release();

	// ゲームウィンドウクラス
	KdWindow		m_window;

	// FPSコントローラー
	KdFPSController	m_fpsController;

	// ゲーム終了フラグ trueで終了する
	bool		m_endFlag = false;

//=====================================================
// シングルトンパターン
//=====================================================
private:
	// 
	Application() {}

public:
	static Application &Instance(){
		static Application Instance;
		return Instance;
	}

//=====================================================
// ユーザー追加
//=====================================================
private:
	FILE* fp;
	std::shared_ptr<GameScene_Class>m_gameScene;
	int m_nowScene = 1;
public:
	//コンソール
	void CreateCons();
	void DestoryCons();
	//スマートポインタのセット(本来Initに書くべきだが可読性を上げるために関数化)
	void SetSharedPtr();
	enum CamViewType
	{
		Default = 0,
		GameMode,
	};
};