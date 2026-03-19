#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneManager.h"
#include "Screen.h"
#include "Keyboard.h"
#include "Time.h"
#include "DxLib.h"

SceneTitle::SceneTitle() :
	m_rootNode(nullptr),
	m_background(0),
	m_title(0),
	m_waitTransitionTime(WaitTransitionTime),
	m_pressAnyButton(0),
	m_elapsedTime(0),
	m_drawFlag(true)
{

}

void SceneTitle::Initialize()
{
	m_background = LoadGraph("Resource/background.png");
	m_title = LoadGraph("Resource/title.png");
	m_pressAnyButton = LoadGraph("Resource/press_any_button.png");
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
	if (m_pressAnyButton)
	{
		DeleteGraph(m_pressAnyButton);
	}
}

void SceneTitle::Update()
{
	m_elapsedTime += Time::GetInstance()->GetDeltaTime();
	if (m_elapsedTime > BlinkDuration)
	{
		m_drawFlag = !m_drawFlag;
		m_elapsedTime -= BlinkDuration;
	}

	if (0 < m_waitTransitionTime)
	{
		m_waitTransitionTime -= Time::GetInstance()->GetDeltaTime();
	}

	if (Keyboard::isAnyPress() && m_waitTransitionTime <= 0)
	{
		SceneManager::GetInstance()->LoadScene(new SceneGame());
	}
}

void SceneTitle::Draw()
{
	DrawRotaGraph(static_cast<int>(Screen::Center.x), static_cast<int>(Screen::Center.y), 1.0f, 0.0f, m_background, true);
	DrawRotaGraph(static_cast<int>(Screen::Center.x), static_cast<int>(Screen::Center.y - 50), 1.0f, 0.0f, m_title, true);

	if (m_drawFlag)
	{
		DrawRotaGraph(static_cast<int>(Screen::Center.x), static_cast<int>(Screen::Center.y + 100), 1.0f, 0.0f, m_pressAnyButton, true);
	}

}
