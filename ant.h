#ifndef antinc
#define antinc

#include <SFML/Graphics.hpp>

#include "cell.h"

class Ant: public sf::CircleShape {
    public:
        Ant(int x, int y, int direction, float r, float g, float b, int rad);
        void setPos(int xMultiplier, int yMultiplier);
        void wrap(int xMax, int yMax);
        void move(Cell& cell);

        int getID();
        int getX();
        int getY();
        int getDirection();
        float getR();
        float getG();
        float getB();

    private:
        void turnLeft();
        void turnRight();
        
        static int ID;
        int x, y, direction;
        float r, g, b;
        const int id;

};

static int ID = 0;

#endif
