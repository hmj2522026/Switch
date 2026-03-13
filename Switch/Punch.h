#pragma once
#include "Actor2D.h"

class PlayerPunch;

class Punch : public Actor2D
{
private:
	static constexpr Vector2 Offset = Vector2(30, 0);
	static constexpr Vector2 HitBoxSize = Vector2(30, 20);

	int m_sprite;
	bool m_isActive;
	bool m_isFront;
	float m_ActiveTime;
	bool m_flipx;
	PlayerPunch* m_playerPunch;

public:
	//Punch(Vector2 playerPos);
	Punch(PlayerPunch* player);

	virtual void Load();
	virtual void Release();
	void Update();
	void Draw();

	void Active();
};
