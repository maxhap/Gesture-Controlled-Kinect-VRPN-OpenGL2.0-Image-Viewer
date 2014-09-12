#include "CarouselZoomDisabledEvent.h"

CarouselZoomDisabledEvent::CarouselZoomDisabledEvent()
{

}

CarouselZoomDisabledEvent::~CarouselZoomDisabledEvent()
{

}

void CarouselZoomDisabledEvent::FireEvent()
{
	MCIVStateController::instance().CarouselZoomEnabled = false;
}
