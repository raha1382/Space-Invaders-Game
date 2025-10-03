#include <iostream>
#include <QApplication>

#include "mainwindow.h"
#include "Game.h"


using namespace std;

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->displayMainMenu();

    return a.exec();
}
