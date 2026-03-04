#pragma once

class Time
{
private:
	// 前フレームの時刻
	int m_prevTime;
	// 前フレームからの経過時間
	float m_deltaTime;

	Time();

public:
	// シングルトン
	static Time* GetInstance()
	{
		static Time instance;
		return &instance;
	}

	void Update();

	// 経過時間の取得
	float GetDeltaTime()
	{
		return m_deltaTime;
	}
};
