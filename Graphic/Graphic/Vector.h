#pragma once
#include <math.h>
using namespace std;
class Vector
{
private:
	int x;
	int y;
public:
	Vector(int x, int y);
	Vector();
	int GetX();
	int GetY();
	void SetPos(int x, int y);
	void add(Vector vector);
	void minus(Vector vector);
	void multiply(int k);
	int divide(int k);
	void Normalize();
	double length();
};

