/*
 * Line.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#ifndef GEOMETRY_LINE_H_
#define GEOMETRY_LINE_H_

#include "Point.h"
#include "../Math/Vector2d.h"

class Line{
	private:
		Point * a;
		Point * b;
	public:
		Line(Point * a, Point * b);
		Vector2d getVector();
		Vector2d getVector(const char * sequence);
};


#endif /* GEOMETRY_LINE_H_ */
