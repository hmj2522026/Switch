#include "Collision2D.h"
#include "BoxCollider.h"
#include "Transform2D.h"
#include "Math.h"

Collision2D::Box::Box(const Transform2D& t, const BoxCollider* col) :
	center(t.position + col->offset * t.scale),
	width(col->size.x * t.scale),
	height(col->size.y * t.scale),
	size(width, height),
	topLeft(center - size / 2),
	bottomRight(topLeft + size)
{ }

Vector2 Collision2D::ResolveBoxBox(
	const Transform2D& boxT1, const BoxCollider* boxCol1,
	const Transform2D& boxT2, const BoxCollider* boxCol2)
{
	Box box1 = Box(boxT1, boxCol1);
	Box box2 = Box(boxT2, boxCol2);

	// é≤ÇÃèdÇ»ÇËÇåvéZ
	Vector2 d = box1.center - box2.center;
	Vector2 overlap = Vector2(
		(box1.width + box2.width) / 2 - Math::Abs(d.x),
		(box1.height + box2.height) / 2 - Math::Abs(d.y)
	);

	// é≤Ç™èdÇ»Ç¡ÇƒÇ»Ç¢
	if (overlap.x <= 0 || overlap.y <= 0) return Vector2();

	Vector2 resolve;
	if (overlap.x < overlap.y)
	{
		resolve.x = (d.x < 0) ? overlap.x : -overlap.x;
	}
	else
	{
		resolve.y = (d.y < 0) ? overlap.y : -overlap.y;
	}

	return resolve;
}

const Collision2D::HitInfo Collision2D::CheckbyBoxBox(
	const Transform2D& boxT1, const BoxCollider* boxCol1,
	const Transform2D& boxT2, const BoxCollider* boxCol2
)
{
	HitInfo info;
	info.resolve = ResolveBoxBox(boxT1, boxCol1, boxT2, boxCol2);
	info.isHit = !info.resolve.IsZero();
	return info;
}
