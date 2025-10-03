#ifndef BULLET2_H
#define BULLET2_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "Game.h"



class Bullet2 : public QObject,public QGraphicsPixmapItem {
    Q_OBJECT

public:
    //constructor
    Bullet2();
public slots:
    //a member function that connects to a signal
    void move();

};

#endif // BULLET2_H
