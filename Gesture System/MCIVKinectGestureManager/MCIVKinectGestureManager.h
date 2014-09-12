#ifndef _MCIVKINECTGESTUREMANAGER_
#define _MCIVKINECTGESTUREMANAGER_

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

#include "Gesture.h"
#include "Action.h"
#include "PositionAction.h"
#include "VelocityAction.h"
#include "ConditionalVelocityAction.h"
#include "AndAction.h"
#include "OrAction.h"
#include "TimeAction.h"
	
#include "MCIVKinectGestureManagerDEFS.h"

typedef void ( *EventFunction ) ( unsigned int, string );

using namespace std;

class MCIVKINECTGESTUREMANAGER_DLL_DEF MCIVKinectGestureManager
{
	MCIVKinectGestureManager( const MCIVKinectGestureManager& );
	MCIVKinectGestureManager& operator=( const MCIVKinectGestureManager& );

protected:

	MCIVKinectGestureManager();
	virtual ~MCIVKinectGestureManager();

public:

	void start( string sGestureFile );
	void stop();
	void proceedGestures();	

	static MCIVKinectGestureManager& instance()
	{
		static MCIVKinectGestureManager instance;
		return instance;
	}

	void setSuccessfullEventFunction( EventFunction pEventFuntion );
	void setTimeoutEventFunction( EventFunction pEventFuntion );

private:

	vector<Gesture*>* _pvGestures;
	bool _bStarted;

	bool buildGestureList( string filePath );
	void addGesture( Gesture* pGesture );
	void deleteGestureList();
	void import( string sFileName );

	Action* loadAction( istream& isFile );

	EventFunction _pEventFuntion;
	EventFunction _pTimoutEventFuntion;

};

#endif