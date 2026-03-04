#include "Player.h"	
#include "Screen.h"
#include "Time.h"
#include "Keyboard.h"

Player::Player() :
	m_sprite(0),
	m_sprite2(0)
{
	position = Screen::Center;
	position2 = Screen::Center - Vector2(50, 0);
}

void Player::Load()
{
	m_sprite = LoadGraph("Resource/heart.png");
	m_sprite2 = LoadGraph("Resource/heart_loss.png");
}

void Player::Release()
{
	DeleteGraph(m_sprite);
	DeleteGraph(m_sprite2);
}

void Player::Update()
{
	Vector2 input;
	if (Keyboard::IsDown(KEY_INPUT_W))
	{
		velocity.y -= 5;
	}
	if (Keyboard::IsDown(KEY_INPUT_S))
	{
		Vector2 pos = position;
		position = position2;
		position2 = pos;
		//Vector2 vel = velocity;
		//velocity = velocity2;
		//velocity2 = vel;
	}

	if (Keyboard::IsPress(KEY_INPUT_A))
	{
		input.x -= 5;
	}
	if (Keyboard::IsPress(KEY_INPUT_D))
	{
		input.x += 5;
	}
	velocity.x = input.x;
	velocity.y += (Gravity * Time::GetInstance()->GetDeltaTime());
	position += velocity;

	if (position.y > 300.0f)
	{
		velocity.y = 0;
		position.y = 300;
	}


	Vector2 input2;
	if (Keyboard::IsDown(KEY_INPUT_UP))
	{

	}
	if (Keyboard::IsDown(KEY_INPUT_DOWN))
	{
		Vector2 pos = position;
		position = position2;
		position2 = pos;
	}

	if (Keyboard::IsPress(KEY_INPUT_LEFT))
	{
		input2.x -= 5;
	}
	if (Keyboard::IsPress(KEY_INPUT_RIGHT))
	{
		input2.x += 5;
	}
	velocity2.x = input2.x;
	velocity2.y += (Gravity * Time::GetInstance()->GetDeltaTime());
	position2 += velocity2;

	if (position2.y > 300.0f)
	{
		velocity2.y = 0;
		position2.y = 300;
	}
}

void Player::Draw()
{
	//DrawGraph(static_cast<int>(position.x), static_cast<int>(position.y),m_sprite, true);
	DrawRotaGraph(static_cast<int>(position.x), static_cast<int>(position.y), 1.0f, 0.0f, m_sprite, true);
	DrawRotaGraph(static_cast<int>(position2.x), static_cast<int>(position2.y), 1.0f, 0.0f, m_sprite2, true);
}
