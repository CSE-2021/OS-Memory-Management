#ifndef SKETCH_H
#define SKETCH_H

#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QDebug>
#include <QList>
#include "shape.h"

class Sketch : public QGraphicsScene {
public:
    Sketch();
    Sketch(qreal,qreal,qreal,qreal,QWidget *parent = nullptr);
    void drawShape(Shape *shape);
    void reset();
    void updateShapes();
    /*void removeShape(Shape* s)*/;

private:
    QList <Shape*> *shapes;

protected:
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
};

#endif // SKETCH_H
