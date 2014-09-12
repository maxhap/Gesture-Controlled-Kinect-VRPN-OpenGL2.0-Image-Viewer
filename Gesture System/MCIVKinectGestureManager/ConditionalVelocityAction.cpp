#include "stdafx.h"
#include "ConditionalVelocityAction.h"

ConditionalVelocityAction::ConditionalVelocityAction( string sName, float uiTimout, GMbodypart uiBodyPart, GMrelationship gmrVelcoityRelationship, GMbodypart gmConditionBodyPart, 
												      GMrelationship gmrConditionRelationship, float fSpeed, AndAction* paPass ) 
	: VelocityAction( sName, uiTimout, uiBodyPart, gmrVelcoityRelationship, fSpeed )
{
	_gmConditionBodyPart = gmConditionBodyPart;
	_paPass = paPass;
	_gmrConditionalRelationship = gmrConditionRelationship;
	_fLastMagnitude = 0;
}

ConditionalVelocityAction::~ConditionalVelocityAction()
{
	if ( _paPass ) delete _paPass;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: towards
Description: Creates a velocity object by subtracting first body part position form the second
			 then store the magnitude in _fLastMagnitude for < comparison next time round.
-------------------------------------------------------------------------------------------*/
bool ConditionalVelocityAction::towards()
{
	bool bReturn = false;	

	HumainBody* pBody = GetBodyData();

	if( pBody != NULL )
	{
		const float* bpFirst = pBody->GetBodyPart( _gmbBodyPart )->getPosition();
		const float* bpSecond = pBody->GetBodyPart( _gmConditionBodyPart )->getPosition();

		Vector3f vDistance( bpFirst[0] - bpSecond[0], bpFirst[1] - bpSecond[1], bpFirst[2] -  bpSecond[2] );	
		float fMagnitude = vDistance.magnitude();

		if( fMagnitude  < _fLastMagnitude )
		{				
			bReturn = true;
		}	

		_fLastMagnitude = fMagnitude;
	}

	return bReturn;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: away
Description: Creates a velocity object by subtracting first body part position form the second
			 then store the magnitude in _fLastMagnitude for > comparison next time round.
-------------------------------------------------------------------------------------------*/
bool ConditionalVelocityAction::away()
{
	bool bReturn = false;	

	HumainBody* pBody = GetBodyData();

	if( pBody != NULL )
	{
		const float* bpFirst = pBody->GetBodyPart( _gmbBodyPart )->getPosition();
		const float* bpSecond = pBody->GetBodyPart( _gmConditionBodyPart )->getPosition();

		Vector3f vDistance( bpFirst[0] - bpSecond[0], bpFirst[1] - bpSecond[1], bpFirst[2] -  bpSecond[2] );	
		
		float fMagnitude = vDistance.magnitude();

		if( fMagnitude  > _fLastMagnitude )
		{
			_fLastMagnitude = fMagnitude;
			bReturn = true;
		}		
	}

	return bReturn;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Accept
Description: Using two switch statement to determine the action state. First switch will 
			 determine correct velocity, the second determines the if the direction of the body
			 part is correct. If both velocity and direction are correct event is fired but 
			 for the action to end the assigned pass action must be true.
-------------------------------------------------------------------------------------------*/
bool ConditionalVelocityAction::Accept()
{
	bool bOutcome = false;

	switch ( _gmrRelationship )
	{
	case RELATIONSHIP_LESS_THAN: bOutcome = LessThan(); break;
	case RELATIONSHIP_GREATER_THAN: bOutcome = GreaterThan(); break;
	default: bOutcome = false;
	}

	if( bOutcome )
	{
		switch( _gmrConditionalRelationship )
		{
		case RELATIONSHIP_TOWARDS: bOutcome = towards(); break;
		case RELATIONSHIP_AWAY: bOutcome = away(); break;
		default:bOutcome = false;
		}
	}
	
	//fire if moving in right direction at right velocity
	if( bOutcome )
	{		
		_pGestureAssignedTo->fireGestureEvent( _sName );

		//check for end of gesture
		bOutcome = _paPass->Accept();		
	}	
	return bOutcome;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Accept
Description: Call inherited function from action to set gesture for this action and then 
			 set the gesture for the held pass action
-------------------------------------------------------------------------------------------*/
void ConditionalVelocityAction::SetGestureAssignedTo( Gesture* pGesture )
{
	Action::SetGestureAssignedTo( pGesture );

	_paPass->SetGestureAssignedTo( pGesture );
}