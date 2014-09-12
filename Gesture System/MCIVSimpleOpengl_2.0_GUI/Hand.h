#ifndef _HAND_
#define _HAND_

#include <MCIVStateController/MCIVStateController.h>
#include "stdafx.h"
#include "DrawableObject.h"

class Hand : public DrawableObject
{

public: 
	
	Hand();
	virtual ~Hand();

	void SetTimeingStage( unsigned int uiTimingStage );
	void SetAditionalTextures( GraphicsTexture* pQuater, GraphicsTexture* pHalf, GraphicsTexture* pThreeQuater, GraphicsTexture* pFull );
	unsigned int GetTimeingStage();

	virtual void Draw();

private:

	unsigned int _uiTimingStage;
	
	GraphicsTexture* _pQuaterTexture;
	GraphicsTexture* _pHalfTexture;
	GraphicsTexture* _pThreeQuaterTexture;
	GraphicsTexture* _pFullTexture;

};


#endif