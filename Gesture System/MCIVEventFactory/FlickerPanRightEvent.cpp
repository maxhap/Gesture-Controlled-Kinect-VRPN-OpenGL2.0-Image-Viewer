#include "FlickerPanRightEvent.h"

FlickerPanRightEvent::FlickerPanRightEvent()
{

}

FlickerPanRightEvent::~FlickerPanRightEvent()
{

}

void FlickerPanRightEvent::FireEvent()
{
	MCIVStateController::instance().FlickerPanRight = true;
}
