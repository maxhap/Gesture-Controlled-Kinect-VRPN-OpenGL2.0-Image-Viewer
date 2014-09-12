#ifndef _CREN_
#define _CREN_

#include <MCIVStateController/MCIVStateController.h>
#include "Event.h"

class CarouselRotateEnabledEvent : public Event
{

public:

	CarouselRotateEnabledEvent();
	virtual ~CarouselRotateEnabledEvent();

	virtual void FireEvent();

protected:

private:

};
#endif