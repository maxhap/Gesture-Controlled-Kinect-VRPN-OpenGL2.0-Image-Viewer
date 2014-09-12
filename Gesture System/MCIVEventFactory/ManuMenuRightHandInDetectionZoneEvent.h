#ifndef _RHIOTEVENT_
#define _RHIOTEVENT_

#include <MCIVStateController/MCIVStateController.h>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"

class MCIVEVENTFACTORY_DLL_DEF ManuMenuRightHandInDetectionZoneEvent : public Event
{

public:

	ManuMenuRightHandInDetectionZoneEvent();
	virtual ~ManuMenuRightHandInDetectionZoneEvent();

	virtual void FireEvent();

protected:

};

#endif