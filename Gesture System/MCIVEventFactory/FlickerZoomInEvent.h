#ifndef _FZIE_
#define _FZIE_

#include <MCIVStateController/MCIVStateController.h>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"

class MCIVEVENTFACTORY_DLL_DEF FlickerZoomInEvent : public Event
{

public:

	FlickerZoomInEvent();
	virtual ~FlickerZoomInEvent();

	virtual void FireEvent();

private:

};

#endif