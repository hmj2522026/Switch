#pragma once
#include "Actor2D.h"
#include "BoxCollider.h"

class HitBox : public Actor2D
{
private:

public:
	HitBox(Vector2 size, Vector2 pos) :
		Actor2D(pos)
	{
		m_collider = new BoxCollider(size);
	}
};
