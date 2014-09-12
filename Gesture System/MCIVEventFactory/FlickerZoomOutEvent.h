#ifndef _FZOE_
#define _FZOE_

#include <MCIVStateController/MCIVStateController.h>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"

class MCIVEVENTFACTORY_DLL_DEF FlickerZoomOutEvent : public Event
{

public:

	FlickerZoomOutEvent();
	virtual ~FlickerZoomOutEvent();

	virtual void FireEvent();

private:

};

#endif