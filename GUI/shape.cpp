#include "shape.h"

Shape::Shape(int startx,int starty,int endx,int endy, Type t, int thickness,QBrush b)/*:QGraphicsItem(startx,startx,endx,endy,parent)*/{
    points = new int[4];
    points[0] = startx;
    points[1] = starty;
    points[2] = endx;
    points[3] = endy;

    this->thickness = thickness;
    this->brush = b;
    this->type = t;
}



Shape::Shape(int* points,int pointsCount, Type t, int thickness){
    this->points = points;
    this->pointsCount = pointsCount;
    this->thickness = thickness;
    this->type = t;
}

void Shape::setThickness(int t){
    thickness = t;
}

int Shape::getThickness() const{
    return thickness;
}

int Shape::getPointsCount() const{
    return pointsCount;
}

Shape::Type Shape::getType() const{
    return this->type;
}






bool Shape::isHovered(qreal x, qreal y){
    if(x > points[0]-hoverOffset && x < points[2]+hoverOffset && y > points[1]-hoverOffset && y < points[3]+hoverOffset){
        return true;
    }else{
        return false;
    }
}

void Shape::setPen(QColor c){
    this->color = c;
}

QColor Shape::getColor(){
    return color;
}

int* Shape::getPoints() const{
    return points;
}

void Shape::setHoverOffset(int offset){
    this->hoverOffset = offset;
}

void Shape::setText(QString text, TextPos t){
    this->textItem = new QGraphicsTextItem(text);
    textItem->setFont(QFont(text,10,QFont::Bold));
    QFontMetrics fm(textItem->font());
    if(t == Shape::MIDDLE){
        this->textItem->setPos(points[0]+points[2]/2-fm.width(text)/2,
                                points[1]+(points[3])/2-fm.height()/2);
    }else if(t == Shape::TOP){
        this->textItem->setPos(points[0]+(points[2]-points[0])/2-fm.width(text)/2,
                                points[1] - fm.height() - 8);
    }
}
QBrush Shape::getBrush()
{
    return  this->brush;
}
QGraphicsTextItem* Shape::getTextItem(){
    return  textItem;
}
