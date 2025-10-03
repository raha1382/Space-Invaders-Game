#include "Game.h"
#include "Score.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Player.h"
#include "Button.h"
#include "Bullet1.h"
#include "Bullet2.h"
#include "Obstacle.h"


Game::Game(){
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1500,1000);
    setBackgroundBrush(QBrush(QImage(":/images/bckg.png")));

    //set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1500,1000);
    setScene(scene);

}



void Game::start()
{
    enemycount = 0;
    playercount = 0;

    //play again
    scene->clear();

    //add player to the scene
    Player* player = new Player();
    scene->addItem(player);
    player->setPos(671.5,840);

    //player responding to key events
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add enemies to the scene
    for(int i = 0 ; i < 6 ; i++){
        //remainder for enemy constructor
        int r1 = rand() % 200;
        //enemy (random)
        int n = rand() % 2 + 1;
        int y = 100;
        int x = 100 + 200*i;
        if(n == 1){
            Enemy1 * enemy1 = new Enemy1(x,y);
            scene->addItem(enemy1);
        }
        else{
            Enemy2 * enemy2 = new Enemy2(x, y, r1);
            scene->addItem(enemy2);
        }
    }
    for(int i = 0 ; i < 6  ; i++){
        int r1 = rand() % 200;
        int n = rand()%2 + 1;
        int y = 250;
        int x = 100+200*i;
        if(n == 1){
            Enemy1 * enemy1 = new Enemy1(x,y);
            scene->addItem(enemy1);
        }
        else{
            Enemy2 * enemy2 = new Enemy2(x, y, r1);
            scene->addItem(enemy2);
        }
    }
    for(int i = 0 ; i < 6  ; i++){
        int r1 = rand()%200;
        int n = rand()%2 + 1;
        int y = 400;
        int x = 100 + 200*i;
        if(n == 1){
            Enemy1 * enemy1 = new Enemy1(x,y);
            scene->addItem(enemy1);
        }
        else{
            Enemy2 * enemy2 = new Enemy2(x, y, r1);
            scene->addItem(enemy2);
        }
    }

    int x;
    //add Obstacles
    for(int i = 0 ; i < 4 ; i++){
        x = 100+80*i;
        int y = 700;
        Obstacle* obstacle = new Obstacle(x,y);
        scene->addItem(obstacle);
    }
    for(int i = 0 ; i<4 ; i++){
        x = 420+80*i;
        int y = 650;
        Obstacle* obstacle = new Obstacle(x,y);
        scene->addItem(obstacle);
    }

    for(int i = 0 ; i<4 ; i++)
    {
        x = 740+80*i;
        int y = 700;
        Obstacle* obstacle = new Obstacle(x,y);
        scene->addItem(obstacle);
    }
    for(int i = 0 ; i<4 ; i++){
        x = 1060+80*i;
        int y = 650;
        Obstacle* obstacle = new Obstacle(x,y);
        scene->addItem(obstacle);
    }


    //create the score
    score = new Score();
    scene->addItem(score);
}

void Game::displayMainMenu(){
    //create the title text
    QGraphicsTextItem* title = new QGraphicsTextItem(QString("SPACE INVADERS"));
    QFont titleFont("Times", 50, QFont :: Bold);
    title->setFont(titleFont);
    title->setDefaultTextColor(Qt :: yellow);
    //title coordinates
    int txPos = this->width()/2 - title->boundingRect().width()/2;
    int tyPos = 150;
    title->setPos(txPos, tyPos);
    scene->addItem(title);

    //create play Button
    Button* playB = new Button(QString("PLAY"));
    //button coordinates
    int pxPos = this->width()/2 - playB->boundingRect().width()/2;
    int pyPos = 450;
    playB->setPos(pxPos, pyPos);
    //when start button clicked --> start game
    connect(playB,SIGNAL(clicked()),this, SLOT(start()));
    scene->addItem(playB);

    //create quit Button
    Button * quitB = new Button(QString("QUIT"));
    int qxPos = this->width()/2 - quitB->boundingRect().width()/2;
    int qyPos = 550;
    quitB->setPos(qxPos, qyPos);
    connect(quitB,SIGNAL(clicked()),this, SLOT(close()));
    scene->addItem(quitB);
}

void Game::gameOver(){
    if(playercount == 1){
        displayLastMenu("GAME OVER !");
    }

    if(enemycount >= 18){
        displayLastMenu("YOU WON !");
    }


}

void Game::displayLastMenu(QString text){
    //pop up semi transparent panel
    QGraphicsRectItem * panel1 = new QGraphicsRectItem(0,0,1500,1000);
    panel1->setBrush(Qt :: black);
    panel1->setOpacity(0.65);
    scene->addItem(panel1);

    //draw panel
    QGraphicsRectItem * panel2 = new QGraphicsRectItem(550,300,400,400);
    panel2->setBrush(Qt :: cyan);
    panel2->setOpacity(0.75);
    scene->addItem(panel2);

    //create play again button
    Button * againB = new Button(QString("PLAY AGAIN"));
    againB->setPos(650, 440);
    connect(againB,SIGNAL(clicked()),this, SLOT(start()));
    scene->addItem(againB);

    //create quit button
    Button * quitB = new Button(QString("QUIT"));
    quitB->setPos(650, 540);
    connect(quitB,SIGNAL(clicked()),this, SLOT(close()));
    scene->addItem(quitB);

    //text = winner / loser
    QGraphicsTextItem * textB = new QGraphicsTextItem(text,panel2);
    QFont tFont("Times", 20, QFont :: Bold);
    textB->setFont(tFont);
    textB->setPos(659,350);
    scene->addItem(textB);
}



