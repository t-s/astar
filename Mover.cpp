#include <iostream>
#include <cmath>
#include "Mover.h"
#include "Grid.h"

Mover::Mover()
{
}

Mover::Mover(int newX, int newY)
{
	x = newX;
	y = newY;
}

void Mover::solve()
{

	coord curPos;
	curPos.x = x;
	curPos.y = y;
	int a = 0;
	int b = 0;
	listOpen.push_back(curPos);

	while((x != this->internalGrid->getGoalX()) &&
	      (y != this->internalGrid->getGoalY()))
	{

	listOpen.push_back(curPos);
	for(a = 0; a < listOpen.size(); ++a)
	{

		coord considerPos = listOpen[a];
		int ax = considerPos.x;
		int ay = considerPos.y;
		int newX = 0;
		int newY = 0;
		double min = 1000;
		double temp = 0;
		for(b = 0; b < 4; b++)
		{
			switch(b)
			{
				case 0:
				temp = returnHScore(ax-1,ay);
				if (temp < min)
				{
					min = temp;
					this->x = ax - 1;
					this->y = ay;
				}							
				break;
				case 1:
				temp = returnHScore(ax,ay-1);
				if ( temp < min )
				{
					min = temp;
					this->x = ax;
					this->y = ay - 1;
				}
				break;
				case 2:
				temp = returnHScore(ax+1,ay);
				if(temp < min)
				{
					min = temp;
					this->x = ax + 1;
					this->y = ay;
				}
				break;
				case 3:
				temp = returnHScore(ax,ay+1);
				if(temp < min)
				{
					min = temp;
					this->x = ax;
					this->y = ay + 1;
				}
				break;
			}
		}
		
	}
	}
}

void Mover::loadGrid(Grid* inGrid)
{

	internalGrid = inGrid;
	x = internalGrid->getStartX();
	y = internalGrid->getStartY();

}

double Mover::returnHScore()
{

	int scoreX = std::abs(x - internalGrid->getGoalX());
	int scoreY = std::abs(y - internalGrid->getGoalY());

	return std::sqrt((scoreX*scoreX) + (scoreY*scoreY)); 

}

double Mover::returnHScore(coord pos)
{
	int thisX = pos.x;
	int thisY = pos.y;

	int scoreX = std::abs(thisX - internalGrid->getGoalX());
	int scoreY = std::abs(thisY - internalGrid->getGoalY());

	return std::sqrt((scoreX*scoreX) + (scoreY*scoreY));

}

double Mover::returnHScore(int newX, int newY)
{
	
	int scoreX = std::abs(newX - internalGrid->getGoalX());
	int scoreY = std::abs(newY - internalGrid->getGoalY());

	return std::sqrt((scoreX*scoreX) + (scoreY*scoreY));

}

void Mover::moveRight()
{
	y = y + 1;
}
void Mover::moveLeft()
{
	if ((y - 1) >= 0)
		y = y - 1;
	else
		y = 0;
}
void Mover::moveDown()
{
	x = x + 1;
}
void Mover::moveUp()
{
	if ((x - 1) >= 0)
		x = x - 1;
	else
		x = 0;
}
int Mover::getX()
{
	return x;
}
int Mover::getY()
{
	return y;
}
void Mover::printGrid()
{

	int i = 0;
    int j = 0;

    std::cout << std::endl;

    for(i = 0; i < internalGrid->getLength(); ++i)
    {

        for(j = 0; j < internalGrid->getWidth(); ++j)
        {

            if((x == i) && (y == j))
                std::cout << "|*| ";
            else if(internalGrid->cells[i][j].isGoal())
                std::cout << "|G| ";
            else if(internalGrid->cells[i][j].isBlockFunc() == true)
                std::cout << "|=| ";
            else
                std::cout << "|" << internalGrid->cells[i][j].getData() << "| ";
        }

        std::cout << std::endl;
        std::cout << std::endl;

    }





}
