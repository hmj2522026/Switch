#pragma once
#include "Vector2.h"

class Transform2D;
class BoxCollider;

class Collision2D
{
private:
	struct Box
	{
		Vector2 center;			// íÜâõç¿ïW
		float width;			// ïù
		float height;			// çÇÇ≥
		Vector2 size;			// ïùÅEçÇÇ≥
		Vector2 topLeft;		// ç∂è„
		Vector2 bottomRight;	// âEâ∫

		Box(const Transform2D& t, const BoxCollider* col);
	};

	static Vector2 ResolveBoxBox(
		const Transform2D& boxT1, const BoxCollider* boxCol1,
		const Transform2D& boxT2, const BoxCollider* boxCol2);

public:
	struct  HitInfo
	{
		bool isHit;
		Vector2 resolve;

		HitInfo() :
			isHit(false)
		{ }
	};

	static const HitInfo CheckbyBoxBox(
		const Transform2D& boxT1, const BoxCollider* boxCol1,
		const Transform2D& boxT2, const BoxCollider* boxCol2);

};
