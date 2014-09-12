#ifndef _TRACKERTHREAD_
#define  _TRACKERTHREAD_

#include <windows.h>
#include <string>

#include <iostream>
#include <boost/thread.hpp>
#include <boost/timer.hpp>

#include <vrpn_Tracker.h>
#include <MCIVUtilities/BodyDefs.h>
#include <MCIVUtilities/HumainBody.h>
#include <MCIVUtilities/BodyPart.h>
#include "MCIVKinectVRPNDEFS.h"

using namespace std;

class MCIVKINECTVRPN_DLL_DEF TrackerThread
{

public:

	TrackerThread( string sHostInfo, HumainBody* pDataBody );
	virtual ~TrackerThread();
	
	void start();
	void stop();
	void loopTracker();
	void manualLoopTracker();

	bool getTrackerAlive();

	void operator () ();

private:

	boost::timer* _ptUpdateTimer;
	vrpn_Tracker_Remote* _pvprnTracker;
	HumainBody* _pDataBody;
	bool _bTrackerAlive;

	boost::thread* _pThread;
	bool _bThreadRunning;
	boost::mutex _mMustStopMutex;

	static void trackerCallBack( void *pData, const vrpn_TRACKERCB t );	
	void trackerUpdate( const vrpn_TRACKERCB vprnTracker );	
};

#endif