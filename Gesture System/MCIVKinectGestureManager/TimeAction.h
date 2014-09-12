#ifndef _TIMEACTION_
#define _TIMEACTION_

#include <MCIVUtilities/Node.h>
#include <MCIVUtilities/BodyDefs.h>
#include <MCIVUtilities/HumainBody.h>
#include <MCIVUtilities/BodyPart.h>
#include <MCIVKinectVRPN/VRPNClient.h>
#include "MCIVKinectGestureManagerDEFS.h"
#include <MCIVUtilities/Vector3f.h>

#include <boost/timer.hpp>

#include "stdafx.h"
#include "Action.h"
#include "MCIVKinectGestureManagerDEFS.h"

class MCIVKINECTGESTUREMANAGER_DLL_DEF TimeAction : public Action
{

public:

	TimeAction( string sName, float uiTimout, float fTimeToPass );

	virtual ~TimeAction();

	virtual bool Accept();	

protected:

	float _fTimeToPass;

	boost::timer* _pTimer;

	bool _bTimeOutDated;

};

#endif