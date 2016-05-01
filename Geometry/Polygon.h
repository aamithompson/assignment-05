/*
 * Polygon.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#ifndef GEOMETRY_POLYGON_H_
#define GEOMETRY_POLYGON_H_

#include "Shape.h"
#include "Line.h"
#include <vector>

class Polygon : public Shape {
public:
	virtual ~Polygon() = default;

	std::vector<Point> vertex;
	std::vector<Line> edge;
};


#endif /* GEOMETRY_POLYGON_H_ */
