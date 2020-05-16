#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QFontMetrics>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QPalette>

class Shape  {
//Q_OBJECT
public:
    enum Type{
        RECTANGLE,LINE,MULTI_LINE,RECTANGLE2
    };

    enum TextPos{
        MIDDLE,TOP
    };

    Shape(int x1,int y1,int x2, int y2,Type t, int thickness = 1, QBrush b =Qt::white);
    Shape(int* points, int pointsCount,Type t, int thickness = 1);
    Type getType() const;
    int* getPoints() const;
    bool isHovered(qreal x, qreal y);
    void setPen(QColor);
    QBrush getBrush();
    QColor getColor();
    void setHoverOffset(int);
    void setText(QString text, TextPos t);
    QGraphicsTextItem* getTextItem();
    void setThickness(int);
    int getThickness() const;
    int getPointsCount() const;
    QGraphicsTextItem *textItem = nullptr;


private:
    Type type;
    int *points;
    int hoverOffset = 10;
    int thickness = 1;
    int pointsCount = 2;
    QColor color = Qt::black;
    QBrush brush ;
    QPalette palette;


};

#endif // DRAWOBJECT_H
