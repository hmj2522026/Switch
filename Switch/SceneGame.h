#pragma once
#include "SceneBase.h"

class PlayerJump;
class PlayerPunch;
class Switch;
class Ground;
class Node;

class SceneGame : public SceneBase
{
private:
	Node* m_rootNode;
	int m_background;
	PlayerJump* m_playerJump;
	PlayerPunch* m_playerPunch;
	Switch* m_switch;
	Ground* m_ground;

public:
	SceneGame();

	virtual void Initialize() override;
	virtual void Finalize() override;
	virtual void Update() override;
	virtual void Draw() override;
};
