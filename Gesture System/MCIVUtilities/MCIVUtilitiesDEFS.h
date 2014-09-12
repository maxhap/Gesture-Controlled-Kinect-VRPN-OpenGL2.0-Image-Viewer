#ifndef _MCIVUTILITIESDEFS_
#define _MCIVUTILITIESDEFS_

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
#define MCIVUTILITIES_DLL_DEF
#else
#ifdef MCIVUTILITIES_EXPORTS
#define MCIVUTILITIES_DLL_DEF __declspec(dllexport)
#else
#define MCIVUTILITIES_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"MCIVUtilitiesD")
#else
#pragma comment(lib,"MCIVUtilitiesR")
#endif
#endif 
#endif
#else
#define MCIVUtilities_DLL_DEF
#endif

#define MCIVUtilities_DEBUG
#endif