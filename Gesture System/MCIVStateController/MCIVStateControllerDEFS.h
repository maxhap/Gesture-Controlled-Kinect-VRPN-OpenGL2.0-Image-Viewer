#ifndef _MCIVSTATECONTROLLERDEFS_
#define _MCIVSTATECONTROLLERDEFS_

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
#define MCI_DLL_DEF
#else
#ifdef MCIVSTATECONTROLLER_EXPORTS
#define MCIVSTATECONTROLLER_DLL_DEF __declspec(dllexport)
#else
#define MCIVSTATECONTROLLER_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"MCIVStateControllerD")
#else
#pragma comment(lib,"MCIVStateControllerR")
#endif
#endif 
#endif
#else
#define MCIVSTATECONTROLLER_DLL_DEF
#endif

#define MCIVSTATECONTROLLER_DEBUG
#endif