#ifndef _LOGICENGINE_
#define _LOGICENGINE_

#include <MCIVKinectVRPN/VRPNClient.h>
#include <MCIVUtilities/BodyDefs.h>
#include <MCIVUtilities/HumainBody.h>
#include <MCIVKinectGestureManager/MCIVKinectGestureManager.h>
#include <MCIVStateController/MCIVStateController.h>
#include <MCIVUtilities/Vector3f.h>
#include "stdafx.h"
#include "Carousel.h"
#include "StartMenu.h"
#include "ImageCarouselMenuItem.h"
#include "Hand.h"
#include "BackToMainMenu.h"
#include "BackToMainMenuItem.h"
#include "ImageFlickerMenuItem.h"
#include "Flicker.h"

class LogicEngine
{

public:

	LogicEngine();
	~LogicEngine();

	bool Initialize();
	bool Quit();

	void GameLoop();

	static bool TwoObjectsCollided( MaxRectangle* pFirst, MaxRectangle* pSecond );

private:

	SDL_Event event;

	GLfloat _Angle;	

	bool _Quit;

	GameTimer* _pGameTimer;
	SDL_Surface* _pScreen;

	Camera* _Camera;
	Carousel* _pCarousel;
	
	Flicker* _pFlicker;

	StartMenu* _pStartMenu;
	BackToMainMenu* _pBackToMainMenu;

	unsigned int _uiGameState;
	
	HumainBody* _pHumainBodyZero;

	Hand* _pHand;	

	void HandleEvents();
	void Render();
	void RenderMainMenu();
	void RenderCarousel();
	void RenderFlicker();
	void SetUpCarousel();
	void SetUpFlicker();
	void SetUpStartMenu();
	void SetUpHand();
	void CarouselUpdate();
	void InitVRPN();
	void UpdateVRPNAndGestures();
	void UpdateFlicker();
	void HandLogic();
	void SetNewCameraPosition();

	bool InitGL();
	bool CleanUp();		
};


#endif