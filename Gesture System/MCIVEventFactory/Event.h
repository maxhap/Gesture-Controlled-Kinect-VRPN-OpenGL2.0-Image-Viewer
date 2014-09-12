#ifndef _EVENT_
#define _EVENT_

#include "MCIVEventFactoryDEFS.h"

class MCIVEVENTFACTORY_DLL_DEF Event
{

public:

	Event();
	virtual ~Event();

	virtual void FireEvent();

protected:

};

#endif