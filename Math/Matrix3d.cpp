/*
 * Matrix3d.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#include "Matrix3d.h"
#include <math.h>

	Matrix3d Matrix3d::identity(){
		Matrix3d result;
		for (int i = 0; i < LENGTH; i++){
			for (int j = 0; j < LENGTH; j++){
				if(i == j)
					result.elements[i + j * LENGTH] = 1.0f;
				else
					result.elements[i + j * LENGTH] = 0.0f;
			}
		}

		return result;
	}

	Matrix3d Matrix3d::translation(Vector2d vector){
		Matrix3d result = identity();

		result.elements[0 + 2 * LENGTH] = vector.getCoordinate(0);
		result.elements[1 + 2 * LENGTH] = vector.getCoordinate(1);

		return result;
	}

	Matrix3d Matrix3d::scale(Vector2d vector){
		Matrix3d result = identity();

		result.elements[0 + 0 * LENGTH] = vector.getCoordinate(0);
		result.elements[1 + 1 * LENGTH] = vector.getCoordinate(1);

		return result;
	}

	Matrix3d Matrix3d::rotation(double angle){
		Matrix3d result = identity();
		double radians = angle * M_PI / 180.0;
		double cosine = cos(radians);
		double sine = sin(radians);

		result.elements[0 + 0 * LENGTH] = cosine;
		result.elements[1 + 0 * LENGTH] = sine;

		result.elements[0 + 1 * LENGTH] = -sine;
		result.elements[1 + 1 * LENGTH] = cosine;

		return result;
	}

	Matrix3d Matrix3d::multiply(Matrix3d matrix){
		Matrix3d result = identity();
		for (int y = 0; y < LENGTH; y++){
			for(int x = 0; x < LENGTH; x++){
				float sum = 0.0f;
				for(int e = 0; e < LENGTH; e++){
					sum += this->elements[x + e * LENGTH] * matrix.elements[e + y * LENGTH];
				}

				result.elements[x + y * LENGTH] = sum;
			}
		}

		return result;
	}

	Vector2d Matrix3d::multiply(Vector2d vector_a){
		Matrix3d result = multiply(translation(vector_a));

		double x = result.elements[0 + 2 * LENGTH];
		double y = result.elements[1 + 2 * LENGTH];

		return Vector2d(x, y);
	}
