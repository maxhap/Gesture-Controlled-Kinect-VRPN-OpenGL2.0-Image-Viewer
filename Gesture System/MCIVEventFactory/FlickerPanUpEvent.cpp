#include "FlickerPanUpEvent.h"

FlickerPanUpEvent::FlickerPanUpEvent()
{

}

FlickerPanUpEvent::~FlickerPanUpEvent()
{

}

void FlickerPanUpEvent::FireEvent()
{
	MCIVStateController::instance().FlickerPanUp = true;
}
