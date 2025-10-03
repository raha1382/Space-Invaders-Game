#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
public:
    Score();
    int getScore();
    void increase();
private:
    int score;
};

#endif // SCORE_H
