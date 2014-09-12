#ifndef _CAROUSEL_
#define _CAROUSEL_

#include "stdafx.h"
#include "CarouselItem.h"
#include "DrawableObject.h"
#include <MCIVUtilities/BodyDefs.h>
#include <MCIVUtilities/Vector3f.h>
#include <MCIVUtilities/HumainBody.h>
#include <boost\filesystem.hpp>

typedef vector<CarouselItem*> CarouselItemList;

using namespace std;

class Carousel : public DrawableObject
{

public:

	Carousel();
	virtual ~Carousel();

	void LoadItems();
	void Rotate( GLfloat fAngleIncreate );
	virtual void Draw();
	void ZoomCarousel( HumainBody* pBody );
	void ResetHandMagnitude();
	void ResetRotation();
	void RotateCarousel( HumainBody* pBody );
	void Update();

	GLfloat GetRadious();

protected:

	CarouselItemList* _pItemList;

	void CalculatePositions();	

	GLfloat _fImageAngle;
	GLfloat _fHandMagnitude;
	GLfloat _fRadious;
	GLfloat _fRotationSpeed;
};

#endif