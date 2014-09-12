#include "stdafx.h"
#include "Action.h"

Action::Action( string sName, float fTimout, GMbodypart gmbBodyPart )
{
	_bActive = false;
	_fTimeout = fTimout;
	_gmbBodyPart = gmbBodyPart;

	_ChiledAction = NULL;
	_pGestureAssignedTo = NULL;
	_sName = sName;
}

Action::~Action()
{
	if( _ChiledAction ) delete _ChiledAction;
	if( _pGestureAssignedTo ) _pGestureAssignedTo = NULL;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Accept
Description: Logic in inherited classes, return false as fail safe
-------------------------------------------------------------------------------------------*/
bool Action::Accept()
{
	return false;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Proceed
Description: basic logic, test Child nodes accept to proceed more complex logic can be added in inherited classes
-------------------------------------------------------------------------------------------*/
bool Action::Proceed()
{
	return _ChiledAction->Accept();
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: SetChildAction
Description: _ChiledAction set to action, creates single direction linked list structure
-------------------------------------------------------------------------------------------*/
void Action::SetChildAction( Action* pAction )
{
	_ChiledAction = pAction;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: SetGestureAssignedTo
Description: set _pGestureAssignedTo to passed in gesture, Gesture is used when firing events or for any Action 
			 logic that requires knowing the gesture state.
-------------------------------------------------------------------------------------------*/
void Action::SetGestureAssignedTo( Gesture* pGesture )
{
	_pGestureAssignedTo = pGesture;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: GetChiledAction
Description: returns the chield action, currently used in Gesture for tracking
-------------------------------------------------------------------------------------------*/
Action* Action::GetChiledAction()
{
	return _ChiledAction;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: GetChiledAction
Description: returns _uiTimout
-------------------------------------------------------------------------------------------*/
float Action::GetTimeout()
{
	return _fTimeout;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: GetChiledAction
Description: returns _sName
-------------------------------------------------------------------------------------------*/
std::string Action::GetName()
{
	return _sName;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: GetChiledAction
Description: uses a stringstream to build the tracker string in relation to skeleton id then returns
			 the HumainBody*
-------------------------------------------------------------------------------------------*/
HumainBody* Action::GetBodyData()
{
	stringstream stringStream (stringstream::in | stringstream::out);
	stringStream << "Tracker" << _pGestureAssignedTo->getSkeletonID() << "@localhost";
	string sTracker = stringStream.str();

	HumainBody* pBody = VRPNClient::instance().getTrackerData( sTracker );		
	return pBody;
}
