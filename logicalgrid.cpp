#include "logicalgrid.h"

LogicalGrid::LogicalGrid(int width, int height, int side, sf::Color defaultColor): Grid{width, height, side, defaultColor} {
    ants.push_back(Ant{width/2, height/2, 0, 0.5f, 0.5f, 0.5f});
}

void LogicalGrid::update(){
    for(auto& ant: ants){
        changedCells.push_back(ant.getX()+ant.getY()*width);
        ant.move(cells[ant.getX()+ant.getY()*width]);
        ant.wrap(side, side);
        changedAnts.push_back(&ant);
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
