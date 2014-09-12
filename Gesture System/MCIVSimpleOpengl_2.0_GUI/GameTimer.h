#ifndef _GAMETIMER_
#define _GAMETIMER_

#include "stdafx.h"

class GameTimer
{
public:
	GameTimer();
	~GameTimer();

	void Start();
	void Stop();
	void Pause();
	void Unpause();
	int GetTicks();

	bool IsStarted();
	bool IsPaused();

private:
	bool _Paused;
	bool _Started;
	int _StartTicks;
	int _PausedTicks;
};

#endif