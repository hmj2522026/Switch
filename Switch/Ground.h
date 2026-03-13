#pragma once
#include "Vector2.h"
#include "Actor2D.h"

class Ground : public Actor2D
{
private:
	int m_sprite;

public:
	Ground();

	virtual void Load();
	virtual void Release();
	void Draw();
};
