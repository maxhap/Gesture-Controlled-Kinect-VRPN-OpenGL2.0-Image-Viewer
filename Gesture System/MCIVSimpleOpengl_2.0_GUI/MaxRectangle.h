#ifndef _MaxRectangle_
#define _MaxRectangle_

#include "stdafx.h"

class MaxRectangle
{

public:

	MaxRectangle();
	MaxRectangle( float x, float y, float w, float h );
	~MaxRectangle();

	float x;
	float y;
	float w;
	float h;

protected:


};

#endif