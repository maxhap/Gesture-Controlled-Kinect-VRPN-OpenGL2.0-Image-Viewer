#include "stdafx.h"
#include "AngleAction.h"

AngleAction::AngleAction( string sName, unsigned int uiTimout, unsigned int uiBodyPart, int iAngle ) : Action( sName, uiTimout, uiBodyPart )
{

}

AngleAction::~AngleAction()
{

}

bool AngleAction::Acept()
{
	return true;
}

bool AngleAction::Proceed()
{
	return true;
}