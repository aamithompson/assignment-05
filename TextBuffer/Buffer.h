/*
 * Buffer.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#ifndef TEXTBUFFER_BUFFER_H_
#define TEXTBUFFER_BUFFER_H_

#include <iostream>
#include <string>
#include<cstdlib>

 const unsigned int TERM_SIZE_X = 80;
 const unsigned int TERM_SIZE_Y = 25;

class Buffer {
 private:
 	char * data_;
 public:
 	const unsigned int size_x;
 	const unsigned int size_y;

 	Buffer(unsigned int a, unsigned int b);

 	~Buffer();

 	char get(unsigned int x, unsigned int y) const;

 	void set(unsigned int x, unsigned int y, char c);

 	void set(unsigned int x, unsigned int y, std::string s);

 	void draw() const;

 	void clear();
 };


#endif /* TEXTBUFFER_BUFFER_H_ */
