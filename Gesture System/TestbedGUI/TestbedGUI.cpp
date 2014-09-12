// TestbedGUI.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <string>
#include <malloc.h>
#include <boost\timer.hpp>

#ifdef WIN32
#pragma warning( disable : 4996 )
#endif

#include <MCIVKinectVRPN/VRPNClient.h>
#include <MCIVUtilities/BodyDefs.h>
#include <MCIVUtilities/HumainBody.h>
#include <MCIVKinectGestureManager/MCIVKinectGestureManager.h>


/* ------------------ file paths----------------------*/
string _sGestureFile = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Development\\raaIVInst64\\data\\position_test.txt";
//string _sGestureFile = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Development\\raaIVInst64\\data\\timetest.txt";

string _sRightGestureTexture = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\right_gesture.bmp";
string _sLeftGestureTexture = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\left_gesture.bmp";
string _sUpGestureTexture = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\above_gesture.bmp";
string _sDownGestureTexture = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\below_gesture.bmp";
string _sInfrontGestureTexture = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\infront_gesture.bmp";
string _sBehindGestureTexture = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\behind_gesture.bmp";
string _sTogetherGestureTexture = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\together_gesture.bmp";
string _sApartGestureTexture = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\apart_gesture.bmp";
string _sAndGestureTexture = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\andinfront_gesture.bmp";
string _sOrGestureTexture = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\orbehind_gesture.bmp";
string _sVelocityGestureTexture = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\velocity_gesture.bmp";
string _sConditionalVelocityGestureTextureA = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\conditional_velocity_gesture_active.bmp";
string _sConditionalVelocityGestureTextureNA = "C:\\SVN_Repositories\\media_city_image_viewer\\trunk\\Photoshop\\conditional_velocity_gesture_nonactive.bmp";
/* ------------------ end of file paths----------------------*/

HumainBody* _pHumainBody;
HumainBody* _pHumainBody2;
HumainBody* _pHumainBody3;
HumainBody* _pHumainBody4;

void display();
void idle();
void keyboard( unsigned char c, int iXPos, int iYPos );
void mouse( int iKey, int iEvent, int iXPos, int iYPos );
void reshape( int iWidth, int iHeight );
void init();
void drawGestureQuest();
void draw_textured_quad( GLuint uiTextureID );
void buildTextures();
void timeOutEventFunction( unsigned int uiSkeleton, string sActionName );
void eventFunction( unsigned int uiSkeleton, string sActionName );

boost::timer* _pTimer;
using namespace std;

int _iGetureTestState;

GLuint* _uiTextureIDs;


int main(int argc, char* argv[])
{		
	cout << " TestbedGUI initialized";

	_pTimer = new boost::timer;

	_iGetureTestState = 0;	

	glutInit( &argc, argv ); 

	// create a glut window
	glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA );
	glutInitWindowPosition( 500,300 );
	glutInitWindowSize( 1024, 768 );
	glutCreateWindow( "MCIV Test" );

	init();
	buildTextures();

	glutDisplayFunc( display ); 
	glutIdleFunc( idle ); 
	glutReshapeFunc( reshape );
	glutKeyboardFunc( keyboard );
	glutMouseFunc( mouse );

	glutMainLoop();

	return 0;
}

void init()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f ); 
	glEnable( GL_LIGHTING );
	glEnable( GL_DEPTH_TEST );
	glEnable( GL_LIGHT0 );

	VRPNClient::instance().setMultiThreaded( false );
	VRPNClient::instance().addTracker( "Tracker0@localhost");
	VRPNClient::instance().addTracker( "Tracker1@localhost");
	VRPNClient::instance().addTracker( "Tracker2@localhost");
	VRPNClient::instance().addTracker( "Tracker3@localhost");

	_pHumainBody = VRPNClient::instance().getTrackerData( "Tracker0@localhost" );
	_pHumainBody2 = VRPNClient::instance().getTrackerData( "Tracker1@localhost" );
	_pHumainBody3 = VRPNClient::instance().getTrackerData( "Tracker2@localhost" );
	_pHumainBody4 = VRPNClient::instance().getTrackerData( "Tracker3@localhost" );


	MCIVKinectGestureManager::instance().setSuccessfullEventFunction( &eventFunction );
	MCIVKinectGestureManager::instance().setTimeoutEventFunction( &timeOutEventFunction );
	MCIVKinectGestureManager::instance().start( _sGestureFile );

}

