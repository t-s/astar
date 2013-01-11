#include <iostream>
#include <cmath>
#include "Mover.h"
#include "Grid.h"

using namespace std;

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

	curPos.g_score = 0;
	curPos.f_score = fScore();

	listOpen.push_back(curPos);
	
	while (!listOpen.empty())
	{
	
		cout << "Current X is: " << x << "." << endl;
		cout << "Current Y is: " << y << "." << endl;

		cout << "Goal X is: " << this->internalGrid->getGoalX() << "." << endl;
		cout << "Goal Y is: " << this->internalGrid->getGoalY() << "." << endl;

		listOpen.push_back(curPos);

		for(a = 0; a < listOpen.size(); ++a)
		{
			cout << "In " << a << "loop of for loop in solver." << endl;

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
						temp = fScore(ax-1,ay);
						if (temp < min)
						{
							min = temp;
							this->x = ax - 1;
							this->y = ay;
						}							
						break;

					case 1:
						temp = fScore(ax,ay-1);
						if ( temp < min )
						{
							min = temp;
							this->x = ax;
							this->y = ay - 1;
						}
						break;

					case 2:
						temp = fScore(ax+1,ay);
						if(temp < min)
						{
							min = temp;
							this->x = ax + 1;
							this->y = ay;
						}
						break;
				
					case 3:
						temp = fScore(ax,ay+1);
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

double Mover::fScore()
{

	int scoreX = std::abs(x - internalGrid->getGoalX());
	int scoreY = std::abs(y - internalGrid->getGoalY());

	return std::sqrt((scoreX*scoreX) + (scoreY*scoreY)); 

}

double Mover::fScore(coord pos)
{
	int thisX = pos.x;
	int thisY = pos.y;

	int scoreX = std::abs(thisX - internalGrid->getGoalX());
	int scoreY = std::abs(thisY - internalGrid->getGoalY());

	return std::sqrt((scoreX*scoreX) + (scoreY*scoreY));

}

double Mover::fScore(int newX, int newY)
{
	
	int scoreX = std::abs(newX - internalGrid->getGoalX());
	int scoreY = std::abs(newY - internalGrid->getGoalY());

	return std::sqrt((scoreX*scoreX) + (scoreY*scoreY));

}

double Mover::gScore(coord origin, coord dest)
{
	int x1 = origin.x;
	int y1 = origin.y;

	int x2 = dest.x;
	int y2 = dest.y;

	int scoreX = std::abs(x1 - x2);
    int scoreY = std::abs(y1 - y2);

    return std::sqrt((scoreX*scoreX) + (scoreY*scoreY));
}

double Mover::gScore(int x1, int y1, int x2, int y2)
{
	int scoreX = std::abs(x1 - x2);
    int scoreY = std::abs(y1 - y2);

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
