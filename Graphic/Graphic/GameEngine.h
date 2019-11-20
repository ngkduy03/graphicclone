#pragma once
#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

class GameEngine
{
private:
	string screen;
	int w, h;
	int total_pixels;
public:
	GameEngine() { screen = "Uninitialize"; }
	GameEngine(int w,int h);
	void Init(int w, int h);

	void Draw();
	void Render(Vector2D vec, char shape);
	void Clear();
	int GetWidth()
	{
		return this->w;
	}

	int GetHeight()
	{
		return this->h;
	}
};

