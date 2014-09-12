#include "stdafx.h"
#include "Referenced.h"

Referenced::Referenced()
{
	_bCanDelete = true;
	_uiRefCount=0;
}

Referenced::~Referenced()
{
}

void Referenced::referenceObject()
{
	_uiRefCount++;
}

bool Referenced::unreferenceObject()
{
	_uiRefCount--;

	if( _bCanDelete && !_uiRefCount )
	{
		delete this;
		return true;
	}

	return  false;
}

void Referenced::setCanDelete( bool bCanDelete )
{
	_bCanDelete = bCanDelete;
}

bool Referenced::getCanDelete()
{
	return _bCanDelete;
}

unsigned int Referenced::referenceCount()
{
	return _uiRefCount;
}

