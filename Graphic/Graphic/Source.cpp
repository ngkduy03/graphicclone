#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
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
			cout << screen[x][y];
		}
		cout << endl;
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
	
	while (true)
	{
		
		draw(screen);
		system("CLS");
	}





	
	
	return 0;
}