#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "Vector.h"
using namespace std;

void Game_init(int *snake, int *food, int width, int height)
{
	srand(time(NULL)); //Create random seed;
	while (snake[0] == food[0] && snake[1] == food[1])
	{
		snake[0] = rand() % (width-2) +1 ;
		snake[1] = rand() % (height-2) + 1;
		food[0] = rand() % (width - 2) + 1;
		food[1] = rand() % (height - 2) + 1;
	}
}
void CreateScreen(char screen[60][20], int height, int width)
{

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (y > 0 && y < height - 1 && x>0 && x < width - 1)
			{
				screen[x][y] = ' ';
			}
			else
			{
				if (y == 0 || y == 19)
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
}
void draw(char screen[60][20], int height, int width)
{

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cout.width(1);
			printf("%c", screen[x][y]);
		}
		printf("\n");
	}
}

int keyPress()
{
	if (_kbhit())
	{
		int a = _getch();
		fflush(stdin);
		switch (a)
		{
		case 119:
			return 1;
			break;
		case 100:
			return 2;
			break;
		case 115:
			return 3;
			break;
		case 97:
			return 4;
			break;

		default:
			break;
		}
	}
	return 0;
}
void update()
{

}
int main()
{
	char screen[60][20];
	int width = 60;
	int height = 20;
	CreateScreen(screen, height, width);
	srand(time(NULL));
	int snake[2];
	int food[2];
	Game_init(snake, food, width, height);
	int moving_vector[2] = { 0,0 };
	while (true)
	{
		system("CLS");
		//Update
		switch (keyPress())
		{
		case 1:
			if (moving_vector[1] != 1)
			{
				moving_vector[0] = 0;
				moving_vector[1] = -1;

			}
			break;
		case 2:
			if (moving_vector[0] != -1)
			{
				moving_vector[0] = 1;
				moving_vector[1] = 0;
			}
			break;
		case 3:
			if (moving_vector[1] != -1)
			{
				moving_vector[0] = 0;
				moving_vector[1] = 1;
			}
			break;
		case 4:
			if (moving_vector[0] != 1)
			{
				moving_vector[0] = -1;
				moving_vector[1] = -0;
			}
			break;

		default:
			break;
		}
		snake[0] += moving_vector[0];
		snake[0] %= 58 + 1;
		if (snake[0] < 0) snake[0] = 58 + snake[0];
		snake[1] += moving_vector[1];
		snake[1] %= 18 + 1;


		switch (keyPress())
			{
			case 1:
				if (moving_vector[1] != 1)
				{
					moving_vector[0] = 0;
					moving_vector[1] = -1;

				}
				break;
			case 2:
				if (moving_vector[0] != -1)
				{
					moving_vector[0] = 1;
					moving_vector[1] = 0;
				}
				break;
			case 3:
				if (moving_vector[1] != -1)
				{
					moving_vector[0] = 0;
					moving_vector[1] = 1;
				}
				break;
			case 4:
				if (moving_vector[0] != 1)
				{
					moving_vector[0] = -1;
					moving_vector[1] = -0;
				}
				break;

			default:
				break;
			}







		while (snake[0] == food[0] && snake[1] == food[1])
		{
			food[0] = rand() % 58 + 1;
			food[1] = rand() % 18 + 1;
		}


		if (snake[1] < 0) snake[1] = 18 + snake[1];
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				if (x > 0 && x < 59 && y> 0 && y < 19)
				{
					screen[x][y] = ' ';
				}

			}
		}
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				if (x == snake[0] && y == snake[1] && x != 0 && x != 59 && y != 0 && y != 19)
				{
					screen[x][y] = 'D';
				}
				if (x == food[0] && y == food[1] && x != 0 && x != 59 && y != 0 && y != 19)
				{
					screen[x][y] = 'O';
				}

			}
		}
		//=======================
			
		draw(screen, height, width);
		Sleep(500);
	}







	return 0;
}



/*
 A=(0,5)
 snake(5,5)
 snake(7,4)
 snake(11,2)

						y           o
						y
						y     o
						y       o
						y
						y           o
						y
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
						y
						y
						y
						y
						y
						y



















*/