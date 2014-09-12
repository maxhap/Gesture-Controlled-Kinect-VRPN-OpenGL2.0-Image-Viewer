#include "stdafx.h"
#include "Flicker.h"

namespace fs = boost::filesystem;

Flicker::Flicker()
{
	_pItemList = new vector<FlickerItem*>();
	_iSelectedImageNumber = 0;
}

Flicker::~Flicker()
{
	if( _pItemList ) delete _pItemList;
}

void Flicker::LoadItems()
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
		FlickerItem* pCarItem = new FlickerItem();
		pCarItem->SetWidthHeightDepth( Initialize::CarouselImageWidth, Initialize::CarouselImageHeight, 0.1f );		
		pCarItem->SetPosition( 0.0f, 0.0f, -5.0f );
		GraphicsTexture* pGT = ImageLoader::instance().LoadGL( ( *i ).string() );

		if( pGT != NULL )
		{
			pCarItem->SetTexture( pGT );
			_pItemList->push_back( pCarItem );
		}		
	}	
}

void Flicker::Draw()
{	
	( *_pItemList )[_iSelectedImageNumber]->Draw();
}

void Flicker::NextImage()
{
	_iSelectedImageNumber++;

	if( _iSelectedImageNumber >= _pItemList->size() ) _iSelectedImageNumber = 0;
}

void Flicker::PreviousImage()
{
	_iSelectedImageNumber--;

	if( _iSelectedImageNumber < 0 ) _iSelectedImageNumber = _pItemList->size() - 1;
}

FlickerItem* Flicker::GetCurrentImage()
{
	return ( *_pItemList )[_iSelectedImageNumber];
}
