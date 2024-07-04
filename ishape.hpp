#include "point.hpp"
#include "Frame.hpp"

#ifndef Ishape_H
#define Ishape_H

class Ishape{
private: 
Point location;
Frame *linkFram;
int color;
int W=10;int H=40;

public:
Ishape (Point _location=(0,0),int _color=0);
void set(Point _location, int _color);
void draw() const; 
void undraw() const;
Point getPoint()const;
int getBottom()const;
void rotate();
void setFrame(Frame *);
Frame* getFrame() const;
};


#endif