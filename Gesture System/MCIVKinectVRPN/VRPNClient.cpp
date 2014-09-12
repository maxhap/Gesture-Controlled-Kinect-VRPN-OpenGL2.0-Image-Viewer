#include "VRPNClient.h"

VRPNClient::VRPNClient()
{
	_pvTrackers = new vector<Tracker*>;
	_bMultiThreaded = false;
}


VRPNClient::~VRPNClient()
{
	// delete the trackers in the trackers vector
	for( vector<Tracker*>::iterator i = _pvTrackers->begin(); i < _pvTrackers->end(); i++ )
	{
		( *i )->stop();

		delete ( *i );
	}

	_pvTrackers->erase( _pvTrackers->begin(), _pvTrackers->end() );

	delete _pvTrackers;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: addTracker
Description: Add a new tracker instance to the _pvTrackers list vector
-------------------------------------------------------------------------------------------*/
void VRPNClient::addTracker( string hostInfo )
{
	Tracker* pTracker = new Tracker( hostInfo, _bMultiThreaded );
	pTracker->start();

	_pvTrackers->push_back( pTracker );
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: getTracker
Description: Search though the list, find the track by id string then return it
-------------------------------------------------------------------------------------------*/
Tracker* VRPNClient::getTracker( string sIdentity )
{
	for( vector<Tracker*>::iterator i = _pvTrackers->begin(); i < _pvTrackers->end(); i++ )
	{
		if( ( *i )->getIdentity() == sIdentity )
		{
			return ( *i );
		}
	}

	return NULL;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: getTrackerData
Description: Search though the list, find the track by id string then return the body data
-------------------------------------------------------------------------------------------*/
HumainBody* VRPNClient::getTrackerData( string sIdentity )
{
	for( vector<Tracker*>::iterator i = _pvTrackers->begin(); i < _pvTrackers->end(); i++ )
	{
		if( ( *i )->getIdentity() == sIdentity )
		{
			return ( *i )->getBodyData();
		}
	}

	return NULL;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: getTrackerAlive
Description: Search though the list, find the track by id string then return the TrackerAlive 
			 data
-------------------------------------------------------------------------------------------*/
bool VRPNClient::getTrackerAlive( string sIdentity )
{
	for( vector<Tracker*>::iterator i = _pvTrackers->begin(); i < _pvTrackers->end(); i++ )
	{
		if( ( *i )->getIdentity() == sIdentity )
		{
			return ( *i )->getTrackerAlive();
		}
	}

	return false;;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: setMultiThreaded
Description: set _bMultiThreaded to parameter value
-------------------------------------------------------------------------------------------*/
void VRPNClient::setMultiThreaded( bool bOnOFF )
{
	_bMultiThreaded = bOnOFF;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: manualLoopAllTrackers
Description: iterate though calling all tracker loops
-------------------------------------------------------------------------------------------*/
void VRPNClient::manualLoopAllTrackers()
{
	if( !_bMultiThreaded )
	{
		for( vector<Tracker*>::iterator i = _pvTrackers->begin(); i < _pvTrackers->end(); i++ )
		{
			( *i )->manualLoopTracker();
		}
	}
	
}
