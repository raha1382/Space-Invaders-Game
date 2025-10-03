#ifndef BULLET1_H
#define BULLET1_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "Game.h"



class Bullet1 : public QObject,public QGraphicsPixmapItem {
    //a macro from QObject
    Q_OBJECT

public:
    //constructor
    Bullet1();


public slots:
    //a member function that connects to a signal
    void move();

};
#endif // BULLET1_H
