#ifndef _ANGLEACTION_
#define _ANGLEACTION_

#include "stdafx.h"
#include "Action.h"
#include "MCIVKinectGestureManagerDEFS.h"

class MCIVKINECTGESTUREMANAGER_DLL_DEF AngleAction : public Action
{

public:

	AngleAction( string sName, unsigned int uiTimout, unsigned int uiBodyPart, int iAngle );
	~AngleAction();

	virtual bool Acept();
	virtual bool Proceed();

private:

};
#endif