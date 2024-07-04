#include "Barrier.hpp"
#include "Point.hpp"
#include "Ishape.hpp"
#include <graphics.h>

Barrier::Barrier(Point _location =(0,0), int width = 0, int height = 0, int color = 0)
{
    empty = NULL;
}

void Barrier::set(Point _location, int _width, int _height, int _color)
{
    location = _location;
    width=_width;
    height=_height;
    color=_color;
}
