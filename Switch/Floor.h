#pragma once
#include "Actor2D.h"

class Floor : public Actor2D
{
protected:
	static constexpr Vector2 HitBoxSize = Vector2(90, 5);
	static constexpr Vector2 Offset = Vector2(0, -2.5);

	int m_sprite;

public:
	Floor(Vector2 pos);

	virtual void Load();
	virtual void Release();
	void Draw();

	virtual void OnCollisionEnter(const Actor2D* other);
	virtual void OnCollisionExit(const Actor2D* other);
};
