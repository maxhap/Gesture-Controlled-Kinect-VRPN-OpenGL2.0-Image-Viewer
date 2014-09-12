// MCIVKinectGestureManager.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MCIVKinectGestureManager.h"

MCIVKinectGestureManager::MCIVKinectGestureManager()
{
	_bStarted = false;
	_pvGestures = new vector<Gesture*>;
	_pEventFuntion = NULL;
}

MCIVKinectGestureManager::~MCIVKinectGestureManager()
{
	deleteGestureList();
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: deleteGestureList
Description: Iterate through deleting all gestures
-------------------------------------------------------------------------------------------*/
void MCIVKinectGestureManager::deleteGestureList()
{
	for( vector<Gesture*>::iterator i = _pvGestures->begin(); i != _pvGestures->end(); i++ )
	{
		delete ( *i );
	}

	_pvGestures->clear();
}


/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: start
Description: set _bStarted to true, push message to console and build the gesture list
-------------------------------------------------------------------------------------------*/
void MCIVKinectGestureManager::start( string sGestureFile )
{
	if( !_bStarted )
	{
		_bStarted = true;
		cout << "Gesture manager started " << "\n";
		//buildGestureList( "%raaIVInst64%\\data\\position_test.txt" );
		buildGestureList( sGestureFile );
	}
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: stop
Description: Push message to console and delete current gestures
-------------------------------------------------------------------------------------------*/
void MCIVKinectGestureManager::stop()
{
	if( _bStarted )
	{
		cout << "Gesture manager stopped " << "\n";
		_bStarted = false;
		deleteGestureList();
	}
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: buildGestureList
Description: prints out status to the consol then calls import method
-------------------------------------------------------------------------------------------*/
bool MCIVKinectGestureManager::buildGestureList( string filePath )
{
	cout << "Building Gesture List " << "\n";


	import( filePath );

	return true;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: addGesture
Description: push the gesture to the back of _pvGestures vector list
-------------------------------------------------------------------------------------------*/
void MCIVKinectGestureManager::addGesture( Gesture* pGesture )
{
	pGesture->_pEventFuntion = _pEventFuntion;
	pGesture->_pTimeoutFuntion = _pTimoutEventFuntion;

	_pvGestures->push_back( pGesture );
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: ProceedGesture
Description: iterate though _pvGestures calling proceedGesture on each Gesture
-------------------------------------------------------------------------------------------*/
void MCIVKinectGestureManager::proceedGestures()
{
	for( vector<Gesture*>::iterator i = _pvGestures->begin(); i != _pvGestures->end(); i++ )
	{
		( *i )->proceedGesture();
	}
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: import
Description:Creates a ifstream to read gesture file. File structure consists of simple block
			format. Method uses compare and substring to extract relevant data to build action
			and gestures.
-------------------------------------------------------------------------------------------*/
void MCIVKinectGestureManager::import( string sFileName )
{
	ifstream isFile( sFileName );		

	Gesture* buildingGesture = NULL;
	unsigned int uiSkeletonID;
	string sLine;

	if( isFile.bad() )
	{
		cout << "Unable to read gesture file";
	}

	if( isFile.is_open() )
	{
		while( isFile.good() )
		{
			getline( isFile, sLine );

			if( sLine.compare( "--------------------------------------------------------Skeliton-----------------------------------------------------" ) == 0)
			{
				getline( isFile, sLine );
				uiSkeletonID = atoi( sLine.substr( 3 ).c_str() );
			}

			else if ( sLine.compare( "-----------------Gesture------------------" ) == 0 )
			{
				getline( isFile, sLine );//read GestureName:
				buildingGesture = new Gesture( uiSkeletonID, sLine.substr( 12 ) );

				//add stub action
				buildingGesture->addAction( new Action( "stub", 0, 0 ) );
			}

			else if ( sLine.compare( "-----Action-----" ) == 0)
			{
				Action* pAction = loadAction( isFile );
				if( pAction != NULL )
				{
					buildingGesture->addAction( pAction );
				}
				else
				{
					cout << "\n Failed To Load An Action \n";
				}
				
			}

			else if ( sLine.compare( "-----------------End------------------" ) == 0 )
			{
				addGesture( buildingGesture );
			}
		}
	}
		
	isFile.close();
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: Load Action
Description: Loads an action using recursion for the and and or
-------------------------------------------------------------------------------------------*/
Action* MCIVKinectGestureManager::loadAction( istream& isFile )
{	
    Action* pAction = NULL; 

	string sLine;

	getline( isFile, sLine );
	string type = sLine.substr( 11 );

	if( type.compare( "Position" ) == 0 )
	{
		getline( isFile, sLine );
		string sName = sLine.substr( 11 );//read name 
		getline( isFile, sLine );
		float fTimeOut  = atof( sLine.substr( 8 ).c_str() );//read Timeout:
		getline( isFile, sLine );
		int iFirstBodyPart = atoi( sLine.substr( 4 ).c_str() );//read FBP:
		getline( isFile, sLine );
		int iRelationship = atoi( sLine.substr( 9 ).c_str() );//read Relationship:
		getline( isFile, sLine );
		int iSecondBodyPart = atoi( sLine.substr( 4 ).c_str() );//read SBP:
		getline( isFile, sLine );
		float fUperBoundsValue = atof( sLine.substr( 17 ).c_str() );//read UpperBoundsValue:
		getline( isFile, sLine );
		float fLowerBoundsValue = atof( sLine.substr( 17 ).c_str() );//read LowerBoundsValue:

		PositionAction* pPosAction = new PositionAction( sName, fTimeOut, iFirstBodyPart, iRelationship, iSecondBodyPart, fUperBoundsValue, fLowerBoundsValue );
		pAction = pPosAction;
	}

	else if( type.compare( "Velocity" ) == 0 )
	{
		getline( isFile, sLine );
		string sName = sLine.substr( 11 );//read name 
		getline( isFile, sLine );
		float fTimeOut  = atof( sLine.substr( 8 ).c_str() );//read Timeout:
		getline( isFile, sLine );
		int iFirstBodyPart = atoi( sLine.substr( 4 ).c_str() );//read FBP:
		getline( isFile, sLine );
		int iRelationship = atoi( sLine.substr( 9 ).c_str() );//read Relationship:
		getline( isFile, sLine );
		float fRelationshipValue = atof( sLine.substr( 6 ).c_str() );//read RelationshipL:

		pAction = new VelocityAction( sName, fTimeOut, iFirstBodyPart, iRelationship, fRelationshipValue );
	}

	else if( type.compare( "ConditionalVelocity" ) == 0 )
	{
		getline( isFile, sLine );
		string sName = sLine.substr( 11 );//read name 
		getline( isFile, sLine );
		float fTimeOut  = atof( sLine.substr( 8 ).c_str() );//read Timeout:
		getline( isFile, sLine );
		int iFirstBodyPart = atoi( sLine.substr( 4 ).c_str() );//read FBP:
		getline( isFile, sLine );
		int iVelocityRelationship = atoi( sLine.substr( 17 ).c_str() );//read VelocityRelationship:
		getline( isFile, sLine );
		int iConditionalBodyPart = atoi( sLine.substr( 12 ).c_str() );//read ConditionalBodyPart:
		getline( isFile, sLine );
		int iConditionalRelationship = atoi( sLine.substr( 24 ).c_str() );//read CondtionalRelationship:
		getline( isFile, sLine );
		float fRelationshipValue = atof( sLine.substr( 14 ).c_str() );//read VelocityValue:
		getline( isFile, sLine );

		AndAction* pAndAction = ( AndAction* ) loadAction( isFile );

		pAction = new ConditionalVelocityAction( sName, fTimeOut, iFirstBodyPart, iVelocityRelationship, iConditionalBodyPart,
												 iConditionalRelationship, fRelationshipValue, pAndAction );
	}

	else if( type.compare( "And" ) == 0 )
	{
		getline( isFile, sLine );
		string sName = sLine.substr( 11 );//read name 
		getline( isFile, sLine );
		float fTimeOut  = atof( sLine.substr( 8 ).c_str() );//read Timeout:

		AndAction* pAndAction = new AndAction( sName, fTimeOut );

		while ( true )
		{
			getline( isFile, sLine );
			if ( sLine.compare( "-----MultiEnd-----" ) == 0 )
			{
				break;
			}
			else if ( sLine.compare( "-----InnerAction-----" ) == 0 )
			{
				pAndAction->addAction( loadAction( isFile ) );
			}
		}

		pAction = pAndAction;
	}

	else if( type.compare( "Or" ) == 0 )
	{
		getline( isFile, sLine );
		string sName = sLine.substr( 11 );//read name 
		getline( isFile, sLine );
		float fTimeOut  = atof( sLine.substr( 8 ).c_str() );//read Timeout:

		OrAction* pAndAction = new OrAction( sName, fTimeOut );

		while ( true )
		{
			getline( isFile, sLine );
			if ( sLine.compare( "-----MultiEnd-----" ) == 0 )
			{
				break;
			}
			else if ( sLine.compare( "-----InnerAction-----" ) == 0 )
			{
				pAndAction->addAction( loadAction( isFile ) );
			}
		}

		pAction = pAndAction;
	}

	else if( type.compare( "Time" ) == 0 )
	{
		getline( isFile, sLine );
		string sName = sLine.substr( 11 );//read name 
		getline( isFile, sLine );
		float fTimeOut  = atof( sLine.substr( 8 ).c_str() );//read Timeout:
		getline( isFile, sLine );
		float fTimeToPass = atof( sLine.substr( 11 ).c_str() );//read TimeToPass:

		pAction = new TimeAction( sName, fTimeOut, fTimeToPass );
	}

	return pAction;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: setSuccessfullEventFunction
Description: sets _pEventFunction with a function pointer with one string parameter
-------------------------------------------------------------------------------------------*/
void MCIVKinectGestureManager::setSuccessfullEventFunction( EventFunction pEventFuntion )
{
	_pEventFuntion = pEventFuntion;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: setTimeoutEventFunction
Description: sets _pEventFunction with a function pointer with one string parameter
-------------------------------------------------------------------------------------------*/
void MCIVKinectGestureManager::setTimeoutEventFunction( EventFunction pEventFuntion )
{
	_pTimoutEventFuntion = pEventFuntion;
}
