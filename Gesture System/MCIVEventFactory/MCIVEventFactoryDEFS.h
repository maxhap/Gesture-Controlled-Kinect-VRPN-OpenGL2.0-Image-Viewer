#ifndef _MCIVEVENTFACTORYDEFS_
#define _MCIVEVENTFACTORYDEFS_

#ifdef WIN32
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_MATESTSETUP
#define MCIVEVENTFACTORY_DLL_DEF
#else
#ifdef MCIVEVENTFACTORY_EXPORTS
#define MCIVEVENTFACTORY_DLL_DEF __declspec(dllexport)
#else
#define MCIVEVENTFACTORY_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"MCIVEventFactoryD")
#else
#pragma comment(lib,"MCIVEventFactoryR")
#endif
#endif 
#endif
#else
#define MCIVEventFactory_DLL_DEF
#endif

#define MCIVEventFactory_DEBUG
#endif