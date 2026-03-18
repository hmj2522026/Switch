#pragma once
#include "Vector2.h"
#include "Actor2D.h"
#include "Screen.h"

class PlayerJump : public Actor2D
{
private:
	static constexpr Vector2 StartPos = Vector2(Screen::BottomLeft + Vector2(75, -30));
	static constexpr Vector2 HitBoxSize = Vector2(30, 30);
	static constexpr Vector2 JumpForce = Vector2(0, -4);
	static constexpr float MoveSpeed = 3.0f;

	int m_sprite;
	bool m_isJump;

public:
	PlayerJump();

	virtual void Load();
	virtual void Release();
	void Update();
	void Draw();

	virtual void OnCollisionEnter(const Actor2D* other);
	virtual void OnCollision(const Actor2D* other);
	virtual void OnCollisionExit(const Actor2D* other);
};
