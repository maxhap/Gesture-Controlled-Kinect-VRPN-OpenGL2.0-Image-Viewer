#ifndef _IMAGECAROUSELMENUITEM_
#define _IMAGECAROUSELMENUITEM_

#include "stdafx.h"

#include "DrawableListItem.h"
#include "StartMenuItem.h"

class ImageCarouselMenuItem : public StartMenuItem
{

public:

	ImageCarouselMenuItem();
	virtual ~ImageCarouselMenuItem();

	virtual void Interact();

protected:


};

#endif