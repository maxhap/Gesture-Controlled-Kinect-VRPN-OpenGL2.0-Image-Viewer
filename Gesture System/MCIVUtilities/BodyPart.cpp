#include "stdafx.h"
#include "BodyPart.h"

BodyPart::BodyPart()
{
	_pfPosition = new float[4];
	_pfPosition[0] = 0.0f;
	_pfPosition[1] = 0.0f;
	_pfPosition[2] = 0.0f;
	_pfPosition[3] = 0.0f;

	_fVelocity = 0.0f;	

	_ptUpdateTimer = new boost::timer();
}

BodyPart::~BodyPart()
{
	delete _pfPosition;
	delete _ptUpdateTimer;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: setPosition
Description: Set the position and velocity of the body part, velocity calculated by taking the 
			 magnitude of the new and last position then dividing it by the update time
-------------------------------------------------------------------------------------------*/
void BodyPart::setPosition( float* pfNewPos )
{
	float dTimeElapsed = ( float) _ptUpdateTimer->elapsed();

	Vector3f vDistance( _pfPosition[0] - pfNewPos[0] , _pfPosition[1] - pfNewPos[1], _pfPosition[2] -  pfNewPos[2] );	
	float fMagnitude = vDistance.magnitude();

	//velocity = distance over time
	_fVelocity = fMagnitude / dTimeElapsed;

	_ptUpdateTimer->restart();

	_pfPosition[0] = pfNewPos[0];
	_pfPosition[1] = pfNewPos[1];
	_pfPosition[2] = pfNewPos[2];
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: getPosition
Description: return vector as flaot pointer array_pfPosition
-------------------------------------------------------------------------------------------*/
const float* BodyPart::getPosition()
{
	return _pfPosition;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: getVelocity
Description: return velocity as float
-------------------------------------------------------------------------------------------*/
const float BodyPart::getVelocity()
{
	return _fVelocity;
}


