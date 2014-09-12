#include "CarouselRotateDisabledEvent.h"

CarouselRotateDisabledEvent::CarouselRotateDisabledEvent()
{

}

CarouselRotateDisabledEvent::~CarouselRotateDisabledEvent()
{

}

void CarouselRotateDisabledEvent::FireEvent()
{
	MCIVStateController::instance().CarouselRotateEnabled = false;
}
