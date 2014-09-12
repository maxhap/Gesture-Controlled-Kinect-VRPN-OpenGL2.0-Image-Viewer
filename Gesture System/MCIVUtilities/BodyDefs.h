#ifndef _BODYDEFINES_
#define  _BODYDEFINES_

#include "stdafx.h"
#include "MCIVUtilitiesDEFS.h"

//body part
const int NO_BODY_PART = -1;
const int BODY_PART_head = 0;
const int BODY_PART_neck = 1;
const int BODY_PART_tourso = 2;
const int BODY_PART_waist = 3;
const int BODY_PART_leftCollar = 4;
const int BODY_PART_leftShoulder = 5;
const int BODY_PART_leftElboy = 6;
const int BODY_PART_leftWrist = 7;
const int BODY_PART_leftHand = 8;
const int BODY_PART_leftFingureTip = 9;
const int BODY_PART_rightCollar = 10; 
const int BODY_PART_rightShoulder = 11; 
const int BODY_PART_rightElboy = 12;
const int BODY_PART_rightWrist = 13;
const int BODY_PART_rightHand = 14;
const int BODY_PART_rightFingureTip = 15;
const int BODY_PART_leftHip = 16;
const int BODY_PART_leftKnee = 17;
const int BODY_PART_leftAnkle = 18;
const int BODY_PART_leftFoot = 19;
const int BODY_PART_righttHip = 20;
const int BODY_PART_rightKnee = 21;
const int BODY_PART_rightAnkle = 22;
const int BODY_PART_rightFoot = 23;

//relationships
const int RELATIONSHIP_TO_THE_LEFT_OF = 100;
const int RELATIONSHIP_TO_THE_RIGHT_OF = 101;
const int RELATIONSHIP_INFRONT = 102;
const int RELATIONSHIP_BEHIND = 103;
const int RELATIONSHIP_ABOVE = 104;
const int RELATIONSHIP_BELOW = 105;
const int RELATIONSHIP_APART_FROM = 106;
const int RELATIONSHIP_TOGETHER = 107;

const int RELATIONSHIP_GREATER_THAN = 108;
const int RELATIONSHIP_LESS_THAN = 109;

const int RELATIONSHIP_TOWARDS = 110;
const int RELATIONSHIP_AWAY = 111; 

typedef int GMbodypart;
typedef int GMrelationship;

#endif