#include "stdafx.h"
#include "MaxRectangle.h"

MaxRectangle::MaxRectangle()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->w = 0.0f;
	this->h = 0.0f;
}

MaxRectangle::MaxRectangle( float x, float y, float w, float h )
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

MaxRectangle::~MaxRectangle()
{

}
