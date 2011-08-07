#ifndef GRID_H
#define GRID_H

#include <iostream>
#include "Cell.h"
#include "Mover.h"

class Mover;

class Grid
{

	private:
		int length;
		int width;
		int startX;
		int startY;
		int goalX;
		int goalY;
		Cell **cells;
		Mover* internalMover;

	public:
		Grid();
		Grid(int length, int width);
		void printGrid(Mover mover);
		int getGoalX();
		int getGoalY();
		int getStartX();
		int getStartY();
		int getLength();
		int getWidth();
		friend class Mover;
};

#endif
