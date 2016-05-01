/*
 * Vector2d.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#ifndef MATH_VECTOR2D_H_
#define MATH_VECTOR2D_H_

#include "../Geometry/Point.h"

class Vector2d : public Point{
private:
	static const int SIZE = 2;
public:
	Vector2d() : Point(Point(0, 0)){}
	Vector2d(double x, double y) : Point(Point(x, y)){}
	Vector2d(Point a, Point b) : Point(Point(b.getCoordinate(0) - a.getCoordinate(0), b.getCoordinate(1) - a.getCoordinate(1))){}
	void translate(double x, double y);
	void translate(Vector2d translation);

	void scale(double scale);
	void scale(double scale_x, double scale_y);

	void rotate(double degrees);

	double getMagnitude();
	double getDegrees();

	Vector2d getUnitVector();
	Vector2d add(Vector2d & vector_b);
	Vector2d subtract(Vector2d & vector_b);
	double dotProduct(Vector2d & vector_b);
	double component(Vector2d & vector_b);
	Vector2d project(Vector2d vector_b);
};

#endif /* MATH_VECTOR2D_H_ */
