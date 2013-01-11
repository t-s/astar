#ifndef MOVER_H
#define MOVER_H

#include "Grid.h"
#include <vector>

struct coord
{
	int x;
	int y;
	int f_score;
	int g_score;
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
		double fScore();
		double fScore(coord pos);
		double fScore(int x, int y);
		double gScore(coord origin, coord dest);
		double gScore(int x1, int y1, int x2, int y2);
		void solve();
};

#endif 
