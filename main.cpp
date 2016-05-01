/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Aaron Thompson <aamithompson@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

#include <iostream>
#include <windows.h>
#include <vector>
#include <time.h>

#include "Math/Vector2d.h"
#include "Geometry/Shape.h"
#include "Geometry/Ellipse.h"
#include "TextBuffer/Buffer.h"

bool running;
const int fps = 60;
//TODO delete
void draw();
void draw(const std::vector<Shape*> & v, Buffer & b);
void clear_screen();

int main() {
	SYSTEMTIME time;
	running = true;
	const double waitTime = 1.0/(double)fps;
	GetSystemTime(&time);

	double lastTime = (time.wMilliseconds);
	double deltaTime = lastTime;

	Buffer b = Buffer(TERM_SIZE_X, TERM_SIZE_Y);

	_Ellipse test_ellipse = _Ellipse(Point(5, 1), Point(5, 1), 2.0, Transform(Point(5,5), 1.0, 1.0, 0.0));
	test_ellipse.transform.angularVelocity = 45;
	test_ellipse.transform.acceleration = Vector2d(0, 9.8);

	Shape * shape_01 = &test_ellipse;
	std::vector<Shape*> v;
	v.push_back(shape_01);

	while(running){;
		GetSystemTime(&time);
		deltaTime = time.wMilliseconds - lastTime;
		lastTime = time.wMilliseconds;
		test_ellipse.update(deltaTime/1000);
		draw(v, b);
		clear_screen();
		b.draw();
		b.clear();
		Sleep(waitTime * 1000.0);
	}

	return 0;
}

void draw(const std::vector<Shape*> & v, Buffer & b){
	for(int i = 0; i < v.size(); i++){
		v[i]->draw(b);
	}
}

void clear_screen(){
	#ifdef WINDOWS
    	std::system("cls");
	#else
    	std::system ("clear");
	#endif
}
