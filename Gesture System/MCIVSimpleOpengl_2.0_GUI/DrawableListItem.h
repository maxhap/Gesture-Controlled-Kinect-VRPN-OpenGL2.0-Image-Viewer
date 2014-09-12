#ifndef _DRAWABLELISTITEM_
#define _DRAWABLELISTITEM_

#include "stdafx.h"
#include "DrawableObject.h"
#include "MaxRectangle.h"

class DrawableListItem : public DrawableObject
{

public:

	DrawableListItem();
	virtual ~DrawableListItem();

	void SetIsSelected( bool bSelected );
	void SetSelectedTexture( GraphicsTexture* _pTexture);	

	virtual void Interact();
	virtual void Draw();
	virtual void ProceedActivation();

	bool SelectColision( MaxRectangle* pColisionBox );


protected:

	bool _bSelected;
	
	unsigned int _uiActivationStage;
	
	GraphicsTexture* _pSelectedTexture;


};
#endif