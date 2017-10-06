#include "paintscene.h"

PaintScene::PaintScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

PaintScene::~PaintScene()
{
}

void PaintScene::slotChangeColor(const QColor &color)
{
    _color = color;
    _pen.setColor(_color);
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        _pen.setWidth(10);
        addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                _pen);

        previousPoint = event->scenePos();
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
        return;

    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               10,
               10,
               QPen(Qt::NoPen),
               QBrush(Qt::red));

    previousPoint = event->scenePos();

    QGraphicsScene::mousePressEvent(event);
}
