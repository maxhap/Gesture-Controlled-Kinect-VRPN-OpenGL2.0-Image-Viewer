#include "stdafx.h"
#include "OrAction.h"

OrAction::OrAction(  string sName, float uiTimout ) : Action( sName, uiTimout, NO_BODY_PART )
{
	_pvActions = new vector<Action*>();
}

OrAction::~OrAction()
{
	for( vector<Action*>::iterator i = _pvActions->begin(); i != _pvActions->end(); i++ )
	{
		delete ( *i );		
	}

	_pvActions->empty();

	delete _pvActions;
}

bool OrAction::Accept()
{
	bool bAccept = false;

	for( vector<Action*>::iterator i = _pvActions->begin(); i != _pvActions->end(); i++ )
	{
		bAccept = ( *i )->Accept();

		if( bAccept == true )
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

void OrAction::addAction( Action* pAction )
{
	_pvActions->push_back( pAction );
}

void OrAction::SetGestureAssignedTo( Gesture* pGesture )
{
	Action::SetGestureAssignedTo( pGesture );

	for( vector<Action*>::iterator i = _pvActions->begin(); i != _pvActions->end(); i++ )
	{
		( *i )->SetGestureAssignedTo( pGesture );
	}
}
