#ifndef _CRD_
#define _CRD_

#include <MCIVStateController/MCIVStateController.h>
#include "Event.h"

class CarouselRotateDisabledEvent : public Event
{

public:

	CarouselRotateDisabledEvent();
	virtual ~CarouselRotateDisabledEvent();

	virtual void FireEvent();

protected:

private:

};
#endif