#pragma once
#include "Actor2D.h"

class Goal : public Actor2D
{
private:
	static constexpr Vector2 HitBoxSize = Vector2(40, 60);
	static constexpr float WaitTransitionTime = 1.5f;

	int m_sprite;
	int m_goalUI;
	bool m_isGoal;

	float m_waitTransitionTime;

public:
	Goal(Vector2 pos);

	virtual void Load();
	virtual void Release();
	void Update();
	void Draw();

	virtual void OnCollisionEnter(const Actor2D* other);
};
