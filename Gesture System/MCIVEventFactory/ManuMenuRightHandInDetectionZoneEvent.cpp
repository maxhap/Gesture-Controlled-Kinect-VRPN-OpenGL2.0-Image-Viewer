#include "ManuMenuRightHandInDetectionZoneEvent.h"

ManuMenuRightHandInDetectionZoneEvent::ManuMenuRightHandInDetectionZoneEvent()
{

}

ManuMenuRightHandInDetectionZoneEvent::~ManuMenuRightHandInDetectionZoneEvent()
{

}

void ManuMenuRightHandInDetectionZoneEvent::FireEvent()
{
	MCIVStateController::instance().RightHandInDetectionZone = true;
}
