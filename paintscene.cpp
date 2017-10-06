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
    _pen.setColor(color);
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    _pen.setWidth(10);
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            _pen);

    previousPoint = event->scenePos();
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse(event->scenePos().x() - 5,
                   event->scenePos().y() - 5,
                   10,
                   10,
                   QPen(Qt::NoPen),
                   QBrush(Qt::red));

    previousPoint = event->scenePos();
}
