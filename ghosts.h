#include "player.h"
class ghosts : public Player
{
public:
	ghosts(double radius, int rowposition, int columnposition, string filename); //constructor
	void move(vector<int> p, int arr[][COLUMNS]); //move function 
private:
	Clock c; //clock
};