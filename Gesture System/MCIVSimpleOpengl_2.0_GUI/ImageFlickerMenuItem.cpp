#include "stdafx.h"
#include "ImageFlickerMenuItem.h"

ImageFlickerMenuItem::ImageFlickerMenuItem()
{

}

ImageFlickerMenuItem::~ImageFlickerMenuItem()
{

}

void ImageFlickerMenuItem::Interact()
{
	MCIVStateController::instance().SetHandState( 0 );
	MCIVStateController::instance().SetState( MCIVStateController::FLICKER );	
}
