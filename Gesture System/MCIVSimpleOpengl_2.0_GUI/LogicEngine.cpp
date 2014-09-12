#include "stdafx.h"
#include <MCIVEventFactory/MCIVEventFactory.h>
 
LogicEngine::LogicEngine()
{
	_Quit = false;
	_pGameTimer = new GameTimer();	
	_Angle = 0;
	_Camera = new Camera();
	_pCarousel = new Carousel();
	_pStartMenu = new StartMenu();
	_pBackToMainMenu = new BackToMainMenu();

	_pHand = new Hand();

	_pFlicker = new Flicker();

	_uiGameState = 0;
}

LogicEngine::~LogicEngine()
{
	if( _pGameTimer ) delete _pGameTimer;	
	if( _Camera) delete _Camera;
	if( _pCarousel ) delete _pCarousel;
	if( _pStartMenu )delete _pStartMenu;
	if( _pHand ) delete _pHand;
	if( _pBackToMainMenu ) delete _pBackToMainMenu;
	if( _pFlicker ) delete _pFlicker;
}

bool LogicEngine::Initialize()
{
	//init of systems
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		return false;
	}

	_pScreen = SDL_SetVideoMode( Initialize::SCREEN_WIDTH, Initialize::SCREEN_HEIGHT, Initialize::SCREEN_BPP, SDL_OPENGL );

	if( _pScreen == NULL )
	{
		return false;
	}

	if( GLEW_OK != glewInit() )
	{
		//ErrorSystem::instance().WriteError( "MainWnd GLEW load Fail" );
		return false;
	}

	if( !InitGL() )
	{
		return false;
	}

	InitVRPN();

	SetUpStartMenu();
	SetUpCarousel();	
	SetUpFlicker();
	SetUpHand();

	return true;
}

bool LogicEngine::InitGL()
{
	//Set clear color
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

	//Set projection
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 45.0,  (double)Initialize::SCREEN_WIDTH / (double)Initialize::SCREEN_HEIGHT, 1.0, 200.0 );
	glViewport( 0, 0, Initialize::SCREEN_WIDTH, Initialize::SCREEN_HEIGHT );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	glEnable( GL_BLEND );
	glBlendFunc( GL_ONE, GL_ONE_MINUS_SRC_ALPHA );
	
	glEnable( GL_ALPHA_TEST );
	glAlphaFunc( GL_GREATER, 0.1f );


	//lighting and shading
	//glEnable( GL_LIGHTING );
	//glEnable( GL_LIGHT0 );
	//glEnable( GL_LIGHT1 );
	glShadeModel( GL_SMOOTH );
	glEnable( GL_COLOR_MATERIAL );

	glEnable( GL_DEPTH_TEST );
	glEnable( GL_NORMALIZE );

	//Initialize model view matrix
	glMatrixMode( GL_MODELVIEW );	
	glLoadIdentity();

	//If there was any errors
	if( glGetError() != GL_NO_ERROR )
	{
		//		ErrorSystem::instance().WriteError( "MainWnd GL load Fail" );
		return false;
	}	

	//If everything initialized
	return true;
}

void LogicEngine::SetUpCarousel()
{
	_pCarousel->LoadItems();
}

bool LogicEngine::CleanUp()
{
	//free the _pScreen sufrace
	if( _pScreen != NULL )
	{
		SDL_FreeSurface( _pScreen );
	}

	//quit sql
	SDL_Quit();

	return true;
}

bool LogicEngine::Quit()
{
	if( CleanUp() == false )
	{
//		ErrorSystem::instance().WriteError( "Logic Engine clean up fail" );
		return false;
	}

	return true;
}

//---------------------------------------------------- GL Work Starts here --------------------------------------------------------------------------

void LogicEngine::GameLoop()
{
	int runTime = 0;

	//Timer used to update the caption
	GameTimer update;
	//Start the update timer
	update.Start();

	while( _Quit == false )
	{
		int frame = 0;

		int ticks = _pGameTimer->GetTicks();
		//reset game timer
		_pGameTimer->Start();

		HandleEvents();		
		UpdateVRPNAndGestures();
		HandLogic();
		SetNewCameraPosition();

		_Camera->Update();
		CarouselUpdate();
		UpdateFlicker();

		Render();		

		//cap frame rate
		if( _pGameTimer->GetTicks() < 1000 / Initialize::FRAMERATE  )
		{
			SDL_Delay( ( 1000 / Initialize::FRAMERATE  ) - _pGameTimer->GetTicks() );
		}		

		//Increment the frame counter
		frame++;

		//If a second has passed since the caption was last updated
		if( update.GetTicks() > 1000 )
		{
			//The frame rate as a string
			std::stringstream caption;

			//Calculate the frames per second and create the string 
			caption << "Average Frames Per Second: " << frame / ( _pGameTimer->GetTicks()/ 1000.f ) << "    Runtime: " << runTime << "       GameTicks: "  << SDL_GetTicks();

			//Reset the cation
			SDL_WM_SetCaption( caption.str().c_str(), NULL );

			//Restart the update timer
			update.Start();
			runTime++;
		}
	}
}

