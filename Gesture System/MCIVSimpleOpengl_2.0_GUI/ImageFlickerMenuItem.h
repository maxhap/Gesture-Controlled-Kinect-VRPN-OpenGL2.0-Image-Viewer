#ifndef _IFMI_
#define _IFMI_

#include "stdafx.h"

#include "DrawableListItem.h"
#include "StartMenuItem.h"

class ImageFlickerMenuItem : public StartMenuItem
{

public:

	ImageFlickerMenuItem();
	virtual ~ImageFlickerMenuItem();

	virtual void Interact();

protected:


};

#endif