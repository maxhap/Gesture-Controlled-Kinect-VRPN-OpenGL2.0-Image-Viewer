#ifndef _RHBTEVENT_
#define _RHBTEVENT_

#include <MCIVStateController/MCIVStateController.h>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"

class MCIVEVENTFACTORY_DLL_DEF ManuMenuRightHandOutDetectionZoneEvent : public Event
{

public:

	ManuMenuRightHandOutDetectionZoneEvent();
	virtual ~ManuMenuRightHandOutDetectionZoneEvent();

	virtual void FireEvent();

protected:

};

#endif