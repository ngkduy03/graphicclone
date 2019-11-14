#include "Vector.h"

Vector::Vector(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Vector::GetX()
{
	return this->x;
}

int Vector::GetY()
{
	return this->y;
}

void Vector::SetPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Vector::add(Vector Vec)
{
	this->x += Vec.GetX();
	this->y += Vec.GetY();
}

void Vector::minus(Vector Vec)
{
	this->x -= Vec.GetX();
	this->y -= Vec.GetY();
}

void Vector::multiply(int k)
{
	this->x *= k;
	this->y *= k;
}

void Vector::Normalize()
{
	this->x /= this->length();
	this->y /= this->length();
}
int Vector::divide(int k)
{
	if (k != 0)
	{
		this->x /= k;
		this->y /= k;
		return 1;
	}
	else
	{
		return 0;
	}
}

double Vector::length()
{
	double length = this->x * this->x + this->y*this->y;
	length = sqrt(length);
	return length;
}