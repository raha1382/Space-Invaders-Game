#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsTextItem>
#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QOBject>

class Button : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    //constructor
    Button(QString name);

    //public methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QString text;

};

#endif // BUTTON_H
