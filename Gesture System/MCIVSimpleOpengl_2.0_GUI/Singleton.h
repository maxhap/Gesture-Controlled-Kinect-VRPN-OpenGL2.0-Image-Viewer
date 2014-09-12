#ifndef _SINGLETON_ 
#define _SINGLETON_ 

template<class T> class Singleton 
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