/*
 * Buffer.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Pikcolo
 */

#include "Buffer.h"
#include <iostream>

 	 Buffer::Buffer(unsigned int a, unsigned int b) : size_x(a), size_y(b) {
 		data_ = new char[a * b];

 		clear();
 	}

 	 Buffer::~Buffer() {
 		delete[] data_;
 	}

 	char Buffer::get(unsigned int x, unsigned int y) const {
 		if (x < size_x && y < size_y)
 			return data_[x, y];
 		else {
 			//std::cerr << "ERROR: `Buffer::get`: index out of bounds\n";
 			//exit(1);
 			return ' ';
 		}
 	}

 	void Buffer::set(unsigned int x, unsigned int y, char c) {
 		if (x < size_x && y < size_y)
 			data_[y*size_x + x] = c;
 		else {
 			//std::cerr << "ERROR: `Buffer::set`: index out of bounds\n";
 			//exit(1);
 		}
 	}

 	void Buffer::set(unsigned int x, unsigned int y, std::string s) {
 		const unsigned int i = x;

 		for (int j = 0; j < s.length(); j++) {
 			if (s[j] == '\n') {
 				y++;
 				x = i;
 			}
 			else {
 				set(x, y, s[j]);
 				x++;
 			}
 		}
 	}

 	void Buffer::draw() const {
 		for (int i = 0; i < size_x*size_y; i++) {
 			std::cout << data_[i] << " ";

 			if ((i + 1) % size_x == 0)
 				std::cout << std::endl;
 		}
 	}

 	void Buffer::clear() {
 		for (int i = 0; i < size_x*size_y; i++)
 			data_[i] = ' ';
 	}
