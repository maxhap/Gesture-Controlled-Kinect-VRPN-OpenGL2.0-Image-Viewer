#include "FlickerNextImageEvent.h"

FlickerNextImageEvent::FlickerNextImageEvent()
{

}

FlickerNextImageEvent::~FlickerNextImageEvent()
{

}

void FlickerNextImageEvent::FireEvent()
{
	MCIVStateController::instance().FlickerNextImage = true;
}
