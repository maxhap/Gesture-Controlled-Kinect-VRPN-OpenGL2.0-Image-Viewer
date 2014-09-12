#ifndef _MCIVEVENTFACTORY_
#define _MCIVEVENTFACTORY_

#include <string>
#include <map>
#include <iostream>
#include "MCIVEventFactoryDEFS.h"
#include "Event.h"
#include "ManuMenuRightHandOutDetectionZoneEvent.h"
#include "ManuMenuRightHandInDetectionZoneEvent.h"
#include "CarouselZoomEnabledEvent.h"
#include "CarouselZoomDisabledEvent.h"
#include "CarouselRotateEnabledEvent.h"
#include "CarouselRotateDisabledEvent.h"
#include "FlickerNextImageEvent.h"
#include "FlickerPreviousImageEvent.h"
#include "FlickerZoomInEvent.h"
#include "FlickerZoomOutEvent.h"
#include "FlickerPanUpEvent.h"
#include "FlickerPanDownEvent.h"
#include "FlickerPanLeftEvent.h"
#include "FlickerPanRightEvent.h"

using namespace std;

class MCIVEVENTFACTORY_DLL_DEF MCIVEventFactory 
{
	MCIVEventFactory( const MCIVEventFactory& );
	MCIVEventFactory& operator=( const MCIVEventFactory& );

public:

	MCIVEventFactory();
	virtual ~MCIVEventFactory();

	static MCIVEventFactory& instance()
	{
		static MCIVEventFactory instance;
		return instance;
	}
	
	void PushEvent( unsigned int uiSkelitonID, string sEvent );
	void PushTimoutEvent( unsigned int uiSkelitonID, string sEvent );

protected:

	map<string, Event*> _EventMap;

	void BuildEvents();

private:
	

};
#endif