#include "stdafx.h"
#include "DrawableListItem.h"


DrawableListItem::DrawableListItem()
{
	_bSelected = false;
}

DrawableListItem::~DrawableListItem()
{
	if( _pSelectedTexture ) delete _pSelectedTexture;
}

void DrawableListItem::SetIsSelected( bool bSelected )
{
	_bSelected = bSelected;
}

void DrawableListItem::SetSelectedTexture( GraphicsTexture* _pTexture )
{
	_pSelectedTexture = _pTexture;
}

void DrawableListItem::Interact()
{

}

void DrawableListItem::Draw()
{
	GLuint uiTexture = 0;

	if( _bSelected )
	{
		uiTexture = _pSelectedTexture->GetTexture();
	}
	else 
	{
		uiTexture = _pGraphicsTexture->GetTexture();
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

bool DrawableListItem::SelectColision( MaxRectangle* pColisionBox )
{
	float fHalfWidth = _pWidthHeightDepth->x() / 2;
	float fHalfHeight = _pWidthHeightDepth->y() / 2;

	float thisItemL = _pPosition->x() - fHalfWidth;
	float thisItemT = _pPosition->y() - fHalfHeight;
	float thisItemR = _pPosition->x() + fHalfWidth;
	float thisItemB = _pPosition->y() + fHalfHeight;

	//detect from other game item
	if( pColisionBox != NULL )
	{
		float otherItemL = pColisionBox->x;
		float otherItemT = pColisionBox->y;
		float otherItemR = pColisionBox->x + pColisionBox->w;
		float otherItemB = pColisionBox->y + pColisionBox->h;

		if( thisItemL > otherItemR )
		{
			return false;
		}

		if( thisItemR < otherItemL )
		{
			return false;
		}

		if( thisItemT > otherItemB )
		{
			return false;
		}

		if( thisItemB < otherItemT )
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	return true;
}

void DrawableListItem::ProceedActivation()
{

}
