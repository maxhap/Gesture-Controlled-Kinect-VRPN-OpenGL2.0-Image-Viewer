#ifndef _FLPANDEVENT_
#define _FLPANDEVENT_

#include <MCIVStateController/MCIVStateController.h>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"

class MCIVEVENTFACTORY_DLL_DEF FlickerPanDownEvent : public Event
{

public :

	FlickerPanDownEvent();
	virtual ~FlickerPanDownEvent();

	virtual void FireEvent();

};
#endif