#pragma once
#include "Actor2D.h"

class Block : public Actor2D
{
private:
	static constexpr Vector2 HitBoxSize = Vector2(30, 30);

	int m_sprite;

public:
	Block(Vector2 pos,Tag tag = Tag::Block);

	virtual void Load();
	virtual void Release();
	void Draw();

	virtual void OnCollisionEnter(const Actor2D* other);
};
