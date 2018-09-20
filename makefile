CXX = g++
oglflags = -lsfml-graphics -lsfml-window -lsfml-system

default: ant.o cell.o grid.o logicalgrid.o main.o
	$(CXX) -o shapes.out main.o cell.o grid.o ant.o logicalgrid.o $(oglflags)

debug: main.o cell.o
	$(CXX) -g -Wall -o dbgshapes.out main.cpp cell.cpp grid.cpp $(oglflags)

main: main.cpp
	$(CXX) -c main.cpp $(oglflags)

cell: cell.cpp cell.h
	$(CXX) -c cell.cpp $(oglflags)

grid: grid.cpp grid.h
	$(CXX) -c grid.cpp $(oglflags)

ant: ant.cpp ant.h
	$(CXX) -c ant.cpp $(oglflags)

logicalgrid: logicalgrid.cpp logicalgrid.h
	$(CXX) -c logicalgrid.cpp $(oglflags)

run: default
	./shapes.out

clean:
	rm -rf *.o *.out
