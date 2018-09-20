#include "ant.h"

Ant::Ant(int x, int y, int direction, float r, float g, float b): sf::CircleShape{3}, x{x}, y{y}, direction{direction}, r{r}, g{g}, b{b}, id{0} {
    setFillColor(sf::Color{(int) (r*255), (int) (g*255), (int) (b*255)});
    setRotation(90*direction);

}

void Ant::setPosition(int xMultiplier, int yMultiplier){
    setPosition(x*xMultiplier, y*yMultiplier);
    setRotation(90*direction);
}

void Ant::wrap(int xMax, int yMax){
    x = (x+xMax)%xMax;
    y = (y+yMax)%yMax;
}

void Ant::move(Cell cell){
    if(&cell == nullptr)
        return;

    if(cell.getValue())
        turnLeft();
    else
        turnRight();
    cell.setValue(1-cell.getValue());
    if(cell.getValue())
        cell.setColor(r*255, g*255, b*255);
    else
        cell.setColor(0,0,0);

    x += (direction == 1)? 1: (direction == 3)? -1: 0;
    y += (direction == 0)? -1: (direction == 2)? 1: 0;
}

int Ant::getID(){
    return id;
}

int Ant::getX(){
    return x;
}

int Ant::getY(){
    return y;
}

int Ant::getDirection(){
    return direction;
}

float Ant::getR(){
    return r;
}

float Ant::getG(){
    return b;
}

float Ant::getB(){
    return b;
}

void Ant::turnLeft(){
    direction += 3;
    direction %= 4;
}

void Ant::turnRight(){
    direction += 1;
    direction %= 4;
}
        