void LogicEngine::HandleEvents()
{
	if( SDL_PollEvent( &event ) )
	{
		if( event.type == SDL_QUIT )
		{
			_Quit = true;
		}
		
		if( event.type == SDL_KEYDOWN || event.type == SDL_KEYUP )
		{
			if( event.key.keysym.sym == SDLK_ESCAPE )
			{
				_Quit = true;
			}
			else
			{
				if( MCIVStateController::instance().GetState() != MCIVStateController::MAINMENU )
				{
					_Camera->HandleMovement( event );
				}				
			}
		}
	}
}

void LogicEngine::Render()
{	
	glLoadIdentity();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glPushMatrix();

	//draw back to main menu
	if( MCIVStateController::instance().GetState() == MCIVStateController::CAROUSEL || MCIVStateController::instance().GetState() == MCIVStateController::FLICKER )
	{
		_pBackToMainMenu->Draw();
		if( MCIVStateController::instance().RightHandInDetectionZone ) _pHand->Draw();
	}

	_Camera->Render();

	switch( MCIVStateController::instance().GetState() )
	{
		case MCIVStateController::MAINMENU: RenderMainMenu(); break;
		case MCIVStateController::CAROUSEL: RenderCarousel(); break;
		case MCIVStateController::FLICKER: RenderFlicker(); break;

		default: break;
	}
	
	glPopMatrix();

	SDL_GL_SwapBuffers();
}


void LogicEngine::RenderMainMenu()
{	
	if( MCIVStateController::instance().RightHandInDetectionZone ) _pHand->Draw();

	_pStartMenu->Draw();
}


void LogicEngine::RenderCarousel()
{
	_pCarousel->Draw();	
}


void LogicEngine::CarouselUpdate()
{
	if( MCIVStateController::instance().CarouselZoomEnabled )
	{
		_pCarousel->ZoomCarousel( _pHumainBodyZero );
	}
	else
	{
		_pCarousel->ResetHandMagnitude();
	}

	if( MCIVStateController::instance().CarouselRotateEnabled )
	{
		_pCarousel->RotateCarousel( _pHumainBodyZero );
	}
	else
	{
		_pCarousel->ResetRotation();
	}

	_pCarousel->Update();
}

void LogicEngine::SetUpStartMenu()
{
	//main menu
	_pStartMenu->SetPosition( 0.0f, 0.0f, -2.4f );
	_pStartMenu->SetWidthHeightDepth( 1.8f, 1.0f, 0.0f );
	_pStartMenu->SetTexture( ImageLoader::instance().LoadGL( Initialize::MainMenuBackgroundImageLocation ) );

	ImageCarouselMenuItem* pIcmi = new ImageCarouselMenuItem();
	pIcmi->SetPosition( -0.6f, 0.0f, -2.0f );
	pIcmi->SetWidthHeightDepth( 0.5f, 0.5f, 0.0f );
	pIcmi->SetTexture( ImageLoader::instance().LoadGL( Initialize::CarouselMenuItemBackgroundLocaiton ) );
	pIcmi->SetSelectedTexture( ImageLoader::instance().LoadGL( Initialize::CarouselMenuItemBackgroundLocaitonActive ) );

	_pStartMenu->AddItem( pIcmi );

	ImageFlickerMenuItem* pIfmi = new ImageFlickerMenuItem();
	pIfmi->SetPosition( 0.6f, 0.0f, -2.0f );
	pIfmi->SetWidthHeightDepth( 0.5f, 0.5f, 0.0f );
	pIfmi->SetTexture( ImageLoader::instance().LoadGL( Initialize::FlickerMenuItemBackgroundLocaiton ) );
	pIfmi->SetSelectedTexture( ImageLoader::instance().LoadGL( Initialize::FlickerMenuItemBackgroundLocaitonActive ) );

	_pStartMenu->AddItem( pIfmi );
	
	//back menu
	_pBackToMainMenu->SetPosition( 0.0f, 0.0f, -2.4f );
	_pBackToMainMenu->SetWidthHeightDepth( 1.8f, 0.1f, 0.0f );
	_pBackToMainMenu->SetTexture( ImageLoader::instance().LoadGL( Initialize::BackToMainMenuBackgroundImageLocation ) );

	BackToMainMenuItem* pBtmm = new BackToMainMenuItem();
	pBtmm->SetPosition( -1.41f, 0.77f, -2.0f );
	pBtmm->SetWidthHeightDepth( 0.05f, 0.05f, 0.0f );
	pBtmm->SetTexture( ImageLoader::instance().LoadGL( Initialize::BackToMainMenuItemBackgroundImageLocation ) );
	pBtmm->SetSelectedTexture( ImageLoader::instance().LoadGL( Initialize::BackToMainMenuItemActiveBackgroundImageLocation ) );

	_pBackToMainMenu->AddItem( pBtmm );

}

