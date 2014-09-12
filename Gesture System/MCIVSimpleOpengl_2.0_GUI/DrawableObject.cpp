#include "stdafx.h"
#include "DrawableObject.h"


DrawableObject::DrawableObject()
{
	_pPosition = new Vector3f();
	_pRotation = new Vector3f();
	_pWidthHeightDepth = new Vector3f();
}

DrawableObject::~DrawableObject()
{
	if( _pPosition ) delete _pPosition;
	if( _pRotation ) delete _pRotation;
	if( _pWidthHeightDepth ) delete _pWidthHeightDepth;
}

Vector3f* DrawableObject::GetPosition()
{
	return _pPosition;
}

Vector3f* DrawableObject::GetRotation()
{
	return _pRotation;
}

Vector3f* DrawableObject::GetWidthHeighDepth()
{
	return _pWidthHeightDepth;
}

void DrawableObject::SetPosition( GLfloat fX, GLfloat fY, GLfloat fZ )
{
	_pPosition->set( fX, fY, fZ );	
}

void DrawableObject::SetRotation( GLfloat fX, GLfloat fY, GLfloat fZ )
{
	_pRotation->set( fX, fY, fZ );
}

void DrawableObject::SetWidthHeightDepth( GLfloat fX, GLfloat fY, GLfloat fZ )
{
	_pWidthHeightDepth->set( fX, fY, fZ );
}

void DrawableObject::Draw()
{
	glPushMatrix();

	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, _pGraphicsTexture->GetTexture() );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

	glTranslatef( _pPosition->x(), _pPosition->y(), _pPosition->z() );	
	
	glRotatef( _pRotation->x(), 1.0f, 0.0f, 0.0f );
	glRotatef( _pRotation->y(), 0.0f, 1.0f, 0.0f );
	glRotatef( _pRotation->z(), 0.0f, 0.0f, 1.0f );		

	glBegin( GL_QUADS );	

	glColor3f( 1.0f, 1.0f, 1.0f );
	glNormal3f( 0.0, 0.0f, 1.0f);

	float fXVal = ( float ) _pGraphicsTexture->_SpriteDimentions.width / ( float ) _pGraphicsTexture->_TextureDimentions.width;
	float fYVal = ( float ) _pGraphicsTexture->_SpriteDimentions.height / ( float ) _pGraphicsTexture->_TextureDimentions.height - 0.01;

	glTexCoord2f( 0.0f, 0.0f );
	glVertex3f( -_pWidthHeightDepth->x(), -_pWidthHeightDepth->y(), _pWidthHeightDepth->z() );
	glTexCoord2f( fXVal, 0.0f );
	glVertex3f( _pWidthHeightDepth->x(), -_pWidthHeightDepth->y(), _pWidthHeightDepth->z() );
	glTexCoord2f( fXVal, fYVal);
	glVertex3f( _pWidthHeightDepth->x(), _pWidthHeightDepth->y(), _pWidthHeightDepth->z() );
	glTexCoord2f( 0.0f, fYVal );
	glVertex3f( -_pWidthHeightDepth->x(), _pWidthHeightDepth->y(), _pWidthHeightDepth->z() );

	glEnd();

	glDisable( GL_TEXTURE_2D );

	glPopMatrix();
}

void DrawableObject::SetTexture( GraphicsTexture* pGraphicsTexture )
{
	_pGraphicsTexture = pGraphicsTexture;
}
