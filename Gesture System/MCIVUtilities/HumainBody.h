#ifndef _HUMAINBODY_
#define _HUMAINBODY_

#include "stdafx.h"
#include "BodyPart.h"
#include "BodyDefs.h"
#include "MCIVUtilitiesDEFS.h"

class MCIVUTILITIES_DLL_DEF HumainBody
{
	
public:

	HumainBody();
	virtual ~HumainBody();

	BodyPart* head;
	BodyPart* neck;
	BodyPart* tourso;
	BodyPart* waist;
	BodyPart* leftCollar;
	BodyPart* leftShoulder;
	BodyPart* leftElboy;
	BodyPart* leftWrist;
	BodyPart* leftHand;
	BodyPart* leftFingureTip;
	BodyPart* rightCollar;
	BodyPart* rightShoulder;
	BodyPart* rightElboy;
	BodyPart* rightWrist;
	BodyPart* rightHand;
	BodyPart* rightFingureTip;
	BodyPart* leftHip;
	BodyPart* leftKnee;
	BodyPart* leftAnkle;
	BodyPart* leftFoot;
	BodyPart* rightHip;
	BodyPart* rightKnee;
	BodyPart* rightAnkle;
	BodyPart* rightFoot;

	BodyPart* GetBodyPart( GMbodypart iBodyPartID );

private:



};
#endif