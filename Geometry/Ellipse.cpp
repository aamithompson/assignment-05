/*
 * Ellipse.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#include <iostream>
using namespace std;
#include "Ellipse.h"

	_Ellipse::_Ellipse(Point foci_a, Point foci_b, double radius, Transform transform) : radius(radius), transform(transform){
		foci[0] = foci_a;
		foci[1] = foci_b;
	}

	bool _Ellipse::contains(const Point & p) const{
		double distance_a = Vector2d(foci[0], p).getMagnitude();
		double distance_b = Vector2d(foci[1], p).getMagnitude();

		return (distance_a + distance_b < 2 * radius);
	}

	void _Ellipse::draw(Buffer & b){
		double distance_x = Vector2d(foci[0].getCoordinate(0), foci[1].getCoordinate(0)).getMagnitude();
		double distance_y = Vector2d(foci[0].getCoordinate(1), foci[1].getCoordinate(1)).getMagnitude();
		double distance_foci = Vector2d(foci[0], foci[1]).getMagnitude();

		double semi_x_axis = sqrt(pow(distance_x + distance_y, 2.0) + distance_foci);
		double semi_y_axis = distance_x + distance_y;

		if(distance_x > distance_y){
			double temp = semi_x_axis;
			semi_x_axis = semi_y_axis;
			semi_y_axis = temp;
		}

		for(int x = 0; x < TERM_SIZE_X; x++){
			for(int y = 0; y < TERM_SIZE_Y; y++){
				double x_value = pow((x - transform.getCenter().getCoordinate(0))/semi_x_axis, 2.0);
				double y_value = pow((y - transform.getCenter().getCoordinate(1))/semi_y_axis, 2.0);
				double sum = x_value + y_value;

				if(sum > pow(radius, 2.0) - error_margin && sum < pow(radius, 2.0) + error_margin){
					Vector2d bufferPosition = Vector2d(x - transform.getCenter().getCoordinate(0), y - transform.getCenter().getCoordinate(1));
					bufferPosition.rotate(transform.rotation);
					bufferPosition.scale(transform.scale.getCoordinate(0), transform.scale.getCoordinate(1));
					bufferPosition.translate(transform.position);
					b.set(bufferPosition.getCoordinate(0), bufferPosition.getCoordinate(1), '*');
				}
			}
		}
	}

	void _Ellipse::update(double delta){
		transform.update(delta);
	}
