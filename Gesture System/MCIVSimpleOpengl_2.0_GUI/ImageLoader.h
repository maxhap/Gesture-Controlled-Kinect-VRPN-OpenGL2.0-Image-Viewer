	#ifndef _IMAGELOADER_
#define _IMAGELOADER_

#include "stdafx.h"

using namespace std;

class ImageLoader : public Singleton< ImageLoader >
{

public:

	~ImageLoader();

	GraphicsTexture* LoadSDL( string location );
	GraphicsTexture* LoadGL( string location );
	GraphicsTexture* Load( string location );

	int Get2nNumber( int number );

	void SetLoadMode( int mode );

private:

	friend Singleton< ImageLoader >;

	ImageLoader();

	int _LoadMode;

	SDL_Surface* FlipImage( SDL_Surface* oSurface );
	void FlipImageVoid( SDL_Surface* oSurface );
};

#endif