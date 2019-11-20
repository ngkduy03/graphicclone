#pragma once
#include <math.h>




class Vector2D
{
public:
	int x;
	int y;
	Vector2D(int x, int y);
	Vector2D();
	Vector2D operator +(const Vector2D& right);
	Vector2D operator +=(const Vector2D& right);
	Vector2D operator -(const Vector2D& right);
	Vector2D operator -=(const Vector2D& right);
	Vector2D operator *(const int& right);
	bool operator ==(const Vector2D& right);
	int Dot(const Vector2D& right);
	Vector2D operator /(const int& right);
};

class Vector3D :public Vector2D
{
public:
	int z;
	Vector3D(int x, int y,int z);
	Vector3D();
	Vector3D operator +(const Vector3D& right);
	Vector3D operator +=(const Vector3D& right);
	Vector3D operator -(const Vector3D& right);
	Vector3D operator -=(const Vector3D& right);
	bool operator ==(const Vector3D& right);
	Vector3D operator *(const int& right);
	Vector3D operator *(const Vector3D& right);
	Vector3D operator /(const int& right);
	int Dot(const Vector3D& right);
};
