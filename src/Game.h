#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include "Score.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Player.h"
#include "Button.h"
#include "Bullet1.h"
#include "Bullet2.h"
#include "Obstacle.h"



class Game : public QGraphicsView
{
    Q_OBJECT
public:
    //constructor
    Game();

    //public methods
    void displayMainMenu();
    void gameOver();
    void displayLastMenu(QString text);

    //public attributes
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    int enemycount;
    int playercount;

public slots:
    void start();
};



#endif // GAME_H
