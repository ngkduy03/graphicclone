#include "Vector.h"



//========================Vector 2d===============================
Vector2D::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D()
{
	this->x = 0;
	this->y = 0;
}

Vector2D Vector2D::operator+(const Vector2D& right)
{

	return Vector2D(this->x+right.x,this->y+right.y);
}

Vector2D Vector2D::operator+=(const Vector2D& right)
{
	this->x += right.x;
	this->y += right.y;
	return *this;
}
Vector2D Vector2D::operator-(const Vector2D& right)
{

	return Vector2D(this->x - right.x, this->y - right.y);
}

Vector2D Vector2D::operator-=(const Vector2D& right)
{
	this->x -= right.x;
	this->y -= right.y;
	return *this;
}


Vector2D Vector2D::operator*(const int& right)
{
	return Vector2D(this->x * right,this->y * right);
}

bool Vector2D::operator==(const Vector2D& right)
{
	return (this->x == right.x) && (this->y == right.y);
}

int Vector2D::Dot(const Vector2D& right)
{
	return this->x*right.x+this->y*right.y;
}

Vector2D Vector2D::operator/(const int& right)
{
	if (right == 0)
	{
		return *this;
	}
	else
	{
		return Vector2D(this->x / right, this->y / right);
	}
}

//========================Vector 3d===============================

Vector3D::Vector3D(int x, int y,int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::Vector3D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3D Vector3D::operator+(const Vector3D& right)
{

	return Vector3D(this->x + right.x, this->y + right.y,this->z+right.z);
}

Vector3D Vector3D::operator+=(const Vector3D& right)
{
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;
	return *this;
}
Vector3D Vector3D::operator-(const Vector3D& right)
{

	return Vector3D(this->x - right.x, this->y - right.y, this->z - right.z);
}

Vector3D Vector3D::operator-=(const Vector3D& right)
{
	this->x -= right.x;
	this->y -= right.y;
	this->z -= right.z;
	return *this;
}

bool Vector3D::operator==(const Vector3D& right)
{
	return (this->x==right.x) && (this->y==right.y) && (this->z == right.z);
}


Vector3D Vector3D::operator*(const int& right)
{
	return Vector3D(this->x * right, this->y * right,this->z*right);
}

Vector3D Vector3D::operator*(const Vector3D& right)
{
	int x = this->y * right.z - right.y * this->z;
	int y = this->z * right.x - right.z * this->x;
	int z = this->x * right.y - this->y * right.x;
	return Vector3D(x,y,z);
}

Vector3D Vector3D::operator/(const int& right)
{
	if (right == 0)
	{
		return *this;
	}
	else
	{
		return Vector3D(this->x / right, this->y / right,this->z/right);
	}
}

int Vector3D::Dot(const Vector3D& right)
{
	return this->x * right.x + this->y * right.y+this->z*right.z;
}
