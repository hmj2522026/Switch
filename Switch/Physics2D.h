#pragma once
#include "Screen.h"
#include <list>
#include <unordered_map>
#include <unordered_set>

class Actor2D;

class Physics2D
{
private:
	static constexpr float Gravity = 9.8f;
	static constexpr float LimitFallSpeed = 4.0f;
	static constexpr int LimitDistance =
		((std::max)(Screen::Width, Screen::Height) / 2) *
		((std::max)(Screen::Width, Screen::Height) / 2);
	struct Pair
	{
		Actor2D* actor1;
		Actor2D* actor2;

		Pair(Actor2D* actor1,Actor2D* actor2) :
			actor1(actor1),
			actor2(actor2)
		{ }
	};

	std::list<Actor2D*> m_actorList;
	std::unordered_map<Actor2D*, std::unordered_set<Actor2D*>> m_prevCallbackList;

	Physics2D()
	{

	}

public:
	static Physics2D* GetInstance()
	{
		static Physics2D instance;
		return &instance;
	}

	void Register(Actor2D* actor) { m_actorList.push_back(actor); }

	void Remove(Actor2D* actor) { m_actorList.remove(actor); }

	void Update();

#ifdef _DEBUG
	void Draw();
#endif // _DEBUG

};
