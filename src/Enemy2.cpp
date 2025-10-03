#include "Enemy2.h"
#include "Bullet2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <iostream>

extern Game* game;

Enemy2::Enemy2(int x2, int y2, int remainder)
{
    this->setPos(x2,y2);
    remain = remainder;
    sx2 = x2;
    sy2 = y2;

    setPixmap(QPixmap(":/images/Enemy2.jpg").scaled(150,100));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);

}

void Enemy2::move(){
    //bullet speed
    if(counter % 200 == remain){
        //shoot while the game is not over
        if(game->enemycount < 18 && game->playercount < 1)
            this->shoot();
    }
    //right (if r = 0 : move right)
    if(r == 0 && pos().x() < 100 + sx2){
        setPos(x()+5,y());
        counter++;
    }
    if(pos().x() >= 100 + sx2){
        d = 1;
        r = 1;
        counter++;
    }
    //down (if d = 1 : move down)
    if(d == 1 && pos().y() < sy2 + 100){
        setPos(x(),y()+5);
        counter++;
    }
    if(pos().y() >= 100 + sy2 && d == 1){
        d = 0;
        l = 1;
    }
    //left (if l = 1 : move left)
    if(l == 1 && pos().x() >= sx2 ){
        setPos(x()-5,y());
        counter++;
    }
    if(pos().x() <= sx2 && l == 1){
        u = 1;
        l = 0;
        counter ++;
    }
    //up (if u = 1 : move up)
    if(u == 1 && pos().y() >= sy2 ){
        setPos(x(),y()-5);
        counter++;
    }
    //repeat
    if(u == 1 && pos().y() <= sy2){
        r = 0;
        u = 0;
        counter++;
    }
}

void Enemy2 :: shoot(){
    //create a bullet
    Bullet2 * bullet2 = new Bullet2();
    bullet2->setPos(pos().x()+58,pos().y()+100);
    scene()->addItem(bullet2);
}
