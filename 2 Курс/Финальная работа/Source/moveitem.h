#ifndef MOVEITEM_H
#define MOVEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

#include "mainwindow.h"

class MoveItem : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit MoveItem(QObject* parent = 0);
    ~MoveItem();

signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem* option,QWidget* widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleseEvent(QGraphicsSceneMouseEvent* event);

};

#endif // MOVEITEM_H
