#include "stdafx.h"
#include "MCIVStateController.h"

MCIVStateController::MCIVStateController()
{
	_uiState = 0;
	_uiHandState = 0;
	RightHandInDetectionZone = false;
	UpdateCameraPosition = false;
	CarouselZoomEnabled = false;
	CarouselRotateEnabled = false;
	FlickerNextImage = false;
	FlickerPreviousImage = false;
	FlickerImageZoomIn = false;
	FlickerImageZoomOut = false;

	FlickerPanUp = false;
	FlickerPanDown = false;
	FlickerPanLeft = false;
	FlickerPanRight = false;
}

MCIVStateController::~MCIVStateController()
{

}

void MCIVStateController::SetState( unsigned int uiState )
{
	_uiState = uiState;
	ResetAllStates();

}

unsigned int MCIVStateController::GetState()
{
	return _uiState;
}

void MCIVStateController::SetHandState( unsigned int uiState )
{
	_uiHandState = uiState;
}

unsigned int MCIVStateController::GetHandState()
{
	return _uiHandState;
}

void MCIVStateController::ResetAllStates()
{
	RightHandInDetectionZone = false;
	UpdateCameraPosition = false;
	CarouselZoomEnabled = false;
	CarouselRotateEnabled = false;
	FlickerNextImage = false;
	FlickerPreviousImage = false;
	FlickerImageZoomIn = false;
	FlickerImageZoomOut = false;

	FlickerPanUp = false;
	FlickerPanDown = false;
	FlickerPanLeft = false;
	FlickerPanRight = false;
}
