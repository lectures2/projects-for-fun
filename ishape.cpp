#include "Ishape.hpp"
#include "point.hpp"

#include <graphics.h>
#include <iostream>


Ishape::Ishape(Point _location, int _color)
{
    linkFram=NULL;
    set(_location,_color);
}
void Ishape::set(Point _location,int _color){
    location=_location;
    color=_color;
}
void Ishape::draw() const{
    int x = location.getX();
    int y = location.getY();

    x += linkFram->getX();
    y += linkFram->getY();

    setfillstyle(SOLID_FILL,color);
    bar(x, y, x + W, y + H);
    setcolor(color);
    rectangle(x,y,x+W,x+H);
}

void Ishape::undraw()const{
    int x = location.getX();
    int y = location.getY();

    x += linkFram->getX();
    y += linkFram->getY();

    setfillstyle(SOLID_FILL,color);
    bar(x, y, x + W, y + H);
    setcolor(0);
    rectangle(x,y,x+W,x+H);
}

Point Ishape::getPoint()const{
    return location;
}

int Ishape::getBottom()const{return location.getY()+H;}

void Ishape::rotate(){
    int c;
    c=W;
    W=H;
    H=c;
}
void Ishape::setFrame(Frame * _linkFrame){linkFram=_linkFrame;}
Frame* Ishape::getFrame ()const{return linkFram;}