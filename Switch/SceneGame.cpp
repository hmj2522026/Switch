#include "SceneGame.h"
#include "Screen.h"
#include "DxLib.h"
#include "Player.h"

SceneGame::SceneGame() :
	m_image(0),
	m_player(nullptr)
{
}

void SceneGame::Initialize()
{
	m_image = LoadGraph("Resource/heart.png");

	m_player = new Player();
	m_player->Load();
}

void SceneGame::Finalize()
{
	if (m_image)
	{
		DeleteGraph(m_image);
	}
	if (m_player)
	{
		m_player->Release();
		delete m_player;
		m_player = nullptr;
	}
}

void SceneGame::Update()
{
	m_player->Update();
}

void SceneGame::Draw()
{
	//DrawGraph(static_cast<int>(Screen::Center.x), static_cast<int>(Screen::Center.y), m_image, true);

	m_player->Draw();
}
