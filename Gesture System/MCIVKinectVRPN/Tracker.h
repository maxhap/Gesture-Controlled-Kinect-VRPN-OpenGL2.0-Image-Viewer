#ifndef _TRACKER_ 
#define _TRACKER_ 

#include <windows.h>
#include <string>
#include <vrpn_Tracker.h>
#include <MCIVUtilities/BodyDefs.h>
#include <MCIVUtilities/HumainBody.h>
#include <MCIVUtilities/BodyPart.h>
#include "TrackerThread.h"
#include "MCIVKinectVRPNDEFS.h"
#include <iostream>

using namespace std;

class MCIVKINECTVRPN_DLL_DEF Tracker
{

public:
	Tracker( string sHostInfo, bool bMultiThreaded );
	virtual ~Tracker();

	void start();
	void stop();
	void manualLoopTracker();

	string getIdentity();

	bool getTrackerAlive();

	HumainBody* getBodyData();	

private:
	
	string _sIdentity;
	
	HumainBody* _pDataBody;
	//void* _pTimer;	

	bool _bThreadRunning;
	bool _bMultiThreaded;
	TrackerThread* _pTrackerTread;

	static void timerCallBack( void* pData, bool bToW );
	void threadTracker();
};

#endif