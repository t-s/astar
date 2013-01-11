#include <ctime>
#include <cstdlib>
#include "Cell.h"
#include "Grid.h"
#include "Mover.h"

Grid::Grid()
{

	length = 5;
	width = 5;
	srand(time(0));
	int isThisABlock = 0;
	startX = rand() % length;
	startY = rand() % width;

	int cornerGoal = rand()%3;

	cells = new Cell *[length];
	for(int i = 0; i < length; ++i)
	{
			cells[i] = new Cell[width];
	}

	cells[startX][startY].setStart();

	switch(cornerGoal)
	{
		case 0: cells[0][0].setGoal(); 
				goalX = 0; goalY = 0; 		        
		break;
		case 1:	cells[0][width-1].setGoal(); 
				goalX = 0; goalY = width-1;       
		break;
		case 2:	cells[length-1][0].setGoal(); 
				goalX = length - 1; goalY = 0;      
		break;
		case 3: cells[length-1][width-1].setGoal(); 
				goalX = length - 1; goalY = width - 1;
		break;
	}

	for(int x = 0; x < length; ++x)
	{
		for(int y = 0; y < length; ++y)
		{
			isThisABlock = rand()%4;
			//if (isThisABlock == 3)
				//cells[x][y].setBlock(true);
			cells[x][y].setData(isThisABlock);
		}

	}

}

Grid::Grid(int newLength, int newWidth)
{

	length = newLength;
	width = newWidth;

	cells = new Cell*[length];
	for(int i = 0; i < length; ++i)
	{
		cells[i] = new Cell[width];
	}
}

void Grid::printGrid(Mover mover)
{
	int i = 0;
	int j = 0;

	int curX = mover.getX();
	int curY = mover.getY();	

	std::cout << std::endl;

	for(i = 0; i < length; ++i)
	{
	
		for(j = 0; j < width; ++j)
		{
			
			if((curX == i) && (curY == j))
				std::cout << "|M| ";
			else if(cells[i][j].isGoal())
				std::cout << "|G| ";
			else if(cells[i][j].isBlockFunc() == true)
				std::cout << "||| ";
			else
				std::cout << "|" << cells[i][j].getData() << "| ";
		}

		std::cout << std::endl;
		std::cout << std::endl;

	}

}

int Grid::getGoalY() 
{ 
	return goalY; 
}
int Grid::getGoalX() 
{ 
	return goalX; 
}
int Grid::getStartX() 
{ 
	return startX; 
}
int Grid::getStartY() 
{ 
	return startY; 
}
int Grid::getWidth()
{
	return width;
}
int Grid::getLength()
{
	return length;
}
