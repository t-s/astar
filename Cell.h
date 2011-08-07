#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell
{

	private:
		bool isBlock;			
		int data;
		bool start;
		bool goal;	

	public:
		Cell();
		Cell(bool isBlock);
		void setBlock(bool newIsBlock);
		bool isBlockFunc();
		void setData(int newData);
		int getData();
		void printCell();
		void setStart();
		bool isStart();
		void setGoal();
		bool isGoal();
};



#endif
