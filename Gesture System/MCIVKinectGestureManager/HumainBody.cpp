#include "stdafx.h"
#include "HumainBody.h"

HumainBody::HumainBody()
{

}

HumainBody::~HumainBody()
{

}

BodyPart* GetBodyPart( int iBodyPartID )
{
	BodyPart* returnPart;

	switch( iBodyPartID )
	{		 
		case BODY_PART_head: 
		case BODY_PART_neck:
		case BODY_PART_tourso:
		case BODY_PART_waist:
		case BODY_PART_leftShoulder:
		case BODY_PART_leftElboy: 
		case BODY_PART_leftWrist:
		case BODY_PART_leftHand:
		case BODY_PART_rightShoulder:
		case BODY_PART_rightElboy: 
		case BODY_PART_rightWrist:
		case BODY_PART_rightHand: 
		case BODY_PART_leftHip: 
		case BODY_PART_leftKnee:
		case BODY_PART_leftAnkle:
		case BODY_PART_leftFoot:
		case BODY_PART_righttHip:
		case BODY_PART_rightKnee:
		case BODY_PART_rightAnkle:
		case BODY_PART_rightFoot:		
		case NO_BODY_PART: returnPart
	}
}