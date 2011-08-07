#include <iostream>

#include "Cell.h"
#include "Mover.h"
#include "Grid.h"

int main()
{

	Grid grid;
	Mover mover;
	//mover1.moveUp();
	//mover1.moveRight();

	mover.loadGrid(&grid);
	mover.printGrid();
	mover.solve();
	mover.printGrid();	
	return 0;
}
