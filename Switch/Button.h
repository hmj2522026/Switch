#pragma once
#include "Actor2D.h"

class Button : public Actor2D
{
private:
	static constexpr Vector2 HitBoxSize = Vector2(30, 30);

	bool m_isPush;
	int m_sprite;
	int m_sePush;

public:
	Button(Vector2 pos);

	virtual void Load();
	virtual void Release();
	void Draw();

	void OnCollisionEnter(const Actor2D* other);

	bool GetPush() { return m_isPush; }
};
