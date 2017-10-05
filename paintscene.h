#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class PaintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    PaintScene(QObject *parent = nullptr);

    ~PaintScene(){}

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QPointF previousPoint;
};

#endif // PAINTSCENE_H
