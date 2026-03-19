#include "DxLib.h"
#include "GameMain.h"
#include "GameConfig.h"
#include "Screen.h"
#include "SceneManager.h"
#include "SceneGame.h"
#include "SceneTitle.h"
#include "Time.h"
#include "Keyboard.h"
#include "Physics2D.h"

GameMain::~GameMain()
{
	// 自作スクリーンの破棄
	DeleteGraph(m_screen);

	DxLib_End();
}

// メインループ
void GameMain::Run()
{
	// DxLib前処理
	ChangeWindowMode(GameConfig::WindowMode);	// ウィンドウモード
	SetMainWindowText(GameConfig::Title);		// ウィンドウタイトル
	SetGraphMode(Screen::Width, Screen::Height, GameConfig::ColorBit);	// ウィンドウサイズ
	SetAlwaysRunFlag(GameConfig::AlwaysRunFlag);	// 非アクティブ時の動作
	SetWaitVSyncFlag(false);

	if (DxLib_Init() == -1)
	{
		throw - 1;
	}

	// シーン起動
	SceneManager::GetInstance()->Setup(new SceneTitle());

	// スクリーン作成
	m_screen = MakeScreen(Screen::Width, Screen::Height);

	LONGLONG frameStartTime;

	while (true)
	{
		// フレームの開始時刻取得（単位　マイクロ秒）
		frameStartTime = GetNowHiPerformanceCount();

		if (ProcessMessage())
		{
			break;
		}

		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// 時間の更新
		Time::GetInstance()->Update();

		// キー入力状態の更新
		Keyboard::Update();

		// シーンの更新
		SceneManager::GetInstance()->Update();

		Physics2D::GetInstance()->Update();

		// 自作スクリーンに描画
		SetDrawScreen(m_screen);
		ClearDrawScreen();

		// シーンの描画
		SceneManager::GetInstance()->Draw();

#ifdef _DEBUG
		Physics2D::GetInstance()->Draw();
#endif // _DEBUG


		// 自作スクリーンを裏画面に描画
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		DrawGraph(0, 0, m_screen, false);

		// 裏画面と表画面をひっくり返す
		ScreenFlip();

		// フレーム内の経過時間が指定したFPSに到達するまで待つ
		while (GetNowHiPerformanceCount() - frameStartTime < 1000000 / GameConfig::FPS);
	}
	
	// シーンの破棄
	SceneManager::GetInstance()->Dispose();
}
