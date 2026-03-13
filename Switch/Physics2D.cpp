#include "Physics2D.h"
#include "Time.h"
#include "Actor2D.h"
#include "Collision2D.h"
#include "BoxCollider.h"

void Physics2D::Update()
{
	const float FrameGravity = Gravity * Time::GetInstance()->GetDeltaTime();
	for (auto actor : m_actorList)
	{
		Rigidbody2D& rbody = actor->m_rigidbody2D;
		Rigidbody2D::BodyType bodyType = rbody.GetBodyType();

		if (bodyType == Rigidbody2D::BodyType::Static) { continue; }

		if (bodyType == Rigidbody2D::BodyType::Dynamic)
		{
			rbody.velocity.y += FrameGravity * rbody.gravityScale;

			if (rbody.velocity.y > LimitFallSpeed)
			{
				rbody.velocity.y = LimitFallSpeed;
			}
		}
		actor->m_transform.position += rbody.velocity;
	}

	std::list<Pair> pairList;
	for (auto it1 = m_actorList.begin();it1 != m_actorList.end();it1++)
	{
		for (auto it2 = it1;it2 != m_actorList.end();it2++)
		{
			Actor2D* actor1 = *it1;
			Actor2D* actor2 = *it2;

			// 自分自身はスキップ
			if (actor1 == actor2) { continue; }

			// 静的同士はスキップ
			if (actor1->m_rigidbody2D.GetBodyType() == Rigidbody2D::BodyType::Static &&
				actor2->m_rigidbody2D.GetBodyType() == Rigidbody2D::BodyType::Static) { continue; }

			// 形状がなければスキップ
			if (!actor1->m_collider) { continue; }
			if (!actor2->m_collider) { continue; }

			if (actor1->m_collider->GetPhysicsBehavior(actor2->GetTag()) == PhysicsBehavior::Ignore) { continue; }
			if (actor2->m_collider->GetPhysicsBehavior(actor1->GetTag()) == PhysicsBehavior::Ignore) { continue; }

			// 一定距離以上離れていればスキップ
			if ((actor1->GetPosition() - actor2->GetPosition()).SqrMagnitude() > LimitDistance) { continue; }

			// ペア登録
			pairList.push_back(Pair(actor1, actor2));
		}
	}

	std::unordered_map<Actor2D*, std::unordered_set<Actor2D*>> callbackList;
	int loopCount = 0;
	while (true)
	{
		for (auto& pair : pairList)
		{
			auto actor1 = pair.actor1;
			auto actor2 = pair.actor2;

			Collision2D::HitInfo hitInfo = Collision2D::CheckbyBoxBox(
				actor1->GetTransform(), actor1->m_collider,
				actor2->GetTransform(), actor2->m_collider
			);

			if (!hitInfo.isHit) { continue; }

			callbackList[actor1].insert(actor2);

			if (actor1->m_collider->GetPhysicsBehavior(actor2->GetTag()) == PhysicsBehavior::Trigger) { continue; }
			if (actor2->m_collider->GetPhysicsBehavior(actor1->GetTag()) == PhysicsBehavior::Trigger) { continue; }

			if (hitInfo.resolve.SqrMagnitude() < 0.1f)
			{
				hitInfo.resolve = hitInfo.resolve.Normalized() * 0.1f;
			}

			Rigidbody2D rbody1 = actor1->m_rigidbody2D;
			Rigidbody2D rbody2 = actor2->m_rigidbody2D;

			if (rbody1.GetBodyType() == Rigidbody2D::BodyType::Static) rbody2.mass = 0;
			if (rbody2.GetBodyType() == Rigidbody2D::BodyType::Static) rbody1.mass = 0;

			const float TotalMass = rbody1.mass + rbody2.mass;
			const float RefRate = (1 + rbody1.bounciness * rbody2.bounciness);

			const Vector2 Resolve = hitInfo.resolve.Normalized();
			const float Dot = Vector2::Dot(rbody1.velocity - rbody2.velocity, Resolve);
			const Vector2 Reflect = RefRate * Dot / TotalMass * Resolve;

			hitInfo.resolve = hitInfo.resolve / TotalMass * 1.01f;

			actor1->m_transform.position += -rbody2.mass * hitInfo.resolve;
			actor1->m_rigidbody2D.velocity = -rbody2.mass * Reflect + rbody1.velocity;
			//actor1->m_transform.position += -rbody2.mass * hitInfo.resolve;
			//actor1->m_rigidbody2D.velocity = -rbody2.mass * Reflect + rbody1.velocity;
			actor2->m_transform.position += rbody1.mass * hitInfo.resolve;
			actor2->m_rigidbody2D.velocity = rbody1.mass * Reflect + rbody2.velocity;

		}
		loopCount++;
		if (loopCount >= 3) { break; }
	}

	for (auto pair : callbackList)
	{
		auto actor1 = pair.first;
		for (auto actor2 : pair.second)
		{
			auto it = m_prevCallbackList.find(actor1);
			if (it != m_prevCallbackList.end() && it->second.find(actor2) != it->second.end())
			{
				actor1->OnCollision(actor2);
				actor2->OnCollision(actor1);

				it->second.erase(actor2);
			}
			else
			{
				actor1->OnCollisionEnter(actor2);
				actor2->OnCollisionEnter(actor1);
			}
		}
	}

	for (auto pair : m_prevCallbackList)
	{
		auto actor1 = pair.first;

		if (std::find(m_actorList.begin(), m_actorList.end(), actor1) == m_actorList.end()) { continue; }

		for (auto actor2 : pair.second)
		{
			if (std::find(m_actorList.begin(), m_actorList.end(), actor2) == m_actorList.end()) { continue; }

			actor1->OnCollisionExit(actor2);
			actor2->OnCollisionExit(actor1);
		}
	}

	m_prevCallbackList = callbackList;
}

#ifdef _DEBUG
void Physics2D::Draw()
{
	for (auto actor : m_actorList)
	{
		auto col = actor->m_collider;
		if (col) col->Draw(actor->GetTransform());
	}
}
#endif // _DEBUG
