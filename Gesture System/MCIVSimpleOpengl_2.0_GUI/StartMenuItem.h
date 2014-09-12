#ifndef _STARTMENUITEM_
#define _STARTMENUITEM_

#include "stdafx.h"
#include "DrawableListItem.h"

class StartMenuItem : public DrawableListItem
{

public:

	StartMenuItem();
	virtual ~StartMenuItem();

	virtual void ProceedActivation();

protected:

	

};
#endif