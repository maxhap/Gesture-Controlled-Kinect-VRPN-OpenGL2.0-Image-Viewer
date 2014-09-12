#ifndef _GRAPHICSTEXTURE_
#define _GRAPHICSTEXTURE_

#include "stdafx.h"

class GraphicsTexture
{

public:

	GraphicsTexture( GLuint texture, GLenum textureFormat, GLint colorCount, int textureWidth, int textureHeight, int spriteWidth, int spriteHeight );
	GraphicsTexture( SDL_Surface* surface, int textureWidth, int textureHeight, int spriteWidth, int spriteHeight );
	~GraphicsTexture();

	GLuint GetTexture();
	GLenum GetTextureFormat();
	GLint GetColorCount();

	struct Dimentions
	{
		int width;
		int height;
	} _SpriteDimentions, _TextureDimentions;

	SDL_Surface* GetSDLSurface();

	void SetSDLSurface( SDL_Surface* surface );

private:

	GLuint _Texture;
	GLenum _TextureFormat;
	GLint _ColorCount;
	SDL_Surface* _pSprite;
};

#endif