#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <iostream>

#include "Enemy1.h"

Enemy1::Enemy1(int x1,int y1){
    setPixmap(QPixmap(":/images/Enemy1.jpg").scaled(150,100));
    //original coordinates
    sx1 = x1;
    sy1 = y1;
    //set coordinates
    this->setPos(x1,y1);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);
}

void Enemy1::move(){
    //right (if r = 0 : move right)
    if(r == 0 && pos().x() < 100 + sx1){
        setPos(x()+5,y());
    }
    if(pos().x() >= 100 + sx1){
        d = 1;
        r = 1;
    }
    //down (if d = 1 : move down)
    if(d == 1 && pos().y() < sy1 + 100){
        setPos(x(),y()+5);
    }
    if(pos().y() >= 100 + sy1 && d == 1){
        d = 0;
        l = 1;
    }
    //left (if l = 1 : move left)
    if(l == 1 && pos().x() >= sx1 ){
        setPos(x()-5,y());
    }
    if(pos().x() <= sx1 && l == 1){
        u = 1;
        l = 0;
    }
    //up(if u = 1 move up)
    if(u == 1 && pos().y() >= sy1 ){
        setPos(x(),y()-5);
    }
    //repeat
    if(u == 1 && pos().y() <= sy1){
        r = 0;
        u = 0;
    }
}
