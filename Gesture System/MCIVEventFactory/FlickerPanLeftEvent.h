#ifndef _FLPANLEVENT_
#define _FLPANLEVENT_

#include <MCIVStateController/MCIVStateController.h>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"

class MCIVEVENTFACTORY_DLL_DEF FlickerPanLeftEvent : public Event
{

public :

	FlickerPanLeftEvent();
	virtual ~FlickerPanLeftEvent();

	virtual void FireEvent();

};
#endif