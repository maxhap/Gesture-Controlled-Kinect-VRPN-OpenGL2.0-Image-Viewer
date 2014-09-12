#include "stdafx.h"
#include "Carousel.h"

namespace fs = boost::filesystem;

Carousel::Carousel() : DrawableObject()
{
	_pItemList = new CarouselItemList();
	_fHandMagnitude = 0.0f;
	_fRotationSpeed = 0.0f;
}

Carousel::~Carousel()
{
	if( _pItemList )
	{
		for( CarouselItemList::iterator i = _pItemList->begin(); i != _pItemList->end(); i++ )
		{
			delete ( *i );
		}

		delete _pItemList;
	}
}

void Carousel::LoadItems()
{	
	fs::path someDir( Initialize::CarouselImagesLocation );
	fs::directory_iterator end_iter;

	vector<fs::path> files;

	if ( fs::exists( someDir ) && fs::is_directory( someDir ) )
	{
		for( fs::directory_iterator dir_iter( someDir ) ; dir_iter != end_iter ; ++dir_iter)
		{
			if ( fs::is_regular_file( dir_iter->status() ) )
			{
				files.push_back( ( * dir_iter ) );
			}
		}
	}

	for( vector<fs::path>::iterator i = files.begin(); i != files.end(); i++ )
	{
		CarouselItem* pCarItem = new CarouselItem();
		pCarItem->SetWidthHeightDepth( Initialize::CarouselImageWidth, Initialize::CarouselImageHeight, 0.1f );		

		GraphicsTexture* pGT = ImageLoader::instance().LoadGL( ( *i ).string() );
		
		if( pGT != NULL )
		{
			pCarItem->SetTexture( pGT );
			_pItemList->push_back( pCarItem );
		}		
	}

	CalculatePositions();

	//set carousel position so visible to camera
	this->SetPosition( 0.0f, 0.0f, -( GetRadious() + 4.0f ) );
}

void Carousel::CalculatePositions()
{
	_fImageAngle = 360.0f / _pItemList->size();

	_fRadious = ( ( Initialize::CarouselImageWidth / 2 * 5 ) / tan( _fImageAngle * M_PI / 180.0 ) );

	int iPosition = 0;
	for( CarouselItemList::iterator i = _pItemList->begin(); i != _pItemList->end(); i++, iPosition++ )
	{
		float fRotation = _fImageAngle * iPosition;
		( *i )->SetRotation( 0.0f, fRotation, 0.0f );
		( *i )->SetPosition( 0.0f, 0.0f, -_fRadious ); 
	}
}

void Carousel::Draw()
{
	glPushMatrix();	

	glTranslatef( _pPosition->x(), _pPosition->y(), _pPosition->z() );

	glRotatef( _pRotation->x(), 1.0f, 0.0f, 0.0f );
	glRotatef( _pRotation->y(), 0.0f, 1.0f, 0.0f );
	glRotatef( _pRotation->z(), 0.0f, 0.0f, 1.0f );

	

	for( CarouselItemList::iterator i = _pItemList->begin(); i != _pItemList->end(); i++ )
	{
		( *i )->Draw();
	}

	glPopMatrix();
}

void Carousel::Rotate( GLfloat fAngleIncreate )
{
	float  fRotation = _pRotation->y() + fAngleIncreate;

	if( fRotation > 360 )
	{
		fRotation = fRotation - 360;
	}

	if(  fRotation < 0 )
	{
		fRotation = 360 - fRotation;
	}

	_pRotation->y( fRotation );
}

void Carousel::ZoomCarousel( HumainBody* pBody )
{
	const float* fFirstPos = pBody->GetBodyPart( BODY_PART_rightHand )->getPosition();
	const float* fSecondPos = pBody->GetBodyPart( BODY_PART_leftHand )->getPosition();

	Vector3f* vDst = new Vector3f( fabs( fFirstPos[0] - fSecondPos[0] ), fabs( fFirstPos[1] - fSecondPos[1] ), fabs( fFirstPos[2] - fSecondPos[2] ) );

	if( _fHandMagnitude == 0.0f )
	{

		_fHandMagnitude = vDst->magnitude();
	}

	GLfloat fZoom = vDst->magnitude() - _fHandMagnitude;
	fZoom = fZoom * 100;

	if( fZoom < -( GetRadious() + 3.0f ) )
	this->SetPosition( this->GetPosition()->x(), this->GetPosition()->y(), fZoom );
	
}

void Carousel::ResetHandMagnitude()
{
	_fHandMagnitude = 0.0f;	
}

GLfloat Carousel::GetRadious()
{
	return _fRadious;
}

void Carousel::RotateCarousel( HumainBody* pBody )
{
	const float* fFirstPos = pBody->GetBodyPart( BODY_PART_rightHand )->getPosition();
	const float* fSecondPos = pBody->GetBodyPart( BODY_PART_tourso )->getPosition();

	Vector3f* vDst = new Vector3f( ( fFirstPos[0] - fSecondPos[0] ), ( fFirstPos[1] - fSecondPos[1] ), 0.0f );

	_fRotationSpeed = ( fFirstPos[0] > fSecondPos[0] ) ? vDst->magnitude() : -vDst->magnitude();	

	if( fabs( _fRotationSpeed ) < 0.3f ) _fRotationSpeed = 0.0f;
}

void Carousel::Update()
{
	Rotate( _fRotationSpeed );
}

void Carousel::ResetRotation()
{
	_fRotationSpeed = 0.0f;
}