void SucessfullEventFunction( unsigned int uiSkeleton, string sEvent )
{
	MCIVEventFactory::instance().PushEvent( uiSkeleton, sEvent );
}

void EventTimeoutFunction( unsigned int uiSkeleton, string sEvent )
{
	MCIVEventFactory::instance().PushTimoutEvent( uiSkeleton, sEvent );
}

void LogicEngine::InitVRPN()
{
	VRPNClient::instance().setMultiThreaded( false );
	VRPNClient::instance().addTracker( "Tracker0@localhost" );

	_pHumainBodyZero = VRPNClient::instance().getTrackerData( "Tracker0@localhost" );

	MCIVKinectGestureManager::instance().setSuccessfullEventFunction( &SucessfullEventFunction );
	MCIVKinectGestureManager::instance().setTimeoutEventFunction( &EventTimeoutFunction );
	MCIVKinectGestureManager::instance().start( Initialize::GestuerFileLocation );
}

void LogicEngine::UpdateVRPNAndGestures()
{
	VRPNClient::instance().manualLoopAllTrackers();
	MCIVKinectGestureManager::instance().proceedGestures();
}

void LogicEngine::SetUpHand()
{
	_pHand->SetTexture( ImageLoader::instance().LoadGL( Initialize::HandImageLoaction ) );
	_pHand->SetAditionalTextures( ImageLoader::instance().LoadGL( Initialize::HandImageLoactionQuater ),
   								  ImageLoader::instance().LoadGL( Initialize::HandImageLoactionHalf ), 
								  ImageLoader::instance().LoadGL( Initialize::HandImageLoactionThreeQuater ),
								  ImageLoader::instance().LoadGL( Initialize::HandImageLoactionFull ) );

	_pHand->SetWidthHeightDepth( 0.05f, 0.05f, 0.0f );	
}

void LogicEngine::HandLogic()
{
	if( MCIVStateController::instance().GetState() == MCIVStateController::MAINMENU )
	{
		if( MCIVStateController::instance().RightHandInDetectionZone )
		{
			if( VRPNClient::instance().getTrackerAlive( "Tracker0@localhost" ) )
			{
				BodyPart* pRightHand = _pHumainBodyZero->GetBodyPart( BODY_PART_rightHand );	
				BodyPart* pTorso = _pHumainBodyZero->GetBodyPart( BODY_PART_tourso );
				Vector3f relativePoss( pRightHand->getPosition()[0] - pTorso->getPosition()[0], 
									   pRightHand->getPosition()[1] - pTorso->getPosition()[1],
									   pRightHand->getPosition()[2] - pTorso->getPosition()[2]);

				float fMultiplacationFactor = 5.0f;
				float fX = ( relativePoss[0] * fMultiplacationFactor > 1.6 ) ? 1.6 : relativePoss[0] * fMultiplacationFactor;
				fX = ( relativePoss[0] * fMultiplacationFactor < -1.6 ) ? -1.6 : fX; 				  

				float fY = ( relativePoss[1] * fMultiplacationFactor > 0.9 ) ? 0.9 : relativePoss[1] * fMultiplacationFactor;
				fY = ( relativePoss[1] * fMultiplacationFactor < -1.9 ) ? -0.9 : fY;

				_pHand->SetPosition( fX, fY, -1.99f );
				

				MaxRectangle rec( _pHand->GetPosition()->x(), _pHand->GetPosition()->y(), _pHand->GetWidthHeighDepth()->x() / 2, 
					_pHand->GetWidthHeighDepth()->y() / 2 );

				_pStartMenu->SelectColision( &rec );
				_pStartMenu->ProceedActivations();
			}
		}		
	}
		
	else if( MCIVStateController::instance().GetState() == MCIVStateController::CAROUSEL || MCIVStateController::instance().GetState() == MCIVStateController::FLICKER )
	{
		if( MCIVStateController::instance().RightHandInDetectionZone )
		{
			if( VRPNClient::instance().getTrackerAlive( "Tracker0@localhost" ) )
			{
				BodyPart* pRightHand = _pHumainBodyZero->GetBodyPart( BODY_PART_rightHand );	
				BodyPart* pTorso = _pHumainBodyZero->GetBodyPart( BODY_PART_tourso );
				Vector3f relativePoss( pRightHand->getPosition()[0] - pTorso->getPosition()[0], 
					pRightHand->getPosition()[1] - pTorso->getPosition()[1],
					pRightHand->getPosition()[2] - pTorso->getPosition()[2]);

				float fMultiplacationFactor = 5.0f;
				float fX = ( relativePoss[0] * fMultiplacationFactor > 1.6 ) ? 1.6 : relativePoss[0] * fMultiplacationFactor;
				fX = ( relativePoss[0] * fMultiplacationFactor < -1.6 ) ? -1.6 : fX; 				  

				float fY = ( relativePoss[1] * fMultiplacationFactor > 0.9 ) ? 0.9 : relativePoss[1] * fMultiplacationFactor;
				fY = ( relativePoss[1] * fMultiplacationFactor < -1.9 ) ? -0.9 : fY;

				_pHand->SetPosition( fX, fY, -1.99f );

				MaxRectangle rec( _pHand->GetPosition()->x(), _pHand->GetPosition()->y(), _pHand->GetWidthHeighDepth()->x(), 
					_pHand->GetWidthHeighDepth()->y() );

				_pBackToMainMenu->SelectColision( &rec );
				_pBackToMainMenu->ProceedActivations();
			}
		}
	}
}

