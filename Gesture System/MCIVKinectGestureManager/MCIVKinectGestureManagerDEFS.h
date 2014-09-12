#ifndef _MCIVKINECTGESTUREMANAGERDEFS1_
#define _MCIVKINECTGESTUREMANAGERDEFS1_

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
#define MCIVKINECTGESTUREMANAGER_DLL_DEF
#else
#ifdef MCIVKINECTGESTUREMANAGER_EXPORTS
#define MCIVKINECTGESTUREMANAGER_DLL_DEF __declspec(dllexport)
#else
#define MCIVKINECTGESTUREMANAGER_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"MCIVKinectGestureManagerD")
#else
#pragma comment(lib,"MCIVKinectGestureManagerR")
#endif
#endif 
#endif
#else
#define MCIVKINECTGESTUREMANAGER_DLL_DEF
#endif

#define MCIVKINECTGESTUREMANAGER_DEBUG
#endif