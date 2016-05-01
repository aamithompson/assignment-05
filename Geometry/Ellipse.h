/*
 * Ellipse.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#ifndef GEOMETRY_ELLIPSE_H_
#define GEOMETRY_ELLIPSE_H_

#include<math.h>

#include "Shape.h"
#include "../TextBuffer/Buffer.h"
#include "Transform.h"

class _Ellipse : public Shape {
protected:
	static const double error_margin = 1.25;
	Point foci[2];
	double radius;
public:
	double lol;
	Transform transform;

	virtual ~_Ellipse(){};
	_Ellipse(Point foci_a, Point foci_b, double radius, Transform transform);
	_Ellipse(Point foci, double radius, Transform transform);

	virtual bool contains(const Point & p) const;
	virtual void draw(Buffer & b);
	virtual void update(double delta);
};

#endif /* GEOMETRY_ELLIPSE_H_ */
