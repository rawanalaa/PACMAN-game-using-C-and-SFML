#include "ghosts.h"
ghosts::ghosts(double radius, int initialrow, int initialcolumn, string filename)
{
	circle.setRadius(radius);
	circle.setPosition(90 + 15 * initialcolumn, 90 + 15 * initialrow);
	texture.loadFromFile(filename);
	circle.setTexture(&texture);
	row = initialrow;
	column = initialcolumn;
}
void ghosts::move(vector<int> p, int arr[][COLUMNS])
{
	for (int i = p.size() - 1; i >= 0; i--)
	{
		if (c.getElapsedTime() > seconds(0.26))
			if (p[i] == arr[row][column - 1]) //comparing the path with the board
			{
				circle.move(-15, 0);
				column--;
				c.restart();
			}
			else if (p[i] == arr[row][column + 1])
			{
				circle.move(15, 0);
				column++;
				c.restart();
			}
			else if (p[i] == arr[row + 1][column])
			{
				circle.move(0, 15);
				row++;
				c.restart();
			}
			else if (p[i] == arr[row - 1][column])
			{
				circle.move(0, -15);
				row--;
				c.restart();
			}
	}
}