void* loadBitmap( const char *pcFile, unsigned int &uiWidth, unsigned int &uiHeight )
{
	FILE *pFile=0;            
	void *pvBits=0;
	long lBitsize=0, lInfosize=0;
	BITMAPFILEHEADER header;
	BITMAPINFO *pInfo=0;

	if(pFile=fopen(pcFile, "rb"))
	{
		if(fread(&header, sizeof(BITMAPFILEHEADER), 1, pFile)==1&&header.bfType=='MB'&&(pInfo=(BITMAPINFO *)_alloca(lInfosize=header.bfOffBits-sizeof(BITMAPFILEHEADER)))&&fread(pInfo, 1, lInfosize, pFile)==lInfosize&&(pvBits=malloc(lBitsize=(((uiWidth=pInfo->bmiHeader.biWidth)*pInfo->bmiHeader.biBitCount+7)>>3)*(uiHeight=pInfo->bmiHeader.biHeight)))&&fread(pvBits,1,lBitsize,pFile)!=lBitsize)
		{
			free(pvBits);
			pvBits=0;
		}
		fclose(pFile);
	}
	return pvBits;
}

GLuint load_texture( string sFileName, unsigned int uiWidth, unsigned int uiHeight )
{	
	void* pCBmp = loadBitmap( sFileName.c_str() , uiWidth, uiHeight );

	GLuint guiTextureID;
	glGenTextures( 1, &guiTextureID );
	glBindTexture( GL_TEXTURE_2D, guiTextureID );

	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, uiWidth, uiHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, pCBmp );

	//clean up pixel data;
	delete pCBmp;
	pCBmp = 0;

	return guiTextureID;
}

void buildTextures()
{
	_uiTextureIDs = new GLuint[13];
	_uiTextureIDs[0] = load_texture( _sRightGestureTexture, 240, 150 );
	_uiTextureIDs[1] = load_texture( _sLeftGestureTexture, 240, 150 );
	_uiTextureIDs[2] = load_texture( _sUpGestureTexture, 240, 150 );
	_uiTextureIDs[3] = load_texture( _sDownGestureTexture, 240, 150 );
	_uiTextureIDs[4] = load_texture( _sInfrontGestureTexture, 240, 150 );
	_uiTextureIDs[5] = load_texture( _sBehindGestureTexture, 240, 150 );
	_uiTextureIDs[6] = load_texture( _sTogetherGestureTexture, 240, 150 );
	_uiTextureIDs[7] = load_texture( _sApartGestureTexture, 240, 150 );
	_uiTextureIDs[8] = load_texture( _sAndGestureTexture, 240, 150 );
	_uiTextureIDs[9] = load_texture( _sOrGestureTexture, 240, 150 );
	_uiTextureIDs[10] = load_texture( _sVelocityGestureTexture, 240, 150 );
	_uiTextureIDs[11] = load_texture( _sConditionalVelocityGestureTextureA, 240, 150 );
	_uiTextureIDs[12] = load_texture( _sConditionalVelocityGestureTextureNA, 240, 150 );
}

