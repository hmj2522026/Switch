#include "Switch.h"
#include "PlayerJump.h"
#include "PlayerPunch.h"

Switch::Switch(PlayerJump* player, PlayerPunch* playerPunch) :
	m_playerJump(player),
	m_playerPunch(playerPunch),
	m_se(0)
{
}

void Switch::Load()
{
	m_se = LoadSoundMem("Resource/sound/switch.wav");
	ChangeVolumeSoundMem(128, m_se);
}

void Switch::Release()
{
	if (m_se)
	{
		DeleteSoundMem(m_se);
	}
}

void Switch::SwitchPlayerPos()
{
	Vector2 pos = m_playerJump->GetPosition();
	m_playerJump->SetPosition(m_playerPunch->GetPosition());
	m_playerPunch->SetPosition(pos);

	// ‰¹
	PlaySoundMem(m_se, DX_PLAYTYPE_BACK);
}
