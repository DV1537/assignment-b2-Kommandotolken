#ifndef FIGURE_H
#define FIGURE_H
#include "Functions.h"
#include "Shape.h"

class Figure {
private:
	int capacity;
	Shape **shapeArray;
	float * floatArray;
	int numberOfPoints;
	int numberOfFigures = 0;
	Shape **shapeArrayTwoTemp = nullptr;

public:
	Figure();
	~Figure();
	Figure(int);
	
	void addShape(Shape *s);
	float* getBoundingBox();
	Shape* getClosest(float location[2], int n);

};

#endif FIGURE_H