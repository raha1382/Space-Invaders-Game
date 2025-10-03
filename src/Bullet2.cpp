#include <QTimer>
#include <QGraphicsScene>
#include <iostream>

#include "Bullet2.h"
#include "Bullet1.h"
#include "Enemy1.h"
#include "Player.h"
#include "Enemy2.h"
#include "Obstacle.h"

extern Game* game;

Bullet2::Bullet2()
{
    setPixmap(QPixmap(":/images/Bullet2.png").scaled(30,40));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);
}


void Bullet2::move(){
    //if bullet collides with enemy or player or obstacle, destroy both
    QList <QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0 ; i < colliding_items.size() ; i++){
        if(typeid(*colliding_items[i]) == typeid(Player) ||
            typeid(*colliding_items[i]) == typeid(Bullet1)||
            typeid(*colliding_items[i]) == typeid(Obstacle)){
            if(typeid(*colliding_items[i]) == typeid(Player))
            {
                //player is dead
                game->playercount++;
                //player lost
                game->gameOver();
            }

            //remove them both
            if(typeid(*colliding_items[i]) == typeid(Obstacle)){
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
    //move the bullet down
    setPos(x(),y()+25);
    //delete bullet if out of screen - memory management
    if(pos().y() > 1000){
        scene()->removeItem(this);
        delete this;
    }
}
