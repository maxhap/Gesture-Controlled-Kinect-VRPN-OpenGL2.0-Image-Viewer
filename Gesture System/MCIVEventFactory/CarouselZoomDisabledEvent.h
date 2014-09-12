#ifndef _CZD_
#define _CZD_

#include <MCIVStateController/MCIVStateController.h>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"

class MCIVEVENTFACTORY_DLL_DEF CarouselZoomDisabledEvent : public Event
{

public:

	CarouselZoomDisabledEvent();
	virtual ~CarouselZoomDisabledEvent();

	virtual void FireEvent();

protected:

};

#endif