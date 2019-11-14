#pragma once
class Vector
{
private:
	int x;
	int y;
public:
	Vector(int x, int y);
	int GetX();
	int GetY();
	void SetPos(int x, int y);
	int add(Vector vector);
	int minus(Vector vector);
	int multiply(int k);
	int divide(int k);
	void Normalize();
	double length();
};

