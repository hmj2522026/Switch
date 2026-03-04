#pragma once
#include "Vector2.h"

class Player
{
private:
	static constexpr float Gravity = 9.8f;

	Vector2 position;
	Vector2 velocity;
	int m_sprite;

	Vector2 position2;
	Vector2 velocity2;
	int m_sprite2;

public:
	Player();

	void Load();
	void Release();
	void Update();
	void Draw();
};
