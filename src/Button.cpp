#include "Button.h"

Button::Button(QString name)
{
    //draw button
    setRect(0,0,200,50);
    this->setBrush(Qt :: darkYellow);

    //write text
    QGraphicsTextItem * text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos, yPos);

    //allow responding to hover events
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //change color to yellow
    this->setBrush(Qt :: yellow);

}

void Button :: hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    //change color back to darkYellow
    this->setBrush(Qt :: darkYellow);
}
