#pragma once
#include "Actor2D.h"

class Goal : public Actor2D
{
private:
	static constexpr Vector2 HitBoxSize = Vector2(40, 60);

	int m_sprite;

public:
	Goal(Vector2 pos);

	virtual void Load();
	virtual void Release();
	void Draw();
};
