all: astar

astar: main.o Grid.o Mover.o Cell.o
	g++ main.o Grid.o Mover.o Cell.o -o astar

main.o:	main.cpp
	g++ -c main.cpp

Grid.o: Grid.cpp
	g++ -c Grid.cpp

Mover.o: Mover.cpp
	g++ -c Mover.cpp

Cell.o: Cell.cpp
	g++ -c Cell.cpp

clean:
	rm -rf *o astar
