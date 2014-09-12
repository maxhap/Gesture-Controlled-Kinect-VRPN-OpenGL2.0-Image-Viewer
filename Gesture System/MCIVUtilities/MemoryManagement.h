#ifndef _MemoryManagement_
#define _MemoryManagement_

#include "stdafx.h"
#include "Singleton.h"
#include <vector>

template<class T> class MCIVUTILITIES_DLL_DEF MemoryManagement
{

public:

	void static cleanVector( vector<T*>* vectorList, bool deleteObjects )
	{
		if( deleteObjects == true )
		{
			for( vector<T*>::iterator i = vectorList->begin(); i < vectorList->end(); i++ )
			{
				delete ( *i );
			}
		}

		vectorList->erase( vectorList->begin(), vectorList->end() );

		delete vectorList;
	};

	void static emptyVector( vector<T*>* vectorList, bool deleteObjects )
	{
		if( deleteObjects == true )
		{
			for( vector<T*>::iterator i = vectorList->begin(); i < vectorList->end(); i++ )
			{
				delete ( *i );
			}
		}

		vectorList->erase( vectorList->begin(), vectorList->end() );
	};

private:

	MemoryManagement() 
	{		
	};

	~MemoryManagement() 
	{		
	};
};

#endif