#ifndef _HUMAINBODY_
#define _HUMAINBODY_

#include "stdafx.h"
#include "MCIVKinectGestureManagerDEFS.h"

struct BodyPart
{
	int iPosition;
	int iangle;
	int ivelocity;

};

class MCIVKINECTGESTUREMANAGER_DLL_DEF HumainBody
{
	
public:

	HumainBody();
	~HumainBody();

	BodyPart head;
	BodyPart neck;
	BodyPart tourso;
	BodyPart waist;
	BodyPart leftShoulder;
	BodyPart leftElboy;
	BodyPart leftWrist;
	BodyPart leftHand;
	BodyPart rightShoulder;
	BodyPart rightElboy;
	BodyPart rightWrist;
	BodyPart rightHand;
	BodyPart leftHip;
	BodyPart leftKnee;
	BodyPart leftAnkle;
	BodyPart leftFoot;
	BodyPart righttHip;
	BodyPart rightKnee;
	BodyPart rightAnkle;
	BodyPart rightFoot;

	BodyPart* GetBodyPart( int iBodyPartID );

private:



};
#endif