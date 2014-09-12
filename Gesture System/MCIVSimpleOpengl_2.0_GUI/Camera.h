#ifndef _CAMERA_
#define _CAMERA_

#include "stdafx.h"

class Camera
{

public:

	Camera();
	~Camera();

	void Render();

	float* GetMatrix();

	void Move ( Vector3f Direction );
	void RotateX ( ::GLfloat Angle );
	void RotateY ( ::GLfloat Angle );
	void RotateZ ( ::GLfloat Angle );
	void RotateXYZ ( Vector3f Angles );
	void MoveForwards ( ::GLfloat Distance );
	void StrafeRight ( ::GLfloat Distance );
	void MoveUp( ::GLfloat Distance );
	void HandleMovement( SDL_Event event );
	void Update();
	void SetPosition( Vector3f position );

private:

	Vector3f _Position;
	Vector3f _ViewDirection;

	int _MovementMultiplier;	

	bool _ViewDirectionChanged;

	GLfloat _RotationSpeed;
	GLfloat _ForwardSpeed;
	GLfloat _StrafingSpeed;
	GLfloat _JumpingSpeed;	
	GLfloat _RotatedX;
	GLfloat _RotatedY;
	GLfloat _RotatedZ;

	float* _pCameraMatrix;

	void RecalculateViewDirection();

};


#endif