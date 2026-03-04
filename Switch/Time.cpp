#include "Time.h"
#include "DxLib.h"

Time::Time() :
	m_prevTime(GetNowCount()),
	m_deltaTime(0)
{
}

void Time::Update()
{
	// 今の時刻
	int nowTime = GetNowCount();

	// 前フレームからの経過時間の計算
	m_deltaTime = (nowTime - m_prevTime) / 1000.0f;

	// 今の時刻を覚えておく
	m_prevTime = nowTime;
}
