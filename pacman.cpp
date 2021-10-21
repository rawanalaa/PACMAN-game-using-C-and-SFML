#include "pacman.h"
//#include "BinarySearchTree.h"
pacman::pacman(float radius, int initialrow, int initialcolumn, string fileName)
{
	circle.setRadius(radius);
	circle.setPosition(90 + 15 * initialcolumn, 90 + 15 * initialrow);
	texture.loadFromFile(fileName);
	circle.setTexture(&texture);
	row = initialrow;
	column = initialcolumn;
	lives = 3;
	s = 0;
}
void pacman::moveOnWindow(Event e, int arr[][COLUMNS])
{
	switch (e.key.code)
	{
	case Keyboard::Up:
		if (clock.getElapsedTime() > seconds(0.2))
			if (arr[row - 1][column] >= 0)
			{
				circle.move(0, -15);
				row--;
				clock.restart();
			}
		break;
	case Keyboard::Down:
		if (clock.getElapsedTime() > seconds(0.2))
			if (arr[row + 1][column] >= 0)
			{
				circle.move(0, 15);
				row++;
				clock.restart();
			}
		break;
	case Keyboard::Right:
		if (clock.getElapsedTime() > seconds(0.2))
			if (arr[row][column + 1] >= 0)
			{
				circle.move(15, 0);
				column++;
				clock.restart();
			}
			else if (arr[row][column] == arr[14][27])
			{
				circle.move(-405, 0);
				column -= 27;
			}
		break;
	case Keyboard::Left:
		if (clock.getElapsedTime() > seconds(0.2))
			if (arr[row][column - 1] >= 0)
			{
				circle.move(-15, 0);
				column--;
				clock.restart();
			}
			else if (arr[row][column] == arr[14][0])
			{
				circle.move(405, 0);
				column += 27;
			}
		break;
	}
}
void pacman::live()
{
	lives = lives - 1;
	DisplayScore();
	if (lives == 0)
	{
		lose();
		insertscore.open("score.txt",fstream::app);
		if (insertscore.is_open())
		{
				insertscore << s << endl;
		}
		insertscore.close();
		b.read(); //to read the file which saves the scores each game
		b.printdes(); // to print the scores in descending order
	}
}
void pacman::score()
{
	s = s + 10;
	DisplayScore();
	if (s == 3000)
	{
		win();
		insertscore.open("score.txt",fstream::app);
		if (insertscore.is_open())
		{
			if (!insertscore.eof())
				insertscore << s << endl;
		}
		insertscore.close();
		b.read(); 
		b.printdes(); 
	}
}
void pacman::DisplayScore()
{
	font.loadFromFile("Sweet Unicorn.ttf"); // font is a class to make me able to set the font of the text
	scoretext.setFont(font); //to set font
	scoretext.setCharacterSize(20); //set font size
	scoretext.setFillColor(Color::Yellow); //set its color
	scoretext.setPosition(90, 60); //set font position
	stringstream ss; 
	ss << "score: " << s; //to link between the score and the text
	scoretext.setString(ss.str()); //set a string of the current contents of the stream
	window.draw(scoretext); //display the score on the window
	f.loadFromFile("Sweet Unicorn.ttf"); 
	livestext.setFont(f);
	livestext.setCharacterSize(20);
	livestext.setFillColor(Color::Yellow);
	livestext.setPosition(90, 555);
	stringstream tt;
	tt << "lives: " << lives;
	livestext.setString(tt.str());
	window.draw(livestext);
}
void pacman::win()
{
	font.loadFromFile("Sweet Unicorn.ttf");
	youwon.setFont(font);
	youwon.setCharacterSize(50);
	youwon.setFillColor(Color::Yellow);
	youwon.setPosition(225, 270);
	stringstream tt;
	tt << "You Won";
	youwon.setString(tt.str());
	window.draw(youwon);

}
void pacman::lose()
{
	font.loadFromFile("Sweet Unicorn.ttf");
	youlost.setFont(font);
	youlost.setCharacterSize(50);
	youlost.setFillColor(Color::Yellow);
	youlost.setPosition(225, 270);
	stringstream tt;
	tt << "You lost";
	youlost.setString(tt.str());
	window.draw(youlost);
}
void pacman::mode()
{
	font.loadFromFile("Sweet Unicorn.ttf");
	mo.setFont(font);
	mo.setCharacterSize(30);
	mo.setFillColor(Color::Yellow);
	mo.setPosition(220, 40);
	stringstream mod;
	mod << "in";
	mo.setString(mod.str());
	window.draw(mo);
}
void pacman::normal()
{
	font.loadFromFile("Sweet Unicorn.ttf");
	normaltext.setFont(font);
	normaltext.setCharacterSize(30);
	normaltext.setFillColor(Color::Yellow);
	normaltext.setPosition(250, 40);
	stringstream n;
	n << "visible";
	normaltext.setString(n.str());
	window.draw(normaltext);
}
int pacman::getscore()
{
	return s;
}
int pacman::getlives()
{
	return lives;
}
