#include "moveitem.h"

MoveItem::MoveItem(QObject* parent): QObject(parent), QGraphicsItem()
{

}

MoveItem::~MoveItem()
{

}

QRectF MoveItem::boundingRect() const
{
    return QRectF (0,0,100,140);
}
void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->drawEllipse(0,0,100,40);
    painter->drawEllipse(0,100,100,40);
    painter->drawLine(0,20,0,120);
    painter->drawLine(100,20,100,120);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    this->setPos(mapToScene(event->pos()));

}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::SizeAllCursor));


    if(event->button() == Qt::RightButton)
                    {
                        qDebug() << "rClicked";

                    }


    Q_UNUSED(event);
}

void MoveItem::mouseReleseEvent(QGraphicsSceneMouseEvent* event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