void eventFunction( unsigned int uiSkeleton, string sActionName )
{
	cout << "\n --------- Action Event -----------" ;
	cout << "\n";
	cout << "\n      Skeleton " << uiSkeleton << ": " << sActionName << "\n";

	//change state
	if( sActionName.compare( "RightHandRightOfTorso" ) == 0 )
	{
		_iGetureTestState = 1;
	}
	else if( sActionName.compare( "RightHandLeftOfTorso" ) == 0 )
	{
		_iGetureTestState = 2;
	}
	else if( sActionName.compare( "RightHandAboveHead" ) == 0 )
	{
		_iGetureTestState = 3;
	}
	else if( sActionName.compare( "RightHandBelowTorso" ) == 0 )
	{
		_iGetureTestState = 4;
	}
	else if( sActionName.compare( "RightHandInfrontOfTorso" ) == 0 )
	{
		_iGetureTestState = 5;
	}
	else if( sActionName.compare( "RightHandBehindTorso" ) == 0 )
	{
		_iGetureTestState = 6;
	}
	else if( sActionName.compare( "RightHandLeftHandTogether" ) == 0 )
	{
		_iGetureTestState = 7;
	}
	else if( sActionName.compare( "RightHandLeftHandApart" ) == 0 )
	{
		_iGetureTestState = 8;
	}
	else if( sActionName.compare( "LefHandRightHandInfrontTorsoAnd" ) == 0 )
	{
		_iGetureTestState = 9;
	}
	else if( sActionName.compare( "LefHandRightHandBehindTorsoOr" ) == 0 )
	{
		_iGetureTestState = 10;
	}
	else if( sActionName.compare( "RightHandVelocity" ) == 0 )
	{
		_iGetureTestState = 11;
	}
	else if( sActionName.compare( "ConditionalVelocityRightHand" ) == 0 )
	{
		_pTimer->restart();		
	}	
	else if( sActionName.compare( "RightHandConditionalEndPoint" ) == 0 )
	{
		_iGetureTestState = 12;
	}
	else if( sActionName.compare( "TimeBreak" ) == 0 )
	{
		_iGetureTestState = 0;
	}

}

void timeOutEventFunction( unsigned int uiSkeleton, string sActionName )
{
	cout << "\n --------- Time Out Event -----------" ;
	cout << "\n";
	cout << "\n      Skeleton " << uiSkeleton << ": " << sActionName << "\n";

	_iGetureTestState = 0;
}

float sdata[] = {1.0f, 1.0f, 1.0f, 1.0f};

void draw_sphere( const float* pfData )
{
	glPushMatrix();

	glPushAttrib( GL_ALL_ATTRIB_BITS );
	glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, sdata  );
	glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, sdata); 
	glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, sdata); 
	glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 100.0f );

	glTranslatef( pfData[0], pfData[1], pfData[2] );

	glutSolidSphere( 0.1f, 20.0f, 20.0f );

	glPopAttrib();

	glPopMatrix();
}

int cap = 0;

void display()
{	
	glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();

	gluLookAt(0.0f, 0.2f, -2.0f, 0.0f, 0.2f, 0.0f, 0.0f, 1.0f, 0.0f);

	drawGestureQuest();

	glPushMatrix();
	glTranslatef( 0.0f, 0.0f, 5.0f );	
	
	if( _pHumainBody && VRPNClient::instance().getTrackerAlive( "Tracker0@localhost" ) )
	{
		if( cap == 10 )
		{
			float vel = _pHumainBody->GetBodyPart( 14 )->getVelocity();
			stringstream stringStream (stringstream::in | stringstream::out);

			stringStream << vel;

			string sVel = "Right Hand Velocity " + stringStream.str(); 

			glutSetWindowTitle( sVel.c_str() );
			 
			cap = 0;
		}
		else
		{
			cap++;
		}
		
		for( int i = 0; i < 24; i++ )
		{
			const float* pfData = _pHumainBody->GetBodyPart( i )->getPosition();

			draw_sphere( pfData );
		}
	}

	if( _pHumainBody2 && VRPNClient::instance().getTrackerAlive( "Tracker1@localhost" ) )
	{
		for( int i = 0; i < 24; i++ )
		{
			const float* pfData = _pHumainBody2->GetBodyPart( i )->getPosition();

			draw_sphere( pfData );
		}
	}

	if( _pHumainBody3 && VRPNClient::instance().getTrackerAlive( "Tracker2@localhost" ) )
	{
		for( int i = 0; i < 24; i++ )
		{
			const float* pfData = _pHumainBody3->GetBodyPart( i )->getPosition();

			draw_sphere( pfData );
		}
	}

	if( _pHumainBody4 && VRPNClient::instance().getTrackerAlive( "Tracker3@localhost" ) )
	{
		for( int i = 0; i < 24; i++ )
		{
			const float* pfData = _pHumainBody4->GetBodyPart( i )->getPosition();

			draw_sphere( pfData );
		}
	}		

	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void idle()
{
	VRPNClient::instance().manualLoopAllTrackers();
	MCIVKinectGestureManager::instance().proceedGestures();
	
	glutPostRedisplay();
}

void reshape(int iWidth, int iHeight)
{
	glViewport( 0, 0, iWidth, iHeight );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 30.0f, ( ( float ) iWidth ) / ( ( float ) iHeight ), 1.0f, 1000.0f );
	glMatrixMode( GL_MODELVIEW );
	glutPostRedisplay();
}

