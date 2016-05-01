/*
 * Shape.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#ifndef GEOMETRY_SHAPE_H_
#define GEOMETRY_SHAPE_H_

#include <string>
#include "Point.h"
#include "../TextBuffer/Buffer.h"
#include "Transform.h"

class Shape{
public:
	virtual ~Shape(){};
	virtual bool contains(const Point & p) const = 0;
	virtual void draw(Buffer & b) = 0;
	virtual void update(double delta) = 0;
};

#endif /* GEOMETRY_SHAPE_H_ */
