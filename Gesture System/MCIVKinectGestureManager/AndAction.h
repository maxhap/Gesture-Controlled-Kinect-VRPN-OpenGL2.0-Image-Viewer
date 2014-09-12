#ifndef _ANDACTION_
#define _ANDACTION_

#include "stdafx.h"
#include "Gesture.h"
#include "Action.h"
#include <vector>
#include "MCIVKinectGestureManagerDEFS.h"

using namespace std;

class MCIVKINECTGESTUREMANAGER_DLL_DEF AndAction : public Action
{

public:

	AndAction( string sName, float uiTimout );
	virtual ~AndAction();

	virtual bool Accept();	

	virtual void SetGestureAssignedTo( Gesture* pGesture );

	void addAction( Action* pAction );

private:

	vector<Action*>* _pvActions;

};

#endif