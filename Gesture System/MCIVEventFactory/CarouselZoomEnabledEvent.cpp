#include "CarouselZoomEnabledEvent.h"

CarouselZoomEnabledEvent::CarouselZoomEnabledEvent()
{

}

CarouselZoomEnabledEvent::~CarouselZoomEnabledEvent()
{

}

void CarouselZoomEnabledEvent::FireEvent()
{
	MCIVStateController::instance().CarouselZoomEnabled = true;
}
