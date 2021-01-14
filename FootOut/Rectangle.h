#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Vec2.h"

struct Rectangle
{
	Vec2f bottomLeft;
	Vec2f topRight;
};

bool RectanglesIntersect(
    const Rectangle& r1, 
    const Rectangle& r2);

bool RectanglesIntersectY(
    const Rectangle& r1, 
    const Rectangle& r2);

bool RectanglesIntersectX(
    const Rectangle& r1, 
    const Rectangle& r2);

#endif
