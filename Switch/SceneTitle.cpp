#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneManager.h"
#include "Screen.h"
#include "Keyboard.h"
#include "DxLib.h"

SceneTitle::SceneTitle() :
	m_rootNode(nullptr),
	m_background(0),
	m_title(0)
{

}

void SceneTitle::Initialize()
{
	m_background = LoadGraph("Resource/background.png");
	m_title = LoadGraph("");
}

void SceneTitle::Finalize()
{
	if (m_background)
	{
		DeleteGraph(m_background);
	}
	if (m_title)
	{
		DeleteGraph(m_title);
	}
}

void SceneTitle::Update()
{
	if (Keyboard::isAnyPress())
	{
		SceneManager::GetInstance()->LoadScene(new SceneGame());
	}
}

void SceneTitle::Draw()
{
	DrawRotaGraph(static_cast<int>(Screen::Center.x), static_cast<int>(Screen::Center.y), 1.0f, 0.0f, m_background, true);
	DrawRotaGraph(static_cast<int>(Screen::Center.x), static_cast<int>(Screen::Center.y), 1.0f, 0.0f, m_title, true);
}
