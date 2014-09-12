#ifndef _FLICKERITEM_
#define _FLICKERITEM_

#include "stdafx.h"
#include "DrawableObject.h"

class FlickerItem : public DrawableObject
{
	
public:

	FlickerItem();
	virtual ~FlickerItem();

	virtual void Draw();

	void ZoomIn();
	void ZoomOut();
	void PanUp();
	void PanDown();
	void PanLeft();
	void PanRight();

protected:

	float _fPanDistance;

	GLfloat _fZoomLevel;
	GLfloat _fXPanAmount;
	GLfloat _fYPanAmount;

};
#endif