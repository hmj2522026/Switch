#pragma once

class Keyboard
{
private:
	static constexpr int KeyStateNum = 256;	// キー入力状態のの要素数（必ず256でないといけない）

	static char m_keyState[KeyStateNum];		// 今のキー入力状態
	static char m_prevKeyState[KeyStateNum];	// 前のキー入力状態

	Keyboard() {}

public:
	static void Update();

	// 押されたとき
	static bool IsDown(int key) { return !m_prevKeyState[key] && m_keyState[key]; }

	// 押されているとき
	static bool IsPress(int key) { return m_keyState[key]; }

	// 離されたとき
	static bool IsUp(int key) { return m_prevKeyState[key] && !m_keyState[key]; }
};
