#pragma once

#include "stdafx.h"
#include "MCIVUtilitiesDEFS.h"

class MCIVUTILITIES_DLL_DEF Referenced
{
public: 
	Referenced();

	void referenceObject();
	bool unreferenceObject();
	void setCanDelete(bool bCanDelete);
	bool getCanDelete();
	unsigned int referenceCount();

protected:
	virtual ~Referenced(); 
private:
	unsigned int _uiRefCount;
	bool _bCanDelete;
};

