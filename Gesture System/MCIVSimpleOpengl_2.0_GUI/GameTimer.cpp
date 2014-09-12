#include "stdafx.h"

GameTimer::GameTimer()
{
	_StartTicks = 0;
	_PausedTicks = 0;
	_Paused = false;
	_Started = false;
}
GameTimer::~GameTimer()
{
}

void GameTimer::Start()
{
	_Started = true;
	_Paused = false;
	_StartTicks = SDL_GetTicks();
}

void GameTimer::Stop()
{
	_Started = false;
	_Paused = false;
}

int GameTimer::GetTicks()
{
	if( _Started == true )
	{
		if( _Paused == true )
		{
			return _PausedTicks;
		}
		else
		{
			return SDL_GetTicks() - _StartTicks;
		}
	}

	//no timer running
	return 0;
}

void GameTimer::Pause()
{
	if( _Started == true && _Paused == false )
	{
		_Paused = true;
		_PausedTicks = SDL_GetTicks() - _StartTicks;
	}
}

void GameTimer::Unpause()
{
	if( _Paused == true )
	{
		_Paused = false;
		_StartTicks = SDL_GetTicks() - _PausedTicks;
	}
}

bool GameTimer::IsStarted()
{
	return _Started;
}

bool GameTimer::IsPaused()
{
	return _Paused;
}

