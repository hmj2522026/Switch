#pragma once
#include "Actor2D.h"

class Floor : public Actor2D
{
protected:
	int m_sprite;

public:
	Floor(Vector2 pos);

	virtual void Load();
	virtual void Release();
	void Draw();

	virtual void OnCollisionEnter(const Actor2D* other);
	virtual void OnCollisionExit(const Actor2D* other);
};
