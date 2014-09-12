#include "stdafx.h"
#include "BackToMainMenu.h"


BackToMainMenu::BackToMainMenu() : DrawableList()
{

}

BackToMainMenu::~BackToMainMenu()
{

}

bool BackToMainMenu::HandToDraw( Hand* pHand )
{
	MaxRectangle handRect( pHand->GetPosition()->x(), pHand->GetPosition()->y(), 
							pHand->GetWidthHeighDepth()->x(), pHand->GetWidthHeighDepth()->y() );

	MaxRectangle thisRect( this->GetPosition()->x(), this->GetPosition()->y(), 
							this->GetWidthHeighDepth()->x(), this->GetWidthHeighDepth()->y() );

	return LogicEngine::TwoObjectsCollided( &handRect, &thisRect  );
}
