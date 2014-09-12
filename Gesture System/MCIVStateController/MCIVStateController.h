#ifndef _MCIVSTATECONTROLLER_
#define _MCIVSTATECONTROLLER_

#include "stdafx.h"
#include "MCIVStateControllerDEFS.h"

class MCIVSTATECONTROLLER_DLL_DEF MCIVStateController
{
	MCIVStateController( const MCIVStateController& );
	MCIVStateController& operator =( const MCIVStateController& );

public:

	static const unsigned int MAINMENU = 0;
	static const unsigned int CAROUSEL = 1;
	static const unsigned int FLICKER = 2;

	static MCIVStateController& instance()
	{
		static MCIVStateController inst;
		return inst;
	};

	void SetState( unsigned int uiState );
	unsigned int GetState();

	void SetHandState( unsigned int uiState );
	unsigned int GetHandState();

	void ResetAllStates();

	bool RightHandInDetectionZone;
	bool UpdateCameraPosition;
	bool CarouselZoomEnabled;
	bool CarouselRotateEnabled;

	bool FlickerNextImage;
	bool FlickerPreviousImage;
	bool FlickerImageZoomIn;
	bool FlickerImageZoomOut;
	bool FlickerPanUp;
	bool FlickerPanDown;
	bool FlickerPanLeft;
	bool FlickerPanRight;

protected:

	MCIVStateController();
	virtual ~MCIVStateController();

	unsigned int _uiState;
	unsigned int _uiHandState;
};

#endif