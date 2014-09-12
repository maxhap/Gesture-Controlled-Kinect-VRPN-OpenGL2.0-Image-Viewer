#include "Tracker.h"

Tracker::Tracker( string sHostInto, bool bMultiThreaded )
{
	_sIdentity = sHostInto;
	_bMultiThreaded = bMultiThreaded;

	_pDataBody = new HumainBody();

	_bThreadRunning = false;

	_pTrackerTread = new TrackerThread( _sIdentity, _pDataBody );
}

Tracker::~Tracker()
{
	if( _pTrackerTread ) delete _pTrackerTread;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: start
Description: Starts a thread using a Media Timer to constantly call the timerCallBack method 
			 and flags _bThreadRunning to true
-------------------------------------------------------------------------------------------*/
void Tracker::start()
{
	if( !_bThreadRunning && _bMultiThreaded )
	{
		//CreateTimerQueueTimer ( &_pTimer, 0, ( WAITORTIMERCALLBACK ) timerCallBack, this, 10, 10, WT_EXECUTEDEFAULT|WT_EXECUTELONGFUNCTION|WT_EXECUTEONLYONCE );
		//_pTrackerTread = new TrackerThread( _sIdentity, _pDataBody );		
		_pTrackerTread->start();
		_bThreadRunning = true;
	}	
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: stop
Description: Stops the Media Timer and flags _bThreadRunning to false
-------------------------------------------------------------------------------------------*/
void Tracker::stop()
{
	if( _bThreadRunning )
	{
		//DeleteTimerQueueTimer( 0, _pTimer, 0 );
		_bThreadRunning = false;
		_pTrackerTread->stop();
	}
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: getBodyData
Description: LReturns _pDataBody, the tracking data
-------------------------------------------------------------------------------------------*/
HumainBody* Tracker::getBodyData()
{
	return _pDataBody;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Accept
Description: returns _sIdentity, the tracker string
-------------------------------------------------------------------------------------------*/
std::string Tracker::getIdentity()
{
	return _sIdentity;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: timerCallBack
Description: Called from Timer thread, timerCallBack calls threadTracker in current instance
-------------------------------------------------------------------------------------------*/
void Tracker::timerCallBack( void* pData, bool bToW )
{
	( ( Tracker* ) pData )->threadTracker();
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: threadTracker
Description: Creates a Thread tracker if _pTrackerTread = null or loops the tracker to 
			 force an update
-------------------------------------------------------------------------------------------*/
void Tracker::threadTracker()
{
//	if( _pTrackerTread == NULL )
//	{
		_pTrackerTread = new TrackerThread( _sIdentity, _pDataBody );
//		std::cout << "tracker created";
//	}
//	else
//	{
		_pTrackerTread->loopTracker();
//	}
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: getTrackerAlive
Description: returns _pTrackerTread, aka is there a skeleton to track
-------------------------------------------------------------------------------------------*/
bool Tracker::getTrackerAlive()
{
	return _pTrackerTread->getTrackerAlive();
	//return true;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: manualLoopTracker
Description: call manual loop tracker
-------------------------------------------------------------------------------------------*/
void Tracker::manualLoopTracker()
{
	_pTrackerTread->manualLoopTracker();
}
