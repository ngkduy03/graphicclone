#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

int main()
{
	char screen[60][20];
	int width = 60;
	int height = 20;
	srand(time(NULL));
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (y > 0 && y <height-1 && x>0 && x<width-1)
			{
				screen[x][y] = ' ';
			}
			else
			{
				if (y == 0 || y == 19 ) 
				{
					switch (x)
					{
					case 0:
						if (y == 0)
						{
							screen[x][y] = 201;
						}
						else
						{
							screen[x][y] = 200;
						}
						break;
					case 59:
						if (y == 0)
						{
							screen[x][y] = 187;
						}
						else
						{
							screen[x][y] = 188;
						}
						break;
					default:
						screen[x][y] = 205;
						break;
					}
				}
				else
				{
					screen[x][y] = 186;
				}
			}
		}
	}

	
	int SnakeX = rand() % 58 + 1;
	int Snakey = rand() % 18 + 1;
	int Snake[2] = { SnakeX,Snakey};
	
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (x == Snake[0] && y == Snake[1])
			{
				screen[x][y] = '*';
			}
		}
	}







	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cout.width(1);
			cout << screen[x][y];
		}
		cout << endl;
	}
	
	return 0;
}