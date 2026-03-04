#include "SceneManager.h"
#include "SceneBase.h"
#include "DxLib.h"

void SceneManager::Setup(SceneBase* initScene)
{
	// 非同期読み込み開始
	SetUseASyncLoadFlag(true);
	m_nextScene = initScene;
	m_phase = Phase::Setup;
}

void SceneManager::Dispose()
{
	// 実行中シーンの破棄
	for (auto scene : m_sceneList)
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}
	m_sceneList.clear();

	// 遷移先シーンの破棄
	if (m_nextScene)
	{
		m_nextScene->Finalize();
		delete m_nextScene;
		m_nextScene = nullptr;
	}

}

void SceneManager::LoadScene(SceneBase* scene)
{
	// シーン切り替え中ならキャンセル
	if (m_nextScene)
	{
		delete scene;
		scene = nullptr;
		return;
	}

	m_nextScene = scene;
	m_phase = Phase::Setup;


}

void SceneManager::Update()
{
	switch (m_phase)
	{
	case Phase::Run:
		m_sceneList.back()->Update();
		break;

	case Phase::Setup:
		// 実行中シーンの更新
		if (!m_sceneList.empty()) m_sceneList.back()->Update();


		// 遷移先シーンの初期化
		m_nextScene->Initialize();

		// 実行中シーンがあれば破棄
		for (auto scene : m_sceneList)
		{
			scene->Finalize();
			delete scene;
			scene = nullptr;
		}
		m_sceneList.clear();


		m_phase = Phase::Transition;
		break;

	// 遷移
	case Phase::Transition:
		// 遷移
		PushScene(m_nextScene);
		m_nextScene = nullptr;


		m_phase = Phase::Run;
		break;
	}
}

void SceneManager::Draw()
{
	for (auto scene : m_sceneList)
	{
		scene->Draw();
	}

}
