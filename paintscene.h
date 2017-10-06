#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QColor>
#include <QPen>

class PaintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    PaintScene(QObject *parent = nullptr);

    ~PaintScene();

public slots:
    void slotChangeColor(const QColor &color);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QPointF previousPoint;

    QPen _pen;
    QColor _color;
};

#endif // PAINTSCENE_H
