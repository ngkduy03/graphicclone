#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "Vector.h"
using namespace std;

void Game_init(Vector *snake, Vector *food, int width, int height)
{
	srand(time(NULL)); //Create random seed;
	while (snake->GetX() == food->GetX() && snake->GetY() == food->GetY())
	{
		snake->SetPos(rand() % (width-2) +1,rand() % (height-2) + 1);
		food->SetPos(rand() % (width - 2) + 1, rand() % (height - 2) + 1);
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
			//cout.width(1);
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
		return a;
	}
	return 0;
}

void update()
{

}

int main()
{
	int clone;
	Vector tail[100];
	int score=0;
	char screen[60][20];
	int width = 60;
	int height = 20;
	CreateScreen(screen, height, width);
	srand(time(NULL));
	Vector snake;
	Vector food;
	Game_init(&snake, &food, width, height);
	Vector mv(0, 0);
	
	while (true)
	{
		system("CLS");
		//Update
		switch (keyPress())
		{
			case 'w':
				if (mv.GetY() != 1)
				{
					mv.SetPos(0, -1);
				}
				break;
			case 'd':
				if (mv.GetX() != -1)
				{
					mv.SetPos(1, 0);
				}
				break;
			case 's':
				if (mv.GetY() != -1)
				{
					mv.SetPos(0, 1);
				}
				break;
			case 'a':
				if (mv.GetX() != 1)
				{
					mv.SetPos(-1, 0);
				}
				break;

			default:
				break;
		}
		// headmovement
		snake.add(mv);
		int snakeX = snake.GetX() % (58) + 1;
		int snakeY = snake.GetY() % (18) + 1;
		if (snakeX < 0) snakeX += 58;
		if (snakeY < 0) snakeY += 58;
		snake.SetPos(snakeX, snakeY);


		switch (keyPress())
		{
			case 'w':
				if (mv.GetY() != 1)
				{
					mv.SetPos(0, -1);
				}
				break;
			case 'd':
				if (mv.GetX() != -1)
				{
					mv.SetPos(1, 0);
				}
				break;
			case 's':
				if (mv.GetY() != -1)
				{
					mv.SetPos(0, 1);
				}
				break;
			case 'a':
				if (mv.GetX() != 1)
				{
					mv.SetPos(-1, 0);
				}
				break;

			default:
				break;
		}






		if (snake.GetX() == food.GetX() && snake.GetY() == food.GetY())
		{
			score++;
			Vector tmp = mv;
			tmp.multiply(-1);
			tmp.add(snake);
			tail[0].SetPos(tmp.GetX(), tmp.GetY());
			
		}

		while (snake.GetX() == food.GetY() && snake.GetY() == food.GetY())
		{
			food.SetPos( rand() % 58 + 1,rand() % 18 + 1);
		}
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
				if (x == snake.GetX() && y == snake.GetY() && x != 0 && x != 59 && y != 0 && y != 19)
				{
					screen[x][y] = '*';
				}
				if (x == food.GetX() && y == food.GetY() && x != 0 && x != 59 && y != 0 && y != 19)
				{
					screen[x][y] = 'O';
				}

			}
		}
		
			
		draw(screen, height, width);
		std::cout << endl << score;
		Sleep(500);
	}







	return 0;
}























