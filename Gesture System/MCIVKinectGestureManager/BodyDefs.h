#ifndef _BODYDEFINES_
#define  _BODYDEFINES_

//body part
const int NO_BODY_PART = -1;
const int BODY_PART_head = 1;
const int BODY_PART_neck = 2;
const int BODY_PART_tourso = 3;
const int BODY_PART_waist = 4;
const int BODY_PART_leftShoulder = 5;
const int BODY_PART_leftElboy = 6;
const int BODY_PART_leftWrist = 7;
const int BODY_PART_leftHand = 8;
const int BODY_PART_rightShoulder = 9; 
const int BODY_PART_rightElboy = 10;
const int BODY_PART_rightWrist = 11;
const int BODY_PART_rightHand = 12;
const int BODY_PART_leftHip = 13;
const int BODY_PART_leftKnee = 14;
const int BODY_PART_leftAnkle = 15;
const int BODY_PART_leftFoot = 16;
const int BODY_PART_righttHip = 17;
const int BODY_PART_rightKnee = 18;
const int BODY_PART_rightAnkle = 19;
const int BODY_PART_rightFoot = 20;

//relationships
const int RELATIONSHIP_TO_THE_LEFT_OF = 0;
const int RELATIONSHIP_TO_THE_RIGHT_OF = 1;
const int RELATIONSHIP_IN_FRONT_OF = 2;
const int RELATIONSHIP_BEHIND = 3;
const int RELATIONSHIP_ABOVE = 4;
const int RELATIONSHIP_BELOW = 5;
const int RELATIONSHIP_APART_FROM = 6;

typedef int GMbodypart;
typedef int GMrelationship;

#endif