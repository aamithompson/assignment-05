/*
 * Transform.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#ifndef GEOMETRY_TRANSFORM_H_
#define GEOMETRY_TRANSFORM_H_

#include "Point.h"
#include "../Math/Vector2d.h"

class Transform{
public:
	Vector2d position;
	Vector2d scale;
	double rotation;

	Vector2d velocity;
	Vector2d acceleration;
	double angularVelocity;
	double angularAcceleration;

	Transform(Point position, double scale_x, double scale_y, double rotation);

	Point getCenter();
	void setCenter(Point position);
	void update(double delta);
};


#endif /* GEOMETRY_TRANSFORM_H_ */
