#pragma once
#include "Vector2.h"
#include "Node.h"

class PlayerJump;
class PlayerPunch;

class Switch : public Node
{
private:
	PlayerJump* m_playerJump;
	PlayerPunch* m_playerPunch;

	int m_se;

public:
	Switch(PlayerJump* player, PlayerPunch* playerPunch);

	virtual void Load();
	virtual void Release();

	void SwitchPlayerPos();
};
