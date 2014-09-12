#include "stdafx.h"
#include "CarouselItem.h"

CarouselItem::CarouselItem()
{
	_pGraphicsTexture = 0;
}

CarouselItem::~CarouselItem()
{
	if( _pGraphicsTexture ) delete _pGraphicsTexture;
}

void CarouselItem::Draw()
{
	glPushMatrix();

	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, _pGraphicsTexture->GetTexture() );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

	glRotatef( _pRotation->y(), 0.0f, 1.0f, 0.0f );	

	glTranslatef( _pPosition->x(), _pPosition->y(), _pPosition->z() );	
	

	glBegin( GL_QUADS );	

	glColor3f( 1.0f, 1.0f, 1.0f );
	glNormal3f( 0.0, 0.0f, 1.0f);

	float fXVal = ( float ) _pGraphicsTexture->_SpriteDimentions.width / ( float ) _pGraphicsTexture->_TextureDimentions.width;
	float fYVal = ( float ) _pGraphicsTexture->_SpriteDimentions.height / ( float ) _pGraphicsTexture->_TextureDimentions.height - 0.01;

	glTexCoord2f( fXVal, 0.0f );
	glVertex3f( -_pWidthHeightDepth->x(), -_pWidthHeightDepth->y(), _pWidthHeightDepth->z() );
	glTexCoord2f( 0.0f, 0.0f );
	glVertex3f( _pWidthHeightDepth->x(), -_pWidthHeightDepth->y(), _pWidthHeightDepth->z() );
	glTexCoord2f( 0.0f, fYVal);
	glVertex3f( _pWidthHeightDepth->x(), _pWidthHeightDepth->y(), _pWidthHeightDepth->z() );
	glTexCoord2f( fXVal, fYVal );
	glVertex3f( -_pWidthHeightDepth->x(), _pWidthHeightDepth->y(), _pWidthHeightDepth->z() );

	glEnd();

	glDisable( GL_TEXTURE_2D );

	glPopMatrix();
}