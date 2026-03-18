#include "FloorInitOff.h"
#include "Button.h"
#include "BoxCollider.h"

FloorInitOff::FloorInitOff(Vector2 pos, Button* button) :
	Floor(pos),
	m_button(button)
{

}

void FloorInitOff::Update()
{
	if (!m_button->GetPush())
	{
		m_collider->SetAllPhysicsBehavior(PhysicsBehavior::Ignore);
	}
	else
	{
		m_collider->SetAllPhysicsBehavior(PhysicsBehavior::Collision);
	}
}

void FloorInitOff::Draw()
{
	if (!m_button->GetPush()) { return; }

	Floor::Draw();
}
