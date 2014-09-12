#ifndef _POSITIONACTION_
#define _POSITIONACTION_

#include "stdafx.h"
#include <iostream>
#include "Action.h"
#include <MCIVUtilities/BodyDefs.h>
#include <MCIVUtilities/HumainBody.h>
#include <MCIVUtilities/BodyPart.h>
#include <MCIVKinectVRPN/VRPNClient.h>
#include "MCIVKinectGestureManagerDEFS.h"
#include <MCIVUtilities/Vector3f.h>

using namespace std;

class MCIVKINECTGESTUREMANAGER_DLL_DEF PositionAction : public Action
{

public:

	PositionAction( string sName, float uiTimout, GMbodypart gmbBodyPart, GMrelationship gmrRelationship, GMbodypart gmbRelationBodyPart, float fUperComparisonDistance,
					float fLowerComparisonDistance );
	virtual ~PositionAction();

	virtual bool Accept();	

private:

	GMrelationship _gmrRelationship;
	GMbodypart _gmbRelationBodyPart;
	
	float _fUperComparisonDistance;
	float _fLowerComparisonDistance;
	float _fLeewayValue;
	 
	bool ToTheLeftOf();
	bool ToTheRightOf();
	bool InFront();
	bool Behind();
	bool Above();
	bool Below();
	bool Apart();
	bool Together();

};
#endif