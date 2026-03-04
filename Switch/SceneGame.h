#pragma once
#include "SceneBase.h"

class Player;

class SceneGame : public SceneBase
{
private:
	int m_image;
	Player* m_player;

public:
	SceneGame();

	virtual void Initialize() override;
	virtual void Finalize() override;
	virtual void Update() override;
	virtual void Draw() override;
};
