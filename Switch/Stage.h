#pragma once
#include "Node.h"

class Button;

class Stage : public Node
{
private:
	Button* m_button;
public:
	Stage();
};
