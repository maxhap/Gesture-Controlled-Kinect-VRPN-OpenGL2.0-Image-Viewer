#ifndef _FNIE_
#define _FNIE_

#include <MCIVStateController/MCIVStateController.h>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"

class MCIVEVENTFACTORY_DLL_DEF FlickerNextImageEvent : public Event
{

public:

	FlickerNextImageEvent();
	virtual ~FlickerNextImageEvent();

	virtual void FireEvent();

private:

};

#endif