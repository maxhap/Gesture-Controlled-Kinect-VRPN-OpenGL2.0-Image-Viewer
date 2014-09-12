#include "stdafx.h"
#include "Vector3f.h"

Vector3f::Vector3f()
{
	_XYZ[0] = 0.0f;
	_XYZ[1] = 0.0f;
	_XYZ[2] = 0.0f;
}

Vector3f::Vector3f( float x, float y, float z )
{
	_XYZ[0] = x;
	_XYZ[1] = y;
	_XYZ[2] = z;
}

Vector3f::Vector3f( Vector3f& vec )
{
	_XYZ[0] = vec[0];
	_XYZ[1] = vec[1];
	_XYZ[2] = vec[2];
}

float &Vector3f::operator[]( int index ) 
{
	return _XYZ[index];
}

float Vector3f::operator[]( int index ) const 
{
	return _XYZ[index];
}

//Vector3f Vector3f::operator*( float scale ) const 
//{
//	return Vector3f( _XYZ[0] * scale, _XYZ[1] * scale, _XYZ[2] * scale );
//}

Vector3f Vector3f::operator/(float scale) const 
{
	return Vector3f( _XYZ[0] / scale, _XYZ[1] / scale, _XYZ[2] / scale );
}

Vector3f Vector3f::operator+(const Vector3f &other) const 
{
	return Vector3f( _XYZ[0] + other._XYZ[0], _XYZ[1] + other._XYZ[1], _XYZ[2] + other._XYZ[2] );
}

Vector3f Vector3f::operator-(const Vector3f &other) const 
{
	return Vector3f( _XYZ[0] - other._XYZ[0], _XYZ[1] - other._XYZ[1], _XYZ[2] - other._XYZ[2] );
}

Vector3f Vector3f::operator-() const 
{
	return Vector3f( -_XYZ[0], -_XYZ[1], -_XYZ[2] );
}

//const Vector3f &Vector3f::operator*=( float scale ) 
//{
//	_XYZ[0] *= scale;
//	_XYZ[1] *= scale;
//	_XYZ[2] *= scale;
//	return *this;
//}

const Vector3f &Vector3f::operator/=( float scale ) 
{
	_XYZ[0] /= scale;
	_XYZ[1] /= scale;
	_XYZ[2] /= scale;
	return *this;
}

const Vector3f &Vector3f::operator+=( const Vector3f &other ) 
{
	_XYZ[0] += other._XYZ[0];
	_XYZ[1] += other._XYZ[1];
	_XYZ[2] += other._XYZ[2];
	return *this;
}

const Vector3f &Vector3f::operator-=( const Vector3f &other ) 
{
	_XYZ[0] -= other._XYZ[0];
	_XYZ[1] -= other._XYZ[1];
	_XYZ[2] -= other._XYZ[2];
	return *this;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: magnitude
Description: return vector magnitude
-------------------------------------------------------------------------------------------*/
float Vector3f::magnitude() const 
{
	return sqrt( _XYZ[0] * _XYZ[0] + _XYZ[1] * _XYZ[1] + _XYZ[2] * _XYZ[2] );
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: magnitudeSquared
Description: returns the magnitude squared aka not square rooting 
-------------------------------------------------------------------------------------------*/
float Vector3f::magnitudeSquared() const 
{
	return _XYZ[0] * _XYZ[0] + _XYZ[1] * _XYZ[1] + _XYZ[2] * _XYZ[2];
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: normalize
Description: returns a new normalized vector
-------------------------------------------------------------------------------------------*/
Vector3f Vector3f::normalize() const 
{
	float m = sqrt( _XYZ[0] * _XYZ[0] + _XYZ[1] * _XYZ[1] + _XYZ[2] * _XYZ[2] );
	return Vector3f( _XYZ[0] / m, _XYZ[1] / m, _XYZ[2] / m );
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: dot
Description: returns the dot product
-------------------------------------------------------------------------------------------*/
float Vector3f::dot( const Vector3f &other ) const 
{
	return _XYZ[0] * other._XYZ[0] + _XYZ[1] * other._XYZ[1] + _XYZ[2] * other._XYZ[2];
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: cross
Description: returns the cross product
-------------------------------------------------------------------------------------------*/
Vector3f Vector3f::cross( const Vector3f &other ) const 
{
	return Vector3f( _XYZ[1] * other._XYZ[2] - _XYZ[2] * other._XYZ[1], _XYZ[2] * other._XYZ[0] - _XYZ[0] * other._XYZ[2],
		_XYZ[0] * other._XYZ[1] - _XYZ[1] * other._XYZ[0] );
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: set
Description: set x y z with parameters 
-------------------------------------------------------------------------------------------*/
void Vector3f::set( float fX, float fY, float fZ )
{
	_XYZ[0] = fX;
	_XYZ[1] = fY;
	_XYZ[2] = fZ;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: x
Description: returns _pXYZ[0] 
-------------------------------------------------------------------------------------------*/
float Vector3f::x()
{
	return _XYZ[0];
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: x
Description: set _XYZ[0]
-------------------------------------------------------------------------------------------*/
void Vector3f::x( float fVal )
{
	_XYZ[0] = fVal;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: y
Description: returns _pXYZ[1] 
-------------------------------------------------------------------------------------------*/
float Vector3f::y()
{
	return _XYZ[1];
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: y
Description: set _pXYZ[1] 
-------------------------------------------------------------------------------------------*/
void Vector3f::y( float fVal )
{
	_XYZ[1] = fVal;
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: z
Description: returns _pXYZ[2] 
-------------------------------------------------------------------------------------------*/
float Vector3f::z()
{
	return _XYZ[2];
}

/*-------------------------------------------------------------------------------------------
Author: Max Ashton
Method: z
Description: set _pXYZ[2] 
-------------------------------------------------------------------------------------------*/
void Vector3f::z( float fVal )
{
	_XYZ[2] = fVal;
}
