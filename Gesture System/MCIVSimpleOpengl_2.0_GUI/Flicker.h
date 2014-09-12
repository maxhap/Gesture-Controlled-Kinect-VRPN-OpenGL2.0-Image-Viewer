#ifndef _FLICKER_
#define _FLICKER_

#include "stdafx.h"
#include "DrawableObject.h"
#include "FlickerItem.h"
#include <MCIVUtilities/BodyDefs.h>
#include <MCIVUtilities/Vector3f.h>
#include <MCIVUtilities/HumainBody.h>
#include <boost\filesystem.hpp>

class Flicker
{
public:

	Flicker();
	virtual ~Flicker();

	void LoadItems();
	void Draw();
	void NextImage();
	void PreviousImage();
	FlickerItem* GetCurrentImage();

protected:

	vector<FlickerItem*>* _pItemList; 
	int _iSelectedImageNumber;

};

#endif