using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MCIVGestureBuilder
{
    class Logic
    {
        public static int StringsToInt( string sVal )
        {
            if( sVal == "Head" ) return 0;
            if( sVal == "Neck" ) return 1;
            if( sVal == "Torso" ) return 2;
            if( sVal == "Waist" ) return 3;
            if( sVal == "LeftCollar" ) return 4;
            if( sVal == "LeftShoulder" ) return 5;
            if( sVal == "LeftElboy" ) return 6;
            if( sVal == "LeftWrist" )  return 7;
            if( sVal == "LeftHand" ) return 8;
            if( sVal == "LeftFingureTip" ) return 9;
            if( sVal == "RightCollar" )  return 10;
            if( sVal == "RightShoulder" )  return 11;
            if( sVal == "RightElboy" ) return 12;
            if( sVal == "RightWrist" ) return 13;
            if( sVal == "RightHand" )  return 14;
            if( sVal == "RightFingureTip" ) return 15;
            if( sVal == "LeftHip" ) return 16;
            if( sVal == "LeftKnee" ) return 17;
            if( sVal == "LeftAnkle" ) return 18;
            if( sVal == "LeftFoot" ) return 19;
            if( sVal == "RighttHip" ) return 20;
            if( sVal == "RightKnee" ) return 21;
            if( sVal == "RightAnkle" ) return 22;
            if ( sVal == "RightFoot" ) return 23;

            if ( sVal == "TO_THE_LEFT_OF" ) return 100;
            if ( sVal == "TO_THE_RIGHT_OF" ) return 101;
            if ( sVal == "INFRONT" ) return 102;
            if ( sVal == "BEHIND" ) return 103;
            if ( sVal == "ABOVE" ) return 104;
            if ( sVal == "BELOW" ) return 105;
            if ( sVal == "APART_FROM" ) return 106;
            if ( sVal == "TOGETHER" ) return 107;
            if ( sVal == "GREATER_THAN" ) return 108;
            if ( sVal == "LESS_THAN" ) return 109;
            if ( sVal == "TOWARDS" ) return 110;
            if ( sVal == "AWAY" ) return 111;

            return -1;
        }

        public static string IntToString( int sVal )
        {
            if ( sVal == 0 ) return "Head";
            if ( sVal == 1 ) return "Neck";
            if ( sVal == 2 ) return "Torso";
            if ( sVal == 3 ) return "Waist";
            if ( sVal == 4 ) return "LeftCollar";
            if ( sVal == 5 ) return "LeftShoulder";
            if ( sVal == 6 ) return "LeftElboy";
            if ( sVal == 7 ) return "LeftWrist";
            if ( sVal == 8 ) return "LeftHand" ;
            if ( sVal == 9 ) return "LeftFingureTip";
            if ( sVal == 10 ) return "RightCollar";
            if ( sVal == 11 ) return "RightShoulder";
            if ( sVal == 12 ) return "RightElboy";
            if ( sVal == 13 ) return "RightWrist";
            if ( sVal == 14 ) return "RightHand";
            if ( sVal == 15 ) return "RightFingureTip";
            if ( sVal == 16 ) return "LeftHip";
            if ( sVal == 17 ) return "LeftKnee";
            if ( sVal == 18 ) return "LeftAnkle";
            if ( sVal == 19 ) return "LeftFoot";
            if ( sVal == 20 ) return "RighttHip";
            if ( sVal == 21 ) return "RightKnee";
            if ( sVal == 22 ) return "RightAnkle";
            if ( sVal == 23 ) return "RightFoot";

            if ( sVal == 100 ) return "TO_THE_LEFT_OF";
            if ( sVal == 101 ) return "TO_THE_RIGHT_OF";
            if ( sVal == 102 ) return "INFRONT";
            if ( sVal == 103 ) return "BEHIND";
            if ( sVal == 104 ) return "ABOVE";
            if ( sVal == 105 ) return "BELOW";
            if ( sVal == 106 ) return "APART_FROM";
            if ( sVal == 107 ) return "TOGETHER";
            if ( sVal == 108 ) return "GREATER_THAN";
            if ( sVal == 109 ) return "LESS_THAN";

            if ( sVal == 110 ) return "TOWARDS";
            if ( sVal == 111 ) return "AWAY";

            return "";
        }


//TO_THE_LEFT_OF
//TO_THE_RIGHT_OF
//INFRONT
//BEHIND
//ABOVE
//BELOW
//APART_FROM
//TOGETHER

//GREATER_THAN
//LESS_THAN

        
//Head
//Neck
//Torso
//Waist
//LeftCollar
//LeftShoulder
//LeftElboy
//LeftWrist
//LeftHand
//LeftFingureTip
//RightCollar
//RightShoulder
//RightElboy
//RightWrist
//RightHand
//RightFingureTip
//LeftHip
//LeftKnee
//LeftAnkle
//LeftFoot
//RighttHip
//RightKnee
//RightAnkl
//RightFoot
    }
}
