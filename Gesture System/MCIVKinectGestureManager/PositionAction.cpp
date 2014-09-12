#include "stdafx.h"
#include "PositionAction.h"

PositionAction::PositionAction( string sName, float uiTimout, GMbodypart gmbBodyPart, GMrelationship gmrRelationship, GMbodypart gmbRelationBodyPart, float fUperComparisonDistance,
								float fLowerComparisonDistance ) : Action( sName, uiTimout, gmbBodyPart )
{
	_gmrRelationship = gmrRelationship;
	_fUperComparisonDistance = fUperComparisonDistance;
	_fLowerComparisonDistance = fLowerComparisonDistance;
	_gmbRelationBodyPart = gmbRelationBodyPart;
}

PositionAction::~PositionAction()
{

}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Accept
Description: if the gmbBodyPart part and the relationBodyPart have the correct relationship
			 ( this is determined by body part value comparisons ) and they are within the 
			 constraints then return true and fire event in assigned gesture
-------------------------------------------------------------------------------------------*/
bool PositionAction::Accept()
{
	//switch to determin function for relationship;
	bool bOutcome = false;

	switch ( _gmrRelationship )
	{
		case RELATIONSHIP_TO_THE_LEFT_OF: bOutcome = ToTheLeftOf(); break;
		case RELATIONSHIP_TO_THE_RIGHT_OF: bOutcome = ToTheRightOf(); break;
		case RELATIONSHIP_INFRONT : bOutcome = InFront();break;
		case RELATIONSHIP_BEHIND : bOutcome = Behind();break;
		case RELATIONSHIP_ABOVE : bOutcome = Above();break;
		case RELATIONSHIP_BELOW : bOutcome = Below();break;
		case RELATIONSHIP_TOGETHER : bOutcome = Together();break;
		case RELATIONSHIP_APART_FROM: bOutcome = Apart();break;
		default:bOutcome = false;
	}

	if( bOutcome )
	{		
		_pGestureAssignedTo->fireGestureEvent( _sName );
	}

	return bOutcome;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: ToTheLeftOf
Description: Compare both body part X axis positions, returns true if FirstBodyPart is less than 
			 SecondBodyPart and the positive (fabs) distance is less than Comparison distance.
-------------------------------------------------------------------------------------------*/
bool PositionAction::ToTheLeftOf()
{
	bool bReturn = false;		

	HumainBody* pBody = GetBodyData();
	
	if( pBody != NULL )
	{
		float fFirstPos = pBody->GetBodyPart( _gmbBodyPart )->getPosition()[0];
		float fSecondPos = pBody->GetBodyPart( _gmbRelationBodyPart )->getPosition()[0];

		float fAdded = ( fFirstPos - fSecondPos );

		if( fFirstPos < fSecondPos )
		{
			if( fabs( fAdded ) > _fLowerComparisonDistance && fabs( fAdded ) < _fUperComparisonDistance )
			{
				bReturn = true;
			}			
		}
	}	

	return bReturn;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: ToTheRightOf
Description: Compare both body part X axis positions, returns true if FirstBodyPart is greater than 
			 SecondBodyPart and the positive (fabs) distance is less than Comparison distance.
-------------------------------------------------------------------------------------------*/
bool PositionAction::ToTheRightOf()
{
	bool bReturn = false;	
	HumainBody* pBody = GetBodyData();

	if( pBody != NULL )
	{
		float fFirstPos = pBody->GetBodyPart( _gmbBodyPart )->getPosition()[0];
		float fSecondPos = pBody->GetBodyPart( _gmbRelationBodyPart )->getPosition()[0];

		float fAdded = ( fFirstPos - fSecondPos );

		if( fFirstPos > fSecondPos )
		{
			if( fabs( fAdded ) > _fLowerComparisonDistance && fabs( fAdded ) < _fUperComparisonDistance )
			{
				bReturn = true;
			}			
		}
	}	

	return bReturn;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: InFront
Description: Compare both body part Z axis positions, returns true if FirstBodyPart is less than 
			 SecondBodyPart and the positive (fabs) distance is less than Comparison distance.
-------------------------------------------------------------------------------------------*/
bool PositionAction::InFront()
{
	bool bReturn = false;	
	HumainBody* pBody = GetBodyData();

	if( pBody != NULL )
	{
		float fFirstPos = pBody->GetBodyPart( _gmbBodyPart )->getPosition()[2];
		float fSecondPos = pBody->GetBodyPart( _gmbRelationBodyPart )->getPosition()[2];

		float fAdded = ( fFirstPos - fSecondPos );

		if( fFirstPos < fSecondPos )
		{
			if( fabs( fAdded ) > _fLowerComparisonDistance && fabs( fAdded )< _fUperComparisonDistance )
			{
				bReturn = true;
			}			
		}
	}	

	return bReturn;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Behind
Description: Compare both body part Z axis positions, returns true if FirstBodyPart is greater than 
			 SecondBodyPart and the positive (fabs) distance is less than Comparison distance.
-------------------------------------------------------------------------------------------*/
bool PositionAction::Behind()
{
	bool bReturn = false;	
	HumainBody* pBody = GetBodyData();

	if( pBody != NULL )
	{
		float fFirstPos = pBody->GetBodyPart( _gmbBodyPart )->getPosition()[2];
		float fSecondPos = pBody->GetBodyPart( _gmbRelationBodyPart )->getPosition()[2];

		float fAdded = ( fFirstPos - fSecondPos );

		if( fFirstPos > fSecondPos )
		{
			if( fabs( fAdded ) > _fLowerComparisonDistance && fabs( fAdded ) < _fUperComparisonDistance )
			{
				bReturn = true;
			}			
		}
	}	

	return bReturn;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Above
Description: Compare both body part Y axis positions, returns true if FirstBodyPart is greater than 
			 SecondBodyPart and the positive (fabs) distance is less than Comparison distance.
-------------------------------------------------------------------------------------------*/
bool PositionAction::Above()
{
	bool bReturn = false;	
	HumainBody* pBody = GetBodyData();

	if( pBody != NULL )
	{
		float fFirstPos = pBody->GetBodyPart( _gmbBodyPart )->getPosition()[1];
		float fSecondPos = pBody->GetBodyPart( _gmbRelationBodyPart )->getPosition()[1];

		float fAdded = ( fFirstPos - fSecondPos );

		if( fFirstPos > fSecondPos )
		{
			if( fabs( fAdded ) > _fLowerComparisonDistance && fabs( fAdded ) < _fUperComparisonDistance )
			{
				bReturn = true;
			}			
		}
	}	

	return bReturn;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Below
Description: Compare both body part Y axis positions, returns true if FirstBodyPart is less than 
			 SecondBodyPart and the positive (fabs) distance is less than Comparison distance.
-------------------------------------------------------------------------------------------*/
bool PositionAction::Below()
{
	bool bReturn = false;	
	HumainBody* pBody = GetBodyData();

	if( pBody != NULL )
	{
		float fFirstPos = pBody->GetBodyPart( _gmbBodyPart )->getPosition()[1];
		float fSecondPos = pBody->GetBodyPart( _gmbRelationBodyPart )->getPosition()[1];

		float fAdded = ( fFirstPos - fSecondPos );

		if( fFirstPos < fSecondPos )
		{
			if( fabs( fAdded ) > _fLowerComparisonDistance && fabs( fAdded ) < _fUperComparisonDistance )
			{
				bReturn = true;
			}			
		}
	}	

	return bReturn;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Apart
Description: Creates a distance vector by subtracting the two points then compares the vector magnitude 
			 to the ComparisonDistance. Returns true if magnitude is greater.
-------------------------------------------------------------------------------------------*/
bool PositionAction::Apart()
{
	bool bReturn = false;	
	HumainBody* pBody = GetBodyData();

	if( pBody != NULL )
	{
		const float* fFirstPos = pBody->GetBodyPart( _gmbBodyPart )->getPosition();
		const float* fSecondPos = pBody->GetBodyPart( _gmbRelationBodyPart )->getPosition();

		Vector3f* vDst = new Vector3f( fabs( fFirstPos[0] - fSecondPos[0] ), fabs( fFirstPos[1] - fSecondPos[1] ), fabs( fFirstPos[2] - fSecondPos[2] ) );	

		if( vDst->magnitude() > _fLowerComparisonDistance  && vDst->magnitude() < _fUperComparisonDistance ) 
		{
			bReturn = true;
		}

		delete vDst;
	}

	return bReturn;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Together
Description: Creates a distance vector by subtracting the two points then compares the vector magnitude 
			 to the ComparisonDistance. Returns true if magnitude is smaller.
-------------------------------------------------------------------------------------------*/
bool PositionAction::Together()
{
	bool bReturn = false;	
	HumainBody* pBody = GetBodyData();

	if( pBody != NULL )
	{
		const float* fFirstPos = pBody->GetBodyPart( _gmbBodyPart )->getPosition();
		const float* fSecondPos = pBody->GetBodyPart( _gmbRelationBodyPart )->getPosition();

		Vector3f* vDst = new Vector3f( fabs( fFirstPos[0] - fSecondPos[0] ), fabs( fFirstPos[1] - fSecondPos[1] ), fabs( fFirstPos[2] - fSecondPos[2] ) );				

		//cout << "First: " << fFirstPos[1] << " Second: " << fSecondPos[1] << " Mag: " << vDst->magnitude() << "\n";

		if( vDst->magnitude() > _fLowerComparisonDistance  && vDst->magnitude() < _fUperComparisonDistance )
		{
			bReturn = true;
		}

		delete vDst;
	}

	return bReturn;
}