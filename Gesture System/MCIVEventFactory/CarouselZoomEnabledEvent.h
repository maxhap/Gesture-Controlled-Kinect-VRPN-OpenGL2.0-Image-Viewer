#ifndef _CZEN_
#define _CZEN_

#include <MCIVStateController/MCIVStateController.h>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"

class MCIVEVENTFACTORY_DLL_DEF CarouselZoomEnabledEvent : public Event
{

public:

	CarouselZoomEnabledEvent();
	virtual ~CarouselZoomEnabledEvent();

	virtual void FireEvent();

protected:

};

#endif