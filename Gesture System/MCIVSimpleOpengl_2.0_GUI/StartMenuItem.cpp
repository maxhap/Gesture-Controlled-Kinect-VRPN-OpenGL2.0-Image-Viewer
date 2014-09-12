#include "stdafx.h"
#include "StartMenuItem.h"

StartMenuItem::StartMenuItem() : DrawableListItem()
{
	_uiActivationStage = 0;
}

StartMenuItem::~StartMenuItem()
{

}

void StartMenuItem::ProceedActivation()
{
	int mult = 2; 

	if( this->_bSelected )
	{
		_uiActivationStage++;

		if( _uiActivationStage < 30 )
		{
			MCIVStateController::instance().SetHandState( 1 );
		}

		else if ( _uiActivationStage < 90 )
		{
			MCIVStateController::instance().SetHandState( 2 );
		}

		else if ( _uiActivationStage < 120 )
		{
			MCIVStateController::instance().SetHandState( 3 );
		}

		else if ( _uiActivationStage < 150 )
		{
			MCIVStateController::instance().SetHandState( 4 );
		}
		else if ( _uiActivationStage < 170 )
		{
			MCIVStateController::instance().SetHandState( 0 );
			_uiActivationStage = 0;
			this->Interact();		
		}

		_uiActivationStage++;
	}
	else
	{
		_uiActivationStage = 0;
		MCIVStateController::instance().SetHandState( 0 );
	}
}
