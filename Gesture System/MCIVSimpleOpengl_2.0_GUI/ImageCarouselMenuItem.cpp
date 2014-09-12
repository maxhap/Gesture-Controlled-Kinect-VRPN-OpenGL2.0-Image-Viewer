#include "stdafx.h"
#include "ImageCarouselMenuItem.h"

ImageCarouselMenuItem::ImageCarouselMenuItem() : StartMenuItem()
{

}

ImageCarouselMenuItem::~ImageCarouselMenuItem()
{

}

void ImageCarouselMenuItem::Interact()
{
	MCIVStateController::instance().SetHandState( 0 );
	MCIVStateController::instance().SetState( MCIVStateController::CAROUSEL );	
}
