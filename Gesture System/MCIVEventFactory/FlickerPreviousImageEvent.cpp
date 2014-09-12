#include "FlickerPreviousImageEvent.h"


FlickerPreviousImageEvent::FlickerPreviousImageEvent()
{

}

FlickerPreviousImageEvent::~FlickerPreviousImageEvent()
{

}

void FlickerPreviousImageEvent::FireEvent()
{
	MCIVStateController::instance().FlickerPreviousImage = true;
}
