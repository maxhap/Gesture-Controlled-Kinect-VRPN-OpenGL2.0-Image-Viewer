#include "stdafx.h"
#include "VelocityAction.h"

VelocityAction::VelocityAction( string sName, float uiTimout, unsigned int uiBodyPart, GMrelationship gmrRelationship, float fSpeed ) : Action( sName, uiTimout, uiBodyPart )
{
	_gmrRelationship = gmrRelationship;
	_fSpeed = fSpeed;
}

VelocityAction::~VelocityAction()
{

}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Accept
Description: if the gmbBodyPart part and the relationBodyPart have the correct relationship
			 ( this is determined by body part velocity comparison ) and they are within the 
			 constraints then return true and fire event in assigned gesture
-------------------------------------------------------------------------------------------*/
bool VelocityAction::Accept()
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
		_pGestureAssignedTo->fireGestureEvent( _sName );
	}

	return bOutcome;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: GreaterThan
Description: Compared the body parts velocity to the comparison speed and returns true if it is greater
-------------------------------------------------------------------------------------------*/
bool VelocityAction::GreaterThan()
{
	bool bReturn = false;	
	HumainBody* pBody = GetBodyData();

	if( pBody != NULL )
	{
		float fFirstVel = pBody->GetBodyPart( _gmbBodyPart )->getVelocity();

		if( fFirstVel > _fSpeed )
		{
			bReturn = true;
		}
	}

	return bReturn;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: LessThan
Description: Compared the body parts velocity to the comparison speed and returns true if it is less than
-------------------------------------------------------------------------------------------*/
bool VelocityAction::LessThan()
{
	bool bReturn = false;	
	HumainBody* pBody = GetBodyData();

	if( pBody != NULL )
	{
		float fFirstVel = pBody->GetBodyPart( _gmbBodyPart )->getVelocity();

		if( fFirstVel < _fSpeed )
		{
			bReturn = true;
		}
	}

	return bReturn;
}
