/*
 * Transform.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#include "Transform.h"

Transform::Transform(Point position, double scale_x, double scale_y, double rotation){
	this->position = Vector2d(Point(), position);
	this->scale = Vector2d(scale_x, scale_y);
	this->rotation = rotation;

	velocity = Vector2d();
	acceleration = Vector2d();
	angularVelocity = 0;
	angularAcceleration = 0;
}

Point Transform::getCenter(){
	return Point(position.getCoordinate(0), position.getCoordinate(1));
}

void Transform::setCenter(Point position){
	position = Vector2d(Point(), position);
}

void Transform::update(double delta){
	Vector2d delta_position;
	Vector2d delta_velocity;
	double delta_angularVelocity;
	double delta_rotation;

	delta_velocity = acceleration;
	delta_velocity.scale(delta);
	velocity.translate(delta_velocity);

	delta_position = velocity;
	velocity.scale(delta);
	position.translate(delta_position);

	delta_angularVelocity = angularAcceleration * delta;
	angularVelocity += delta_angularVelocity;

	delta_rotation = angularVelocity * delta;
	rotation += delta_rotation;
}

