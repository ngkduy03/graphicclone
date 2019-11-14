#include "Graphic.h"
Graphic::Graphic(int width, int height)
{
	int total_pixels = (width+3) * (height+2);
	this->width = width;
	this->height = height;
	this->eol = width + 2;
	screen.resize(total_pixels,' ');
	for (int pixel = 0; pixel < total_pixels; pixel++)
	{
		if (pixel % (width + 3) == eol)
		{
			this->screen[pixel] = '\n';
		}
		else
		{
			if (pixel % (width + 3) == 0 || pixel % (width + 3) == width + 1||(pixel/(width+3))==0|| (pixel / (width + 3)) == height+1)
			{
				this->screen[pixel] = '*';
			}
			else
			{
				this->screen[pixel] = ' ';
			}
		}
	}
}

void Graphic::clear()
{
	for (int pixel = 0; pixel <screen.length(); pixel++)
	{
		if (pixel % (width + 3) == eol)
		{
			this->screen[pixel] = '\n';
		}
		else
		{
			if (pixel % (width + 3) == 0 || pixel % (width + 3) == width + 1 || (pixel / (width + 3)) == 0 || (pixel / (width + 3)) == height + 1)
			{
				this->screen[pixel] = '*';
			}
			else
			{
				this->screen[pixel] = ' ';
			}
		}
	}
}

void Graphic::update(int obj[2],char shape)
{
	for (int pixel = 0; pixel < screen.size(); pixel++)
	{
		int pX = pixel % (width + 3);
		int pY = pixel /(width + 3);
		if (pX - 1 == obj[0] && pY - 1 == obj[1])
		{
			screen[pixel] = shape;
		}
	}

}

void Graphic::draw()
{
	std::cout.width(1);
	std::cout << screen;
}