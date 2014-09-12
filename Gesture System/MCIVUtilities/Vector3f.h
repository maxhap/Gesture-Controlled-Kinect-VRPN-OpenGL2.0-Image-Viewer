#ifndef _VECTOR3f_
#define  _VECTOR3f_

#include "stdafx.h"
#include "MCIVUtilitiesDEFS.h"

#define PI 3.1415926535
#define PIdiv180 PI / 180

class MCIVUTILITIES_DLL_DEF Vector3f
{
public:

	Vector3f();
	Vector3f( float x, float y, float z );
	Vector3f( Vector3f& vec );

	float &operator[] ( int index );
	float operator[]( int index ) const;

	//Vector3f operator*( float scale ) const;
	Vector3f operator/( float scale ) const;
	Vector3f operator+( const Vector3f &other ) const;
	Vector3f operator-( const Vector3f &other ) const;
	Vector3f operator-() const;

	//const Vector3f &operator*=( float scale );
	const Vector3f &operator/=( float scale );
	const Vector3f &operator+=( const Vector3f &other );
	const Vector3f &operator-=( const Vector3f &other );

	float magnitude() const;
	float magnitudeSquared() const;
	Vector3f normalize() const;
	float dot( const Vector3f &other ) const;
	Vector3f cross( const Vector3f &other ) const;

	void set( float fX, float fY, float fZ);
	void x( float fVal );
	void y( float fVal );
	void z( float fVal);

	float x();
	float y();
	float z();

	
private:

	float _XYZ[3];

};

#endif
