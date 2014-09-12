#include "StdAfx.h"
#include "Gesture.h"

Gesture::Gesture( unsigned int uiSkeletonID, string sName )
{
	_uiSkeletonID = uiSkeletonID;
	_sName = sName;

	_pCurrentAction = NULL;
	_pGestureHeadAction = NULL;
	_pGestureTailAction = NULL;

	_ptTimeoutTimer = new boost::timer();
}

Gesture::~Gesture()
{	
	if( _pGestureHeadAction ) delete _pGestureHeadAction;
	if( _pCurrentAction ) _pCurrentAction = 0;	
	if( _pGestureTailAction ) _pGestureTailAction = 0;

	if( _ptTimeoutTimer ) delete _ptTimeoutTimer;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: AddAction
Description: if the head is not null aka not first action in the gesture then set current tails 
			 child action to new action and new action to tail. if head is null make new action
			 head and tail
-------------------------------------------------------------------------------------------*/
void Gesture::addAction( Action* paAction )
{
	paAction->SetGestureAssignedTo( this );

	if( _pGestureHeadAction == NULL )
	{
		_pGestureHeadAction = paAction;
		_pCurrentAction = paAction;
		_pGestureTailAction = paAction;
	}
	else
	{
		_pGestureTailAction->SetChildAction( paAction );
		_pGestureTailAction = paAction;
	}
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: ProceedGesture
Description: call Proceed on current gesture, if true then set new current gesture to old gestures
			 child action. loop this process until proceed = false. If _currentActon = tail rest 
			 to head. Also checks to see if an action has passed its timeout time using the boost
			 timer progressing through a gesture restarts the timer.
-------------------------------------------------------------------------------------------*/
void Gesture::proceedGesture()
{
	float fTime = _ptTimeoutTimer->elapsed();
	//check for time out
	if( _pCurrentAction->GetTimeout() != 0 && fTime > _pCurrentAction->GetTimeout() )
	{
		fireTimeoutEvent( _pCurrentAction->GetName() );
		_ptTimeoutTimer->restart();
	}

	//keep proceeding if possible( multiple conditions might be valid at once)
	while( true )
	{
		if( _pCurrentAction != _pGestureTailAction )
		{
			if( _pCurrentAction->Proceed() )
			{
				_ptTimeoutTimer->restart();
				_pCurrentAction = _pCurrentAction->GetChiledAction();
			}			
			else
			{
				break;
			}
		}
		else
		{
			_pCurrentAction = _pGestureHeadAction;
		}	
	}	
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: ProceedGesture
Description: fire function pointed passing the string 
-------------------------------------------------------------------------------------------*/
void Gesture::fireGestureEvent( string sActionName )
{
	if( _pTimeoutFuntion )
	{
		this->_pEventFuntion( _uiSkeletonID,  sActionName );
	}
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: fireTimeoutEvent
Description: set current action to gesture head and fire function pointed passing the string 
-------------------------------------------------------------------------------------------*/
void Gesture::fireTimeoutEvent( string sActionName )
{
	_pCurrentAction = _pGestureHeadAction;	

	if( _pTimeoutFuntion )
	{
		this->_pTimeoutFuntion( _uiSkeletonID, sActionName );
	}	
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: setSkeletonID
Description: assigns _uiSkeliton id to parameter 
-------------------------------------------------------------------------------------------*/
void Gesture::setSkeletonID( unsigned int uiSkeletonID )
{
	_uiSkeletonID = uiSkeletonID;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: getSkeletonID
Description: return _uiSkeliton 
-------------------------------------------------------------------------------------------*/
unsigned int Gesture::getSkeletonID()
{
	return _uiSkeletonID;
}
