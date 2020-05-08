#include "sketch.h"

Sketch::Sketch(){
    shapes = new QList<Shape*>();
}

Sketch::Sketch(qreal x, qreal y, qreal width, qreal height, QWidget* parent):QGraphicsScene(x,y,width,height,parent){
    shapes = new QList<Shape*>();
}

void Sketch::drawShape(Shape *shape){
    if(!shapes->contains(shape)){
        shapes->append(shape);
    }
    if(shape->getType() == Shape::RECTANGLE){
        int *points = shape->getPoints();
        this->addRect(points[0],points[1],points[2]-points[0],points[3]-points[1],QPen(shape->getColor(),shape->getThickness()));
    }else if(shape->getType() == Shape::LINE){
        int *points = shape->getPoints();
        this->addLine(points[0],points[1],points[2],points[3],QPen(shape->getColor(),shape->getThickness()));
    }else if(shape->getType() == Shape::MULTI_LINE){
        int *points = shape->getPoints();
        int pointsCount = shape->getPointsCount();
        for (int c = 0; c < pointsCount-1; c++){
            this->addLine(points[c*2],points[c*2+1],points[c*2+2],points[c*2+3],QPen(shape->getColor(),shape->getThickness()));
        }
    }
    if(shape->getTextItem() != nullptr){
        shape->getTextItem()->setDefaultTextColor(shape->getColor());
        this->addItem(shape->getTextItem());
    }
}

void Sketch::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    qreal x = event->scenePos().x();
    qreal y = event->scenePos().y();
    for (QGraphicsItem* i : items()){
        removeItem(i);
    }
    for(Shape *s : *shapes){
        if(s->isHovered(x,y)){
            s->setColor(s->getColor());
        }else{
            s->setColor(s->getColor());
        }
        drawShape(s);
    }
}

void Sketch::updateShapes(){
    for(Shape *s : *shapes){
            s->setColor(s->getColor());
        drawShape(s);
    }
}

void Sketch::reset(){
for(Shape *s : *shapes){
//    s->setText("",Shape::MIDDLE);
    s->setColor(Qt::black);
//    s->setText("",Shape::MIDDLE);
}
}

