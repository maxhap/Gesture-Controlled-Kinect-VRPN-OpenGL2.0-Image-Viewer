#ifndef _FPIE_
#define _FPIE_

#include <MCIVStateController/MCIVStateController.h>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"

class MCIVEVENTFACTORY_DLL_DEF FlickerPreviousImageEvent : public Event
{

public:

	FlickerPreviousImageEvent();
	virtual ~FlickerPreviousImageEvent();

	virtual void FireEvent();

private:

};

#endif