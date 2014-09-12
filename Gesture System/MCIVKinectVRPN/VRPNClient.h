#ifndef _VRPNCLIENT_
#define _VRPNCLIENT_

#include <string>
#include <vector>
#include "Tracker.h"
#include "MCIVUtilities/HumainBody.h"
#include "MCIVKinectVRPNDEFS.h"

using namespace std;

class MCIVKINECTVRPN_DLL_DEF VRPNClient
{
	VRPNClient( const VRPNClient& );
	VRPNClient& operator=( const VRPNClient& ); 

protected:

	VRPNClient();
	~VRPNClient();

public:

	static VRPNClient& instance()
	{
		static VRPNClient inst;
		return inst;
	};

	void addTracker( string hostInfo ); 
	void manualLoopAllTrackers();
	void setMultiThreaded( bool bOnOFF );

	Tracker* getTracker( string sIdentity );
	HumainBody* getTrackerData( string sIdentity );
	
	bool getTrackerAlive( string sIdentity );
	

private:

	vector<Tracker*>* _pvTrackers;

	bool _bMultiThreaded;

};

#endif

