/*
 * Vector2d.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#include "Vector2d.h"
#include "Matrix3d.h"
#include <cmath>

	void Vector2d::translate(double x, double y){
		this->translate(Vector2d(x, y));
	}

	void Vector2d::translate(Vector2d translation){
		Vector2d result = Matrix3d::translation(translation).multiply(*this);

		for(int i = 0; i < SIZE; i++)
			this->setCoordinate(i, result.getCoordinate(i));
	}

	void Vector2d::scale(double scale){
		this->scale(scale, scale);
	}

	void Vector2d::scale(double scale_x, double scale_y){
		Vector2d result = Matrix3d::scale(Vector2d(scale_x, scale_y)).multiply(*this);


		for(int i = 0; i < SIZE; i++)
			this->setCoordinate(i, result.getCoordinate(i));
	}

	void Vector2d::rotate(double angle){
		Vector2d result = Matrix3d::rotation(angle).multiply(*this);


		for(int i = 0; i < SIZE; i++)
			this->setCoordinate(i, result.getCoordinate(i));
	}

	double Vector2d::getMagnitude(){
		double sum = 0;

		for(int i = 0; i < SIZE; i++)
			sum += pow(this->getCoordinate(0), 2.0);

		return sqrt(sum);
	}

	double Vector2d::getDegrees(){
		double radians = atan2(getCoordinate(1), getCoordinate(0));
		return radians * 180.0 / M_PI;
	}

	Vector2d Vector2d::getUnitVector(){
		Vector2d vector_a = *this;
		for(int i = 0; i < SIZE; i++)
			vector_a.setCoordinate(i, vector_a.getCoordinate(i)/this->getMagnitude());

		return vector_a;
	}

	Vector2d Vector2d::add(Vector2d & vector_b){
		Vector2d vector_a = *this;
		for(int i = 0; i < SIZE; i++)
			vector_a.setCoordinate(i, vector_a.getCoordinate(i) + vector_b.getCoordinate(i));

		return vector_a;
	}

	Vector2d Vector2d::subtract(Vector2d & vector_b){
		Vector2d vector_a = *this;
		for(int i = 0; i < SIZE; i++)
			vector_a.setCoordinate(i, vector_a.getCoordinate(i) - vector_b.getCoordinate(i));

		return vector_a;
	}

	double Vector2d::dotProduct(Vector2d & vector_b){
		double sum = 0;
		for(int i = 0; i < SIZE; i++)
			sum += this->getCoordinate(i) * vector_b.getCoordinate(i);

		return sum;
	}

	double Vector2d::component(Vector2d & vector_b){
		return dotProduct(vector_b)/vector_b.getMagnitude();
	}

	Vector2d Vector2d::project(Vector2d vector_b){
		vector_b.getUnitVector().scale(component(vector_b));
		return vector_b;
	}

