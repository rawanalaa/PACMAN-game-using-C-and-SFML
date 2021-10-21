#ifndef PLAYER
#define PLAYER

#include<iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include<sstream>
#include<vector>
using namespace std;
using namespace sf;
const int ROWS = 31, COLUMNS = 28;
const int COUNT = 330;
const int INFINITE = 9999;
class Player // base class which other classes will inheret from
{
protected:
	RenderWindow window; //to create a window
	CircleShape circle; //to draw circle shape
	Texture texture; // to be able to upload photos in
	int row;
	int column;
public:
	void drawOnWindow(RenderWindow& window); // function to make me able to draw and display something in window
	CircleShape getPlayer(); //return the circle (pacman,ghosts)
	void getp(int initialrow, int initialcolumn); // to get the intial position only for pacman or the ghost
	int getrow(); //return row
	int getcolumn(); // return column
};
#endif
