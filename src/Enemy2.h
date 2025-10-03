#ifndef ENEMY2_H
#define ENEMY2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy2 : public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    //constructor
    Enemy2(int x2 , int y2, int remainder);
    //check directions
    int r = 0 , d = 0, l = 0, u = 0, remain;
    int counter = 0;
    //coordinates
    int sx2 , sy2;


public slots:
    void move();
    void shoot();

};

#endif // ENEMY2_H