void LogicEngine::SetNewCameraPosition()
{
	if( MCIVStateController::instance().UpdateCameraPosition )
	{
		if( MCIVStateController::instance().GetState() == MCIVStateController::CAROUSEL )
		{
			//_Camera->MoveForwards( _pCarousel->GetRadious() + 4.0f );
		}
		else if ( MCIVStateController::instance().GetState() == MCIVStateController::MAINMENU )
		{
			Vector3f pos;
			pos.x( 0.0f );
			pos.y( 0.0f );
			pos.z( 0.0f );
			_Camera->SetPosition( pos );
		}

		MCIVStateController::instance().UpdateCameraPosition = false;
	}
}

bool LogicEngine::TwoObjectsCollided( MaxRectangle* pFirst, MaxRectangle* pSecond )
{
	float thisItemL = pFirst->x;
	float thisItemT = pFirst->y;
	float thisItemR = pFirst->x + pFirst->w;
	float thisItemB = pFirst->y + pFirst->h;

	//detect from other game item
	float otherItemL = pSecond->x;
	float otherItemT = pSecond->y;
	float otherItemR = pSecond->x + pSecond->w;
	float otherItemB = pSecond->y + pSecond->h;

	if( thisItemL > otherItemR )
	{
		return false;
	}

	if( thisItemR < otherItemL )
	{
		return false;
	}

	if( thisItemT > otherItemB )
	{
		return false;
	}

	if( thisItemB < otherItemT )
	{
		return false;
	}	

	return true;
}

void LogicEngine::SetUpFlicker()
{
	_pFlicker->LoadItems();
}

void LogicEngine::RenderFlicker()
{
	_pFlicker->Draw();
}

void LogicEngine::UpdateFlicker()
{
	if( MCIVStateController::instance().GetState() == MCIVStateController::FLICKER )
	{
		if( MCIVStateController::instance().FlickerNextImage )
		{
			_pFlicker->NextImage();
			MCIVStateController::instance().FlickerNextImage = false;
		}

		if( MCIVStateController::instance().FlickerPreviousImage ) 
		{
			_pFlicker->PreviousImage();
			MCIVStateController::instance().FlickerPreviousImage = false;
		}

		if( MCIVStateController::instance().FlickerImageZoomIn )
		{
			_pFlicker->GetCurrentImage()->ZoomIn();
			MCIVStateController::instance().FlickerImageZoomIn = false;
		}

		if( MCIVStateController::instance().FlickerImageZoomOut )
		{
			_pFlicker->GetCurrentImage()->ZoomOut();
			MCIVStateController::instance().FlickerImageZoomOut = false;
		}

		if( MCIVStateController::instance().FlickerPanUp )
		{
			_pFlicker->GetCurrentImage()->PanUp();
			MCIVStateController::instance().FlickerPanUp = false;
		}

		if( MCIVStateController::instance().FlickerPanDown )
		{
			_pFlicker->GetCurrentImage()->PanDown();
			MCIVStateController::instance().FlickerPanDown = false;
		}

		if( MCIVStateController::instance().FlickerPanLeft )
		{
			_pFlicker->GetCurrentImage()->PanLeft();
			MCIVStateController::instance().FlickerPanLeft = false;
		}

		if( MCIVStateController::instance().FlickerPanRight )
		{
			_pFlicker->GetCurrentImage()->PanRight();
			MCIVStateController::instance().FlickerPanRight = false;
		}
	}
}


