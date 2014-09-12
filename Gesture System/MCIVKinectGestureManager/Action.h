#ifndef _ACTION_
#define _ACTION_

#include "stdafx.h"
#include <sstream>
#include <MCIVUtilities/BodyDefs.h>
#include <MCIVUtilities/HumainBody.h>
#include <MCIVUtilities/BodyPart.h>
#include <MCIVKinectVRPN/VRPNClient.h>
#include <MCIVUtilities/Node.h>
#include "Gesture.h"
#include "MCIVKinectGestureManagerDEFS.h"

class Gesture;

using namespace std;

class MCIVKINECTGESTUREMANAGER_DLL_DEF Action
{

public:
	
	Action( string sName, float fTimout, GMbodypart gmbBodyPart );
	virtual ~Action();

	virtual bool Accept();
	virtual bool Proceed();

	void SetChildAction( Action* pAction );
	virtual void SetGestureAssignedTo( Gesture* pGesture );
	
	Action* GetChiledAction();

	float GetTimeout();

	string GetName();


protected:

	float _fTimeout;
	GMbodypart _gmbBodyPart; 

	bool _bActive;

	Action* _ChiledAction;
	Gesture* _pGestureAssignedTo;

	string _sName;

	HumainBody* GetBodyData();

};

#endif