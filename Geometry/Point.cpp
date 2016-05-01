/*
 * Point.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#include "Point.h"

	double Point::getCoordinate(const int id){
		switch (id){
			case 0: return x;
				break;
			case 1: return y;
				break;
			default: return x;
				break;
		};
	}

	double Point::getCoordinate(const char id){
		switch (id){
			case 'x': return x;
				break;
			case 'y': return y;
				break;
			default: return x;
				break;
		};
	}

	void Point::setCoordinate(const int id, const double value){
		switch (id){
			case 0: x = value;
				break;
			case 1: y = value;
				break;
			default: x = value;
				break;
		};
	}

	void Point::setCoordinate(const char id, const double value){
		switch (id){
			case 'x': x = value;
				break;
			case 'y': y = value;
				break;
			default: x = value;
				break;
		};
	}


