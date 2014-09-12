#ifndef _BTMM_
#define _BTMM_

#include "stdafx.h"

#include "DrawableList.h"
#include "Hand.h"
#include "MaxRectangle.h"

class BackToMainMenu : public DrawableList
{

public:

	BackToMainMenu();
	virtual ~BackToMainMenu();
	
	bool HandToDraw( Hand* pHand );

protected:

private:

};

#endif