#pragma once
#include "Floor.h"

class Button;

class FloorInitOff : public Floor
{
private:
	Button* m_button;

public:
	FloorInitOff(Vector2 pos, Button* button);

	void Update();
	void Draw();

};
