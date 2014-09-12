#ifndef _CONDITIONALVELOCITYACTION_
#define _CONDITIONALVELOCITYACTION_

#include "VelocityAction.h"
#include "AndAction.h" 
#include "stdafx.h"
#include "Action.h"
#include <MCIVUtilities/BodyDefs.h>
#include <MCIVUtilities/HumainBody.h>
#include <MCIVUtilities/BodyPart.h>
#include <MCIVKinectVRPN/VRPNClient.h>
#include "MCIVKinectGestureManagerDEFS.h"
#include <MCIVUtilities/Vector3f.h>
#include "MCIVKinectGestureManagerDEFS.h"

class MCIVKINECTGESTUREMANAGER_DLL_DEF ConditionalVelocityAction : public VelocityAction
{
public:

	ConditionalVelocityAction( string sName, float uiTimout, GMbodypart uiBodyPart, GMrelationship gmrVelcoityRelationship, GMbodypart gmConditionBodyPart, 
							   GMrelationship gmrConditionRelationship, float fSpeed, AndAction* paPass );
	virtual ~ConditionalVelocityAction();

	virtual bool Accept();

	virtual void SetGestureAssignedTo( Gesture* pGesture );

protected:

	AndAction* _paPass;
	GMrelationship _gmrConditionalRelationship;
	GMbodypart _gmConditionBodyPart;

	float _fLastMagnitude;
	
	bool towards();
	bool away();

	bool velocityCheck();

private:

};

#endif