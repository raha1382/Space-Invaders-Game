#ifndef ENEMY1_H
#define ENEMY1_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy1 : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    //constructor (gets coordinates)
    Enemy1(int x1, int y1);
    //direction check
    int r = 0, d = 0, l = 0, u = 0 ;
    //coordinates
    int sx1, sy1;

public slots:
    void move();

};

#endif // ENEMY1_H
