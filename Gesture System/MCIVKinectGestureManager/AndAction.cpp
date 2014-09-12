#include "stdafx.h"
#include "AndAction.h"

AndAction::AndAction(  string sName, float uiTimout ) : Action( sName, uiTimout, NO_BODY_PART )
{
	_pvActions = new vector<Action*>();
}

AndAction::~AndAction()
{
	for( vector<Action*>::iterator i = _pvActions->begin(); i != _pvActions->end(); i++ )
	{
		delete ( *i );		
	}

	_pvActions->empty();

	delete _pvActions;
}

bool AndAction::Accept()
{
	bool bAccept = true;

	for( vector<Action*>::iterator i = _pvActions->begin(); i != _pvActions->end(); i++ )
	{
		bAccept = ( *i )->Accept();

		if( bAccept == false )
		{
			break;
		}
	}

	if( bAccept )
	{		
		_pGestureAssignedTo->fireGestureEvent( _sName );
	}

	return bAccept;
}

void AndAction::addAction( Action* pAction )
{
	_pvActions->push_back( pAction );
}

void AndAction::SetGestureAssignedTo( Gesture* pGesture )
{
	Action::SetGestureAssignedTo( pGesture );

	for( vector<Action*>::iterator i = _pvActions->begin(); i != _pvActions->end(); i++ )
	{
		( *i )->SetGestureAssignedTo( pGesture );
	}
}
