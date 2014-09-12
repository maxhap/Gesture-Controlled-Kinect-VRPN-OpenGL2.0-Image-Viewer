#include "stdafx.h"
#include "Hand.h"

Hand::Hand()
{
	_uiTimingStage = 0;
}

Hand::~Hand()
{
	if( _pQuaterTexture ) delete _pQuaterTexture;
	if( _pHalfTexture ) delete _pHalfTexture;
	if( _pThreeQuaterTexture ) delete _pThreeQuaterTexture;
	if( _pFullTexture ) delete _pFullTexture;
}

void Hand::SetTimeingStage( unsigned int uiTimingStage )
{
	_uiTimingStage = uiTimingStage;
}

unsigned int Hand::GetTimeingStage()
{
	return _uiTimingStage;
}

void Hand::SetAditionalTextures( GraphicsTexture* pQuater, GraphicsTexture* pHalf, GraphicsTexture* pThreeQuater, GraphicsTexture* pFull )
{
	_pQuaterTexture = pQuater;
	_pHalfTexture = pHalf;
	_pThreeQuaterTexture = pThreeQuater;
	_pFullTexture = pFull;
}

void Hand::Draw()
{
	GLuint uiTexture = 0;

	switch( MCIVStateController::instance().GetHandState() )
	{
		case 0: uiTexture = _pGraphicsTexture->GetTexture(); break;
		case 1: uiTexture = _pQuaterTexture->GetTexture(); break;
		case 2: uiTexture = _pHalfTexture->GetTexture(); break;
		case 3: uiTexture = _pThreeQuaterTexture->GetTexture(); break;
		case 4: uiTexture = _pFullTexture->GetTexture(); break;
	}

	glPushMatrix();

	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, uiTexture );
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

