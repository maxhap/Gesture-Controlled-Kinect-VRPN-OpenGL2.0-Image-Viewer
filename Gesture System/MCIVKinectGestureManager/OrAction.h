#ifndef _ORACTION_
#define _ORACTION_

#include "stdafx.h"
#include "Gesture.h"
#include "Action.h"
#include <vector>
#include "MCIVKinectGestureManagerDEFS.h"

using namespace std;

class MCIVKINECTGESTUREMANAGER_DLL_DEF OrAction : public Action
{

public:

	OrAction( string sName, float uiTimout );
	virtual ~OrAction();

	virtual bool Accept();

	virtual void SetGestureAssignedTo( Gesture* pGesture );

	void addAction( Action* pAction );

private:

	vector<Action*>* _pvActions;

};

#endif