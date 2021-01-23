#include "Timer.h"

Timer::Timer()
{
	delay = 0;
	time = 0;
}
Timer::Timer(float Delay)
{
	delay = Delay;
	time = 0;
}

float Timer::GetTime()
{
	return time;
}
float Timer::GetDelay()
{
	return delay;
}
float Timer::PercentComplete()
{
	return time / delay;
}
float Timer::TimeRemaining()
{
	return delay - time;
}

void Timer::Reset()
{
	time = 0;
}
void Timer::Reset(float startPoint)
{
	time = startPoint;
}
void Timer::CountByTime()
{
	time += GetFrameTime();
}
void Timer::CountByValue(float value)
{
	time += value;
}

bool Timer::IsComplete()
{
	if (time >= delay)
	{
		Reset();

		return true;
	}

	return false;
}
bool Timer::IsComplete(bool resetOnTrue)
{
	if (time >= delay)
	{
		if (resetOnTrue)
			Reset();

		return true;
	}

	return false;
}
bool Timer::Check()
{
	if (IsComplete())
		return true;

	CountByTime();

	return false;
}
bool Timer::Check(bool resetOnTrue)
{
	if (IsComplete(resetOnTrue))
		return true;

	CountByTime();

	return false;
}
bool Timer::Check(float value)
{
	if (IsComplete())
		return true;

	CountByValue(value);

	return false;
}
bool Timer::Check(float value, bool resetOnTrue)
{
	if (IsComplete(resetOnTrue))
		return true;

	CountByValue(value);

	return false;
}