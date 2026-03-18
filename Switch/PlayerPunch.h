#pragma once
#include "Vector2.h"
#include "Actor2D.h"
#include "Screen.h"

class Punch;

class PlayerPunch : public Actor2D
{
private:
	static constexpr Vector2 StartPos = Vector2(Screen::BottomLeft + Vector2(150, -30));
	static constexpr Vector2 HitBoxSize = Vector2(30, 30);
	static constexpr float MoveSpeed = 3.0f;

	int m_sprite;
	Punch* m_punch;
	bool m_front;

public:
	PlayerPunch();

	virtual void Load();
	virtual void Release();
	void Update();
	void Draw();

	bool GetFront() const { return m_front; }
};
