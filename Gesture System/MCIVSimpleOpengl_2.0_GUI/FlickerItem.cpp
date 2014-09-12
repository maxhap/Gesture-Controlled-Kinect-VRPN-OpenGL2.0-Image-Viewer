#include "stdafx.h"
#include "FlickerItem.h"

FlickerItem::FlickerItem() : DrawableObject()
{
	_fZoomLevel = 1.0f;
	_fYPanAmount = 0.0f;
	_fXPanAmount = 0.0f;

	_fPanDistance = 1.0f;
}

FlickerItem::~FlickerItem()
{

}

void FlickerItem::Draw()
{
	glPushMatrix();

	glTranslatef( _fXPanAmount, _fYPanAmount, 0.0f );

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
	glVertex3f( -_pWidthHeightDepth->x() * _fZoomLevel, -_pWidthHeightDepth->y() * _fZoomLevel, _pWidthHeightDepth->z() );
	glTexCoord2f( fXVal, 0.0f );
	glVertex3f( _pWidthHeightDepth->x() * _fZoomLevel, -_pWidthHeightDepth->y() * _fZoomLevel, _pWidthHeightDepth->z() );
	glTexCoord2f( fXVal, fYVal);
	glVertex3f( _pWidthHeightDepth->x() * _fZoomLevel, _pWidthHeightDepth->y() * _fZoomLevel, _pWidthHeightDepth->z() );
	glTexCoord2f( 0.0f, fYVal );
	glVertex3f( -_pWidthHeightDepth->x() * _fZoomLevel, _pWidthHeightDepth->y() * _fZoomLevel, _pWidthHeightDepth->z() );

	glEnd();

	glDisable( GL_TEXTURE_2D );

	glPopMatrix();
}

void FlickerItem::ZoomIn()
{
	_fZoomLevel += 0.5;
}

void FlickerItem::ZoomOut()
{
	_fZoomLevel -= 0.5;
}

void FlickerItem::PanUp()
{
	_fYPanAmount -= _fPanDistance;
}

void FlickerItem::PanDown()
{
	_fYPanAmount += _fPanDistance;
}

void FlickerItem::PanLeft()
{
	_fXPanAmount -= _fPanDistance;
}

void FlickerItem::PanRight()
{
	_fXPanAmount += _fPanDistance;
}
