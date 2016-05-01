/*
 * Matrix3d.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#ifndef MATH_MATRIX3D_H_
#define MATH_MATRIX3D_H_

#include "Vector2d.h"

class Matrix3d{
private:
	static const int LENGTH = 3;
	static const int SIZE = LENGTH * LENGTH;

public:
	double elements[SIZE];

	static Matrix3d identity();
	static Matrix3d translation(Vector2d vector);
	static Matrix3d scale(Vector2d vector);
	static Matrix3d rotation(double angle);
	Matrix3d multiply(Matrix3d matrix);
	Vector2d multiply(Vector2d vector);
};


#endif /* MATH_MATRIX3D_H_ */
