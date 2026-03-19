#pragma once
#include "SceneBase.h"

class Node;

class SceneTitle : public SceneBase
{
private:
	static constexpr float BlinkDuration = 1.0f;
	static constexpr float WaitTransitionTime = 0.5f;

	Node* m_rootNode;
	int m_background;
	int m_title;
	float m_waitTransitionTime;

	int m_pressAnyButton;
	float m_elapsedTime;
	bool m_drawFlag;

public:
	SceneTitle();

	virtual void Initialize() override;
	virtual void Finalize() override;
	virtual void Update() override;
	virtual void Draw() override;
};
