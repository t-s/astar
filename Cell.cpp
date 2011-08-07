#include <iostream>

#include "Cell.h"

Cell::Cell()
{
	isBlock = false;
	data = 0;
	start = false;
};

Cell::Cell(bool newIsBlock)
{
	isBlock = newIsBlock;
};

int Cell::getData()
{
	return data;
}

void Cell::setData(int newData)
{
	data = newData;
}
	
bool Cell::isBlockFunc()
{
	return isBlock;
}

void Cell::setBlock(bool newIsBlock)
{
	isBlock = newIsBlock;
}

bool Cell::isStart()
{
	return start;
}

void Cell::setStart()
{
	start = true;
}

bool Cell::isGoal()
{
	return goal;
}

void Cell::setGoal()
{
	goal = true;
}

void Cell::printCell()
{

	std::cout << " ---  " ;
	std::cout << "|   | " ;
	std::cout << "|   | " ;
	std::cout << "|   | " ;
    std::cout << " ---  " ;

}
