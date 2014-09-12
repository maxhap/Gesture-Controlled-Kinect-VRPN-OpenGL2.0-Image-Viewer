#include "FlickerPanDownEvent.h"

FlickerPanDownEvent::FlickerPanDownEvent()
{

}

FlickerPanDownEvent::~FlickerPanDownEvent()
{

}

void FlickerPanDownEvent::FireEvent()
{
	MCIVStateController::instance().FlickerPanDown = true;
}
