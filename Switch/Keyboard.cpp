#include "Keyboard.h"
#include "DxLib.h"
#include <cstring>

char Keyboard::m_keyState[Keyboard::KeyStateNum];
char Keyboard::m_prevKeyState[Keyboard::KeyStateNum];

void Keyboard::Update()
{
	std::memcpy(m_prevKeyState, m_keyState, sizeof(char) * KeyStateNum);

	GetHitKeyStateAll(m_keyState);
}
