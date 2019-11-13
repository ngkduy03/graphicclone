#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
using namespace std;


void CreateScreen(char screen [] [20])
{
	int width = 60;
	int height = 20;
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
void draw(char screen[][20])
{
	int width = 60;
	int height = 20;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cout.width(1);
			printf("%c",screen[x][y]);
		}
		printf("\n");
	}
}

void update()
{

}
int main()
{
	char screen[60][20];
	int width = 60;
	int height = 20;
	CreateScreen(screen);
	srand(time(NULL));
	int x = rand() % 58 + 1;
	int y = rand() % 28 + 1;
	int snake[2] = { 2,2 };
	int moving_vector[2] = { 3,3 };
	while (true)
	{
		system("CLS");
		//Update
		snake[0] += moving_vector[0];
		snake[0] %=58+1;
		snake[1] += moving_vector[1];
		snake[1] %=19+1;
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				if (x >0 && x< 59 && y> 0 && y < 19)
				{
					screen[x][y] = ' ';
				}
			}
		}
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				if (x == snake[0] && y == snake[1] && x != 0 && x!=59 &&y!=0&&y!=19)
				{
					screen[x][y] = '*';
				}
			}
		}
		//=======================
		draw(screen);
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