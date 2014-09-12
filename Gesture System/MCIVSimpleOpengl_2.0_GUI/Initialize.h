#ifndef _INITIALIZE_
#define _INITIALIZE_

#include "stdafx.h"

using namespace std;

class Initialize
{

public:

	//testmode
	static const bool TestMode = false;

	//logs
	static const string ErrorLogLocation;
	static const string EventLogLocation;

	//gamespeed
	static const int FRAMERATE = 60;
	static const int RunAnimationRate = 15;
	static const int AttackAnimationRate = 2;

	//Attributes of screen dont change
	static const int SCREEN_WIDTH = 1600;
	static const int SCREEN_HEIGHT = 900;
	static const int SCREEN_BPP = 32;

	static const float CarouselImageWidth;
	static const float CarouselImageHeight;

	static const string CarouselImagesLocation;
	static const string MainMenuBackgroundImageLocation;
	static const string CarouselMenuItemBackgroundLocaiton;
	static const string CarouselMenuItemBackgroundLocaitonActive;
	static const string FlickerMenuItemBackgroundLocaiton;
	static const string FlickerMenuItemBackgroundLocaitonActive;
	
	static const string HandImageLoaction;
	static const string HandImageLoactionQuater;
	static const string HandImageLoactionHalf;
	static const string HandImageLoactionThreeQuater;
	static const string HandImageLoactionFull;

	static const string BackToMainMenuBackgroundImageLocation;
	static const string BackToMainMenuItemBackgroundImageLocation;
	static const string BackToMainMenuItemActiveBackgroundImageLocation;


	static const string GestuerFileLocation;
};

#endif