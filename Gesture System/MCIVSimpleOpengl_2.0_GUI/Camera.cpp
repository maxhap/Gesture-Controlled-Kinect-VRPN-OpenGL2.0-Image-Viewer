#include "stdafx.h"

Camera::Camera()
{	
	//initializes xyz to 0 as default
	_Position = Vector3f();
	_ViewDirection = Vector3f( 0.0f, 0.0f, -1.0f);

	_MovementMultiplier = 1;
	_ViewDirectionChanged = false;

	_RotatedX = _RotatedY = _RotatedZ = 0.0;
	_RotationSpeed = 0.0f;
	_ForwardSpeed = 0.0f;
	_StrafingSpeed = 0.0f;
	_JumpingSpeed = 0.0f;

	_pCameraMatrix = new float[4];
}

Camera::~Camera()
{
	delete _pCameraMatrix;
}

void Camera::RecalculateViewDirection()
{
	Vector3f Step1, Step2;
	//Rotate around Y-axis:
	Step1[0] = cos( ( _RotatedY + 90.0f ) * ( float ) PIdiv180 );
	Step1[2] = -sin( ( _RotatedY + 90.0f ) * ( float ) PIdiv180 );
	//Rotate around X-axis:
	float cosX = cos ( _RotatedX * ( float ) PIdiv180 );
	Step2[0] = Step1[0] * cosX;
	Step2[2] = Step1[2] * cosX;
	Step2[1] = sin( _RotatedX * ( float ) PIdiv180 );
	//Rotation around Z-axis not yet implemented, so:
	_ViewDirection = Step2;
}

void Camera::Move( Vector3f Direction)
{
	_Position += Direction;
}

void Camera::RotateY( ::GLfloat Angle )
{
	_RotatedY += Angle;
	_ViewDirectionChanged = true;
}

void Camera::RotateX ( ::GLfloat Angle)
{
	_RotatedX += Angle;
	_ViewDirectionChanged = true;
}

void Camera::RotateZ( ::GLfloat Angle )
{
	_RotatedZ += Angle;
	_ViewDirectionChanged = true;
}

void Camera::Render( void )
{
	glRotatef( -_RotatedX , 1.0, 0.0, 0.0);
	glRotatef( -_RotatedY , 0.0, 1.0, 0.0);
	glRotatef( -_RotatedZ , 0.0, 0.0, 1.0);
	glTranslatef( -_Position[0], -_Position[1], -_Position[2] );
}

void Camera::MoveForwards( ::GLfloat Distance )
{
	if ( _ViewDirectionChanged )
	{
		RecalculateViewDirection();
	}

	Vector3f MoveVector;
	MoveVector[0] = _ViewDirection[0] * -Distance;
	MoveVector[1] = _ViewDirection[1] * -Distance;
 	MoveVector[2] = _ViewDirection[2] * -Distance;
	_Position += MoveVector;
}

void Camera::StrafeRight ( ::GLfloat Distance )
{
	if ( _ViewDirectionChanged )
	{
		RecalculateViewDirection();
	}

	if( Distance > 0 )
	{
		cout << "";
	}
	Vector3f MoveVector;
	MoveVector[2] = -_ViewDirection[0] * -Distance;
	MoveVector[1] = 0.0;
	MoveVector[0] = _ViewDirection[2] * -Distance;
	_Position += MoveVector;
}

void Camera::HandleMovement( SDL_Event event )
{
	//pop event from sdl key stack
	SDLKey key = event.key.keysym.sym;		

	if( event.type == SDL_KEYDOWN )
	{
		if( key == SDLK_w )
		{
			_ForwardSpeed = -0.5f;
		}
		else if( key == SDLK_s )
		{
			_ForwardSpeed = 0.5f;
		}
		else if( key == SDLK_a )
		{
			_StrafingSpeed = -0.5f;
		}
		else if( key == SDLK_d )
		{
			_StrafingSpeed = 0.5f;
		}
		else if( key == SDLK_LEFT )
		{
			_RotationSpeed = 2.0f;
		}
		else if( key == SDLK_RIGHT )
		{
			_RotationSpeed = -2.0f;
		}
		else if( key == SDLK_UP )
		{
			_JumpingSpeed = -1.0f;
		}
		else if( key == SDLK_DOWN )
		{
			_JumpingSpeed = 1.0f;
		}
		else if( key == SDLK_RSHIFT || key == SDLK_LSHIFT )
		{
			_MovementMultiplier = 4;
		}
	}
	else if ( event.type == SDL_KEYUP )
	{
		if( key == SDLK_w )
		{
			_ForwardSpeed = 0.0f;
		}
		else if( key == SDLK_s )
		{
			_ForwardSpeed = 0.0f;
		}
		else if( key == SDLK_a )
		{
			_StrafingSpeed = 0.0f;
		}
		else if( key == SDLK_d )
		{
			_StrafingSpeed = 0.0f;
		}
		else if( key == SDLK_LEFT )
		{
			_RotationSpeed = 0.0f;
		}
		else if( key == SDLK_RIGHT )
		{
			_RotationSpeed = 0.0f;
		}
		else if( key == SDLK_UP )
		{
			_JumpingSpeed = 0.0f;
		}
		else if( key == SDLK_DOWN )
		{
			_JumpingSpeed = 0.0f;
		}
		else if( key == SDLK_RSHIFT || key == SDLK_LSHIFT )
		{
			_MovementMultiplier = 1;
		}
	}
}

void Camera::MoveUp( ::GLfloat Distance )
{
	if ( _ViewDirectionChanged )
	{
		RecalculateViewDirection();
	}

	Vector3f MoveVector;
	MoveVector[0] = 0;
	MoveVector[1] = _ViewDirection[1] + -Distance;
	MoveVector[2] = 0;
	_Position+= MoveVector;

}

void Camera::Update()
{
	MoveForwards( _ForwardSpeed * _MovementMultiplier);
	StrafeRight( _StrafingSpeed * _MovementMultiplier);
	RotateY( _RotationSpeed * _MovementMultiplier);
	MoveUp( _JumpingSpeed * _MovementMultiplier);
}

float* Camera::GetMatrix()
{
	_pCameraMatrix[0] = _Position[0];
	_pCameraMatrix[1] = _Position[1];
	_pCameraMatrix[2] = _Position[2];
	_pCameraMatrix[3] = 0.0f;

	return _pCameraMatrix;
}

void Camera::SetPosition( Vector3f position )
{
	_Position = position;
}
