#ifndef _BODYPART_
#define _BODYPART_

#include <boost/timer.hpp>
#include "Vector3f.h"
#include "MCIVUtilitiesDEFS.h"

class MCIVUTILITIES_DLL_DEF BodyPart
{

public:
	BodyPart();
	virtual ~BodyPart();

	void setPosition( float* pfNewPos );	

	const float* getPosition();	
	const float getVelocity();

private:

	boost::timer* _ptUpdateTimer;
	float* _pfPosition;	
	float _fVelocity;
};
#endif