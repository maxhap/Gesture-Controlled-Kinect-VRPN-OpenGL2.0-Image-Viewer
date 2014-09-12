#include "stdafx.h"

GraphicsTexture::GraphicsTexture( GLuint texture, GLenum textureFormat, GLint colorCount, int textureWidth, int textureHeight, int spriteWidth, int spriteHeight )
{
	_Texture = texture;
	_TextureFormat = textureFormat;
	_ColorCount = colorCount;

	_TextureDimentions.width = textureWidth;
	_TextureDimentions.height = textureHeight;

	_SpriteDimentions.width = spriteWidth;
	_SpriteDimentions.height = spriteHeight;

	_pSprite = NULL;
}

GraphicsTexture::GraphicsTexture( SDL_Surface* surface, int textureWidth, int textureHeight, int spriteWidth, int spriteHeight )
{
	_Texture = NULL;
	_TextureFormat = NULL;
	_ColorCount = NULL;

	_pSprite = surface;

	_TextureDimentions.width = textureWidth;
	_TextureDimentions.height = textureHeight;

	_SpriteDimentions.width = spriteWidth;
	_SpriteDimentions.height = spriteHeight;
}

GraphicsTexture::~GraphicsTexture()
{
	if( _Texture != NULL )
	{
		glDeleteTextures( 1, &_Texture );
	}

	if( _pSprite != NULL )
	{
		SDL_FreeSurface( _pSprite );
	}
}

GLuint GraphicsTexture::GetTexture()
{
	return _Texture;
}

GLenum GraphicsTexture::GetTextureFormat()
{
	return _TextureFormat;
}

GLint GraphicsTexture::GetColorCount()
{
	return _ColorCount;
}

SDL_Surface* GraphicsTexture::GetSDLSurface()
{
	return _pSprite;
}

void GraphicsTexture::SetSDLSurface( SDL_Surface* surface )
{
	if( _pSprite != NULL )
	{
		SDL_FreeSurface( _pSprite );
		_pSprite = NULL;
	}

	_pSprite = surface;

}
