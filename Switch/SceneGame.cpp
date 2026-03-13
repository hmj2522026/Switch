#include "SceneGame.h"
#include "SceneManager.h"
#include "Screen.h"
#include "DxLib.h"
#include "PlayerJump.h"
#include "PlayerPunch.h"
#include "Switch.h"
#include "Keyboard.h"
#include "Ground.h"
#include "HitBox.h"
#include "Node.h"
#include "Stage.h"

SceneGame::SceneGame() :
	m_background(0),
	m_rootNode(nullptr),
	m_playerJump(nullptr),
	m_playerPunch(nullptr),
	m_switch(nullptr),
	m_ground(nullptr)
{
}

void SceneGame::Initialize()
{
	m_background = LoadGraph("Resource/background.png");
	m_rootNode = new Node();

	m_ground = new Ground();
	//m_ground->Load();
	m_rootNode->AddChild(m_ground);

	m_rootNode->AddChild(new HitBox(Vector2(30, Screen::Height), Screen::CenterLeft + Vector2(-15, 0)));
	m_rootNode->AddChild(new HitBox(Vector2(30, Screen::Height), Screen::CenterRight + Vector2(15, 0)));
	
	m_rootNode->AddChild(new Stage());

	m_playerJump = new PlayerJump();
	//m_playerJump->Load();
	m_rootNode->AddChild(m_playerJump);
	
	m_playerPunch = new PlayerPunch();
	//m_playerPunch->Load();
	m_rootNode->AddChild(m_playerPunch);
	
	m_switch = new Switch(m_playerJump, m_playerPunch);
	
}

void SceneGame::Finalize()
{
	if (m_rootNode)
	{
		m_rootNode->TreeRelease();
		delete m_rootNode;
		m_rootNode = nullptr;
	}

	if (m_background)
	{
		DeleteGraph(m_background);
	}
	//if (m_playerJump)
	//{
	//	m_playerJump->Release();
	//	delete m_playerJump;
	//	m_playerJump = nullptr;
	//}
	//if (m_playerPunch)
	//{
	//	m_playerPunch->Release();
	//	delete m_playerPunch;
	//	m_playerPunch = nullptr;
	//}
	//m_ground->Release();
}

void SceneGame::Update()
{
	m_rootNode->TreeUpdate();
	if (Keyboard::IsDown(KEY_INPUT_S))
	{
		m_switch->SwitchPlayerPos();
	}
	if (Keyboard::IsDown(KEY_INPUT_DOWN))
	{
		m_switch->SwitchPlayerPos();
	}
#ifdef _DEBUG
	if (Keyboard::IsDown(KEY_INPUT_R))
	{
		SceneManager::GetInstance()->LoadScene(new SceneGame());
	}
#endif // _DEBUG

	//m_playerJump->Update();
	//m_playerPunch->Update();
}

void SceneGame::Draw()
{
	DrawRotaGraph(static_cast<int>(Screen::Center.x), static_cast<int>(Screen::Center.y), 1.0f, 0.0f, m_background, true);
	m_rootNode->TreeDraw();

	//m_playerJump->Draw();
	//m_playerPunch->Draw();

}
