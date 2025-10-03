#include "Obstacle.h"
Obstacle::Obstacle(int x, int y){
    setPixmap(QPixmap(":/images/Obstacle.jpeg").scaled(70,70));
    this->setPos(x,y);
}
