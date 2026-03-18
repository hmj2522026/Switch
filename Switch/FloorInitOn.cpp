#include "FloorInitOn.h"
#include "Button.h"
#include "BoxCollider.h"

FloorInitOn::FloorInitOn(Vector2 pos,Button* button) :
	Floor(pos),
	m_button(button)
{

}

void FloorInitOn::Update()
{
	if (m_button->GetPush())
	{
		m_collider->SetAllPhysicsBehavior(PhysicsBehavior::Ignore);
	}
	else
	{
		m_collider->SetAllPhysicsBehavior(PhysicsBehavior::Collision);
	}
}

void FloorInitOn::Draw()
{
	if (m_button->GetPush()) { return; }

	Floor::Draw();
}
