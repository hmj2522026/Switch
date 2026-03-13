#pragma once
#include "Tag.h"
#include "Transform2D.h"
#include "Rigidbody2D.h"
#include "Node.h"

class BoxCollider;
class Physics2D;

class Actor2D : public Node
{
	friend Physics2D;

protected:
	Tag m_tag;
	Transform2D m_transform;
	Rigidbody2D m_rigidbody2D;
	BoxCollider* m_collider;

	virtual void Load();
	virtual void Release();

public:
	Actor2D(
		const Vector2& position,
		const Tag& tag = Tag::None,
		const Rigidbody2D::BodyType bodyType = Rigidbody2D::BodyType::Static
	);

	virtual void TreeUpdate() override;

	const Transform2D& GetTransform() const { return m_transform; }

	const Vector2& GetPosition() const { return m_transform.position; }

	void SetPosition(const Vector2& pos) { m_transform.position = pos; }

	const Tag GetTag() const { return m_tag; }

	virtual void OnCollisionEnter(const Actor2D* other) {}
	virtual void OnCollision(const Actor2D* other) {}
	virtual void OnCollisionExit(const Actor2D* other) {}
};
