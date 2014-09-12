#include "MCIVEventFactory.h"

MCIVEventFactory::MCIVEventFactory()
{
	BuildEvents();
}

MCIVEventFactory::~MCIVEventFactory()
{

}

void MCIVEventFactory::PushEvent( unsigned int uiSkelitonID, string sEvent )
{
	map<string, Event*>::iterator fi = _EventMap.find( sEvent );

	if( fi != _EventMap.end() )
	{
		cout << "\n --------- Action Event -----------" ;
		cout << "\n";
		cout << "\n      Skeleton " << uiSkelitonID << ": " << sEvent << "\n";

		_EventMap[ sEvent ]->FireEvent();
	}	
}

void MCIVEventFactory::BuildEvents()
{
	_EventMap["ManuMenuRightHandInDetectionZone"] = new ManuMenuRightHandInDetectionZoneEvent();
	_EventMap["ManuMenuRightHandOutDetectionZone"] = new ManuMenuRightHandOutDetectionZoneEvent();
	_EventMap["ZoomingHandsClamped"] = new CarouselZoomEnabledEvent();
	_EventMap["ZoomingHandsUnclamped"] = new CarouselZoomDisabledEvent();
	_EventMap["CarouselRotatingActive"] = new CarouselRotateEnabledEvent();
	_EventMap["CarouselRotatingInactive"] = new CarouselRotateDisabledEvent();
	_EventMap["FlickerForwardImageRightHandAtTourso"] = new FlickerNextImageEvent();
	_EventMap["FlickerBackwardsImageLeftHandAtTourso"] = new FlickerPreviousImageEvent();
	_EventMap["FlickerZoomRightHandInfrontEndingPosition"] = new FlickerZoomInEvent();	
	_EventMap["FlickerZoomOutRightHandInfrontEndingPosition"] = new FlickerZoomOutEvent();
	_EventMap["FlickerPanUpCenter"] = new FlickerPanUpEvent();
	_EventMap["FlickerPanDownCenter"] = new FlickerPanDownEvent();
	_EventMap["FlickerPanLeftCenter"] = new FlickerPanLeftEvent();
	_EventMap["FlickerPanRightCenter"] = new FlickerPanRightEvent();
}

void MCIVEventFactory::PushTimoutEvent( unsigned int uiSkelitonID, string sEvent )
{
	cout << "\n --------- Time Out Event -----------" ;
	cout << "\n";
	cout << "\n      Skeleton " << uiSkelitonID << ": " << sEvent << "\n";

}
