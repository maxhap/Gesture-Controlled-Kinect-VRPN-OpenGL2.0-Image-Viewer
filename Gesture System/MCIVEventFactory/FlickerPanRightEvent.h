#ifndef _FLPANREVENT_
#define _FLPANREVENT_

#include <MCIVStateController/MCIVStateController.h>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"

class MCIVEVENTFACTORY_DLL_DEF FlickerPanRightEvent : public Event
{

public :

	FlickerPanRightEvent();
	virtual ~FlickerPanRightEvent();

	virtual void FireEvent();

};
#endif