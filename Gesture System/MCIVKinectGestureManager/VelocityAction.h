#ifndef _VELOCITYACTION_
#define _VELOCITYACTION_

#include <MCIVUtilities/Node.h>
#include "stdafx.h"
#include "Action.h"
#include <MCIVUtilities/BodyDefs.h>
#include <MCIVUtilities/HumainBody.h>
#include <MCIVUtilities/BodyPart.h>
#include <MCIVKinectVRPN/VRPNClient.h>
#include "MCIVKinectGestureManagerDEFS.h"
#include <MCIVUtilities/Vector3f.h>

#include "MCIVKinectGestureManagerDEFS.h"

class MCIVKINECTGESTUREMANAGER_DLL_DEF VelocityAction : public Action
{

public:

	VelocityAction( string sName, float uiTimout, unsigned int uiBodyPart, GMrelationship gmrRelationship, float fSpeed );

	virtual ~VelocityAction();

	virtual bool Accept();	

protected:

	float _fSpeed;
	GMrelationship _gmrRelationship;

	bool GreaterThan();
	bool LessThan();
};

#endif