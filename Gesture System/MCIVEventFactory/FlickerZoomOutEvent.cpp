#include "FlickerZoomOutEvent.h"

FlickerZoomOutEvent::FlickerZoomOutEvent()
{

}

FlickerZoomOutEvent::~FlickerZoomOutEvent()
{

}

void FlickerZoomOutEvent::FireEvent()
{
	MCIVStateController::instance().FlickerImageZoomOut = true;
}
