#include "FlickerZoomInEvent.h"

FlickerZoomInEvent::FlickerZoomInEvent()
{

}

FlickerZoomInEvent::~FlickerZoomInEvent()
{

}

void FlickerZoomInEvent::FireEvent()
{
	MCIVStateController::instance().FlickerImageZoomIn = true;
}
