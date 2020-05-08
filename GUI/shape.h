#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QFontMetrics>

class Shape {

public:

    enum Type{
        RECTANGLE,LINE,MULTI_LINE
    };

    enum TextPos{
        MIDDLE,TOP
    };

    Shape(int x1,int x2,int y1,int y2,Type t, int thickness = 1);
    Shape(int* points, int pointsCount,Type t, int thickness = 1);
    Type getType() const;
    int* getPoints() const;
    bool isHovered(qreal x, qreal y);
    void setColor(QColor);
    QColor getColor();
    void setHoverOffset(int);
    void setText(QString text, TextPos t);
    QGraphicsTextItem* getTextItem();
    void setThickness(int);
    int getThickness() const;
    int getPointsCount() const;

private:
    Type type;
    int *points;
    int hoverOffset = 10;
    int thickness = 1;
    int pointsCount = 2;
    QColor color = Qt::black;
    QGraphicsTextItem *textItem = nullptr;

};

#endif // DRAWOBJECT_H
