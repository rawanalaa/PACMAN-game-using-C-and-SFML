#include"Player.h"
#include "pacman.h"
#include"ghosts.h"
#include"BinarySearchTree.h"
vector<int> Dijkstra(int Graph[COUNT][COUNT], int startNode, int endnode);
int main()
{
	RenderWindow window; // to create the window
	window.create(VideoMode(600, 600), "pac man"); // to create the size of the board and naming it
	int arr[ROWS][COLUMNS]; // to save the board from the text file
	ifstream inputfile; // to read the board from a file
	inputfile.open("Text1.txt");
	if (inputfile.is_open())
	{
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLUMNS; j++)
				if (!inputfile.eof())
					inputfile >> arr[i][j];
	};
	inputfile.close();
	pacman pac(7.5, 23, 13, "pacman.png"); //creating object of class pacman and itializing its position and texture
	ghosts ghost1(7.5, 12, 13, "ghost1.png"); //creating object of class ghosts and itializing its position and texture
	ghosts ghost2(7.5, 13, 12, "ghost2.png");
	ghosts ghost3(7.5, 14, 14, "ghost3.png"); // creating a clock
	Clock clock1; // creating a clock
	bool visible = true;
	Texture food; //setting a texture
	Texture power;
	Texture blocks;
	blocks.loadFromFile("blocks.png"); //uploading a photo  
	power.loadFromFile("power.png");
	food.loadFromFile("food.png");
	RectangleShape board[ROWS][COLUMNS]; //drawing a rectangle for each number of the board from the textfile
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
		{
			board[i][j].setSize(Vector2f(15, 15)); //creating the size of the rectangle
			board[i][j].setPosition(90 + 15 * j, 90 + 15 * i); //setting the position of eachrectangle 
			if (arr[i][j] == -01)
				board[i][j].setTexture(&blocks);
			else if ((arr[i][j] == 30) || (arr[i][j] == 231) || (arr[i][j] == 35) || (arr[i][j] == 252))
				board[i][j].setTexture(&power);
			else if ((arr[i][j] <= 309))
				board[i][j].setTexture(&food);
			else
				board[i][j].setFillColor(Color::Black);
		}
	int Graph[COUNT][COUNT];
	for (int i = 0; i < COUNT; i++)
		for (int j = 0; j < COUNT; j++)
		{
			Graph[i][j] = INFINITE;
		}

	for (int i = 1; i < ROWS; i++)
	{
		for (int j = 1; j < COLUMNS; j++)
        {
			if (arr[i][j] >= 0)
			{

				if ((arr[i][j - 1] >= 0)) // to check if it can move left
					Graph[arr[i][j]][arr[i][j - 1]] = 1;
				if (arr[i - 1][j] != -1) //to check if it can move up
					Graph[arr[i][j]][arr[i - 1][j]] = 1;
				if (arr[i][j + 1] != -1) //to check if it can move right
					Graph[arr[i][j]][arr[i][j + 1]] = 1;
				if (arr[i + 1][j] != -1) //to check if it can move down
					Graph[arr[i][j]][arr[i + 1][j]] = 1;
			}
		}
	}
	   vector<int> path;
		Event e;
		while (window.isOpen())
		{
			while (window.pollEvent(e))
			{
				if (e.type == Event::Closed)
					window.close();
				else if (e.type == Event::KeyPressed)
					pac.moveOnWindow(e, arr);
			}
			pac.normal();
				pac.moveOnWindow(e, arr);
				path = Dijkstra(Graph, arr[ghost1.getrow()][ghost1.getcolumn()], arr[pac.getrow()][pac.getcolumn()]);
				ghost1.move(path, arr);
				path = Dijkstra(Graph, arr[ghost2.getrow()][ghost2.getcolumn()], arr[pac.getrow()][pac.getcolumn()]);
				ghost2.move(path, arr);
				path = Dijkstra(Graph, arr[ghost3.getrow()][ghost3.getcolumn()], arr[pac.getrow()][pac.getcolumn()]);
				ghost3.move(path, arr);
			window.clear();
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLUMNS; j++)
					if ((pac.getPlayer().getPosition().x == board[i][j].getPosition().x && pac.getPlayer().getPosition().y == board[i][j].getPosition().y) && board[i][j].getTexture() == &food && board[i][j].getFillColor() != Color::Black)
					{
						board[i][j].setFillColor(Color::Black);
						pac.score();
					}
					else if ((pac.getPlayer().getPosition().x == board[i][j].getPosition().x && pac.getPlayer().getPosition().y == board[i][j].getPosition().y && board[i][j].getTexture() == &power && board[i][j].getFillColor() != Color::Black))
					{

						board[i][j].setFillColor(Color::Black);
						pac.score();
						visible = false;

					}
			}
			if (!visible)
			{
				pac.mode();
				window.clear();
				window.draw(pac.mo);
			}
			if (clock1.getElapsedTime().asSeconds() >= 10)
				visible = true;
			if (visible)
			{
				if ((pac.getPlayer().getPosition().x == ghost1.getPlayer().getPosition().x && pac.getPlayer().getPosition().y == ghost1.getPlayer().getPosition().y) || (pac.getPlayer().getPosition().x == ghost2.getPlayer().getPosition().x && pac.getPlayer().getPosition().y == ghost2.getPlayer().getPosition().y) || (pac.getPlayer().getPosition().x == ghost3.getPlayer().getPosition().x && pac.getPlayer().getPosition().y == ghost3.getPlayer().getPosition().y))
				{
					pac.live();
					pac.getp(23, 13);
				}
			}
			if ((pac.getscore() == 3000) || (pac.getlives() == 0)||(pac.getlives()<0))
			{
				if (e.type == Event::KeyPressed)
					window.close();
			}

			for (int i = 0; i < ROWS; i++)
				for (int j = 0; j < COLUMNS; j++)
					window.draw(board[i][j]);

			pac.DisplayScore();
			window.draw(pac.scoretext);
			window.draw(pac.livestext);
			window.draw(pac.youlost);
			window.draw(pac.youwon);
			window.draw(pac.normaltext);
			pac.drawOnWindow(window);
		    ghost1.drawOnWindow(window);
			ghost2.drawOnWindow(window);
			ghost3.drawOnWindow(window);
			window.display();

		}
}
vector<int> Dijkstra(int Graph[COUNT][COUNT], int startNode, int endnode)
{
	int costs[COUNT], previous[COUNT];
	bool visited[COUNT];
	// to intialize costs,previous,and visited
	for (int i = 0; i < COUNT; i++)
	{
		costs[i] = Graph[startNode][i];
		previous[i] = startNode;
		visited[i] = false;
	}
	costs[startNode] = 0;
	visited[startNode] = true;

	int count = 1, nextNode = 0, minimumCost;
	while (count < COUNT)
	{
		// Find the minimum cost in order to visit a node.
		minimumCost = INFINITE;
		for (int i = 0; i < COUNT; i++)
			if ((costs[i] < minimumCost) && (visited[i] == false))
			{
				minimumCost = costs[i];
				nextNode = i;
			}
		visited[nextNode] = true;
		// Update the costs of the children of the visited node.
		for (int i = 0; i < COUNT; i++)
			if ((minimumCost + Graph[nextNode][i] < costs[i]) && (visited[i] == false))
			{
				costs[i] = minimumCost + Graph[nextNode][i];
				previous[i] = nextNode;
			}
		count++;
	}
	//fill the paths
	int j;
	vector<int> paths;
	paths.push_back(endnode);
	if (endnode != startNode)
	{
		j = endnode;
		do
		{
			j = previous[j];
			paths.push_back(j);
		} while (j != startNode);
	}
	return paths;
}