void keyboard(unsigned char c, int iXPos, int iYPos)
{
	glutPostRedisplay();
}

void mouse(int iKey, int iEvent, int iXPos, int iYPos)
{

}

void drawGestureQuest()
{
	glPushMatrix();
	glDisable( GL_LIGHTING );

	if( _iGetureTestState == 0 )
	{
		glTranslatef( 1.5f, 0.0f, 0.0f );
		draw_textured_quad( _uiTextureIDs[0] );		
	}
	else if( _iGetureTestState == 1 )
	{
		glTranslatef( -1.5f, 0.0f, 0.0f );
		draw_textured_quad( _uiTextureIDs[1] );		
	}
	else if( _iGetureTestState == 2 )
	{
		glTranslatef( 0.0f, 1.0f, 0.0f );
		draw_textured_quad( _uiTextureIDs[2] );	
	}
	else if( _iGetureTestState == 3 )
	{
		glTranslatef( 0.0f, -1.0f, 0.0f );
		draw_textured_quad( _uiTextureIDs[3] );		
	}

	else if( _iGetureTestState == 4 )
	{
		glTranslatef( -0.5f, -0.5f, 0.0f );
		draw_textured_quad( _uiTextureIDs[4] );		
	}

	else if( _iGetureTestState == 5 )
	{
		glTranslatef( 0.5f, -0.5f, 0.0f );
		draw_textured_quad( _uiTextureIDs[5] );		
	}

	else if( _iGetureTestState == 6 )
	{
		glTranslatef( -0.5f, 0.5f, 0.0f );
		draw_textured_quad( _uiTextureIDs[6] );		
	}

	else if( _iGetureTestState == 7 )
	{
		glTranslatef( 0.5f, 0.5f, 0.0f );
		draw_textured_quad( _uiTextureIDs[7] );		
	}

	else if( _iGetureTestState == 8 )
	{
		glTranslatef( -0.5f, -0.5f, 0.0f );
		draw_textured_quad( _uiTextureIDs[8] );		
	}

	else if( _iGetureTestState == 9 )
	{
		glTranslatef( 0.5f, -0.5f, 0.0f );
		draw_textured_quad( _uiTextureIDs[9] );		
	}

	else if( _iGetureTestState == 10 )
	{
		glTranslatef( 0.0f, 0.0f, 0.0f );
		draw_textured_quad( _uiTextureIDs[10] );		
	}

	else if( _iGetureTestState == 11 )
	{
		if( _pTimer->elapsed() < 0.2 )
		{
			glTranslatef( 0.0f, 0.0f, 0.0f );
			draw_textured_quad( _uiTextureIDs[11] );		
		}
		else
		{
			glTranslatef( 0.0f, 0.0f, 0.0f );
			draw_textured_quad( _uiTextureIDs[12] );		
		}		
	}

	glEnable( GL_LIGHTING );
	glPopMatrix();
}

/*--------------------------------------------
Author: Max Ashton
Description: Texture mapped to a simple quad consisting of 4 vertices's glbegin and glend
			 used to specify vertices's 
----------------------------------------------*/
void draw_textured_quad( GLuint uiTextureID )
{
	glPushMatrix();

	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, uiTextureID );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

	glTranslatef( 0.0f, 0.0f, 4.9f );

	glBegin(GL_QUADS);
	glColor3f( 1.0f, 1.0f, 1.0f );

	glNormal3f( 0.0, 0.0f, 1.0f);
	glTexCoord2f( 1.0f, 0.0f );
	glVertex3f( -0.5f, -0.5f, 0.0f );
	glTexCoord2f( 0.0f, 0.0f );
	glVertex3f( 0.5f, -0.5f, 0.0f );
	glTexCoord2f( 0.0f, 1.0f );
	glVertex3f( 0.5f, 0.5f, 0.0f );
	glTexCoord2f( 1.0f, 1.0f );
	glVertex3f( -0.5f, 0.5f, 0.0f );

	glEnd();	

	glDisable( GL_TEXTURE_2D );

	glPopMatrix();
}