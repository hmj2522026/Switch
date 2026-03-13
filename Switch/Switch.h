#pragma once
#include "Vector2.h"
#include "PlayerJump.h"
#include "PlayerPunch.h"

class Switch
{
private:
	PlayerJump* m_playerJump;
	PlayerPunch* m_playerPunch;

public:
	Switch(PlayerJump* player,PlayerPunch* playerPunch) :
		m_playerJump(player),
		m_playerPunch(playerPunch)
	{ }

	void SwitchPlayerPos()
	{
		Vector2 pos = m_playerJump->GetPosition();
		m_playerJump->SetPosition(m_playerPunch->GetPosition());
		m_playerPunch->SetPosition(pos);

		// ‰¹
	}
};
