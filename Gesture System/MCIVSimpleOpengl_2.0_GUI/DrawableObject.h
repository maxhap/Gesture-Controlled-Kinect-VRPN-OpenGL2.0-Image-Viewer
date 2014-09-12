#ifndef _DRAWABLEOBJECT_
#define  _DRAWABLEOBJECT_

#include "stdafx.h"
#include "MaxRectangle.h"

class DrawableObject
{

public:

	DrawableObject();
	virtual ~DrawableObject();

	Vector3f* GetPosition();
	Vector3f* GetRotation();
	Vector3f* GetWidthHeighDepth();

	void SetPosition( GLfloat fX, GLfloat fY, GLfloat fZ );
	void SetRotation( GLfloat fX, GLfloat fY, GLfloat fZ );
	void SetWidthHeightDepth( GLfloat fX, GLfloat fY, GLfloat fZ );

	void SetTexture( GraphicsTexture* pGraphicsTexture );

	virtual void Draw();

protected:

	Vector3f* _pPosition;
	Vector3f* _pRotation;
	Vector3f* _pWidthHeightDepth;

	GraphicsTexture* _pGraphicsTexture;
};

#endif