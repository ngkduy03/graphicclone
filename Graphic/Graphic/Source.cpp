#include<iostream>
using namespace std;

int main()
{
	char screen[30][20];
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 30; x++)
		{
			if (y >= 1 && y <= 18 && x>0 && x<29)
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
					case 29:
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
						screen[x][y] = 200;
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

	










	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 30; x++)
		{
			cout.width(1);
			cout << screen[x][y];
		}
		cout << endl;
	}
	
	return 0;
}