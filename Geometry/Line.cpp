/*
 * Line.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#include "Line.h"

		Line::Line(Point * a, Point * b){
			this->a = a;
			this->b = b;
		}

		Vector2d Line::getVector(){
			return Vector2d(*a, *b);
		}

		Vector2d Line::getVector(const char * sequence){
			if(sequence == "ba" || sequence == "BA")
				return Vector2d(*b, *a);
			else
				return getVector();
		}
