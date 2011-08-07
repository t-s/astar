#ifndef MOVER_H
#define MOVER_H

#include "Grid.h"
#include <vector>

struct coord
{
	int x;
	int y;
};

class Grid;
class Mover
{

	private:
		int x;
		int y;
		Grid* internalGrid;
	
		std::vector<coord> listOpen;
		std::vector<coord> listClosed;
		std::vector<coord> listPath;
		

	public:
		Mover();
		Mover(int newX, int newY);
		void moveUp();
		void moveLeft();
		void moveRight();
		void moveDown();
		void loadGrid(Grid* inGrid);
		int getX();
		int getY();
		void printGrid();
		double returnHScore();
		double returnHScore(coord pos);
		double returnHScore(int x, int y);
		void solve();
};

#endif 
