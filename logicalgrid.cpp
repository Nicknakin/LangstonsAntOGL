#include "logicalgrid.h"

#include <stdlib.h>

LogicalGrid::LogicalGrid(int width, int height, int side, sf::Color defaultColor): Grid{width, height, side, defaultColor} {
    srand(std::time(nullptr));
    for(int i = 0; i < 500; i++){
        ants.push_back(Ant{rand()%width, rand()%height, rand()%4, (float) (rand()%255)/255.f, (float) (rand()%255)/255.f, (float) (rand()%255)/255.f, side});
    }
}

void LogicalGrid::update(){
    for(auto& ant: ants){
        int cellIndex = ant.getX()+ant.getY()*width;
        changedCells.push_back(cellIndex);
        ant.move(cells[cellIndex]);
        ant.wrap(width, height);
        ant.setPos(side,side);
        if(cells[cellIndex].getValue() == 0)
            cells[cellIndex].setColor(defaultColor);
    }
}

Ant& LogicalGrid::popAnt(){
    Ant& temp = *ants[changedAnts[0]];
    changedAnts.erase(changedAnts.begin(), changedAnts.begin()+1);
    return temp;
}

int LogicalGrid::getChangedAntSize(){
    return changedAnts.size();
}
