#include "Player.h"
int Player::getrow()
{
	return row;
}
int Player::getcolumn()
{
	return column;
}
void Player::getp(int initialrow, int initialcolumn)
{
	circle.setPosition(90 + 15 * initialcolumn, 90 + 15 * initialrow); //set position  of the circle
	row = initialrow; //set row
	column = initialcolumn; //set column
}
void Player::drawOnWindow(RenderWindow& window)
{
	window.draw(circle);
}
CircleShape Player::getPlayer()
{
	return circle;
}