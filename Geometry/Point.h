/*
 * Point.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#ifndef GEOMETRY_POINT_H_
#define GEOMETRY_POINT_H_


class Point{
protected:
	double x, y;
public:
	Point() : x(0), y(0){};
	Point(double x, double y) : x(x), y(y){};

	double getCoordinate(const int id);
	double getCoordinate(const char id);

	void setCoordinate(const int id, const double value);
	void setCoordinate(const char id, const double value);
};


#endif /* GEOMETRY_POINT_H_ */
