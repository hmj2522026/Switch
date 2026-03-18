#pragma once
#include "SceneBase.h"

class Node;

class SceneTitle : public SceneBase
{
private:
	Node* m_rootNode;
	int m_background;
	int m_title;

public:
	SceneTitle();

	virtual void Initialize() override;
	virtual void Finalize() override;
	virtual void Update() override;
	virtual void Draw() override;
};
