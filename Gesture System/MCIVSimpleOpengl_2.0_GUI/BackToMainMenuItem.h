#ifndef _BACKTOMAINMENUITEM1_
#define _BACKTOMAINMENUITEM1_

#include "stdafx.h"
#include "DrawableListItem.h"

class BackToMainMenuItem : public DrawableListItem
{

public:

	BackToMainMenuItem();
	virtual ~BackToMainMenuItem();

	virtual void ProceedActivation();
	virtual void Interact();


protected:


};
#endif