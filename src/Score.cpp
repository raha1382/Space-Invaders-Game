#include <QFont>

#include "Score.h"

Score::Score(){
    //initiliaze score to zero
    score = 0;

    //draw the text
    setPlainText(QString("Score : ") + QString :: number(score));
    setDefaultTextColor(Qt :: cyan);
    setFont(QFont("Times",16));
    setPos(680,8);
}

int Score::getScore(){
    return score;
}

void Score::increase(){
    score += 50;
    setPlainText(QString("Score : ") + QString :: number(score));
}
