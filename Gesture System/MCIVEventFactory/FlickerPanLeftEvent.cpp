#include "FlickerPanLeftEvent.h"

FlickerPanLeftEvent::FlickerPanLeftEvent()
{

}

FlickerPanLeftEvent::~FlickerPanLeftEvent()
{

}

void FlickerPanLeftEvent::FireEvent()
{
	MCIVStateController::instance().FlickerPanLeft = true;
}
