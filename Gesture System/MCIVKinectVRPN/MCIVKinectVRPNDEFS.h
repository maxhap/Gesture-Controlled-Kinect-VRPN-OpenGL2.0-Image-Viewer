#ifndef MCIVKINECTVRPNDEFS
#define MCIVKINECTVRPNDEFS

#ifdef WIN32
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_MCIVKINECTVRPN
#define MCIVKINECTVRPN_DLL_DEF
#else
#ifdef MCIVKINECTVRPN_EXPORTS
#define MCIVKINECTVRPN_DLL_DEF __declspec(dllexport)
#else
#define MCIVKINECTVRPN_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"MCIVKinectVRPND")
#else
#pragma comment(lib,"MCIVKinectVRPNR")
#endif
#endif 
#endif
#else
#define MCIVKINECTVRPN_DLL_DEF
#endif

#define MCIVKINECTVRPN_DEBUG

#endif