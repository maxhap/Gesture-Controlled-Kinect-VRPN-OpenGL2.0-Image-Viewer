#ifndef _GESTURE_
#define _GESTURE_

#include <boost/timer.hpp>
#include "stdafx.h"
#include "Action.h"
#include "GestureCONSTS.h"
#include "MCIVKinectGestureManagerDEFS.h"

using namespace std;

class Action;

typedef void ( *EventFunction ) ( unsigned int, string );

class MCIVKINECTGESTUREMANAGER_DLL_DEF Gesture
{
public:

	Gesture( unsigned int uiSkeletonID, string sName );
	~Gesture();

	void addAction( Action* paAction );
	void proceedGesture();	
	void fireGestureEvent( string sActionName );
	void fireTimeoutEvent( string sActionName );
	void setSkeletonID( unsigned int uiSkeletonID );

	unsigned int getSkeletonID();

	EventFunction _pEventFuntion;
	EventFunction _pTimeoutFuntion;

private:	

	Action* _pCurrentAction;
	Action* _pGestureHeadAction;
	Action* _pGestureTailAction;

	string _sName;

	boost::timer* _ptTimeoutTimer;

	unsigned int _uiSkeletonID;

};

#endif