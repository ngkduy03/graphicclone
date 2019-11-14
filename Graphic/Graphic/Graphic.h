#pragma once
#include <string>
#include <iostream>

using namespace std;

class Graphic
{
private:
	string screen;
	int width;
	int height;
	int eol;
public:
	Graphic(int width, int height);
	void draw();
	void clear();
	void fill(char fill);
	void update(int Snake[2],char shape);
	//~Graphic();

};

