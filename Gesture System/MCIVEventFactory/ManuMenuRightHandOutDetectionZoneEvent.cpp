#include "ManuMenuRightHandOutDetectionZoneEvent.h"

ManuMenuRightHandOutDetectionZoneEvent::ManuMenuRightHandOutDetectionZoneEvent()
{
	
}

ManuMenuRightHandOutDetectionZoneEvent::~ManuMenuRightHandOutDetectionZoneEvent()
{

}

void ManuMenuRightHandOutDetectionZoneEvent::FireEvent()
{
	MCIVStateController::instance().RightHandInDetectionZone = false;
}
