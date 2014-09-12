#ifndef _FLPANUPEVENT_
#define _FLPANUPEVENT_

#include <MCIVStateController/MCIVStateController.h>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"

class MCIVEVENTFACTORY_DLL_DEF FlickerPanUpEvent : public Event
{

public :

	FlickerPanUpEvent();
	virtual ~FlickerPanUpEvent();

	virtual void FireEvent();

};
#endif