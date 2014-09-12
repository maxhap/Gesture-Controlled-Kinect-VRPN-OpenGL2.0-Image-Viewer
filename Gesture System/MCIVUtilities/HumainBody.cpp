#include "stdafx.h"
#include "HumainBody.h"
#include "BodyPart.h"
#include "BodyDefs.h"
#include "MCIVUtilitiesDEFS.h"

HumainBody::HumainBody()
{
	head = new BodyPart();
	neck = new BodyPart();
	tourso = new BodyPart();
	waist = new BodyPart();
	leftCollar = new BodyPart();
	leftShoulder = new BodyPart();
	leftElboy = new BodyPart();
	leftWrist = new BodyPart();
	leftHand = new BodyPart();
	leftFingureTip = new BodyPart();
	rightCollar = new BodyPart();
	rightShoulder = new BodyPart();
	rightElboy = new BodyPart();
	rightWrist = new BodyPart();
	rightHand = new BodyPart();
	rightFingureTip = new BodyPart();
	leftHip = new BodyPart();
	leftKnee = new BodyPart();
	leftAnkle = new BodyPart();
	leftFoot = new BodyPart();
	rightHip = new BodyPart();
	rightKnee = new BodyPart();
	rightAnkle = new BodyPart();
	rightFoot = new BodyPart();
}

HumainBody::~HumainBody()
{
	delete head;
	delete neck; 
	delete tourso; 
	delete waist; 
	delete leftCollar; 
	delete leftShoulder; 
	delete leftElboy; 
	delete leftWrist;
	delete leftHand; 
	delete leftFingureTip; 
	delete rightCollar; 
	delete rightShoulder; 
	delete rightElboy; 
	delete rightWrist; 
	delete rightHand; 
	delete rightFingureTip; 
	delete leftHip; 
	delete leftKnee; 
	delete leftAnkle; 
	delete leftFoot;
	delete rightHip; 
	delete rightKnee; 
	delete rightAnkle; 
	delete rightFoot; 
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: GetBodyPart
Description: return Body part based on parameter ID
-------------------------------------------------------------------------------------------*/
BodyPart* HumainBody::GetBodyPart( GMbodypart iBodyPartID )
{
	BodyPart* returnPart;

	switch( iBodyPartID )
	{		 
		case BODY_PART_head: return head; break; 
		case BODY_PART_neck: return neck; break;
		case BODY_PART_tourso: return tourso; break;
		case BODY_PART_waist: return waist; break;
		case BODY_PART_leftCollar: return leftCollar;break;
		case BODY_PART_leftShoulder:return leftShoulder; break;
		case BODY_PART_leftElboy: return leftElboy;break;
		case BODY_PART_leftWrist:return leftWrist; break;
		case BODY_PART_leftHand:return leftHand; break;
		case BODY_PART_leftFingureTip: return leftFingureTip;break;
		case BODY_PART_rightCollar: return rightCollar;break;
		case BODY_PART_rightShoulder:return rightShoulder; break;
		case BODY_PART_rightElboy:return rightElboy; break;
		case BODY_PART_rightWrist:return rightWrist; break;
		case BODY_PART_rightHand:return rightHand; break;
		case BODY_PART_rightFingureTip: return rightFingureTip;break;
		case BODY_PART_leftHip:return leftHip; break; 
		case BODY_PART_leftKnee:return leftKnee; break;
		case BODY_PART_leftAnkle:return leftAnkle; break;
		case BODY_PART_leftFoot:return leftFoot; break;
		case BODY_PART_righttHip:return rightHip; break;
		case BODY_PART_rightKnee:return rightKnee; break;
		case BODY_PART_rightAnkle:return rightAnkle; break;
		case BODY_PART_rightFoot:return rightFoot; break;
		case NO_BODY_PART: returnPart; break;
	}

	return NULL;
}