#include "Rectangle.h"

bool RectanglesIntersect(const Rectangle& r1, const Rectangle& r2)
{
	// Check if the rectangles intersect along the x axis.
	//  Then check the y axis. If they intersect in both axes,
	//  we return true.

	// Use && for "and"

	bool intersectX = 
		r1.bottomLeft.x < r2.topRight.x &&
		r1.topRight.x > r2.bottomLeft.x;

	bool intersectY =
		r1.bottomLeft.y > r2.topRight.y &&
		r1.topRight.y < r2.bottomLeft.y;

	bool intersect = intersectX && intersectY;
	return intersect;
}

bool RectanglesIntersectX(const Rectangle& r1, const Rectangle& r2)
{
	// Check if the rectangles intersect along the x axis.
	//  Then check the y axis. If they intersect in both axes,
	//  we return true.

	// Use && for "and"

	bool intersectX = 
		r1.bottomLeft.x < r2.topRight.x &&
		r1.topRight.x > r2.bottomLeft.x;

	bool intersectY =
		r1.bottomLeft.y >= r2.topRight.y ||
		r1.topRight.y <= r2.bottomLeft.y;

	bool intersect = false;

	if(intersectX == true)
	{
		if(intersect == true)
		{
			intersect = true;
		}
		
	}
	return intersect;
}
