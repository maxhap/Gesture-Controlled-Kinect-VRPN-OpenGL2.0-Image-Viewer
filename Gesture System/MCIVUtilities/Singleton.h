#ifndef _SINGLETON_ 
#define _SINGLETON_ 

#include "stdafx.h"

template<class T> class MCIVUTILITIES_DLL_DEF Singleton 
{
	Singleton( const Singleton& );
	Singleton& operator=( const Singleton& );

protected: 

	Singleton() {}
	virtual ~Singleton() {}

public :

	static T& instance()
	{
		static T instance;
		return instance;
	}

};

#endif