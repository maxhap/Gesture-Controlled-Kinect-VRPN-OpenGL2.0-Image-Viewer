#include "CarouselRotateEnabledEvent.h"


CarouselRotateEnabledEvent::CarouselRotateEnabledEvent()
{

}

CarouselRotateEnabledEvent::~CarouselRotateEnabledEvent()
{

}

void CarouselRotateEnabledEvent::FireEvent()
{
	MCIVStateController::instance().CarouselRotateEnabled = true;
}
