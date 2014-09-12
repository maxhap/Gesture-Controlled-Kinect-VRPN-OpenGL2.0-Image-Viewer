// MCIVSimpleOpengl_2.0_GUI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	LogicEngine* logicEngine = new LogicEngine();

	if( logicEngine->Initialize() == false )
	{
		//clear up resources
		logicEngine->Quit();
		delete logicEngine;

		return 1;
	}
	else
	{
		//start game loop
		logicEngine->GameLoop();
	}

	//clear up resources
	if ( logicEngine->Quit() == false )
	{
		delete logicEngine;
		return 1;
	}

	delete logicEngine;

	return 0;
}

