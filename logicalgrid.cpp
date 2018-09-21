#include "logicalgrid.h"

LogicalGrid::LogicalGrid(int width, int height, int side, sf::Color defaultColor): Grid{width, height, side, defaultColor} {
    ants.push_back(Ant{width/2, height/2, 0, 0.5f, 0.5f, 0.5f, side});
}

void LogicalGrid::update(){
    for(auto& ant: ants){
        int cellIndex = ant.getX()+ant.getY()*width;
        changedCells.push_back(cellIndex);
        ant.move(cells[cellIndex]);
        ant.wrap(width, height);
        ant.setPos(side,side);
        changedAnts.push_back(&ant);
        if(cells[cellIndex].getValue() == 0)
            cells[cellIndex].setColor(defaultColor);
    }
}

Ant& LogicalGrid::popAnt(){
    Ant& temp = *changedAnts[0];
    changedAnts.erase(changedAnts.begin(), changedAnts.begin()+1);
    return temp;
}

int LogicalGrid::getChangedAntSize(){
    return changedAnts.size();
}
