#pragma once
#include "Floor.h"

class Button;

class FloorInitOn : public Floor
{
private:
	Button* m_button;

public:
	FloorInitOn(Vector2 pos,Button* button);

	void Update();
	void Draw();

};
