#pragma once
#include "raylib.h"

// Be very careful using timers with opening window

struct Timer
{
private:
	float delay;
	float time;

public:
	Timer();
	Timer(float Delay);

	float GetTime();
	float GetDelay();
	float PercentComplete();
	float TimeRemaining();

	void Reset();
	void Reset(float startPoint);
	void CountByTime();
	void CountByValue(float value);
	bool IsComplete();
	bool IsComplete(bool resetOnTrue);
	bool Check();
	bool Check(bool resetOnTrue);
	bool Check(float value);
	bool Check(float value, bool resetOnTrue);
};

