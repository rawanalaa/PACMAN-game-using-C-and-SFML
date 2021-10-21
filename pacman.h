#include "player.h"
#include"BinarySearchTree.h"
class pacman : public Player
{
public:
	pacman(float radius, int intialrow, int intialcolumn, string filename); //constructor
	void moveOnWindow(Event e, int arr[][COLUMNS]); //to make pacman able to move according to user's action
	void DisplayScore(); 
	void score();
	void live();
	void mode();
	void normal();
	int getscore(); 
	int getlives();
	Text scoretext;
	Text livestext;
	Text youwon;
	Text youlost;
	Text mo;
	Text normaltext;
private:
	void win();
	void lose();
	fstream insertscore;
	BinarySearchTree b; //object of class binary search tree
	int lives;
	int s;
	Clock clock;
	Font font;
	Font f;
};
