#include "stdafx.h"
#include "TimeAction.h"

TimeAction::TimeAction( string sName, float uiTimout, float fTimeToPass ) : Action( sName, uiTimout, NO_BODY_PART )
{
	_pTimer = new boost::timer();
	_bTimeOutDated = true;
	_fTimeToPass = fTimeToPass;
}

TimeAction::~TimeAction()
{
	if( _pTimer ) delete _pTimer;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Accept
Description: using boost timer if elapsed time since first Accept call is greater than TimeToPass
			 then return true.
-------------------------------------------------------------------------------------------*/
bool TimeAction::Accept()
{
	bool bOutcome = false;

	if( _bTimeOutDated )
	{
		_pTimer->restart();
		_bTimeOutDated = false;
	}

	if( _pTimer->elapsed() >= _fTimeToPass )
	{
		_bTimeOutDated = true;

		_pGestureAssignedTo->fireGestureEvent( _sName );

		bOutcome = true;
	}

	return bOutcome;
}
