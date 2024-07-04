#ifndef Def_H
#define Def_H

//the point class is used to simplify the movement for the block....
class Point{
private:
    int x,y;
public:
    Point(int _x=0, int _y=0);
	int getX() const;
	int getY() const;
	void setX(int value);
	void setY(int value);
	void set(int _x, int _y);
	void move(int dx=10);
    void drop(int dx=10);
};


//the Block is the thing need to move to insert inside the barrier.
//Block now should only have I shape and square shape... L shape will do or not depend on the situation....
class Block
{
private:
    Point location;
    int width,height;
    int color;
public:
    Block(Point _location=(0,0),int _width=0,int _height=0,int _color=0);
};
//I shape declaration         
class IShape:public Block{
private:

public:
draw();
undraw();
};
//Square shape declaration
class Squareshape:public Block{
private:

public:
draw();
undraw();
};
//Lshape declaration 
class LShape:public Block{
private:

public:
draw();
undraw();
};
//



//the barrie is inserted by the block
//may use subclass of the frame...
class Barrier
{
private:
    Block *empty;
    int x,y;
    int width,height;
    int color;
    int mark;
public:
    draw();
    undraw();
    markcalculate();
};

#endif
