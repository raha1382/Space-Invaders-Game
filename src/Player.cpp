#include "Player.h"
#include "Bullet1.h"
#include "Game.h"

#include <QKeyEvent>
#include <QGraphicsview>
#include <QApplication>
#include <QBrush>

extern Game* game;

Player :: Player(){
    // set graphic
    setPixmap(QPixmap(":/images/Player.jpeg").scaled(105,165));
}
void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if(pos().x()>0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x()+190 < 1500)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        //create a bullet
        if(game->enemycount < 18 && game->playercount < 1){
            Bullet1 * bullet1 = new Bullet1();
            bullet1->setPos(x()+20,y()-40);
            scene()->addItem(bullet1);
        }
    }
}
