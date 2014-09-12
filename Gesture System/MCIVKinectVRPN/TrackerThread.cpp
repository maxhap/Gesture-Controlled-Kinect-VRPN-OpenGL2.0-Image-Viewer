#include "TrackerThread.h"

TrackerThread::TrackerThread( string sHostInfo, HumainBody* pDataBody )
{
	_bTrackerAlive = false;
	_pDataBody = pDataBody;
	_pvprnTracker = new vrpn_Tracker_Remote( sHostInfo.c_str() );
	_pvprnTracker->register_change_handler( this, trackerCallBack );
	
	_ptUpdateTimer = new boost::timer();	
	_ptUpdateTimer->restart();

	_pThread = NULL;
}

TrackerThread::~TrackerThread()
{
	if( _ptUpdateTimer )delete _ptUpdateTimer;
	if( _pThread ) delete _pThread;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: trackerCallBack
Description: Calls trackerUpdate in current instance
-------------------------------------------------------------------------------------------*/
void TrackerThread::trackerCallBack( void *pData, const vrpn_TRACKERCB t )
{
	( ( TrackerThread* ) pData )->trackerUpdate( t );
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: trackerUpdate
Description: Updates the position and velocity of the body part. Velocity is calculated using 
			 the boost timer and last position/ current position
-------------------------------------------------------------------------------------------*/
void TrackerThread::trackerUpdate( const vrpn_TRACKERCB vprnTracker )
{
	//keep tracker alive by resetting timer
	_bTrackerAlive = true;
	_ptUpdateTimer->restart();

	float f[3];

	f[0]= vprnTracker.pos[0];
	f[1]= vprnTracker.pos[1];
	f[2]= vprnTracker.pos[2];

	_pDataBody->GetBodyPart( ( unsigned int ) vprnTracker.sensor )->setPosition( f );
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton

		     skeleton has left the tractable area set _bTrackerAlive to false.
-------------------------------------------------------------------------------------------*/
void TrackerThread::loopTracker()
{	
	bool bRun = true;

	while ( bRun)
	{
		if( _ptUpdateTimer->elapsed() > 0.1f )
		{
			_bTrackerAlive = false;
		}

		if( _pvprnTracker->connectionPtr() != NULL )
		{
			_mMustStopMutex.lock();
			if( _pvprnTracker ) _pvprnTracker->mainloop();
			_mMustStopMutex.unlock();

		}

		_mMustStopMutex.lock();
		bRun = _bThreadRunning;
		_mMustStopMutex.unlock();
	}	
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: getTrackerAlive
Description: return _bTrackerAlive
-------------------------------------------------------------------------------------------*/
bool TrackerThread::getTrackerAlive()
{
	return _bTrackerAlive;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: start
Description: initializes the thread
-------------------------------------------------------------------------------------------*/
void TrackerThread::start()
{
	if( _pThread == NULL )
	{
		_bThreadRunning = true;
		_pThread = new boost::thread( boost::bind( &TrackerThread::loopTracker, this ) );		
	}	
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: start
Description: stop the thread and delete the pointer
-------------------------------------------------------------------------------------------*/
void TrackerThread::stop()
{
	_mMustStopMutex.lock();
	_bThreadRunning = false;
	_mMustStopMutex.unlock();

	// Wait for the thread to finish.
	if ( _pThread != NULL ) _pThread->join();
	if( _pThread ) delete _pThread;
	_pThread = NULL;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: manualLoopTracker
Description: call _pvprnTracker->mainloop();
-------------------------------------------------------------------------------------------*/
void TrackerThread::manualLoopTracker()
{
	if( _ptUpdateTimer->elapsed() > 0.1f )
	{
		_bTrackerAlive = false;
	}

	if( _pvprnTracker ) _pvprnTracker->mainloop();
}
