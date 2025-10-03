#include <QTimer>
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>
#include <iostream>

#include "Bullet1.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Game.h"
#include "Obstacle.h"
#include "Score.h"

//external global game object in main
extern Game* game;


Bullet1::Bullet1(){

    //Adding bullet picture
    setPixmap(QPixmap(":/images/Bullet1.png").scaled(65,40));

    //move repeatedly
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(40);

}


void Bullet1::move(){

    //if bullet collides with enemy or obstacle, destroy both
    QList <QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0 ; i < colliding_items.size() ; i++){
        if(typeid(*colliding_items[i]) == typeid(Enemy1) ||
            typeid(*colliding_items[i]) == typeid(Enemy2) ||
            typeid(*colliding_items[i]) == typeid(Obstacle) ||
            typeid(*colliding_items[i]) == typeid(Score)){
            if(typeid(*colliding_items[i]) != typeid(Obstacle) &&
                typeid(*colliding_items[i]) != typeid(Score)){
                //increase score
                game->score->increase();
                //increase enemycount
                game->enemycount++;
            }
            if(game->enemycount >= 18)
                //player wins
                game->gameOver();
            //remove them both
            if(typeid(*colliding_items[i]) == typeid(Score)){
                scene()->removeItem(this);
                delete this;
            }
            else{
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete colliding_items[i];
                delete this;
            }
            return;
        }
    }
    //move the bullet up
    setPos(x(),y()-10);

    //delete bullet when out of screen - memory management
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
