#include "stdafx.h"
using namespace std;

ImageLoader::ImageLoader()
{
}

ImageLoader::~ImageLoader()
{
}

void ImageLoader::SetLoadMode( int mode )
{
	_LoadMode = mode;
}

GraphicsTexture* ImageLoader::Load( string filename )
{
	return LoadGL( filename );	
}

GraphicsTexture* ImageLoader::LoadSDL( string filename )
{
	//temp storage for image
	SDL_Surface* originalImage = NULL;

	//Optimized image 
	SDL_Surface* optimizedImage = NULL;

	//load image
	originalImage = IMG_Load( filename.c_str() );

	if( originalImage == NULL )
	{
		return NULL;
	}

	//create optimized image
	optimizedImage =  SDL_DisplayFormatAlpha( originalImage );
	//free original image
	SDL_FreeSurface( originalImage ); 

	GraphicsTexture* graphicsTexture = new GraphicsTexture( optimizedImage, optimizedImage->w, optimizedImage->h, optimizedImage->w, optimizedImage->h );

	return graphicsTexture ;
}

GraphicsTexture* ImageLoader::LoadGL( string location )
{
	GLuint texture;			// This is a handle to our texture object
	SDL_Surface* surface;	// This surface will tell us the details of the image
	GLenum texture_format;
	GLint  nOfColors;

	//convert surface to 2^n
	SDL_Surface* origionalSurface = IMG_Load( location.c_str() );

	//load image
	if( origionalSurface != NULL )
	{

		//image flipping
		FlipImageVoid( origionalSurface );

		int spriteWidth = origionalSurface->w;
		int spriteHeight =  origionalSurface->h;

		int textureWidth = 0;
		int textureHeight = 0;

		surface = SDL_CreateRGBSurface( SDL_SWSURFACE, Get2nNumber( origionalSurface->w ) , Get2nNumber( origionalSurface->h ), origionalSurface->format->BitsPerPixel, origionalSurface->format->Rmask, origionalSurface->format->Gmask, origionalSurface->format->Bmask, origionalSurface->format->Amask );		

		// Save the alpha blending attributes.
		Uint32 saved_flags = origionalSurface->flags & (SDL_SRCALPHA | SDL_RLEACCELOK);
		Uint8 saved_alpha = origionalSurface->format->alpha;

		if((saved_flags & SDL_SRCALPHA) == SDL_SRCALPHA)
		{
			SDL_SetAlpha(origionalSurface, 0, 0);
		}

		SDL_Rect corner;
		corner.x = 0;
		corner.y = 0;

		SDL_BlitSurface( origionalSurface, NULL, surface, &corner );	

		/* Restore the alpha blending attributes */
		if((saved_flags & SDL_SRCALPHA) == SDL_SRCALPHA)
		{
			SDL_SetAlpha(origionalSurface, saved_flags, saved_alpha);
		}

		if( surface != NULL )
		{
			//error check
			// Check that the image's width is a power of 2
			if ( ( surface->w & ( surface->w - 1 ) ) != 0 )
			{
				cout << "warning: image's width is not a power of 2\n";
			}

			// Also check if the height is a power of 2
			if ( ( surface->h & ( surface->h - 1 ) ) != 0 )
			{
				cout << "warning: image's height is not a power of 2\n";
			}

			bool colorFlag = true;

			// get the number of channels in the SDL surface
			nOfColors = surface->format->BytesPerPixel;
			if (nOfColors == 4)     // contains an alpha channel
			{
				if (surface->format->Rmask == 0x000000ff)
				{
					texture_format = GL_RGBA;
				}
				else
				{
					texture_format = GL_BGRA;
				}
			}
			else if ( nOfColors == 3 )     // no alpha channel
			{
				if ( surface->format->Rmask == 0x000000ff )
				{
					texture_format = GL_RGB;
				}
				else
				{
					texture_format = GL_BGR;			
				}
			}
			else 
			{
				printf( "warning: the image is not truecolor..  this will probably break\n" );
				colorFlag = false;					
			}

			if( colorFlag )
			{
				textureWidth = surface->w;
				textureHeight = surface->h;

				// Have OpenGL generate a texture object handle for us
				glGenTextures( 1, &texture );

				// Bind the texture object
				glBindTexture( GL_TEXTURE_2D, texture );

				// Set the texture's stretching properties
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
				glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

				// Edit the texture object's image data using the information SDL_Surface gives us
				glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
					texture_format, GL_UNSIGNED_BYTE, surface->pixels );

				SDL_FreeSurface( origionalSurface );
				SDL_FreeSurface( surface );

				GraphicsTexture* graphicsTexture = new GraphicsTexture( texture, texture_format, nOfColors, textureWidth, textureHeight, spriteWidth, spriteHeight );

				return graphicsTexture;
			}
		}	
	}

	return NULL;	
}

int ImageLoader::Get2nNumber( int number )
{
	int currentNumber = 0;
	int n = 1;

	while( currentNumber < number )
	{
		currentNumber = ( int ) ( pow( 2 + 0.0, n + 0.0 ) );
		n++;
	}

	return currentNumber;
}


SDL_Surface* ImageLoader::FlipImage( SDL_Surface* oSurface )
{
	unsigned char* destination = ( unsigned char* ) malloc( oSurface->w * oSurface->h * oSurface->format->BytesPerPixel );

	int dp = 0;

	int sourceBlockSize = oSurface->w * oSurface->format->BytesPerPixel;

	for( int sp = (sourceBlockSize * oSurface->h) - sourceBlockSize; sp > 0; sp -= sourceBlockSize )
	{
		memcpy( destination + dp, ( unsigned char* ) oSurface->pixels + sp,  sourceBlockSize);
		dp += sourceBlockSize;
	}

	SDL_Surface *Srfc2 = SDL_ConvertSurface(oSurface, oSurface->format, oSurface->flags);

	//memcpy((unsigned char*)  Srfc2->pixels, destination, oSurface->w * oSurface->h * oSurface->format->BytesPerPixel);

	Srfc2->pixels = destination;


	return Srfc2;
}

void ImageLoader::FlipImageVoid( SDL_Surface* oSurface )
{
	unsigned char* destination = ( unsigned char* ) malloc( oSurface->w * oSurface->h * oSurface->format->BytesPerPixel );

	int dp = 0;

	int sourceBlockSize = oSurface->w * oSurface->format->BytesPerPixel;

	for( int sp = ( sourceBlockSize * oSurface->h ) - sourceBlockSize; sp > 0; sp -= sourceBlockSize )
	{
		memcpy( destination + dp, ( unsigned char* ) oSurface->pixels + sp,  sourceBlockSize);
		dp += sourceBlockSize;
	}

	memcpy( ( unsigned char* )  oSurface->pixels, destination, oSurface->w * oSurface->h * oSurface->format->BytesPerPixel );

	free( destination );
}